// Arithmetic Logic Unit -- the part of the CPU that executes instructions.
// Included by the `STATE_EXECUTE_INSTRUCTION state in top.v's state machine.
// NOTE: The next_instruction() task is defined in top.v. It advances the
// instruction pointer and state machine.

case (operation)
    // No operation.
    `OPERATION_NOP:
    begin
        $display("NOP");
        next_instruction();
    end
    // Load value from RAM address to register.
    `OPERATION_LOAD:
    begin
        if (operand_byte_index == `OPERAND_SIZE_BYTES)
        begin
            $display("LOAD");
            $display("Loaded value %0d from address %0d in RAM to register %0d.", registers[operand2], operand1, operand2);
            operand_byte_index <= 'b0;
            next_instruction();
        end
        else if (ram_read_complete)
        begin
            registers[operand2] <= {ram_read_data[7:0], registers[operand2][31:8]};
            operand_byte_index <= operand_byte_index + 8'd1;
            ram_read_complete <= 'b0;
        end
        else
            read_from_ram(operand1 + operand_byte_index);
    end
    // Load value from RAM address (stored in a register) to a register.
    `OPERATION_RLOAD:
    begin
        if (ram_read_complete)
        begin
            registers[operand2] <= {ram_read_data[7:0], registers[operand2][31:8]};
            operand_byte_index <= operand_byte_index + 8'd1;
            ram_read_complete <= 'b0;
        end
        else if (operand_byte_index == `OPERAND_SIZE_BYTES)
        begin
            $display("RLOAD");
            $display("Loaded value %0d from address %0d in RAM to register %0d.", registers[operand2], temp_address, operand2);
            operand_byte_index <= 'b0;
            next_instruction();
        end
        else
        begin
            if (operand_byte_index == 'd0)
            begin
                temp_address <= registers[operand1]; // In the event that RLOAD is called with the same register for both operands, copying the address to a separate temporary register stops the instruction from corrupting its own address register.
                read_from_ram(registers[operand1] + operand_byte_index);
            end
            else
                read_from_ram(temp_address + operand_byte_index);
        end
    end
    // Load value from constant operand into a register.
    `OPERATION_CLOAD:
    begin
        $display("CLOAD");
        registers[operand2] <= operand1;
        next_instruction();
    end
    // Store value into RAM from register.
    `OPERATION_STORE:
    begin
        if (operand_byte_index == `OPERAND_SIZE_BYTES)
        begin
            $display("STORE");
            sdram_controller_wr_n_i <= 'b1;
            operand_byte_index <= 'b0;
            next_instruction();
        end
        else if (ram_write_complete)
        begin
            operand_byte_index <= operand_byte_index + 8'd1;
            registers[operand1] <= {registers[operand1][7:0], registers[operand1][`OPERAND_SIZE_BITS - 1:8]};
            ram_write_complete <= 'b0;
        end
        else
        begin
            write_to_ram(operand2 + operand_byte_index, registers[operand1][7:0]);
        end
    end
    // Store value into RAM (at address specified by a register) from a register. registers[operand1] is the value being stored. registers[operand2] is the address in RAM to store at.
    `OPERATION_RSTORE:
    begin
        if (operand_byte_index == `OPERAND_SIZE_BYTES)
        begin
            $display("RSTORE");
            sdram_controller_wr_n_i <= 'b1;
            operand_byte_index <= 'b0;
            next_instruction();
        end
        else if (ram_write_complete)
        begin
            operand_byte_index <= operand_byte_index + 8'd1;
            registers[operand1] <= {registers[operand1][7:0], registers[operand1][`OPERAND_SIZE_BITS - 1:8]};
            ram_write_complete <= 'b0;
        end
        else
        begin
            if (operand_byte_index == 'b0)
            begin
                temp_address <= registers[operand2]; // In the event that RSTORE is called with the same register for both arguments, storing the address in a separate temporary register prevents the instruction corrupting its own address register.
                write_to_ram(registers[operand2] + operand_byte_index, registers[operand1][7:0]);
            end
            else
                write_to_ram(temp_address + operand_byte_index, registers[operand1][7:0]);
        end
    end
    // Add two registers and store the result in register A.
    `OPERATION_ADD:
    begin
        $display("ADD");
        `REGISTER_A <= registers[operand1] + registers[operand2];
        next_instruction();
    end
    // Subtract two registers and store the result in register A.
    `OPERATION_SUB:
    begin
        $display("SUB");
        `REGISTER_A <= registers[operand1] - registers[operand2];
        next_instruction();
    end
    // Multiply two registers and store the result in register A.
    `OPERATION_MULT:
    begin
        $display("MULT");
        `REGISTER_A <= registers[operand1] * registers[operand2];
        next_instruction();
    end
    // Divide the first register by the second register. Store the quotient in A and the remainder in B.
    `OPERATION_DIV:
    begin
        if (division_delay_counter == 'b0)
        begin
            divider_numerator <= registers[operand1];
            divider_denominator <= registers[operand2];
            division_delay_counter <= division_delay_counter + 'b1;
        end
        else if (division_delay_counter == `DIVISION_CYCLES + 'b1)
        begin
            $display("DIV");
            `REGISTER_A <= divider_quotient;
            `REGISTER_B <= divider_remainder;
            division_delay_counter <= 'b0;
            next_instruction();
        end
        else
        begin
            division_delay_counter <= division_delay_counter + 'b1;
        end
    end
    // Write to the I/O "memory" space (currently just the GPU's text buffer and the interrupt value). operand1 is the register number of the register containing the address to write to. operand2 is the register number of the register containing the value to write.
    `OPERATION_OUT:
    begin
        if (gpu_access_state == `GPU_ACCESS_STATE_SETUP && registers[operand1] < `GPU_TEXT_BUFFER_LENGTH)
        begin
            $display("OUT [address %0d, character '%c' (integer value %0d)]", registers[operand1], registers[operand2], registers[operand2]);
            gpu_write_enable <= 'b1;
            gpu_cell_to_access <= registers[operand1];
            gpu_character_to_write <= registers[operand2];
            gpu_access_state <= `GPU_ACCESS_STATE_FINISH;
        end
        else if (registers[operand1] == `INTERRUPT_VALUE_PORT)
        begin
            $display("Error: CPU cannot write to interrupt value port.");
            next_instruction(); // You cannot write to the interrupt value port.
        end
        else
        begin
            gpu_write_enable <= 'b0;
            gpu_access_state <= `GPU_ACCESS_STATE_SETUP;
            next_instruction();
        end
    end
    // Read from the I/O "memory" space. operand1 is the
    // register number of the register containing the port
    // number to read from. operand2 is the register number of the
    // register to read into.
    `OPERATION_IN:
    begin
        $display("IN");
        if (gpu_access_state == `GPU_ACCESS_STATE_SETUP && registers[operand1] < `GPU_TEXT_BUFFER_LENGTH)
        begin
            gpu_cell_to_access <= registers[operand1];
            gpu_access_state <= `GPU_ACCESS_STATE_FINISH;
        end
        else if (registers[operand1] == `INTERRUPT_VALUE_PORT)
        begin
            registers[operand2] <= interrupt_value_fifo_data_out;
            next_instruction();
        end
        else
        begin
            registers[operand2] <= {24'b0, gpu_character_read};
            gpu_access_state <= `GPU_ACCESS_STATE_SETUP;
            next_instruction();
        end
    end
    // Copy register 1 to register 2.
    `OPERATION_MOV:
    begin
        $display("MOV");
        registers[operand2] <= registers[operand1];
        next_instruction();
    end
    `OPERATION_CMP:
    begin
        $display("CMP register %0d (value %0d), register %0d (value %0d)", operand1, registers[operand1], operand2, registers[operand2]);
        if (registers[operand1] < registers[operand2])
            `REGISTER_A <= 'd0;
        else if (registers[operand1] == registers[operand2])
            `REGISTER_A <= 'd1;
        else
            `REGISTER_A <= 'd2;
        next_instruction();
    end
    `OPERATION_JMPL:
    begin
        $display("JMPL");
        if (`REGISTER_A == 0)
            `REGISTER_IP <= code_section_start_address + operand1;
        else
            `REGISTER_IP <= `REGISTER_IP + `INSTRUCTION_SIZE_BYTES;
        state <= `STATE_RUN_INTERRUPT;
    end
    `OPERATION_JMPE:
    begin
        $display("JMPE");
        if (`REGISTER_A == 1)
            `REGISTER_IP <= code_section_start_address + operand1;
        else
            `REGISTER_IP <= `REGISTER_IP + `INSTRUCTION_SIZE_BYTES;
        state <= `STATE_RUN_INTERRUPT;
    end
    `OPERATION_JMPG:
    begin
        $display("JMPG");
        if (`REGISTER_A == 2)
            `REGISTER_IP <= code_section_start_address + operand1;
        else
            `REGISTER_IP <= `REGISTER_IP + `INSTRUCTION_SIZE_BYTES;
        state <= `STATE_RUN_INTERRUPT;
    end
    // Bitwise OR two registers and store the result into A.
    `OPERATION_OR:
    begin
        `REGISTER_A <= registers[operand1] | registers[operand2];
        next_instruction();
    end
    // Bitwise AND two registers and store the result into A.
    `OPERATION_AND:
    begin
        `REGISTER_A <= registers[operand1] & registers[operand2];
        next_instruction();
    end
    // Bitwise XOR two registers and store the result into A.
    `OPERATION_XOR:
    begin
        `REGISTER_A <= registers[operand1] ^ registers[operand2];
        next_instruction();
    end
    // Flip all the bits in a register.
    `OPERATION_NOT:
    begin
        registers[operand1] <= ~registers[operand1];
        next_instruction();
    end
    `OPERATION_ISR:
    begin
        $display("ISR");
        interrupt_vector_table[registers[operand1]] <= operand2;
        next_instruction();
    end
    `OPERATION_INT:
    begin
        $display("INT");
        if (interrupt_fifo_access_state == `INTERRUPT_FIFO_ACCESS_STATE_SETUP)
        begin
            interrupt_fifo_data_in <= registers[operand1];
            interrupt_fifo_write <= 'b1;
            interrupt_fifo_access_state <= `INTERRUPT_FIFO_ACCESS_STATE_FINISH;
            interrupt_value_fifo_data_in <= 'b0;
            interrupt_value_fifo_write <= 'b1;
        end
        else
        begin
            state <= `STATE_RUN_INTERRUPT;
            interrupt_fifo_write <= 'b0;
            interrupt_value_fifo_write <= 'b0;
            interrupt_fifo_access_state <= `INTERRUPT_FIFO_ACCESS_STATE_SETUP;
        end
    end
    `OPERATION_RST:
    begin
        $display("RST");
        `REGISTER_IP <= code_section_start_address;
        `REGISTER_A <= 'b0;
        `REGISTER_B <= 'b0;
        `REGISTER_C <= 'b0;
        `REGISTER_D <= 'b0;
        `REGISTER_E <= 'b0;
        `REGISTER_F <= 'b0;
        `REGISTER_G <= 'b0;
        // TODO: Clear interrupt vector table and interrupt FIFO.
        state <= `STATE_RUN_INTERRUPT;
    end
    `OPERATION_ENDINT:
    begin
        $display("ENDINT");
        for (i = 0; i < `NUM_REGISTERS; i = i + 1)
            registers[i] <= shadow_registers[i];
        state <= `STATE_RUN_INTERRUPT;
        //`REGISTER_IR <= 'b0;
    end
    `OPERATION_HALT:
    begin
        //$display("HALT");
        state <= `STATE_EXECUTE_INSTRUCTION;
        //$finish;
    end
endcase
