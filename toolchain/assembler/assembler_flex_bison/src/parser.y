%{
    #include <stdio.h>
    #include <glib.h>
    #include "assembler.h"

    int yylex(void);
    void yyerror(char *);

    AssemblySection current_section = DATA_SECTION;

    FILE *output_file;

    GSList *variables_table = NULL;
    GSList *instructions_table = NULL;
    GSList *labels_table = NULL;

    // Convert a string like "IP" or "A" to a Register number.
    Register stringToRegister(char *str) {
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

    // Free all dynamically allocated memory in an Instruction structure, given a pointer to that structure. Assumes that the structure was created using g_new() but that the members of the structure were created using regular malloc(). Only frees address operands (because register operands are freed immediately after use in the parser).
    void freeInstruction(Instruction *instruction) {
        switch (instruction->operation) {
            case OPERATION_LOAD:
                free(instruction->operand1.operand_address);
                break;
            case OPERATION_STORE:
                free(instruction->operand2.operand_address);
                break;
            case OPERATION_JMPL:
                free(instruction->operand1.operand_address);
                break;
            case OPERATION_JMPE:
                free(instruction->operand1.operand_address);
                break;
            case OPERATION_JMPG:
                free(instruction->operand1.operand_address);
                break;
        }

        g_free(instruction);
    }
%}

%token TOKEN_NOP
%token TOKEN_LOAD
%token TOKEN_STORE
%token TOKEN_ADD
%token TOKEN_SUB
%token TOKEN_OUT
%token TOKEN_IN
%token TOKEN_MOV
%token TOKEN_CMP
%token TOKEN_JMPL
%token TOKEN_JMPE
%token TOKEN_JMPG
%token TOKEN_RST
%token TOKEN_HALT
%token TOKEN_DOT_DATA
%token TOKEN_DOT_CODE
%token TOKEN_IDENTIFIER
%token TOKEN_REGISTER
%token TOKEN_EQUALS
%token TOKEN_CONSTANT
%token TOKEN_EOL
%token TOKEN_COLON

%start line

%union {
    int intval;
    char *strval;
}

%%

line:
    | line TOKEN_DOT_DATA TOKEN_EOL {
        printf("Start .data section.\n");

        current_section = DATA_SECTION;
    }
    | line TOKEN_DOT_CODE TOKEN_EOL {
        printf("Start .code section.\n");

        current_section = CODE_SECTION;
    }
    | line TOKEN_IDENTIFIER TOKEN_COLON TOKEN_EOL {
        char *label = $<strval>2;

        printf("Label: %s\n", label);

        labels_table = g_slist_append(labels_table, label);
    }
    | line variable_declaration TOKEN_EOL
    | line instruction TOKEN_EOL
;

variable_declaration: TOKEN_IDENTIFIER TOKEN_EQUALS TOKEN_CONSTANT {
    printf("Declaring variable \"%s\" as %d.\n", $<strval>1, $<intval>3);

    Variable *variable = g_new(Variable, 1);
    variable->name = $<strval>1;
    memcpy(variable->value, &($<intval>3), OPERAND_SIZE);
    variables_table = g_slist_append(variables_table, variable);
}
;

instruction: TOKEN_NOP {
        printf("Instruction: NOP\n");

        Instruction *instruction = g_new(Instruction, 1);
        instruction->operation = OPERATION_NOP;
        instructions_table = g_slist_append(instructions_table, instruction);
    }
    | TOKEN_LOAD TOKEN_IDENTIFIER TOKEN_REGISTER {
        printf("Instruction: LOAD %s,%s\n", $<strval>2, $<strval>3);

        Instruction *instruction = g_new(Instruction, 1);
        instruction->operation = OPERATION_LOAD;
        instruction->operand1.operand_address = $<strval>2;
        instruction->operand2.operand_register = stringToRegister($<strval>3);
        instructions_table = g_slist_append(instructions_table, instruction);

        free($<strval>3);
    }
    | TOKEN_STORE TOKEN_REGISTER TOKEN_IDENTIFIER {
        printf("Instruction: STORE %s,%s\n", $<strval>2, $<strval>3);

        Instruction *instruction = g_new(Instruction, 1);
        instruction->operation = OPERATION_STORE;
        instruction->operand1.operand_register = stringToRegister($<strval>2);
        instruction->operand2.operand_address = $<strval>3;
        instructions_table = g_slist_append(instructions_table, instruction);

        free($<strval>2);
    }
    | TOKEN_ADD TOKEN_REGISTER TOKEN_REGISTER {
        printf("Instruction: ADD %s,%s\n", $<strval>2, $<strval>3);

        Instruction *instruction = g_new(Instruction, 1);
        instruction->operation = OPERATION_ADD;
        instruction->operand1.operand_register = stringToRegister($<strval>2);
        instruction->operand2.operand_register = stringToRegister($<strval>3);
        instructions_table = g_slist_append(instructions_table, instruction);

        free($<strval>2);
        free($<strval>3);
    }
    | TOKEN_SUB TOKEN_REGISTER TOKEN_REGISTER {
        printf("Instruction: SUB %s,%s\n", $<strval>2, $<strval>3);

        Instruction *instruction = g_new(Instruction, 1);
        instruction->operation = OPERATION_SUB;
        instruction->operand1.operand_register = stringToRegister($<strval>2);
        instruction->operand2.operand_register = stringToRegister($<strval>3);
        instructions_table = g_slist_append(instructions_table, instruction);

        free($<strval>2);
        free($<strval>3);
    }
    | TOKEN_OUT TOKEN_REGISTER {
        printf("Instruction: OUT %s\n", $<strval>2);

        Instruction *instruction = g_new(Instruction, 1);
        instruction->operation = OPERATION_OUT;
        instruction->operand1.operand_register = stringToRegister($<strval>2);
        instructions_table = g_slist_append(instructions_table, instruction);

        free($<strval>2);
    }
    | TOKEN_MOV TOKEN_REGISTER TOKEN_REGISTER {
        printf("Instruction: MOV %s,%s\n", $<strval>2, $<strval>3);

        Instruction *instruction = g_new(Instruction, 1);
        instruction->operation = OPERATION_MOV;
        instruction->operand1.operand_register = stringToRegister($<strval>2);
        instruction->operand2.operand_register = stringToRegister($<strval>3);
        instructions_table = g_slist_append(instructions_table, instruction);

        free($<strval>2);
        free($<strval>3);
    }
    | TOKEN_CMP TOKEN_REGISTER TOKEN_REGISTER {
        printf("Instruction: CMP %s,%s\n", $<strval>2, $<strval>3);

        Instruction *instruction = g_new(Instruction, 1);
        instruction->operation = OPERATION_CMP;
        instruction->operand1.operand_register = stringToRegister($<strval>2);
        instruction->operand2.operand_register = stringToRegister($<strval>3);
        instructions_table = g_slist_append(instructions_table, instruction);

        free($<strval>2);
        free($<strval>3);
    }
    | TOKEN_JMPL TOKEN_IDENTIFIER {
        printf("Instruction: JMPL %s\n", $<strval>2);

        Instruction *instruction = g_new(Instruction, 1);
        instruction->operation = OPERATION_JMPL;
        instruction->operand1.operand_address = $<strval>2;
        instructions_table = g_slist_append(instructions_table, instruction);
    }
    | TOKEN_JMPE TOKEN_IDENTIFIER {
        printf("Instruction: JMPE %s\n", $<strval>2);

        Instruction *instruction = g_new(Instruction, 1);
        instruction->operation = OPERATION_JMPE;
        instruction->operand1.operand_address = $<strval>2;
        instructions_table = g_slist_append(instructions_table, instruction);
    }
    | TOKEN_JMPG TOKEN_IDENTIFIER {
        printf("Instruction: JMPG %s\n", $<strval>2);

        Instruction *instruction = g_new(Instruction, 1);
        instruction->operation = OPERATION_JMPG;
        instruction->operand1.operand_address = $<strval>2;
        instructions_table = g_slist_append(instructions_table, instruction);
    }
    | TOKEN_RST {
        printf("Instruction: RST\n");

        Instruction *instruction = g_new(Instruction, 1);
        instruction->operation = OPERATION_RST;
        instructions_table = g_slist_append(instructions_table, instruction);
    }
    | TOKEN_HALT {
        printf("Instruction: HALT\n");

        Instruction *instruction = g_new(Instruction, 1);
        instruction->operation = OPERATION_HALT;
        instructions_table = g_slist_append(instructions_table, instruction);
    }
;

%%

void startParseString(const char *);
void endParseString(void);

int main(int argc, char *argv[]) {
    char *input_buffer;

    if (argc < 2) {
        printf("Usage: ./main program.asm [output.bin]\n");
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        fprintf(stderr, "Error: Failed to open file \"%s\" for reading.\n", argv[1]);
        return 1;
    }
    fseek(input_file, 0, SEEK_END);
    size_t input_file_size = (size_t) ftell(input_file);
    rewind(input_file);
    input_buffer = malloc(input_file_size + 1);
    size_t bytes_read = fread(input_buffer, 1, input_file_size, input_file);
    input_buffer[bytes_read] = '\0';
    fclose(input_file);

    if (argc == 2) {
        output_file = fopen("output.bin", "w");
        if (output_file == NULL) {
            fprintf(stderr, "Error: Failed to open file \"output.bin\" for writing.\n");
            return 1;
        }
    }
    else if (argc == 3) {
        output_file = fopen(argv[2], "w");
        if (output_file == NULL) {
            fprintf(stderr, "Error: Failed to open file \"%s\" for writing.\n", argv[2]);
            return 1;
        }
    }

    startParseString(input_buffer);
    yyparse();
    endParseString();

    for (GSList *iterator = labels_table; iterator; iterator = iterator->next) {
        free(iterator->data);
    }
    for (GSList *iterator = variables_table; iterator; iterator = iterator->next) {
        Variable *variable = iterator->data;
        free(variable->name);
        g_free(variable);
    }
    for (GSList *iterator = instructions_table; iterator; iterator = iterator->next) {
        Instruction *instruction = iterator->data;
        freeInstruction(instruction);
    }
    g_slist_free(variables_table);
    g_slist_free(instructions_table);
    g_slist_free(labels_table);
    free(input_buffer);
    fclose(output_file);
}

void yyerror(char *s) {
    fprintf(stderr, "Error: %s\n", s);
}
