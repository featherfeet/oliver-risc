#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include <stdint.h>
#include "processor.h"

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

typedef enum {
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
    OPERATION_ISR,
    OPERATION_INT,
    OPERATION_ENDINT,
    OPERATION_RLOAD,
    OPERATION_RSTORE,
    OPERATION_CLOAD,
    OPERATION_MULT,
    OPERATION_DIV
} Operation;

typedef enum {
	IP,              // Instruction pointer register.
	A,               // Generic registers A-G.
	B,
	C,
	D,
	E,
	F,
	G
} Register;

typedef enum {
    DATA_SECTION,
    CODE_SECTION
} AssemblySection;

// Represent a variable like "varname3 = 9" or whatever.
typedef struct {
    uint8_t address[OPERAND_SIZE];
	uint8_t value[OPERAND_SIZE];
} Variable;

// Represent an operand to an instruction. Operands can be either registers or memory addresses.
typedef union {
    Register operand_register;
    char *operand_address;
    OPERAND_C_TYPE operand_constant;
} Operand;

// Represent an instruction like "MOV A,B" or whatever.
typedef struct {
	Operation operation;                     // Store the operation (MOV, JMPL, etc.) of the instruction.
    Operand operand1;                        // Store the first operand of the instruction.
    Operand operand2;                        // Store the second operand of the instruction.
} Instruction;

// Represent a label (a place the code can jump to) like "label_name:" or whatever.
struct Label {
	char *name;                    // The label's name.
	int instruction_index;         // The index of the instruction that comes after the label (i. e. the index of the instruction that this label is used to jump to).
};

#endif // ASSEMBLER_H
