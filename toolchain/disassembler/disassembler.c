#include <stdio.h>
#include <stdlib.h>
#include "assembler.h" // Symlinked from the assembler's source code.

const char *registerToString(enum Register reg) {
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
	// Loop through and disassemble the .data section of the binary.
	int i;
	printf(".data:\n");
	for (i = 0; i < raw_binary_length; i++) {
		if (raw_binary[i] == OPERATION_CODE) {
			break;
		}
		printf("\t[%#08x]\t%d\n", i, raw_binary[i]);
	}
	// Loop through and disassemble the .code section of the binary.
	int instruction_index = 0;
	printf(".code:\n");
	for (i = i + 1; i < raw_binary_length; i += 3) {
		printf("\t[%#08x]\t", instruction_index * 3);
		instruction_index++;
		switch (raw_binary[i]) {
			case OPERATION_NOP:
				printf("NOP");
				break;
			case OPERATION_LOAD:
				printf("LOAD %#08x, %s", raw_binary[i + 1], registerToString(raw_binary[i + 2]));
				break;
			case OPERATION_STORE:
				printf("STORE %s, %#08x", registerToString(raw_binary[i + 1]), raw_binary[i + 2]);
				break;
			case OPERATION_ADD:
				printf("ADD %s, %s", registerToString(raw_binary[i + 1]), registerToString(raw_binary[i + 2]));
				break;
			case OPERATION_SUB:
				printf("SUB %s, %s", registerToString(raw_binary[i + 1]), registerToString(raw_binary[i + 2]));
				break;
			case OPERATION_OUT:
				printf("OUT %s", registerToString(raw_binary[i + 1]));
				break;
			case OPERATION_IN:
				printf("IN %s", registerToString(raw_binary[i + 1]));
				break;
			case OPERATION_MOV:
				printf("MOV %s, %s", registerToString(raw_binary[i + 1]), registerToString(raw_binary[i + 2]));
				break;
			case OPERATION_CMP:
				printf("CMP %s, %s", registerToString(raw_binary[i + 1]), registerToString(raw_binary[i + 2]));
				break;
			case OPERATION_JMPL:
				printf("JMPL %#08x", raw_binary[i + 1]);
				break;
			case OPERATION_JMPE:
				printf("JMPE %#08x", raw_binary[i + 1]);
				break;
			case OPERATION_JMPG:
				printf("JMPG %#08x", raw_binary[i + 1]);
				break;
			case OPERATION_RST:
				printf("RST");
				break;
			case OPERATION_HALT:
				printf("HALT");
				break;
			default:
				printf("???? ");
				break;
		}
		printf("\n");
	}
	return EXIT_SUCCESS;
}
