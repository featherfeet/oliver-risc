`include "defines.v"

module top(
    input [3:0] KEY,
    input [1:0] CLOCK_50,
    input [9:0] SW,
    output [6:0] HEX0,
    output [6:0] HEX1,
    output [6:0] HEX2,
    output [6:0] HEX3,
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
    inout [15:0] DRAM_DQ
);

// CPU registers.
reg [`OPERATION_SIZE_BITS - 1:0] operation;
reg [`OPERAND_SIZE_BITS - 1:0] operand1;
reg [`OPERAND_SIZE_BITS - 1:0] operand2;
reg [`OPERAND_SIZE_BITS - 1:0] registers [`OPERAND_SIZE_BITS - 1:0]; // IP, A, B, C, D, E, F, and G: eight 8-bit registers.
reg [`OPERAND_SIZE_BITS - 1:0] code_section_start_address; // Where (in RAM) the instructions are located. code_section_start_address + IP is the address of the current instruction. Address is in bytes.

// ROM to read the program from.
reg [31:0] program_rom_address;
wire [7:0] program_rom_byte;
wire program_rom_done;
rom program_rom (
    .address(program_rom_address),
    .byte(program_rom_byte),
    .done(program_rom_done)
);

// Clock generator for SDRAM.
sdram_system_up_clocks_0 up_clocks_0 (
    .CLOCK_50    (CLOCK_50[0]),                       // clk_in_primary.clk
    .reset       (~KEY[0]),                        // clk_in_primary_reset.reset
    .sys_clk     (),                               // sys_clk.clk
    .sys_reset_n (),                               // sys_clk_reset.reset_n
    .SDRAM_CLK   (DRAM_CLK)                       // sdram_clk.clk
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
    .zs_we_n                        (DRAM_WE_N)
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
                ram_read_state <= START_READ_FROM_RAM;
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
always @(posedge CLOCK_50)
begin
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
    end
    else
    begin
        case (state)
            `STATE_INITIALIZE:
            begin
                if (sdram_controller.init_done && ram_stabilization_counter == 20)
                begin
                    $display("%t: Changing state to STATE_LOAD_TO_RAM", $time);
                    state <= `STATE_LOAD_TO_RAM;
                end
                else if (sdram_controller.init_done)
                begin
                    ram_stabilization_counter <= ram_stabilization_counter + 1;
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
                    if (program_rom_byte == `OPERATION_CODE)
                    begin
                        code_section_start_address <= program_rom_address + 1;
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
                    operation <= ram_read_data;
                    state <= `STATE_FETCH_OPERAND1;
                    $display("Fetched operation %d.", ram_read_data);
                    $display("%t: Changing state to STATE_FETCH_OPERAND1", $time);
                end
                else
                begin
                    state <= `STATE_FETCH_OPERATION;
                end
            end
            `STATE_FETCH_OPERAND1:
            begin
                if (ram_read_complete)
                begin
                    operand1 <= {ram_read_data[7:0], operand1[31:8]};
                    operand_byte_index <= operand_byte_index + 1;
                    ram_read_complete <= 'b0;
                end
                else
                    read_from_ram(`REGISTER_IP + `OPERATION_SIZE_BYTES + operand_byte_index);
                if (operand_byte_index == `OPERAND_SIZE_BYTES)
                begin
                    operand_byte_index <= 'b0;
                    state <= `STATE_FETCH_OPERAND2;
                    $display("Fetched operand1 %d.", operand1);
                end
                else
                    state <= `STATE_FETCH_OPERAND1;
            end
            `STATE_FETCH_OPERAND2:
            begin
                if (ram_read_complete)
                begin
                    operand2 <= {ram_read_data[7:0], operand2[31:8]};
                    operand_byte_index <= operand_byte_index + 1;
                    ram_read_complete <= 'b0;
                end
                else
                    read_from_ram(`REGISTER_IP + `OPERATION_SIZE_BYTES + `OPERAND_SIZE_BYTES + operand_byte_index);
                if (operand_byte_index == `OPERAND_SIZE_BYTES)
                begin
                    operand_byte_index <= 'b0;
                    state <= `STATE_EXECUTE_INSTRUCTION;
                    $display("Fetched operand2 %d.", operand2);
                end
                else
                    state <= `STATE_FETCH_OPERAND2;
            end
            `STATE_EXECUTE_INSTRUCTION:
            begin
                case (operation)
                    // No operation.
                    `OPERATION_NOP:
                    begin
                        //$display("NOP");
                        `REGISTER_IP <= `REGISTER_IP + `INSTRUCTION_SIZE_BYTES;
                    end
                    // Load value from RAM to register.
                    `OPERATION_LOAD:
                    begin
                        //$display("LOAD");
                        if (ram_read_complete)
                        begin
                            registers[operand2] <= {ram_read_data[7:0], registers[operand2][31:8]};
                            operand_byte_index <= operand_byte_index + 1;
                            ram_read_complete <= 'b0;
                        end
                        else
                            read_from_ram(operand1 + operand_byte_index);
                        if (operand_byte_index == `OPERAND_SIZE_BYTES)
                        begin
                            $display("Loaded value %d from address %d in RAM to register %d.", registers[operand2], operand1, operand2);
                            operand_byte_index <= 'b0;
                            `REGISTER_IP <= `REGISTER_IP + `INSTRUCTION_SIZE_BYTES;
                            state <= `STATE_FETCH_OPERATION;
                        end
                    end
                    // Store value into RAM from register.
                    `OPERATION_STORE:
                    begin
                        //$display("STORE");
                        if (ram_write_complete)
                        begin
                            operand_byte_index <= operand_byte_index + 1;
                            registers[operand1] <= {registers[operand1][`OPERAND_SIZE_BITS - 1:8], 8'b0};
                            ram_write_complete <= 'b0;
                        end
                        else
                        begin
                            write_to_ram(operand2 + operand_byte_index, registers[operand1][7:0]);
                        end
                        if (operand_byte_index == `OPERAND_SIZE_BYTES)
                        begin
                            operand_byte_index <= 'b0;
                            `REGISTER_IP <= `REGISTER_IP + `INSTRUCTION_SIZE_BYTES;
                            state <= `STATE_FETCH_OPERATION;
                        end
                    end
                    // Add two registers and store the result in register A.
                    `OPERATION_ADD:
                    begin
                        //$display("ADD");
                        `REGISTER_A <= registers[operand1] + registers[operand2];
                        `REGISTER_IP <= `REGISTER_IP + `INSTRUCTION_SIZE_BYTES;
                        state <= `STATE_FETCH_OPERATION;
                    end
                    // Subtract two registers and store the result in register A.
                    `OPERATION_SUB:
                    begin
                        //$display("SUB");
                        `REGISTER_A <= registers[operand1] - registers[operand2];
                        `REGISTER_IP <= `REGISTER_IP + `INSTRUCTION_SIZE_BYTES;
                        state <= `STATE_FETCH_OPERATION;
                    end
                    `OPERATION_OUT:
                    begin
                        $display("%d", registers[operand1]);
                        `REGISTER_IP <= `REGISTER_IP + `INSTRUCTION_SIZE_BYTES;
                        state <= `STATE_FETCH_OPERATION;
                    end
                    `OPERATION_IN:
                    begin
                        //$display("IN");
                        `REGISTER_IP <= `REGISTER_IP + `INSTRUCTION_SIZE_BYTES;
                        state <= `STATE_FETCH_OPERATION;
                    end
                    // Copy register 1 to register 2.
                    `OPERATION_MOV:
                    begin
                        //$display("MOV");
                        registers[operand2] <= registers[operand1];
                        `REGISTER_IP <= `REGISTER_IP + `INSTRUCTION_SIZE_BYTES;
                        state <= `STATE_FETCH_OPERATION;
                    end
                    `OPERATION_CMP:
                    begin
                        //$display("CMP");
                        if (registers[operand1] < registers[operand2])
                            `REGISTER_A <= 'd0;
                        else if (registers[operand1] == registers[operand2])
                            `REGISTER_A <= 'd1;
                        else
                            `REGISTER_A <= 'd2;
                        `REGISTER_IP <= `REGISTER_IP + `INSTRUCTION_SIZE_BYTES;
                        state <= `STATE_FETCH_OPERATION;
                    end
                    `OPERATION_JMPL:
                    begin
                        if (`REGISTER_A == 0)
                            `REGISTER_IP <= code_section_start_address + operand1;
                        else
                            `REGISTER_IP <= `REGISTER_IP + `INSTRUCTION_SIZE_BYTES;
                        state <= `STATE_FETCH_OPERATION;
                    end
                    `OPERATION_JMPE:
                    begin
                        if (`REGISTER_A == 1)
                            `REGISTER_IP <= code_section_start_address + operand1;
                        else
                            `REGISTER_IP <= `REGISTER_IP + `INSTRUCTION_SIZE_BYTES;
                        state <= `STATE_FETCH_OPERATION;
                    end
                    `OPERATION_JMPG:
                    begin
                        if (`REGISTER_A == 2)
                            `REGISTER_IP <= code_section_start_address + operand1;
                        else
                            `REGISTER_IP <= `REGISTER_IP + `INSTRUCTION_SIZE_BYTES;
                        state <= `STATE_FETCH_OPERATION;
                    end
                    `OPERATION_RST:
                    begin
                        `REGISTER_IP <= code_section_start_address;
                        `REGISTER_A <= 'b0;
                        `REGISTER_B <= 'b0;
                        `REGISTER_C <= 'b0;
                        `REGISTER_D <= 'b0;
                        `REGISTER_E <= 'b0;
                        `REGISTER_F <= 'b0;
                        `REGISTER_G <= 'b0;
                        state <= `STATE_FETCH_OPERATION;
                    end
                    `OPERATION_HALT:
                    begin
                        $finish;
                    end
                endcase
            end
        endcase
    end
end

endmodule
