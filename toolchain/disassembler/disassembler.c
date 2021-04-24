#include "disassembler.h"

#include <stdio.h>
#include <string.h>
#include <stdint.h>

const size_t CONSTANT_SIZE = sizeof(RawConstantOperand);

const char *operations[] = {
    "NOP",
    "LOAD",
    "STORE",
    "ADD",
    "MULT",
    "DIV",
    "OUT",
    "IN",
    "MOV",
    "CMP",
    "JMP",
    "RST",
    "HALT",
    "ISR",
    "INT",
    "ENDINT",
    "OR",
    "AND",
    "XOR",
    "NOT",
    "SHIFT"
};

const char *variants[][MAXIMUM_NUMBER_OF_VARIANTS] = {
    {"(default)", "(invalid variant)", "(invalid variant)", "(invalid variant)", "(invalid variant)", "(invalid variant)", "(invalid variant)", "(invalid variant)"},
    {"(register, register)", "(constant, register)", "(invalid variant)", "(invalid variant)", "(invalid variant)", "(invalid variant)", "(invalid variant)", "(invalid variant)"},
    {"(register, register)", "(constant, register)", "(register, constant)", "(invalid variant)", "(invalid variant)", "(invalid variant)", "(invalid variant)", "(invalid variant)"},
    {"(register, register, register)", "(register, constant, register)", "(invalid variant)", "(invalid variant)", "(invalid variant)", "(invalid variant)", "(invalid variant)", "(invalid variant)"},
    {"(register, register, register)", "(register, constant, register)", "(invalid variant)", "(invalid variant)", "(invalid variant)", "(invalid variant)", "(invalid variant)", "(invalid variant)"},
    {"(DIVISION : register, register, register)", "(DIVISION : register, constant, register)", "(DIVISION : constant, register, register)", "(MODULUS : register, register, register)", "(MODULUS : register, constant, register)", "(MODULUS : constant, register, register)", "(invalid variant)", "(invalid variant)"},
    {"(register, register)", "(constant, register)", "(register, constant)", "(invalid variant)", "(invalid variant)", "(invalid variant)", "(invalid variant)", "(invalid variant)"},
    {"(register, register)", "(constant, register)", "(invalid variant)", "(invalid variant)", "(invalid variant)", "(invalid variant)", "(invalid variant)", "(invalid variant)"},
    {"(register, register)", "(constant, register)", "(invalid variant)", "(invalid variant)", "(invalid variant)", "(invalid variant)", "(invalid variant)", "(invalid variant)"},
    {"(register, register, register)", "(register, constant, register)", "(constant, register, register)", "(invalid variant)", "(invalid variant)", "(invalid variant)", "(invalid variant)", "(invalid variant)"},
    {"(unconditional)", "(if equal)", "(if not equal)", "(if less than)", "(if greater than)", "(if less than or equal to)", "(if greater than or equal to)", "(invalid variant)"},
    {"(default)", "(invalid variant)", "(invalid variant)", "(invalid variant)", "(invalid variant)", "(invalid variant)", "(invalid variant)", "(invalid variant)"},
    {"(default)", "(invalid variant)", "(invalid variant)", "(invalid variant)", "(invalid variant)", "(invalid variant)", "(invalid variant)", "(invalid variant)"},
    {"(default)", "(invalid variant)", "(invalid variant)", "(invalid variant)", "(invalid variant)", "(invalid variant)", "(invalid variant)", "(invalid variant)"},
    {"(register)", "(constant)", "(invalid variant)", "(invalid variant)", "(invalid variant)", "(invalid variant)", "(invalid variant)", "(invalid variant)"},
    {"(default)", "(invalid variant)", "(invalid variant)", "(invalid variant)", "(invalid variant)", "(invalid variant)", "(invalid variant)", "(invalid variant)"},
    {"(register, register, register)", "(register, constant, register)", "(invalid variant)", "(invalid variant)", "(invalid variant)", "(invalid variant)", "(invalid variant)", "(invalid variant)"},
    {"(register, register, register)", "(register, constant, register)", "(invalid variant)", "(invalid variant)", "(invalid variant)", "(invalid variant)", "(invalid variant)", "(invalid variant)"},
    {"(register, register, register)", "(register, constant, register)", "(invalid variant)", "(invalid variant)", "(invalid variant)", "(invalid variant)", "(invalid variant)", "(invalid variant)"},
    {"(default)", "(invalid variant)", "(invalid variant)", "(invalid variant)", "(invalid variant)", "(invalid variant)", "(invalid variant)", "(invalid variant)"},
    {"(LEFT : register, register, register)", "(LEFT : register, constant, register)", "(RIGHT : register, register, register)", "(RIGHT : register, constant, register)", "(LEFT : constant, register, register)", "(RIGHT : constant, register, register)", "(invalid variant)", "(invalid variant)"}
};

const int number_of_operations = sizeof(operations) / sizeof(char *);

long disassemble(long raw_binary_length, const uint8_t *raw_binary) {
    // Read offset to start of .code section.
    if (raw_binary_length < CONSTANT_SIZE) {
        fprintf(stderr, "Binary file must be at least %ld bytes long because the first %ld bytes of the file are used to store the length of the .data section.\n", CONSTANT_SIZE, CONSTANT_SIZE);
        return -1;
    }
    RawConstantOperand code_section_offset = 0;
    memcpy(&code_section_offset, raw_binary, CONSTANT_SIZE);
    if (code_section_offset > raw_binary_length) {
        fprintf(stderr, "The first %lu bytes of the binary indicate that the .data section is %u bytes long, but the entire file is only %ld bytes long.\n", CONSTANT_SIZE, code_section_offset, raw_binary_length);
        return -1;
    }
    // Disassemble instructions.
    long valid_instructions = 0;
    for (const uint8_t *raw_binary_instruction = raw_binary + code_section_offset; raw_binary_instruction < raw_binary + raw_binary_length; raw_binary_instruction += INSTRUCTION_SIZE) {
        if (raw_binary_instruction + INSTRUCTION_SIZE > raw_binary + raw_binary_length) {
            fprintf(stderr, "\033[1;31mERROR: Incomplete instruction.\033[0m\n");
            break;
        }
        union Instruction *instruction = (union Instruction *) raw_binary_instruction;
        uint8_t operation = instruction->register_only_instruction.operation;
        uint8_t variant = instruction->register_only_instruction.variant;
        if (operation >= number_of_operations) {
            fprintf(stderr, "\033[1;31mERROR: INVALID OPERATION CODE %u.\033[0m\n", operation);
            continue;
        }
        else {
            printf("    %s ", operations[operation]);
        }
        if (variant >= MAXIMUM_NUMBER_OF_VARIANTS) {
            fprintf(stderr, "\n\033[1;31mERROR: INVALID VARIANT %u ON OPERATION %s.\n", variant, operations[operation]);
            continue;
        }
        else {
            printf("%s\n", variants[operation][variant]);
        }
        valid_instructions++;
    }
    return valid_instructions;
}
