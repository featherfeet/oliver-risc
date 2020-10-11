#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <stdint.h>

#define TOTAL_RAM_SIZE_BYTES 8000000 // bytes

#define OPERATION_SIZE 1 // bytes
#define OPERAND_SIZE   4 // bytes
#define OPERAND_C_TYPE uint32_t // The C type used to represent a single operand. uint32_t for a 4-byte (32-bit) operand CPU.
#define INSTRUCTION_SIZE (OPERATION_SIZE + OPERAND_SIZE + OPERAND_SIZE) // bytes

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
    OPERATION_DIV,
    OPERATION_OR,
    OPERATION_AND,
    OPERATION_XOR,
    OPERATION_NOT
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

// Represents whether a variable is an integer or a string.
typedef enum {
    INTEGER_VARIABLE,
    STRING_VARIABLE
} VariableType;

// Represents the value of a variable.
typedef union {
    uint8_t integer[OPERAND_SIZE];
    char *string;
} VariableValue;

// Represent a variable like "varname3 = 9" or whatever.
typedef struct {
    uint8_t address[OPERAND_SIZE];
    VariableType variable_type;
    VariableValue variable_value;
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

#endif // PROCESSOR_H
