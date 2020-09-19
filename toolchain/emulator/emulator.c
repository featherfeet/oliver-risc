#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "assembler.h"
#include "processor.h"

#define NUM_REGISTERS 8
#define REGISTER_IP registers[0]
#define REGISTER_A registers[1]
#define REGISTER_B registers[2]

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./emulator out.bin\n");
        return EXIT_FAILURE;
    }

	// Read in binary file.
	FILE *file = fopen(argv[1], "rb");
	fseek(file, 0L, SEEK_END);
	int raw_binary_length = ftell(file);
    if (raw_binary_length > TOTAL_RAM_SIZE_BYTES) {
        printf("\033[1;31mERROR: Program is too large to fit in RAM.\033[0m\n");
        return 1;
    }
	uint8_t *raw_binary = malloc(TOTAL_RAM_SIZE_BYTES);
	rewind(file);
	fread(raw_binary, raw_binary_length, 1, file);

    // Find the start of the .code section.
    int start_of_code_section_offset = 0; // The address in the raw binary where the .code section starts.
	for (int i = 0; i < raw_binary_length; i += OPERAND_SIZE) {
		if (raw_binary[i] == OPERATION_CODE) {
            start_of_code_section_offset = i + 1;
			break;
		}
	}

    OPERAND_C_TYPE registers[NUM_REGISTERS] = {0};

    REGISTER_IP = start_of_code_section_offset;
    // Execution loop.
    while (1) {
        printf("IP = %u\n", REGISTER_IP);
        // Fetch operation and operands.
        uint8_t operation = raw_binary[REGISTER_IP];
        OPERAND_C_TYPE operand1;
        memcpy(&operand1, raw_binary + REGISTER_IP + OPERATION_SIZE, OPERAND_SIZE);
        OPERAND_C_TYPE operand2;
        memcpy(&operand2, raw_binary + REGISTER_IP + OPERATION_SIZE + OPERAND_SIZE, OPERAND_SIZE);
        // Execute operation.
        switch (operation) {
            case (OPERATION_NOP):
                printf("NOP\n");
                REGISTER_IP += INSTRUCTION_SIZE;
                break;
            case (OPERATION_LOAD):
                printf("LOAD\n");
                memcpy(&registers[operand2], raw_binary + operand1, OPERAND_SIZE);
                printf("Loaded value %u from address %u in RAM to register %u.\n", registers[operand2], operand1, operand2);
                REGISTER_IP += INSTRUCTION_SIZE;
                break;
            case (OPERATION_STORE):
                printf("STORE\n");
                memcpy(raw_binary + operand2, &registers[operand1], OPERAND_SIZE);
                printf("Stored value %u into address %u in RAM from register %u.\n", registers[operand1], operand2, operand1);
                REGISTER_IP += INSTRUCTION_SIZE;
                break;
            case (OPERATION_ADD):
                printf("ADD\n");
                REGISTER_A = registers[operand1] + registers[operand2];
                REGISTER_IP += INSTRUCTION_SIZE;
                break;
            case (OPERATION_SUB):
                printf("SUB\n");
                REGISTER_A = registers[operand1] - registers[operand2];
                REGISTER_IP += INSTRUCTION_SIZE;
                break;
            case OPERATION_MULT:
                printf("MULT\n");
                REGISTER_A = registers[operand1] * registers[operand2];
                REGISTER_IP += INSTRUCTION_SIZE;
                break;
            case OPERATION_DIV:
                printf("DIV\n");
                OPERAND_C_TYPE reg1 = registers[operand1];
                OPERAND_C_TYPE reg2 = registers[operand2];
                REGISTER_A = reg1 / reg2;
                REGISTER_B = reg1 % reg2;
                // printf("%u / %u = %u R %u\n", reg1, reg2, REGISTER_A, REGISTER_B);
                REGISTER_IP += INSTRUCTION_SIZE;
                break;
            case (OPERATION_OUT):
                printf("\033[1;32mOUT [address %u, character '%c' (integer value %u)]\033[0m\n", registers[operand1], registers[operand2], registers[operand2]);
                REGISTER_IP += INSTRUCTION_SIZE;
                break;
            case (OPERATION_IN):
                printf("\033[1;31mOPERATION `IN` NOT SUPPORTED BY EMULATOR.\033[0m\n");
                REGISTER_IP += INSTRUCTION_SIZE;
                break;
            case (OPERATION_MOV):
                printf("MOV\n");
                registers[operand2] = registers[operand1];
                REGISTER_IP += INSTRUCTION_SIZE;
                break;
            case (OPERATION_CMP):
                printf("CMP register %u (value %u), register %u (value %u)\n", operand1, registers[operand1], operand2, registers[operand2]);
                if (registers[operand1] < registers[operand2])
                    REGISTER_A = 0;
                else if (registers[operand1] == registers[operand2])
                    REGISTER_A = 1;
                else
                    REGISTER_A = 2;
                REGISTER_IP += INSTRUCTION_SIZE;
                break;
            case (OPERATION_JMPL):
                printf("JMPL\n");
                if (REGISTER_A == 0)
                    REGISTER_IP = start_of_code_section_offset + operand1;
                else
                    REGISTER_IP += INSTRUCTION_SIZE;
                break;
            case (OPERATION_JMPE):
                printf("JMPE\n");
                if (REGISTER_A == 1)
                    REGISTER_IP = start_of_code_section_offset + operand1;
                else
                    REGISTER_IP += INSTRUCTION_SIZE;
                break;
            case (OPERATION_JMPG):
                printf("JMPG\n");
                if (REGISTER_A == 2)
                    REGISTER_IP = start_of_code_section_offset + operand1;
                else
                    REGISTER_IP += INSTRUCTION_SIZE;
                break;
            case (OPERATION_RST):
                printf("RST\n");
                memset(registers, 0, NUM_REGISTERS * OPERAND_SIZE);
                break;
            case (OPERATION_HALT):
                printf("HALT\n");
                exit(0);
                break;
            case (OPERATION_ISR):
                printf("\033[1;31mOPERATION `ISR` NOT SUPPORTED BY EMULATOR.\033[0m\n");
                REGISTER_IP += INSTRUCTION_SIZE;
                break;
            case (OPERATION_INT):
                printf("\033[1;31mOPERATION `INT` NOT SUPPORTED BY EMULATOR.\033[0m\n");
                REGISTER_IP += INSTRUCTION_SIZE;
                break;
            case (OPERATION_ENDINT):
                printf("\033[1;31mOPERATION `ENDINT` NOT SUPPORTED BY EMULATOR.\033[0m\n");
                REGISTER_IP += INSTRUCTION_SIZE;
                break;
            case (OPERATION_RLOAD):
                printf("RLOAD\n");
                memcpy(&registers[operand2], raw_binary + registers[operand1], OPERAND_SIZE);
                printf("Loaded value %u from address %u in RAM to register %u.\n", registers[operand2], operand1, operand2);
                REGISTER_IP += INSTRUCTION_SIZE;
                break;
            case (OPERATION_RSTORE):
                printf("RSTORE\n");
                memcpy(raw_binary + registers[operand2], &registers[operand1], OPERAND_SIZE);
                REGISTER_IP += INSTRUCTION_SIZE;
                break;
            case (OPERATION_CLOAD):
                printf("CLOAD\n");
                memcpy(&registers[operand2], &operand1, OPERAND_SIZE);
                REGISTER_IP += INSTRUCTION_SIZE;
                break;
        }
    }

    return 0;
}
