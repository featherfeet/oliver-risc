`timescale 1ps/1ps

`include "defines.v"
`include "gpu/gpu_defines.v"

`ifdef verilator
    `include "libraries/220model.v"
    `include "gpu/gpu.v"
    `include "sdram/sdram_system_new_sdram_controller_0.v"
`endif

module top(
    input [3:0] KEY,
    input CLOCK_50,

    output DRAM_CLK,
    output [11:0] DRAM_ADDR,
    output DRAM_BA_0,
    output DRAM_BA_1,
    output DRAM_CAS_N,
    output DRAM_CKE,
    output DRAM_CS_N,
    output DRAM_LDQM,
    output DRAM_UDQM,
    output DRAM_RAS_N,
    output DRAM_WE_N,
    inout [15:0] DRAM_DQ,

    output wire [3:0] VGA_R,
    output wire [3:0] VGA_G,
    output wire [3:0] VGA_B,
    output wire VGA_HS,
    output wire VGA_VS,
    // synthesis translate_off
    output wire VGA_PIXEL_CLOCK,
    // synthesis translate_on

    input PS2_CLK,
    input PS2_DAT,
    output wire [7:0] LEDG,
    output wire [35:0] GPIO_0,

    output wire SD_CLK, // Also called SCK or SCLK.
    output wire SD_CMD, // Also called DI or COPI.
    input SD_DAT, // Also called DO or CIPO.
    output wire SD_DAT3 // Also called CS or SS.

    `ifdef verilator
        ,input verilator_only_dram_clk,
        input verilator_only_vga_pixel_clock
    `endif
);

integer i; // Counter used for unrolled for-loops.

// Clock generator for the SDRAM and VGA clocks. When given a 50 MHz clock as
// inclk0, this PLL generates a 50 MHz clock with -3000 ps phase shift as c0
// and a 150 MHz clock with 0 ps phase shift as c1. c0 is used for the SDRAM
// clock, and c1 is used as the VGA pixel clock.
`ifdef verilator
    assign DRAM_CLK = verilator_only_dram_clk;
    assign VGA_PIXEL_CLOCK = verilator_only_vga_pixel_clock;
`else
    clock_generator clock_generator(.areset(~KEY[0]),
                                    .inclk0(CLOCK_50),
                                    .c0(DRAM_CLK),
                                    .c1(VGA_PIXEL_CLOCK)
    );
`endif

// CPU registers.
reg [`OPERATION_SIZE_BITS - 1:0] operation;
reg [`OPERAND_SIZE_BITS - 1:0] operand1;
reg [`OPERAND_SIZE_BITS - 1:0] operand2;
reg [`OPERAND_SIZE_BITS - 1:0] registers [`NUM_REGISTERS - 1:0]; // IP, A, B, C, D, E, F, and G: eight 32-bit registers.
reg [`OPERAND_SIZE_BITS - 1:0] shadow_registers [`NUM_REGISTERS - 1:0]; // "registers" is copied to here while an interrupt is running.
reg [`OPERAND_SIZE_BITS - 1:0] code_section_start_address; // Where (in RAM) the instructions are located.
reg [`OPERAND_SIZE_BITS - 1:0] program_end_address; // Where (in RAM) the binary ends.

reg [`OPERAND_SIZE_BITS - 1:0] temp_address; // For the RLOAD and RSTORE instructions, this register is used to store a copy of the address specified so that the instruction doesn't corrupt its own address register while executing.

// Interrupt vector table -- sets the memory addresses of the interrupt service routines.
reg [`OPERAND_SIZE_BITS - 1:0] interrupt_vector_table [`NUM_INTERRUPTS - 1:0]; // interrupt_vector_table[0] is the address of ISR number 0.

// Interrupt FIFO -- interrupts are placed into this fifo for processing.
reg [`OPERAND_SIZE_BITS - 1:0] interrupt_fifo_data_in;
reg interrupt_fifo_write;
wire interrupt_fifo_empty;
wire interrupt_fifo_full;
wire [`OPERAND_SIZE_BITS - 1:0] interrupt_fifo_data_out;
reg interrupt_fifo_read;
fifo #(.ITEM_SIZE_BITS(`OPERAND_SIZE_BITS), .FIFO_SIZE(10)) interrupt_fifo(.CLOCK_50(CLOCK_50),
                    .RST_N(KEY[0]),
                    .data_in(interrupt_fifo_data_in),
                    .write(interrupt_fifo_write),
                    .data_out(interrupt_fifo_data_out),
                    .read(interrupt_fifo_read),
                    .empty(interrupt_fifo_empty),
                    .full(interrupt_fifo_full)
);
reg [1:0] interrupt_fifo_access_state;

