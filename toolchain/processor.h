#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <stdint.h>

#define OPERATION_SIZE 1 // bytes
#define OPERAND_SIZE   4 // bytes
#define OPERAND_C_TYPE uint32_t // The C type used to represent a single operand. uint32_t for a 4-byte (32-bit) operand CPU.
#define INSTRUCTION_SIZE (OPERATION_SIZE + OPERAND_SIZE + OPERAND_SIZE) // bytes

#endif // PROCESSOR_H
