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

// State machine for the reading from ROM to RAM.
reg[7:0] load_to_ram_state;
parameter WAIT_FOR_RAM = 8'd0;
parameter WRITE_TO_RAM = 8'd1;
// Counter used to wait for the RAM to finish stabilizing.
reg[7:0] ram_stabilization_counter;
// State machine for the entire CPU's operation.
reg[7:0] state;
/////////////////////////////
initial
begin
    $display("Starting at time %t.", $time);
end
/////////////////////////////
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
        load_to_ram_state <= WAIT_FOR_RAM;
        operation <= 'b0;
        operand1 <= 'b0;
        operand2 <= 'b0;
        ram_stabilization_counter <= 'b0;
        `REGISTER_IP <= code_section_start_address;
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
                    state <= `STATE_FETCH_OPERATION;
                end
                else
                begin
                    case (load_to_ram_state)
                        WAIT_FOR_RAM:
                        begin
                            if (~sdram_controller_waitrequest_o)
                                load_to_ram_state <= WRITE_TO_RAM;
                            else
                                load_to_ram_state <= WAIT_FOR_RAM;
                        end
                        WRITE_TO_RAM:
                        begin
                            sdram_controller_address_i <= program_rom_address;
                            sdram_controller_be_n_i <= 'b00;
                            sdram_controller_cs_i <= 'b1;
                            sdram_controller_data_i <= program_rom_byte;
                            sdram_controller_wr_n_i <= 'b0;
                            if (sdram_controller_waitrequest_o)
                            begin
                                sdram_controller_wr_n_i <= 'b1;
                                load_to_ram_state <= WAIT_FOR_RAM;
                            end
                            else
                            begin
                                program_rom_address <= program_rom_address + 1;
                            end
                        end
                    endcase
                end
            end
            /*
            `STATE_FETCH_OPERATION:
            begin
                operation <= sdram[`REGISTER_IP];
                state <= `STATE_FETCH_OPERAND1;
            end
            `STATE_FETCH_OPERAND1:
            begin
                operand1 <= {sdram[`REGISTER_IP + `OPERATION_SIZE_BYTES + 3], sdram[`REGISTER_IP + `OPERATION_SIZE_BYTES + 2], sdram[`REGISTER_IP + `OPERATION_SIZE_BYTES + 1], sdram[`REGISTER_IP + `OPERATION_SIZE_BYTES]};
                state <= `STATE_FETCH_OPERAND2;
            end
            `STATE_FETCH_OPERAND2:
            begin
                operand2 <= {sdram[`REGISTER_IP + `OPERATION_SIZE_BYTES + `OPERAND_SIZE_BYTES + 3], sdram[`REGISTER_IP + `OPERATION_SIZE_BYTES + `OPERAND_SIZE_BYTES + 2], sdram[`REGISTER_IP + `OPERATION_SIZE_BYTES + `OPERAND_SIZE_BYTES + 1], sdram[`REGISTER_IP + `OPERATION_SIZE_BYTES + `OPERAND_SIZE_BYTES]};
                state <= `STATE_EXECUTE_INSTRUCTION;
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
                        registers[operand2] <= {sdram[operand1 + 3], sdram[operand1 + 2], sdram[operand1 + 1], sdram[operand1]};
                        `REGISTER_IP <= `REGISTER_IP + `INSTRUCTION_SIZE_BYTES;
                    end
                    // Store value into RAM from register.
                    `OPERATION_STORE:
                    begin
                        //$display("STORE");
                        sdram[operand2] <= registers[operand1][7:0];
                        sdram[operand2 + 1] <= registers[operand1][15:8];
                        sdram[operand2 + 2] <= registers[operand1][23:16];
                        sdram[operand2 + 3] <= registers[operand1][31:24];
                        `REGISTER_IP <= `REGISTER_IP + `INSTRUCTION_SIZE_BYTES;
                    end
                    // Add two registers and store the result in register A.
                    `OPERATION_ADD:
                    begin
                        //$display("ADD");
                        `REGISTER_A <= registers[operand1] + registers[operand2];
                        `REGISTER_IP <= `REGISTER_IP + `INSTRUCTION_SIZE_BYTES;
                    end
                    // Subtract two registers and store the result in register A.
                    `OPERATION_SUB:
                    begin
                        //$display("SUB");
                        `REGISTER_A <= registers[operand1] - registers[operand2];
                        `REGISTER_IP <= `REGISTER_IP + `INSTRUCTION_SIZE_BYTES;
                    end
                    `OPERATION_OUT:
                    begin
                        $display("%d", registers[operand1]);
                        `REGISTER_IP <= `REGISTER_IP + `INSTRUCTION_SIZE_BYTES;
                    end
                    `OPERATION_IN:
                    begin
                        //$display("IN");
                        `REGISTER_IP <= `REGISTER_IP + `INSTRUCTION_SIZE_BYTES;
                    end
                    // Copy register 1 to register 2.
                    `OPERATION_MOV:
                    begin
                        //$display("MOV");
                        registers[operand2] <= registers[operand1];
                        `REGISTER_IP <= `REGISTER_IP + `INSTRUCTION_SIZE_BYTES;
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
                    end
                    `OPERATION_JMPL:
                    begin
                        if (`REGISTER_A == 0)
                            `REGISTER_IP <= code_section_start_address + operand1;
                        else
                            `REGISTER_IP <= `REGISTER_IP + `INSTRUCTION_SIZE_BYTES;
                    end
                    `OPERATION_JMPE:
                    begin
                        if (`REGISTER_A == 1)
                            `REGISTER_IP <= code_section_start_address + operand1;
                        else
                            `REGISTER_IP <= `REGISTER_IP + `INSTRUCTION_SIZE_BYTES;
                    end
                    `OPERATION_JMPG:
                    begin
                        if (`REGISTER_A == 2)
                            `REGISTER_IP <= code_section_start_address + operand1;
                        else
                            `REGISTER_IP <= `REGISTER_IP + `INSTRUCTION_SIZE_BYTES;
                    end
                    `OPERATION_RST:
                    begin
                        `REGISTER_IP <= 'b0;
                        `REGISTER_A <= 'b0;
                        `REGISTER_B <= 'b0;
                        `REGISTER_C <= 'b0;
                        `REGISTER_D <= 'b0;
                        `REGISTER_E <= 'b0;
                        `REGISTER_F <= 'b0;
                        `REGISTER_G <= 'b0;
                    end
                    `OPERATION_HALT:
                    begin
                        $finish;
                    end
                endcase
                state <= `STATE_FETCH_OPERATION;
            end
        */
        endcase
    end
end

endmodule
