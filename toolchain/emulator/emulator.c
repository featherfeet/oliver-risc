#include "assembler.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	// Parse arguments.
	if (argc != 2) {
		fprintf(stderr, "Usage: ./emulator binary.bin\n");
		return EXIT_FAILURE;
	}
	// Read in binary file.
	FILE *file = fopen(argv[1], "rb");
	fseek(file, 0L, SEEK_END);
	int raw_binary_length = ftell(file);
	uint8_t *raw_binary = malloc(raw_binary_length);
	rewind(file);
	fread(raw_binary, raw_binary_length, 1, file);
	// Allocate RAM for the emulated processor.
	uint8_t *data_ram = malloc(4000000);
	uint8_t *code_ram = malloc(4000000);
	// Define registers for the emulated processor.
	uint32_t registers[8]; // Contains registers IP, A, B, C, D, E, F, and G.
	registers[IP] = 0; // Set the instruction pointer register to the first instruction in code RAM (address 0x0).
	/****************************************************
	           Emulated execution starts here.
	*****************************************************/
	// Copy .data section of the executable across.
	int i;
	for (i = 0; i < raw_binary_length; i++) {
		if (raw_binary[i] == OPERATION_CODE) {
			break;
		}
		data_ram[i] = raw_binary[i];
	}
	// Copy .code section of the executable across.
	int j = 0;
	for (i++; i < raw_binary_length; i++) {
		code_ram[j] = raw_binary[i];
		j++;
	}
	// Execute the .code section of the executable.
	while (1) {
		Operation operation = code_ram[registers[IP]];
		uint32_t operand1 = code_ram[registers[IP] + OPERATION_SIZE];
		uint32_t operand2 = code_ram[registers[IP] + OPERATION_SIZE + OPERAND_SIZE];
		switch (operation) {
			case OPERATION_NOP:
				registers[IP] += INSTRUCTION_SIZE;
				break;
			case OPERATION_LOAD:
                for (int i = OPERAND_SIZE - 1; i >= 0; i--) {
                    registers[operand2] <<= 8;
                    registers[operand2] |= data_ram[operand1 + i];
                }
				registers[IP] += INSTRUCTION_SIZE;
				break;
			case OPERATION_STORE:
				//data_ram[operand2] = registers[operand1];
                memcpy(data_ram + operand2, &(registers[operand1]), OPERAND_SIZE);
				registers[IP] += INSTRUCTION_SIZE;
				break;
			case OPERATION_ADD:
				registers[A] = registers[operand1] + registers[operand2];
				registers[IP] += INSTRUCTION_SIZE;
				break;
			case OPERATION_SUB:
				registers[A] = registers[operand1] - registers[operand2];
				registers[IP] += INSTRUCTION_SIZE;
				break;
			case OPERATION_OUT:
				printf("%d\n", registers[operand1]);
				registers[IP] += INSTRUCTION_SIZE;
				break;
			case OPERATION_IN:
				printf("IN: ");
				scanf("%d\n", &registers[operand1]);
				registers[IP] += INSTRUCTION_SIZE;
				break;
			case OPERATION_MOV:
				registers[operand2] = registers[operand1];
				registers[IP] += INSTRUCTION_SIZE;
				break;
			case OPERATION_CMP:
				if (registers[operand1] < registers[operand2]) {
					registers[A] = 0;
				}
				else if (registers[operand1] == registers[operand2]) {
					registers[A] = 1;
				}
				else {
					registers[A] = 2;
				}
				registers[IP] += INSTRUCTION_SIZE;
				break;
			case OPERATION_JMPL:
				if (registers[A] == 0) {
					registers[IP] = operand1;
				}
				else {
					registers[IP] += INSTRUCTION_SIZE;
				}
				break;
			case OPERATION_JMPE:
				if (registers[A] == 1) {
					registers[IP] = operand1;
				}
				else {
					registers[IP] += INSTRUCTION_SIZE;
				}
				break;
			case OPERATION_JMPG:
				if (registers[A] == 2) {
					registers[IP] = operand1;
				}
				else {
					registers[IP] += INSTRUCTION_SIZE;
				}
				break;
			case OPERATION_RST:
				for (int i = 0; i < sizeof(registers); i++) {
					registers[i] = 0;
				}
				break;
			case OPERATION_HALT:
				exit(EXIT_SUCCESS);
				break;
            default:
                printf("UNRECOGNIZED INSTRUCTION\n");
                break;
		}
	}
	return 0;
}
