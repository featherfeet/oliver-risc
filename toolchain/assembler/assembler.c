#include "assembler.h"
#include "stringproc.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

/*************************************************************************************
Assembler for the Oliver-RISC soft CPU. Converts Oliver-RISC assembly to binaries.
Copyright 2019 Oliver Trevor
**************************************************************************************/

// Convert a string like "IP" or "A" to a Register number.
enum Register stringToRegister(char *str) {
    if (strcmp(str, "IP") == 0) {
        return IP;
    }
    else if (strcmp(str, "A") == 0) {
        return A;
    }
    else if (strcmp(str, "B") == 0) {
        return B;
    }
    else if (strcmp(str, "C") == 0) {
        return C;
    }
    else if (strcmp(str, "D") == 0) {
        return D;
    }
    else if (strcmp(str, "E") == 0) {
        return E;
    }
    else if (strcmp(str, "F") == 0) {
        return F;
    }
    return G;
}

// Search a symbol table for a symbol with the given name and return the index of that symbol. Return -1 if not found.
int findSymbol(struct Symbol *symbol_table, int symbol_table_length, char *symbol_name) {
    for (int i = 0; i < symbol_table_length; i++) {
        if (strcmp(symbol_name, symbol_table[i].name) == 0) {
            return i;
        }
    }
    printf("\033[1;31mERROR:\033[0m Could not find symbol '%s' in symbol table.\n", symbol_name);
    return -1;
}

// Search a label table for a label with the given name and return the label's instruction_index member.
int findLabel(struct Label *label_table, int label_table_length, char *label_name) {
    for (int i = 0; i < label_table_length; i++) {
        if (strcmp(label_name, label_table[i].name) == 0) {
            return label_table[i].instruction_index;
        }
    }
    printf("\033[1;31mERROR:\033[0m Could not find label '%s' in label table.\n", label_name);
    return -1;
}

