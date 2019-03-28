`include "defines.v"

module top(
    input [3:0] KEY,
    input [1:0] CLOCK_50,
    input [9:0] SW,
    output [6:0] HEX0,
    output [6:0] HEX1,
    output [6:0] HEX2,
    output [6:0] HEX3
);

// File to read compiled binary from.
integer binary_file;
integer bytes_read;
integer i;
initial
begin
    binary_file = $fopen("out.bin", "rb");
    bytes_read = $fread(sdram, binary_file);
    $fclose(binary_file);
    for (i = 0; i < 8000000; i = i + 1)
    begin
        if (sdram[i] == 'd14)
        begin
            code_section_start_address = i + 1;
            `REGISTER_IP = code_section_start_address;
            i = 8000000;
        end
    end
end

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

always @(posedge CLOCK_50)
begin
    if (KEY[0] == 0)
    begin
        state <= 'b0;
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
            `STATE_LOAD_TO_RAM:
            begin
                // TODO: Modify this state so that it actually loads from SD card.
                state <= `STATE_FETCH_OPERATION;
            end
            `STATE_FETCH_OPERATION:
            begin
                operation <= sdram[`REGISTER_IP];
                //$display("Fetched operation %d.", operation);
                state <= `STATE_FETCH_OPERAND1;
            end
            `STATE_FETCH_OPERAND1:
            begin
                operand1 <= sdram[`REGISTER_IP + 1];
                //$display("Fetched operand1 %d.", operand1);
                state <= `STATE_FETCH_OPERAND2;
            end
            `STATE_FETCH_OPERAND2:
            begin
                operand2 <= sdram[`REGISTER_IP + 2];
                //$display("Fetched operand2 %d.", operand2);
                state <= `STATE_EXECUTE_INSTRUCTION;
            end
            `STATE_EXECUTE_INSTRUCTION:
            begin
                case (operation)
                    // No operation.
                    `OPERATION_NOP:
                    begin
                        //$display("NOP");
                        `REGISTER_IP <= `REGISTER_IP + 'd3;
                    end
                    // Load value from RAM to register.
                    `OPERATION_LOAD:
                    begin
                        //$display("LOAD");
                        registers[operand2] <= sdram[operand1];
                        `REGISTER_IP <= `REGISTER_IP + 'd3;
                    end
                    // Store value into RAM from register.
                    `OPERATION_STORE:
                    begin
                        //$display("STORE");
                        sdram[operand2] <= registers[operand1];
                        `REGISTER_IP <= `REGISTER_IP + 'd3;
                    end
                    // Add two registers and store the result in register A.
                    `OPERATION_ADD:
                    begin
                        //$display("ADD");
                        `REGISTER_A <= registers[operand1] + registers[operand2];
                        `REGISTER_IP <= `REGISTER_IP + 'd3;
                    end
                    // Subtract two registers and store the result in register A.
                    `OPERATION_SUB:
                    begin
                        //$display("SUB");
                        `REGISTER_A <= registers[operand1] - registers[operand2];
                        `REGISTER_IP <= `REGISTER_IP + 'd3;
                    end
                    `OPERATION_OUT:
                    begin
                        //$display("OUT");
                        $display("%d", registers[operand1]);
                        `REGISTER_IP <= `REGISTER_IP + 'd3;
                    end
                    `OPERATION_IN:
                    begin
                        //$display("IN");
                        `REGISTER_IP <= `REGISTER_IP + 'd3;
                    end
                    // Copy register 1 to register 2.
                    `OPERATION_MOV:
                    begin
                        //$display("MOV");
                        registers[operand2] <= registers[operand1];
                        `REGISTER_IP <= `REGISTER_IP + 'd3;
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
                        `REGISTER_IP <= `REGISTER_IP + 'd3;
                    end
                    `OPERATION_JMPL:
                    begin
                        if (`REGISTER_A == 0)
                            `REGISTER_IP <= code_section_start_address + operand1;
                        else
                            `REGISTER_IP <= `REGISTER_IP + 'd3;
                    end
                    `OPERATION_JMPE:
                    begin
                        if (`REGISTER_A == 1)
                            `REGISTER_IP <= code_section_start_address + operand1;
                        else
                            `REGISTER_IP <= `REGISTER_IP + 'd3;
                    end
                    `OPERATION_JMPG:
                    begin
                        if (`REGISTER_A == 2)
                            `REGISTER_IP <= code_section_start_address + operand1;
                        else
                            `REGISTER_IP <= `REGISTER_IP + 'd3;
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
        endcase
    end
end

endmodule
