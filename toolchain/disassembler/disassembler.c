#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "processor.h"

const char *registerToString(Register reg) {
	switch (reg) {
		case IP:
			return "IP";
		case A:
			return "A";
		case B:
			return "B";
		case C:
			return "C";
		case D:
			return "D";
		case E:
			return "E";
		case F:
			return "F";
		case G:
			return "G";
		default:
			return "?";
	}
}

const char *operationToString(Operation operation) {
    switch (operation) {
        case OPERATION_NOP:
            return "NOP";
        case OPERATION_LOAD:
            return "LOAD";
        case OPERATION_STORE:
            return "STORE";
        case OPERATION_ADD:
            return "ADD";
        case OPERATION_SUB:
            return "SUB";
        case OPERATION_OUT:
            return "OUT";
        case OPERATION_IN:
            return "IN";
        case OPERATION_MOV:
            return "MOV";
        case OPERATION_CMP:
            return "CMP";
        case OPERATION_JMPL:
            return "JMPL";
        case OPERATION_JMPE:
            return "JMPE";
        case OPERATION_JMPG:
            return "JMPG";
        case OPERATION_RST:
            return "RST";
        case OPERATION_HALT:
            return "HALT";
        case OPERATION_ISR:
            return "ISR";
        case OPERATION_INT:
            return "INT";
        case OPERATION_ENDINT:
            return "ENDINT";
        case OPERATION_RLOAD:
            return "RLOAD";
        case OPERATION_RSTORE:
            return "RSTORE";
        case OPERATION_CLOAD:
            return "CLOAD";
        case OPERATION_MULT:
            return "MULT";
        case OPERATION_DIV:
            return "DIV";
        case OPERATION_OR:
            return "OR";
        case OPERATION_AND:
            return "AND";
        case OPERATION_XOR:
            return "XOR";
        case OPERATION_NOT:
            return "NOT";
        default:
            return "???";
    }
}

int main(int argc, char *argv[]) {
	// Parse arguments.
	if (argc != 2) {
		fprintf(stderr, "Usage: ./disassembler binary.bin\n");
		return EXIT_FAILURE;
	}
	// Read in binary file.
	FILE *file = fopen(argv[1], "rb");
	fseek(file, 0L, SEEK_END);
	int raw_binary_length = ftell(file);
	uint8_t *raw_binary = malloc(raw_binary_length);
	rewind(file);
	fread(raw_binary, raw_binary_length, 1, file);
    OPERAND_C_TYPE start_of_code_section_offset = 0; // The address in the raw binary where the .code section starts.
    memcpy(&start_of_code_section_offset, raw_binary, OPERAND_SIZE); // The first OPERAND_SIZE bytes of the binary file specify the length of the .data section (which is also the offset at which the .code section begins).
    start_of_code_section_offset += OPERAND_SIZE; // Compensate for the first OPERAND_SIZE bytes of the binary file being used for the length of the .data section.
	// Loop through and disassemble the .data section of the binary.
	int i;
	printf(".data:\n");
	for (i = OPERAND_SIZE; i < start_of_code_section_offset; i += OPERAND_SIZE) {
        uint32_t value = 0;
        memcpy(&value, raw_binary + i, OPERAND_SIZE);
		printf("\t[%#08x]\t%d\n", i, value);
	}
	// Loop through and disassemble the .code section of the binary.
    printf(".code:\n");
    for (i = start_of_code_section_offset; i < raw_binary_length; i += INSTRUCTION_SIZE) {
        Operation operation = raw_binary[i];
        uint32_t operand1 = 0;
        uint32_t operand2 = 0;
        memcpy(&operand1, raw_binary + i + OPERATION_SIZE, OPERAND_SIZE);
        memcpy(&operand2, raw_binary + i + OPERATION_SIZE + OPERAND_SIZE, OPERAND_SIZE);
//        printf("\t[%#08x]\t%s", i - start_of_code_section_offset, operationToString(raw_binary[i]));
        printf("\t[%#08x]\t%s", i, operationToString(raw_binary[i]));
        switch (operation) {
            case OPERATION_NOP:
                printf("\n");
                break;
            case OPERATION_LOAD:
                printf(" [%#08x], %s\n", operand1, registerToString(operand2));
                break;
            case OPERATION_STORE:
                printf(" %s, [%#08x]\n", registerToString(operand1), operand2);
                break;
            case OPERATION_ADD:
                printf(" %s, %s\n", registerToString(operand1), registerToString(operand2));
                break;
            case OPERATION_SUB:
                printf(" %s, %s\n", registerToString(operand1), registerToString(operand2));
                break;
            case OPERATION_MULT:
                printf(" %s, %s\n", registerToString(operand1), registerToString(operand2));
                break;
            case OPERATION_DIV:
                printf(" %s, %s\n", registerToString(operand1), registerToString(operand2));
                break;
            case OPERATION_OUT:
                printf(" %s, %s\n", registerToString(operand1), registerToString(operand2));
                break;
            case OPERATION_IN:
                printf(" %s, %s\n", registerToString(operand1), registerToString(operand2));
                break;
            case OPERATION_MOV:
                printf(" %s, %s\n", registerToString(operand1), registerToString(operand2));
                break;
            case OPERATION_CMP:
                printf(" %s, %s\n", registerToString(operand1), registerToString(operand2));
                break;
            case OPERATION_JMPL:
                printf(" [%#08x],\n", operand1);
                break;
            case OPERATION_JMPE:
                printf(" [%#08x],\n", operand1);
                break;
            case OPERATION_JMPG:
                printf(" [%#08x],\n", operand1);
                break;
            case OPERATION_RST:
                printf("\n");
                break;
            case OPERATION_HALT:
                printf("\n");
                break;
            case OPERATION_ISR:
                printf(" %s, %s\n", registerToString(operand1), registerToString(operand2));
                break;
            case OPERATION_INT:
                printf(" %s\n", registerToString(operand1));
                break;
            case OPERATION_ENDINT:
                printf("\n");
                break;
            case OPERATION_RLOAD:
                printf(" %s, %s\n", registerToString(operand1), registerToString(operand2));
                break;
            case OPERATION_RSTORE:
                printf(" %s, %s\n", registerToString(operand1), registerToString(operand2));
                break;
            case OPERATION_CLOAD:
                printf(" %d, %s\n", operand1, registerToString(operand2));
                break;
            case OPERATION_OR:
                printf(" %s, %s\n", registerToString(operand1), registerToString(operand2));
                break;
            case OPERATION_AND:
                printf(" %s, %s\n", registerToString(operand1), registerToString(operand2));
                break;
            case OPERATION_XOR:
                printf(" %s, %s\n", registerToString(operand1), registerToString(operand2));
                break;
            case OPERATION_NOT:
                printf(" %s\n", registerToString(operand1));
                break;
        }
    }
	return EXIT_SUCCESS;
}
