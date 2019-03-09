`include "defines.v"

module top(
    input [3:0] KEY,
    input [1:0] CLOCK_50,
    input [9:0] SW,
    output [6:0] HEX0,
    output [6:0] HEX1,
    output [6:0] HEX2,
    output [6:0] HEX3,
);

// CPU registers.
reg [7:0] operation;
reg [7:0] operand1;
reg [7:0] operand2;
reg [7:0] registers [7:0]; // IP, A, B, C, D, E, F, and G: eight 8-bit registers.
reg [31:0] code_section_start_address; // Where (in RAM) the instructions are located. code_section_start_address + IP is the address of the current instruction. Address is in bytes.

// SDRAM.
reg [7:0] sdram [8000000 - 1:0]; // 8 MB as 8 million bytes.
// State machine.
reg[7:0] state;

always @(posedge clk)
begin
    if (KEY[0] == 0)
    begin
        state <= 'b0;
        registers <= 'b0;
    end
    else
    begin
        case (state)
            // TODO: Modify this state so that it actually loads from SD card.
            `STATE_LOAD_TO_RAM:
            begin
                binary_file = $fopen("out.bin", "rb");
                $fread(sdram, binary_file);
                $fclose(binary_file);
                for (i = 0; i < 8000000; i = i + 1)
                begin
                    if (sdram[i] == 14)
                    begin
                        code_section_start_address <= i + 1;
                        break;
                    end
                end
                state <= `STATE_FETCH_OPERATION;
            end
            `STATE_FETCH_OPERATION:
            begin
                    operation <= sdram[`REGISTER_IP];
                    state <= `STATE_FETCH_OPERAND1;
            end
            `STATE_FETCH_OPERAND1:
            begin
            operand1 <= sdram[`REGISTER_IP + 1];
                    state <= `STATE_FETCH_OPERAND2;
            end
            `STATE_FETCH_OPERAND2:
            begin
            operand2 <= sdram[`REGISTER_IP + 2];
                    state <= `STATE_EXECUTE_INSTRUCTION;
            end
            `STATE_EXECUTE_INSTRUCTION:
            begin
                case (operation)
                    // No operation.
                    `OPERATION_NOP:
                    begin
                    end
                    // Load value from RAM to register.
                    `OPERATION_LOAD:
                    begin
                        registers[operand2] <= sdram[operand1];
                    end
                    // Store value into RAM from register.
                    `OPERATION_STORE:
                    begin
                        sdram[operand2] <= registers[operand1];
                    end
                    // Add two registers and store the result in register A.
                    `OPERATION_ADD:
                    begin
                        `REGISTER_A <= registers[operand1] + registers[operand2];
                    end
                    // Subtract two registers and store the result in register A.
                    `OPERATION_SUB:
                    begin
                        `REGISTER_A <= registers[operand1] - registers[operand2];
                    end
                    `OPERATION_OUT:
                    begin
                        $display("%d\n", registers[operand1];
                    end
                    `OPERATION_IN:
                    begin
                    end
                    // Copy register 1 to register 2.
                    `OPERATION_MOV:
                    begin
                        registers[operand2] <= registers[operand1];
                    end
                    `OPERATION_CMP:
                    begin
                    end
                    `OPERATION_JMPL:
                    begin
                    end
                    `OPERATION_JMPE:
                    begin
                    end
                    `OPERATION_JMPG:
                    begin
                    end
                    `OPERATION_RST:
                    begin
                    end
                    `OPERATION_HALT:
                    begin
                    end
                endcase
            end
        endcase
    end
end

endmodule
