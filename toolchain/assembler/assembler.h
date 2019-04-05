#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include <stdint.h>

/*
Assembly code format (curly braces are replacements) (each line in the .code section is an instruction):
.data:
	{variable1 name} = {variable1 value}
	{variable2 name} = {variable2 value}
	{variable3 name} = {variable3 value}
.code:
	{label1 name}:
			{Operation} {Operand1},{Operand2}
	{label2 name}:
			{Operation} {Operand1},{Operand2}
			{Operation} {Operand1},{Operand2}
*/

enum Operation {
	OPERATION_NOP,
	OPERATION_LOAD,
	OPERATION_STORE,
	OPERATION_ADD,
	OPERATION_SUB,
	OPERATION_OUT,
	OPERATION_IN,
	OPERATION_MOV,
	OPERATION_CMP,
	OPERATION_JMPL,
	OPERATION_JMPE,
	OPERATION_JMPG,
	OPERATION_RST,
	OPERATION_HALT,
	OPERATION_CODE
};

enum Register {
	IP,              // Instruction pointer register.
	A,               // Generic registers A-G.
	B,
	C,
	D,
	E,
	F,
	G
};

enum CodeSection {
	DATA_SECTION,
	CODE_SECTION
};

// Represent a symbol like "varname3 = 9" or whatever.
struct Symbol {
	char *name;
	uint8_t value;
};

// Represent an instruction like "MOV A,B" or whatever. Depending on the operation, only ever uses up to two of the register/address variables.
struct Instruction {
	enum Operation operation;             // Store the operation (MOV, JMPL, etc.) of the instruction.
	enum Register operand1_register;      // If operand 1 of the instruction is a register, store it here.
	enum Register operand2_register;      // If operand 2 of the instruction is a register, store it here.
	char* operand1_address;               // If operand 1 of the instruction is an address, store it here. Also used to store the label name for JMP* instructions to jump to.
	char* operand2_address;               // If operand 2 of the instruction is an address, store it here.
};

// Represent a label (a place the code can jump to) like "label_name:" or whatever.
struct Label {
	char *name;                    // The label's name.
	int instruction_index;         // The index of the instruction that comes after the label.
};

#endif // ASSEMBLER_H