// Interrupt value FIFO -- used to store data that needs to be passed to interrupt service routines.
// Is always read/written in sync with the interrupt FIFO, so the empty/full signals aren't necessary.
reg [`OPERAND_SIZE_BITS - 1:0] interrupt_value_fifo_data_in;
reg interrupt_value_fifo_write;
wire [`OPERAND_SIZE_BITS - 1:0] interrupt_value_fifo_data_out;
reg interrupt_value_fifo_read;
fifo #(.ITEM_SIZE_BITS(`OPERAND_SIZE_BITS), .FIFO_SIZE(10)) interrupt_value_fifo(.CLOCK_50(CLOCK_50),
                                                                                .RST_N(KEY[0]),
                                                                                .data_in(interrupt_value_fifo_data_in),
                                                                                .write(interrupt_value_fifo_write),
                                                                                .data_out(interrupt_value_fifo_data_out),
                                                                                .read(interrupt_value_fifo_read));

// PS/2 keyboard.
wire[7:0] keyboard_scancode;
wire keyboard_scancode_ready;

assign LEDG = keyboard_scancode; // DEBUG

keyboard ps2_keyboard(
    .rst_n(KEY[0]),
    .CLOCK_50(CLOCK_50),
    .PS2_CLK(PS2_CLK),
    .PS2_DAT(PS2_DAT),
    .scancode(keyboard_scancode),
    .ready(keyboard_scancode_ready)
);

// FIFO to store keys.
wire [7:0] keyboard_scancode_fifo_data_out;
reg keyboard_scancode_fifo_read;
wire keyboard_scancode_fifo_empty;
wire keyboard_scancode_fifo_full;
reg[2:0] keyboard_scancode_fifo_access_state;
fifo #(.ITEM_SIZE_BITS(8), .FIFO_SIZE(5)) keyboard_scancodes_fifo(.CLOCK_50(CLOCK_50),
                                                                  .RST_N(KEY[0]),
                                                                  .data_in(keyboard_scancode),
                                                                  .write(keyboard_scancode_ready),
                                                                  .data_out(keyboard_scancode_fifo_data_out),
                                                                  .read(keyboard_scancode_fifo_read),
                                                                  .empty(keyboard_scancode_fifo_empty),
                                                                  .full(keyboard_scancode_fifo_full));

