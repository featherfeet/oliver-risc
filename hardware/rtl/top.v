`include "defines.v"
`include "gpu/gpu_defines.v"

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
    output wire VGA_PIXEL_CLOCK,

    input PS2_CLK,
    input PS2_DAT,
    output wire [7:0] LEDG,
    output wire [35:0] GPIO_0
);

integer i; // Counter used for unrolled for-loops.

// CPU registers.
reg [`OPERATION_SIZE_BITS - 1:0] operation;
reg [`OPERAND_SIZE_BITS - 1:0] operand1;
reg [`OPERAND_SIZE_BITS - 1:0] operand2;
reg [`OPERAND_SIZE_BITS - 1:0] registers [`NUM_REGISTERS - 1:0]; // IP, A, B, C, D, E, F, and G: eight 32-bit registers.
reg [`OPERAND_SIZE_BITS - 1:0] shadow_registers [`NUM_REGISTERS - 1:0]; // "registers" is copied to here while an interrupt is running.
reg [`OPERAND_SIZE_BITS - 1:0] code_section_start_address; // Where (in RAM) the instructions are located.
reg code_section_start_found; // Whether "code_section_start_address" has been found yet. 0 for not-found-yet, 1 for found.
reg [`OPERAND_SIZE_BITS - 1:0] program_end_address; // Where (in RAM) the binary ends.

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
reg interrupt_fifo_access_state;

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
assign GPIO_0[0] = PS2_CLK; // DEBUG
assign GPIO_0[1] = PS2_DAT; // DEBUG
assign LEDG = keyboard_scancode; // DEBUG
keyboard ps2_keyboard(.scancode(keyboard_scancode),
                      .ready(keyboard_scancode_ready),
                      .PS2_CLK(PS2_CLK),
                      .PS2_DAT(PS2_DAT));

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
reg [7:0] gpu_character_to_write;
wire [7:0] gpu_character_read;
gpu integrated_graphics(.CLOCK_50(CLOCK_50),
                        .reset(~KEY[0]),
                        .VGA_CLK(VGA_PIXEL_CLOCK),
                        .VGA_R(VGA_R),
                        .VGA_G(VGA_G),
                        .VGA_B(VGA_B),
                        .VGA_HS(VGA_HS),
                        .VGA_VS(VGA_VS),
                        .cell_to_access(gpu_cell_to_access),
                        .write_enable(gpu_write_enable),
                        .character_to_write(gpu_character_to_write),
                        .character_read(gpu_character_read));
reg gpu_access_state;

// ROM to read the program from.
reg [31:0] program_rom_address;
wire [7:0] program_rom_byte;
wire program_rom_done;
rom program_rom (
    .address(program_rom_address),
    .output_byte(program_rom_byte),
    .done(program_rom_done)
);

// Clock generator for SDRAM and VGA.
sdram_system_up_clocks_0 up_clocks_0 (
    .CLOCK_50    (CLOCK_50),                      // clk_in_primary.clk
    .reset       (~KEY[0]),                       // clk_in_primary_reset.reset
    .sys_clk     (),                              // sys_clk.clk
    .sys_reset_n (),                              // sys_clk_reset.reset_n
    .SDRAM_CLK   (DRAM_CLK),                      // sdram_clk.clk
    .VGA_CLK     (VGA_PIXEL_CLOCK)
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
reg division_state;
reg [`OPERAND_SIZE_BITS - 1:0] divider_numerator;
reg [`OPERAND_SIZE_BITS - 1:0] divider_denominator;
wire [`OPERAND_SIZE_BITS - 1:0] divider_quotient;
wire [`OPERAND_SIZE_BITS - 1:0] divider_remainder;
lpm_divide #(.lpm_widthn(`OPERAND_SIZE_BITS), .lpm_widthd(`OPERAND_SIZE_BITS)) divider (
    .numer(divider_numerator),
    .denom(divider_denominator),
    //.clock(),
    //.aclr('b0),
    //.clken('b1),
    .quotient(divider_quotient),
    .remain(divider_remainder)
);

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
        `REGISTER_IE <= 'b1;
        `REGISTER_IR <= 'b0;
        for (i = 0; i < `NUM_INTERRUPTS; i = i + 1)
            interrupt_vector_table[i] <= 'b0;
        gpu_access_state <= `GPU_ACCESS_STATE_SETUP;
        interrupt_fifo_write <= 'b0;
        interrupt_fifo_data_in <= 'b0;
        interrupt_fifo_read <= 'b0;
        interrupt_fifo_access_state <= `INTERRUPT_FIFO_ACCESS_STATE_SETUP;
        keyboard_scancode_fifo_read <= 'b0;
        keyboard_scancode_fifo_access_state <= `KEYBOARD_SCANCODE_FIFO_ACCESS_STATE_READ_START;
        interrupt_value_fifo_write <= 'b0;
        interrupt_value_fifo_read <= 'b0;
        code_section_start_address <= 'b0;
        code_section_start_found <= 'b0;
        program_end_address <= 'b0;
        divider_numerator <= 'b0;
        divider_denominator <= 'b0;
        division_state <= `DIVISION_STATE_LATCH;
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
                    state <= `STATE_FETCH_OPERATION;
                end
                else
                begin
                    write_to_ram(program_rom_address, program_rom_byte);
                    if (ram_write_complete)
                    begin
                        program_rom_address <= program_rom_address + 1;
                    end
                    else
                    begin
                        state <= `STATE_LOAD_TO_RAM;
                    end
                    if (~code_section_start_found && program_rom_byte == `OPERATION_CODE)
                    begin
                        code_section_start_address <= program_rom_address + 1;
                        code_section_start_found <= 'b1;
                        `REGISTER_IP <= program_rom_address + 1;
                    end
                    else
                    begin
                        state <= `STATE_LOAD_TO_RAM;
                    end
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
                if (interrupt_fifo_empty && interrupt_fifo_access_state == `INTERRUPT_FIFO_ACCESS_STATE_SETUP)
                    state <= `STATE_ADD_INTERRUPTS;
                // If there is an interrupt to process (and we are not currently servicing an ISR), read it from the interrupt FIFO.
                else if (~`REGISTER_IR && ~interrupt_fifo_empty && interrupt_fifo_access_state == `INTERRUPT_FIFO_ACCESS_STATE_SETUP)
                begin
                    interrupt_fifo_read <= 'b1;
                    interrupt_value_fifo_read <= 'b1;
                    interrupt_fifo_access_state <= `INTERRUPT_FIFO_ACCESS_STATE_FINISH;
                end
                // Process the interrupt that was read from the FIFO.
                else if (interrupt_fifo_access_state == `INTERRUPT_FIFO_ACCESS_STATE_FINISH)
                begin
                    // Set the interrupt-running register.
                    `REGISTER_IR <= 'b1;
                    // Save all registers' states (except the IP register).
                    for (i = 1; i < `NUM_REGISTERS; i = i + 1)
                        shadow_registers[i] <= registers[i];
                    // Make the shadow (saved) IP register point at the next instruction so that the program flow will continue after the interrupt routine completes (unless IP will go past the end of the program.
                    if (`REGISTER_IP + `INSTRUCTION_SIZE_BYTES >= program_end_address)
                        shadow_registers[0] <= `REGISTER_IP;
                    else
                        shadow_registers[0] <= `REGISTER_IP + `INSTRUCTION_SIZE_BYTES;
                    // Jump the current IP register to the interrupt routine.
                    `REGISTER_IP <= code_section_start_address + interrupt_vector_table[interrupt_fifo_data_out];
                    // Stop reading from the FIFO.
                    interrupt_fifo_read <= 'b0;
                    interrupt_value_fifo_read <= 'b0;
                    interrupt_fifo_access_state <= `INTERRUPT_FIFO_ACCESS_STATE_SETUP;
                    state <= `STATE_ADD_INTERRUPTS;
                end
            end
            // Add any new hardware-triggered interrupts (keycodes, GPIO events, etc.) to the interrupt FIFO.
            `STATE_ADD_INTERRUPTS:
            begin
                if (keyboard_scancode_fifo_empty && keyboard_scancode_fifo_access_state == `KEYBOARD_SCANCODE_FIFO_ACCESS_STATE_READ_START)
                    state <= `STATE_FETCH_OPERATION;
                else if (~keyboard_scancode_fifo_empty && keyboard_scancode_fifo_access_state == `KEYBOARD_SCANCODE_FIFO_ACCESS_STATE_READ_START)
                begin
                    keyboard_scancode_fifo_read <= 'b1;
                    keyboard_scancode_fifo_access_state <= `KEYBOARD_SCANCODE_FIFO_ACCESS_STATE_READ_END;
                end
                else if (keyboard_scancode_fifo_access_state == `KEYBOARD_SCANCODE_FIFO_ACCESS_STATE_READ_END)
                    keyboard_scancode_fifo_access_state <= `KEYBOARD_SCANCODE_FIFO_ACCESS_STATE_WRITE_START;
                else if (keyboard_scancode_fifo_access_state == `KEYBOARD_SCANCODE_FIFO_ACCESS_STATE_WRITE_START)
                begin
                    keyboard_scancode_fifo_read <= 'b0;
                    interrupt_fifo_write <= 'b1;
                    interrupt_fifo_data_in <= `INTERRUPT_TYPE_KEY;
                    interrupt_value_fifo_data_in <= {24'b0, keyboard_scancode_fifo_data_out};
                    interrupt_value_fifo_write <= 'b1;
                    keyboard_scancode_fifo_access_state <= `KEYBOARD_SCANCODE_FIFO_ACCESS_STATE_WRITE_END;
                end
                else if (keyboard_scancode_fifo_access_state == `KEYBOARD_SCANCODE_FIFO_ACCESS_STATE_WRITE_END)
                    keyboard_scancode_fifo_access_state <= `KEYBOARD_SCANCODE_FIFO_ACCESS_STATE_FINISH;
                else if (keyboard_scancode_fifo_access_state == `KEYBOARD_SCANCODE_FIFO_ACCESS_STATE_FINISH)
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
