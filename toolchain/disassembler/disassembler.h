#ifndef DISASSEMBLER_H
#define DISASSEMBLER_H

#include <stdlib.h>
#include <stdint.h>

#define INSTRUCTION_SIZE 7 // bytes
#define MAXIMUM_NUMBER_OF_VARIANTS 8 // 3 bits can represent 8 distinct binary numbers.

typedef uint32_t RawConstantOperand;

extern const size_t CONSTANT_SIZE;

extern const char *operations[];

extern const char *variants[][MAXIMUM_NUMBER_OF_VARIANTS];

extern const int number_of_operations;

struct RegisterOnlyInstruction {
    uint8_t operation : 5;
    uint8_t variant : 3;
    uint8_t size : 2;
    uint8_t register_operand_1 : 4;
    uint8_t register_operand_2 : 4;
    uint8_t register_operand_3 : 4;
    uint64_t _padding : 34;
} __attribute__((__packed__));

struct InstructionWithConstant {
    uint8_t operation : 5;
    uint8_t variant : 3;
    uint8_t size : 2;
    uint8_t register_operand_1 : 4;
    uint8_t register_operand_2 : 4;
    uint32_t constant_operand : 32;
    uint8_t _padding : 6;
} __attribute__((__packed__));

union Instruction {
    struct RegisterOnlyInstruction register_only_instruction;
    struct InstructionWithConstant instruction_with_constant;
} __attribute__((__packed__));

long disassemble(long raw_binary_length, const uint8_t *raw_binary);

#endif // DISASSEMBLER_H