// Integrated GPU.
reg [$clog2(`GPU_TEXT_BUFFER_LENGTH) - 1:0] gpu_cell_to_access;
reg gpu_write_enable;
reg [6:0] gpu_character_to_write;
wire [6:0] gpu_character_read;
gpu integrated_graphics(.CLOCK_150(VGA_PIXEL_CLOCK),
                        .reset(~KEY[0]),
                        .VGA_R(VGA_R),
                        .VGA_G(VGA_G),
                        .VGA_B(VGA_B),
                        .VGA_HS(VGA_HS),
                        .VGA_VS(VGA_VS),
                        .CLOCK_50(CLOCK_50),
                        .cell_to_access(gpu_cell_to_access),
                        .write_enable(gpu_write_enable),
                        .character_to_write(gpu_character_to_write),
                        .character_read(gpu_character_read));
reg gpu_access_state;

// ROM to read the program from.
reg [31:0] program_rom_address;
wire [7:0] program_rom_byte;
wire program_rom_done;
reg program_rom_read_state;
rom program_rom (
    .CLOCK_50(CLOCK_50),
    .address(program_rom_address),
    .output_byte(program_rom_byte),
    .done(program_rom_done)
);

// SDRAM controller.
reg[21:0] sdram_controller_address_i;
reg[1:0] sdram_controller_be_n_i;
reg sdram_controller_cs_i;
reg[15:0] sdram_controller_data_i;
reg sdram_controller_rd_n_i;
reg sdram_controller_wr_n_i;
wire[15:0] sdram_controller_data_o;
wire sdram_controller_valid_o;
wire sdram_controller_waitrequest_o;
wire sdram_controller_init_done;
sdram_system_new_sdram_controller_0 sdram_controller(
    .az_addr                        (sdram_controller_address_i),
    .az_be_n                        (sdram_controller_be_n_i),
    .az_cs                          (sdram_controller_cs_i),
    .az_data                        (sdram_controller_data_i),
    .az_rd_n                        (sdram_controller_rd_n_i),
    .az_wr_n                        (sdram_controller_wr_n_i),
    .clk                            (DRAM_CLK),
    .reset_n                        (KEY[0]),
    .za_data                        (sdram_controller_data_o),
    .za_valid                       (sdram_controller_valid_o),
    .za_waitrequest                 (sdram_controller_waitrequest_o),
    .zs_addr                        (DRAM_ADDR),
    .zs_ba                          ({DRAM_BA_1, DRAM_BA_0}),
    .zs_cas_n                       (DRAM_CAS_N),
    .zs_cke                         (DRAM_CKE),
    .zs_cs_n                        (DRAM_CS_N),
    .zs_dq                          (DRAM_DQ),
    .zs_dqm                         ({DRAM_UDQM, DRAM_LDQM}),
    .zs_ras_n                       (DRAM_RAS_N),
    .zs_we_n                        (DRAM_WE_N),
    .init_done                      (sdram_controller_init_done)
);

// Task for writing to RAM.
// State machine for RAM write task.
reg[7:0] ram_write_state;
parameter WAIT_FOR_RAM_WRITE = 8'd0;
parameter WRITE_TO_RAM = 8'd1;
parameter RAM_WRITE_DONE = 8'd2;
reg ram_write_complete;
task write_to_ram;
    // Inputs for the address to write to and the data to write.
    input[21:0] ram_write_address;
    input[15:0] ram_write_data;
    begin
        case (ram_write_state)
            WAIT_FOR_RAM_WRITE:
            begin
                ram_write_complete <= 'b0;
                if (~sdram_controller_waitrequest_o)
                begin
                    ram_write_state <= WRITE_TO_RAM;
                end
                else
                begin
                    ram_write_state <= WAIT_FOR_RAM_WRITE;
                end
            end
            WRITE_TO_RAM:
            begin
                sdram_controller_address_i <= ram_write_address;
                sdram_controller_be_n_i <= 'b00;
                sdram_controller_cs_i <= 'b1;
                sdram_controller_data_i <= ram_write_data;
                sdram_controller_wr_n_i <= 'b0;
                ram_write_state <= RAM_WRITE_DONE;
            end
            RAM_WRITE_DONE:
            begin
                ram_write_complete <= 'b1;
                ram_write_state <= WAIT_FOR_RAM_WRITE;
            end
        endcase
    end
endtask

// Task for reading from RAM.
// State machine for RAM read task.
reg[7:0] ram_read_state;
parameter LATCH_RAM_READ_ADDRESS = 8'd0;
parameter START_READ_FROM_RAM = 8'd1;
parameter WAIT_FOR_RAM_READ = 8'd2;
reg ram_read_complete;
reg[15:0] ram_read_data;
task read_from_ram;
    // Address to read from.
    input[21:0] ram_read_address;
    begin
        case (ram_read_state)
            LATCH_RAM_READ_ADDRESS:
            begin
                sdram_controller_address_i <= ram_read_address;
                if (~sdram_controller_waitrequest_o)
                    ram_read_state <= START_READ_FROM_RAM;
                else
                    ram_read_state <= LATCH_RAM_READ_ADDRESS;
            end
            START_READ_FROM_RAM:
            begin
                //ram_read_complete <= 'b0;
                sdram_controller_address_i <= ram_read_address;
                sdram_controller_be_n_i <= 'b00;
                sdram_controller_cs_i <= 'b1;
                sdram_controller_rd_n_i <= 'b0;
                ram_read_state <= WAIT_FOR_RAM_READ;
            end
            WAIT_FOR_RAM_READ:
            begin
                sdram_controller_rd_n_i <= 'b1;
                if (sdram_controller_valid_o)
                begin
                    ram_read_state <= LATCH_RAM_READ_ADDRESS;
                    ram_read_data <= sdram_controller_data_o;
                    ram_read_complete <= 'b1;
                end
            end
        endcase
    end
endtask

// Counter used to wait for the RAM to finish stabilizing.
reg[7:0] ram_stabilization_counter;
// Counter used to read the 4-byte operands.
reg[7:0] operand_byte_index;
// State machine for the entire CPU's operation.
reg[7:0] state;

// Task to advance the state machine to the next instruction.
task next_instruction;
begin
    `REGISTER_IP <= `REGISTER_IP + `INSTRUCTION_SIZE_BYTES;
    state <= `STATE_RUN_INTERRUPT;
end
endtask

// Divider used for the DIV instruction (see alu/alu.v).
reg[$clog2(`DIVISION_CYCLES + 1):0] division_delay_counter;
reg [`OPERAND_SIZE_BITS - 1:0] divider_numerator;
reg [`OPERAND_SIZE_BITS - 1:0] divider_denominator;
wire [`OPERAND_SIZE_BITS - 1:0] divider_quotient;
wire [`OPERAND_SIZE_BITS - 1:0] divider_remainder;
lpm_divide #(.lpm_widthn(`OPERAND_SIZE_BITS), .lpm_widthd(`OPERAND_SIZE_BITS), .lpm_pipeline(`DIVISION_CYCLES)) divider (
    .numer(divider_numerator),
    .denom(divider_denominator),
    .clock(CLOCK_50),
    .aclr(1'b0),
    .clken(1'b1),
    .quotient(divider_quotient),
    .remain(divider_remainder)
);

// DEBUG
assign GPIO_0[0] = SD_CLK;
assign GPIO_0[1] = SD_CMD;
assign GPIO_0[2] = SD_DAT;
assign GPIO_0[3] = SD_DAT3;

// SPI controller for the SD card.
reg sd_card_spi_clock_select = 'b0;
assign SD_DAT3 = sd_card_spi_clock_select;

reg sd_card_spi_transmit_pulse = 0;
wire sd_card_spi_transmit_done;
reg [7:0] sd_card_spi_byte_to_send;
wire [7:0] sd_card_spi_byte_received;
spi_controller spi_controller(.reset_n(KEY[0]),
                              .CLOCK_50(CLOCK_50),
                              .transmit_pulse(sd_card_spi_transmit_pulse),
                              .transmit_done(sd_card_spi_transmit_done),
                              .byte_to_send(sd_card_spi_byte_to_send),
                              .byte_received(sd_card_spi_byte_received),
                              .SCK(SD_CLK),
                              .COPI(SD_CMD),
                              .CIPO(SD_DAT)
                          );

reg sd_card_spi_access_state;

always @(posedge CLOCK_50)
begin
    // RESET LOGIC
    if (KEY[0] == 0)
    begin
        sdram_controller_address_i <= 'b0;
        sdram_controller_be_n_i <= 'b0;
        sdram_controller_cs_i <= 'b1;
        sdram_controller_data_i <= 'b0;
        sdram_controller_rd_n_i <= 'b1;
        sdram_controller_wr_n_i <= 'b1;
        program_rom_address <= 'b0;
        program_rom_read_state <= `PROGRAM_ROM_READ_STATE_SETUP;
        state <= 'b0;
        operation <= 'b0;
        operand1 <= 'b0;
        operand2 <= 'b0;
        ram_stabilization_counter <= 'b0;
        ram_write_state <= WAIT_FOR_RAM_WRITE;
        ram_write_complete <= 'b0;
        ram_read_state <= LATCH_RAM_READ_ADDRESS;
        ram_read_complete <= 'b0;
        ram_read_data <= 'b0;
        operand_byte_index <= 'b0;
        `REGISTER_IP <= 'b0;
        `REGISTER_A <= 'b0;
        `REGISTER_B <= 'b0;
        `REGISTER_C <= 'b0;
        `REGISTER_D <= 'b0;
        `REGISTER_E <= 'b0;
        `REGISTER_F <= 'b0;
        `REGISTER_G <= 'b0;
        `REGISTER_IE <= 'b0;
        `REGISTER_IR <= 'b0;
        for (i = 0; i < `NUM_INTERRUPTS; i = i + 1)
            interrupt_vector_table[i] <= 'b0;
        gpu_access_state <= `GPU_ACCESS_STATE_SETUP;
        gpu_write_enable <= 'b0;
        gpu_character_to_write <= 'b0;
        interrupt_fifo_write <= 'b0;
        interrupt_fifo_data_in <= 'b0;
        interrupt_fifo_read <= 'b0;
        interrupt_fifo_access_state <= `INTERRUPT_FIFO_ACCESS_STATE_SETUP;
        keyboard_scancode_fifo_read <= 'b0;
        keyboard_scancode_fifo_access_state <= `KEYBOARD_SCANCODE_FIFO_ACCESS_STATE_READ_START;
        interrupt_value_fifo_write <= 'b0;
        interrupt_value_fifo_read <= 'b0;
        interrupt_value_fifo_data_in <= 'b0;
        code_section_start_address <= 'b0;
        program_end_address <= 'b0;
        divider_numerator <= 'b0;
        divider_denominator <= 'b0;
        division_delay_counter <= 'b0;
        temp_address <= 'b0;
        sd_card_spi_transmit_pulse <= 'b0;
        sd_card_spi_byte_to_send <= 'b0;
        sd_card_spi_clock_select <= 'b0;
        sd_card_spi_access_state <= `SD_CARD_SPI_ACCESS_STATE_WRITE;
    end
    else
    begin
        case (state)
            `STATE_INITIALIZE:
            begin
                if (sdram_controller_init_done && ram_stabilization_counter == 20)
                begin
                    $display("%t: Changing state to STATE_LOAD_TO_RAM", $time);
                    state <= `STATE_LOAD_TO_RAM;
                end
                else if (sdram_controller_init_done)
                begin
                    ram_stabilization_counter <= ram_stabilization_counter + 8'd1;
                    $display("%t: Init_done is done. Counter is %d.", $time, ram_stabilization_counter);
                end
                else
                begin
                    state <= `STATE_INITIALIZE;
                end
            end
            `STATE_LOAD_TO_RAM:
            begin
                if (program_rom_done)
                begin
                    $display("%t: Changing state to STATE_FETCH_OPERATION", $time);
                    sdram_controller_wr_n_i <= 'b1;
                    program_end_address <= program_rom_address;
                    // Add an offset OPERAND_SIZE_BYTES to the start of the
                    // code section because of the space taken up OPERAND_SIZE_BYTES bytes at
                    // the start of the file used to store the length.
                    code_section_start_address <= code_section_start_address + `OPERAND_SIZE_BYTES;
                    `REGISTER_IP <= code_section_start_address + `OPERAND_SIZE_BYTES;
                    // Next state.
                    state <= `STATE_FETCH_OPERATION;
                end
                else
                begin
                    /*
                    // Load the program from the ROM to RAM.
                    write_to_ram(program_rom_address, program_rom_byte);
                    if (ram_write_complete)
                    begin
                        // Read the next address.
                        program_rom_address <= program_rom_address + 1;
                        // The first OPERAND_SIZE_BYTES bytes of the binary
                        // contain the length of the .data section (which is also
                        // the offset to the beginning of the .code section). We
                        // store this value into code_section_start_address.
                        if (program_rom_address < `OPERAND_SIZE_BYTES)
                        begin
                            $display("program_rom_byte: %d", program_rom_byte);
                            code_section_start_address <= {program_rom_byte, code_section_start_address[31:8]};
                        end
                    end
                    else
                    begin
                        state <= `STATE_LOAD_TO_RAM;
                    end
                    */
                    if (program_rom_read_state == `PROGRAM_ROM_READ_STATE_SETUP)
                    begin
                        write_to_ram(program_rom_address, program_rom_byte);
                        $display("program_rom_address: %d", program_rom_address);
                        $display("program_rom_byte: %d", program_rom_byte);
                    end
                    if (ram_write_complete)
                    begin
                        if (program_rom_address < `OPERAND_SIZE_BYTES)
                        begin
                            code_section_start_address <= {program_rom_byte, code_section_start_address[31:8]};
                        end
                        // Read the next address.
                        program_rom_address <= program_rom_address + 1;
                        // Wait a cycle for the ROM to read by going through
                        // the FINISH state.
                        program_rom_read_state <= `PROGRAM_ROM_READ_STATE_FINISH;
                    end
                    else if (program_rom_read_state <= `PROGRAM_ROM_READ_STATE_FINISH)
                        program_rom_read_state <= `PROGRAM_ROM_READ_STATE_SETUP;
                end
            end
            `STATE_FETCH_OPERATION:
            begin
                read_from_ram(`REGISTER_IP);
                if (ram_read_complete)
                begin
                    ram_read_complete <= 'b0;
                    operation <= ram_read_data[7:0];
                    state <= `STATE_FETCH_OPERAND1;
                    //$display("Fetched operation %d.", ram_read_data);
                    //$display("%t: Changing state to STATE_FETCH_OPERAND1", $time);
                end
                else
                begin
                    state <= `STATE_FETCH_OPERATION;
                end
            end
            `STATE_FETCH_OPERAND1:
            begin
                if (operand_byte_index == `OPERAND_SIZE_BYTES)
                begin
                    operand_byte_index <= 'b0;
                    state <= `STATE_FETCH_OPERAND2;
                    //$display("Fetched operand1 %d.", operand1);
                end
                else if (ram_read_complete)
                begin
                    operand1 <= {ram_read_data[7:0], operand1[31:8]};
                    operand_byte_index <= operand_byte_index + 8'd1;
                    ram_read_complete <= 'b0;
                end
                else
                    read_from_ram(`REGISTER_IP + `OPERATION_SIZE_BYTES + operand_byte_index);
            end
            `STATE_FETCH_OPERAND2:
            begin
                if (operand_byte_index == `OPERAND_SIZE_BYTES)
                begin
                    operand_byte_index <= 'b0;
                    state <= `STATE_EXECUTE_INSTRUCTION;
                    //$display("Fetched operand2 %d.", operand2);
                end
                else if (ram_read_complete)
                begin
                    operand2 <= {ram_read_data[7:0], operand2[31:8]};
                    operand_byte_index <= operand_byte_index + 8'd1;
                    ram_read_complete <= 'b0;
                end
                else
                    read_from_ram(`REGISTER_IP + `OPERATION_SIZE_BYTES + `OPERAND_SIZE_BYTES + operand_byte_index);
            end
            `STATE_EXECUTE_INSTRUCTION:
            begin
                `include "alu/alu.v"
            end
            // Every cycle, check for interrupts and run the topmost one on the FIFO.
            `STATE_RUN_INTERRUPT:
            begin
                // If there are no interrupts to process (and we're not in the middle of processing one), proceed to the next state.
                if (`REGISTER_IR || (interrupt_fifo_empty && interrupt_fifo_access_state == `INTERRUPT_FIFO_ACCESS_STATE_SETUP))
                    state <= `STATE_ADD_INTERRUPTS;
                // If there is an interrupt to process (and we are not currently servicing an ISR), read it from the interrupt FIFO.
                else if (~`REGISTER_IR && ~interrupt_fifo_empty && interrupt_fifo_access_state == `INTERRUPT_FIFO_ACCESS_STATE_SETUP)
                begin
                    interrupt_fifo_read <= 'b1;
                    interrupt_value_fifo_read <= 'b1;
                    interrupt_fifo_access_state <= `INTERRUPT_FIFO_ACCESS_STATE_WAIT;
                end
                else if (interrupt_fifo_access_state == `INTERRUPT_FIFO_ACCESS_STATE_WAIT)
                begin
                    // Stop reading from the FIFO.
                    interrupt_fifo_read <= 'b0;
                    interrupt_value_fifo_read <= 'b0;
                    interrupt_fifo_access_state <= `INTERRUPT_FIFO_ACCESS_STATE_FINISH;
                end
                // Process the interrupt that was read from the FIFO.
                else if (interrupt_fifo_access_state == `INTERRUPT_FIFO_ACCESS_STATE_FINISH)
                begin
                    // Set the interrupt-running register.
                    `REGISTER_IR <= 'b1;
                    // Save all registers' states.
                    for (i = 0; i < `NUM_REGISTERS; i = i + 1)
                        shadow_registers[i] <= registers[i];
                    // Jump the current IP register to the interrupt routine.
                    $display("interrupt_fifo_data_out: %d", interrupt_fifo_data_out);
                    `REGISTER_IP <= code_section_start_address + interrupt_vector_table[interrupt_fifo_data_out];
                    interrupt_fifo_access_state <= `INTERRUPT_FIFO_ACCESS_STATE_SETUP;
                    state <= `STATE_ADD_INTERRUPTS;
                end
            end
            // Add any new hardware-triggered interrupts (keycodes, GPIO events, etc.) to the interrupt FIFO.
            `STATE_ADD_INTERRUPTS:
            begin
                if (`REGISTER_IE == 'b0 || (keyboard_scancode_fifo_empty && keyboard_scancode_fifo_access_state == `KEYBOARD_SCANCODE_FIFO_ACCESS_STATE_READ_START))
                    state <= `STATE_FETCH_OPERATION;
                else if (~keyboard_scancode_fifo_empty && keyboard_scancode_fifo_access_state == `KEYBOARD_SCANCODE_FIFO_ACCESS_STATE_READ_START)
                begin
                    keyboard_scancode_fifo_read <= 'b1;
                    keyboard_scancode_fifo_access_state <= `KEYBOARD_SCANCODE_FIFO_ACCESS_STATE_READ_END;
                end
                else if (keyboard_scancode_fifo_access_state == `KEYBOARD_SCANCODE_FIFO_ACCESS_STATE_READ_END)
                begin
                    keyboard_scancode_fifo_read <= 'b0;
                    keyboard_scancode_fifo_access_state <= `KEYBOARD_SCANCODE_FIFO_ACCESS_STATE_WRITE_START;
                end
                else if (keyboard_scancode_fifo_access_state == `KEYBOARD_SCANCODE_FIFO_ACCESS_STATE_WRITE_START)
                begin
                    interrupt_fifo_write <= 'b1;
                    interrupt_fifo_data_in <= `INTERRUPT_TYPE_KEY;
                    interrupt_value_fifo_data_in <= {24'b0, keyboard_scancode_fifo_data_out};
                    interrupt_value_fifo_write <= 'b1;
                    keyboard_scancode_fifo_access_state <= `KEYBOARD_SCANCODE_FIFO_ACCESS_STATE_WRITE_END;
                end
                else if (keyboard_scancode_fifo_access_state == `KEYBOARD_SCANCODE_FIFO_ACCESS_STATE_WRITE_END)
                begin
                    interrupt_fifo_write <= 'b0;
                    interrupt_value_fifo_write <= 'b0;
                    keyboard_scancode_fifo_access_state <= `KEYBOARD_SCANCODE_FIFO_ACCESS_STATE_READ_START;
                end
            end
        endcase
    end
end

endmodule