int main(int argc, char *argv[]) {
    /****************************************************************************************************
    Parse command-line arguments.
    *****************************************************************************************************/
    if (argc != 3) {
        printf("Usage: ./assembler inputfile.asm outputfile.bin\n");
        return 1;
    }
    /****************************************************************************************************
    Open the input assembly code file.
    *****************************************************************************************************/
    FILE *input_file = fopen(argv[1], "r");
    /****************************************************************************************************
    Initialize the parser state and misc. variables.
    *****************************************************************************************************/
    enum CodeSection code_section = DATA_SECTION;             // Stores whether the parser is parsing the .code section of the assembly or the .data section.
    char *cleaned_line;                                       // Used to store lines of the input source after they are stripped of excess whitespace.
    char *symbol_name;                                        // Used to store the names of variables in the .data section.
    char *raw_symbol_value;                                   // Used to store the values of variables in the .data section.
    struct Symbol *symbol_table = malloc(0);                  // Table (array of structs) storing variable names, values, and positions in memory.
    int symbol_table_length = 0;                              // The length of the symbol_table array.
    char *raw_operation;                                      // MOV, JMPE, etc.
    char *raw_operands;                                       // The two operands, separated by a comma.
    char *raw_operand1;                                       // A register or memory address.
    char *raw_operand2;                                       // A register or memory address.
    char *cleaned_operation;                                  // The operation (MOV, JMPE, etc.) without whitespace.
    char *cleaned_operand1;                                   // Operand1 (memory address or register) without whitespace;
    char *cleaned_operand2;                                   // Operand1 (memory address or register) without whitespace;
    struct Instruction *instruction_table = malloc(0);        // Table (array of instructions) storing instructions like "MOV A,B".
    int instruction_table_length = 0;                         // The length of the instruction_table array.
    struct Label *label_table = malloc(0);                    // Table (array of structs) storing labels like "label_name:".
    int label_table_length = 0;                               // The length of the label_table array.
    /******************************************************************************************************
    Read and parse the file into symbol_table, instruction_table, and label_table.
    *******************************************************************************************************/
    char *line = NULL;                                        // The current line of the file, including whitespace.
    size_t line_length = 0;
    while (getline(&line, &line_length, input_file) != -1) {
        // Recognize if we are starting the .data (variable declarations) section of the program.
        if (strcmp(line, ".data:\n") == 0) {
            code_section = DATA_SECTION;
            printf("Starting .data section.\n");
        }
        // Recognize if we are starting the .code (instructions) section of the program.
        else if (strcmp(line, ".code:\n") == 0) {
            printf("\033[1;37mSymbol table:\n");
            for (int i = 0; i < symbol_table_length; i++) {
                uint32_t symbol_value = 0;
                memcpy(&symbol_value, symbol_table[i].value, OPERAND_SIZE);
                printf("%s = %d\n", symbol_table[i].name, symbol_value);
            }
            printf("\033[0m");
            code_section = CODE_SECTION;
            printf("Starting .code section.\n");
        }
        /********************************************************************
        Parse the .data (variable declarations) section of the assembly file.
        *********************************************************************/
        else if (code_section == DATA_SECTION) {
            cleaned_line = stripWhitespace(line);
            symbol_table = realloc(symbol_table, symbol_table_length * sizeof(struct Symbol) + sizeof(struct Symbol));
            symbol_table_length++;
            splitOnCharacter(cleaned_line, '=', &symbol_name, &raw_symbol_value);
            symbol_table[symbol_table_length - 1].name = malloc(strlen(symbol_name) + 1);
            strcpy(symbol_table[symbol_table_length - 1].name, symbol_name);
            int symbol_value = atoi(raw_symbol_value);
            memcpy(symbol_table[symbol_table_length - 1].value, &symbol_value, OPERAND_SIZE);
            free(cleaned_line);
            free(symbol_name);
            free(raw_symbol_value);
        }
        /*********************************************************************
        Parse the .code (instructions) section of the assembly file.
        **********************************************************************/
        else if (code_section == CODE_SECTION) {
            splitOnCharacter(line, ' ', &raw_operation, &raw_operands);
            splitOnCharacter(raw_operands, ',', &raw_operand1, &raw_operand2);
            cleaned_operation = stripWhitespace(raw_operation);
            cleaned_operand1 = stripWhitespace(raw_operand1);
            cleaned_operand2 = stripWhitespace(raw_operand2);
            cleaned_line = stripWhitespace(line);
            // If this line is a label, then add it to label_table.
            if (cleaned_line[strlen(cleaned_line) - 1] == ':') {
                label_table = realloc(label_table, label_table_length * sizeof(struct Label) + sizeof(struct Label));
                label_table_length++;
                label_table[label_table_length - 1].name = malloc(strlen(cleaned_line)); // Since we're not copying the colon at the end of the line, we don't need to add another byte for the null character.
                strncpy(label_table[label_table_length - 1].name, cleaned_line, strlen(cleaned_line) - 1);
                label_table[label_table_length - 1].name[strlen(cleaned_line)] = '\0';
                label_table[label_table_length - 1].instruction_index = instruction_table_length;
            }
            // If this line is an instruction, then add it to instruction_table.
            else {
                instruction_table = realloc(instruction_table, instruction_table_length * sizeof(struct Instruction) + sizeof(struct Instruction));
                instruction_table_length++;
                if (strcmp(cleaned_operation, "NOP") == 0) {
                    instruction_table[instruction_table_length - 1].operation = OPERATION_NOP;
                }
                else if (strcmp(cleaned_operation, "LOAD") == 0) {
                    instruction_table[instruction_table_length - 1].operation = OPERATION_LOAD;
                    instruction_table[instruction_table_length - 1].operand1_address = malloc(strlen(cleaned_operand1) + 1);
                    strcpy(instruction_table[instruction_table_length - 1].operand1_address, cleaned_operand1);
                    instruction_table[instruction_table_length - 1].operand2_register = stringToRegister(cleaned_operand2);
                }
                else if (strcmp(cleaned_operation, "STORE") == 0) {
                    instruction_table[instruction_table_length - 1].operation = OPERATION_STORE;
                    instruction_table[instruction_table_length - 1].operand1_register = stringToRegister(cleaned_operand1);
                    instruction_table[instruction_table_length - 1].operand2_address = malloc(strlen(cleaned_operand2) + 1);
                    strcpy(instruction_table[instruction_table_length - 1].operand2_address, cleaned_operand2);
                }
                else if (strcmp(cleaned_operation, "ADD") == 0) {
                    instruction_table[instruction_table_length - 1].operation = OPERATION_ADD;
                    instruction_table[instruction_table_length - 1].operand1_register = stringToRegister(cleaned_operand1);
                    instruction_table[instruction_table_length - 1].operand2_register = stringToRegister(cleaned_operand2);
                }
                else if (strcmp(cleaned_operation, "SUB") == 0) {
                    instruction_table[instruction_table_length - 1].operation = OPERATION_SUB;
                    instruction_table[instruction_table_length - 1].operand1_register = stringToRegister(cleaned_operand1);
                    instruction_table[instruction_table_length - 1].operand2_register = stringToRegister(cleaned_operand2);
                }
                else if (strcmp(cleaned_operation, "OUT") == 0) {
                    instruction_table[instruction_table_length - 1].operation = OPERATION_OUT;
                    instruction_table[instruction_table_length - 1].operand1_register = stringToRegister(cleaned_operand1);
                }
                else if (strcmp(cleaned_operation, "IN") == 0) {
                    instruction_table[instruction_table_length - 1].operation = OPERATION_IN;
                    instruction_table[instruction_table_length - 1].operand1_register = stringToRegister(cleaned_operand1);
                }
                else if (strcmp(cleaned_operation, "MOV") == 0) {
                    instruction_table[instruction_table_length - 1].operation = OPERATION_MOV;
                    instruction_table[instruction_table_length - 1].operand1_register = stringToRegister(cleaned_operand1);
                    instruction_table[instruction_table_length - 1].operand2_register = stringToRegister(cleaned_operand2);
                }
                else if (strcmp(cleaned_operation, "CMP") == 0) {
                    instruction_table[instruction_table_length - 1].operation = OPERATION_CMP;
                    instruction_table[instruction_table_length - 1].operand1_register = stringToRegister(cleaned_operand1);
                    instruction_table[instruction_table_length - 1].operand2_register = stringToRegister(cleaned_operand2);
                }
                else if (strcmp(cleaned_operation, "JMPL") == 0) {
                    instruction_table[instruction_table_length - 1].operation = OPERATION_JMPL;
                    instruction_table[instruction_table_length - 1].operand1_address = malloc(strlen(cleaned_operand1) + 1);
                    strcpy(instruction_table[instruction_table_length - 1].operand1_address, cleaned_operand1);
                }
                else if (strcmp(cleaned_operation, "JMPE") == 0) {
                    instruction_table[instruction_table_length - 1].operation = OPERATION_JMPE;
                    instruction_table[instruction_table_length - 1].operand1_address = malloc(strlen(cleaned_operand1) + 1);
                    strcpy(instruction_table[instruction_table_length - 1].operand1_address, cleaned_operand1);
                }
                else if (strcmp(cleaned_operation, "JMPG") == 0) {
                    instruction_table[instruction_table_length - 1].operation = OPERATION_JMPG;
                    instruction_table[instruction_table_length - 1].operand1_address = malloc(strlen(cleaned_operand1) + 1);
                    strcpy(instruction_table[instruction_table_length - 1].operand1_address, cleaned_operand1);
                }
                else if (strcmp(cleaned_line, "RST") == 0) {
                    instruction_table[instruction_table_length - 1].operation = OPERATION_RST;
                }
                else if (strcmp(cleaned_line, "HALT") == 0) {
                    instruction_table[instruction_table_length - 1].operation = OPERATION_HALT;
                }
                else {
                    printf("\033[1;31mError: Unrecognized instruction or misformatted label: %s\033[0m", line);
                }
            }
            free(raw_operation);
            free(raw_operands);
            free(raw_operand1);
            free(raw_operand2);
            free(cleaned_line);
        }
        free(line);
        line = NULL;
    }
    /******************************************************************************************
    Compile symbol_table to binary.
    *******************************************************************************************/
    void *symbol_table_binary = malloc(symbol_table_length * OPERAND_SIZE);
    for (int i = 0; i < symbol_table_length; i++) {
        // Copy the OPERAND_SIZE-byte value from the symbol table into the binary.
        memcpy(symbol_table_binary + i * OPERAND_SIZE, &symbol_table[i].value, OPERAND_SIZE);
    }
    printf("Symbol table compiled. Takes %d bytes.\n", symbol_table_length * OPERAND_SIZE);
    /******************************************************************************************
    Compile instruction_table to binary (using label_table to resolve the label names in JMPs).
    *******************************************************************************************/
    void *instruction_table_binary = malloc(instruction_table_length * INSTRUCTION_SIZE);
    struct Instruction instruction;
    for (int i = 0; i < instruction_table_length; i++) {
        // Get the instruction.
        instruction = instruction_table[i];
        // Each instruction takes INSTRUCTION_SIZE bytes. Copy the operation to the binary.
        memcpy(instruction_table_binary + INSTRUCTION_SIZE * i, &instruction.operation, OPERATION_SIZE);
        // Work out whether the arguments should be registers, memory addresses, or some combination thereof.
        bool operand1_is_register = false;
        bool operand1_is_address = false;
        bool operand2_is_register = false;
        bool operand2_is_address = false;
        switch (instruction.operation) {
            case OPERATION_LOAD:
                operand1_is_address = true;
                operand2_is_register = true;
                break;
            case OPERATION_STORE:
                operand1_is_register = true;
                operand1_is_address = true;
                break;
            case OPERATION_ADD:
                operand1_is_register = true;
                operand2_is_register = true;
                break;
            case OPERATION_SUB:
                operand1_is_register = true;
                operand2_is_register = true;
                break;
            case OPERATION_OUT:
                operand1_is_register = true;
                break;
            case OPERATION_IN:
                operand1_is_register = true;
                break;
            case OPERATION_MOV:
                operand1_is_register = true;
                operand2_is_register = true;
                break;
            case OPERATION_CMP:
                operand1_is_register = true;
                operand2_is_register = true;
                break;
            case OPERATION_JMPL:
                operand1_is_address = true;
                break;
            case OPERATION_JMPE:
                operand1_is_address = true;
                break;
            case OPERATION_JMPG:
                operand1_is_address = true;
                break;
        }
        if (operand1_is_register) {
            memcpy(instruction_table_binary + INSTRUCTION_SIZE * i + OPERATION_SIZE, &instruction.operand1_register, OPERAND_SIZE);
        }
        else if (instruction.operation == OPERATION_JMPL || instruction.operation == OPERATION_JMPE || instruction.operation == OPERATION_JMPG) {
            // Look up the address of the label that we are jumping to.
            int instruction_index = findLabel(label_table, label_table_length, instruction.operand1_address); // The index (in instruction_table) of the instruction to jump to.
            int binary_instruction_index = INSTRUCTION_SIZE * instruction_index;                              // The address (in the binary .code section) of the instruction to jump to.
            memcpy(instruction_table_binary + INSTRUCTION_SIZE * i + OPERATION_SIZE, &binary_instruction_index, OPERAND_SIZE);
        }
        else if (operand1_is_address) {
            uint8_t symbol_location = findSymbol(symbol_table, symbol_table_length, instruction.operand1_address);
            memcpy(instruction_table_binary + INSTRUCTION_SIZE * i + OPERATION_SIZE, &symbol_location, OPERAND_SIZE);
        }
        if (operand2_is_register) {
            memcpy(instruction_table_binary + INSTRUCTION_SIZE * i + OPERATION_SIZE + OPERAND_SIZE, &instruction.operand2_register, OPERAND_SIZE);
        }
        else if (operand2_is_address) {
            uint8_t symbol_location = findSymbol(symbol_table, symbol_table_length, instruction.operand2_address);
            memcpy(instruction_table_binary + INSTRUCTION_SIZE * i + OPERATION_SIZE + OPERAND_SIZE, &symbol_location, OPERAND_SIZE);
        }
    }
    printf("INSTRUCTION_SIZE: %d\n", INSTRUCTION_SIZE);
    printf("instruction_table_length: %d\n", instruction_table_length);
    printf("Instruction table compiled. Takes %d bytes.\n", instruction_table_length * INSTRUCTION_SIZE);
    /******************************************************************************************
    Write out binary file.
    *******************************************************************************************/
    FILE *output_file = fopen(argv[2], "wb");
    if (fwrite(symbol_table_binary, sizeof(uint8_t), symbol_table_length * OPERAND_SIZE, output_file) != symbol_table_length * OPERAND_SIZE) {
        printf("\033[1;31mERROR:\033[0m Could not write %d bytes of data to the file.\n", symbol_table_length * OPERAND_SIZE);
    }
    uint8_t section_separator[OPERAND_SIZE];
    int operation_code = OPERATION_CODE;
    memcpy(section_separator, &operation_code, sizeof(enum Operation));
    if (fwrite(&section_separator, sizeof(uint8_t), OPERATION_SIZE, output_file) != OPERATION_SIZE) {
        printf("\033[1;31mERROR:\033[0m Could not write %d bytes of data to the file.\n", OPERATION_SIZE);
    }
    if (fwrite(instruction_table_binary, sizeof(uint8_t), instruction_table_length * INSTRUCTION_SIZE, output_file) != instruction_table_length * INSTRUCTION_SIZE) {
        printf("\033[1;31mERROR:\033[0m Could not write %d bytes of data to the file.\n", instruction_table_length * INSTRUCTION_SIZE);
    }
    return 0;
}
