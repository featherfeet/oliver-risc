%{
    #include <stdio.h>
    #include <glib.h>
    #include "processor.h"

    // Forward declarations for functions provided by the Flex-generated lexer (or defined later in this program).
    int yylex(void);
    void yyerror(char *);

    // Variable used to store whether the program is parsing the .data: or the .code: section of the program. Currently not used by the parser.
    AssemblySection current_section = DATA_SECTION;

    // File handle for the binary output file of the assembler.
    FILE *output_file;

    // GLib hash table associating variable names to pointers to Variable structures (see assembler.h).
    GHashTable *variables_table;
    OPERAND_C_TYPE variables_address_counter = OPERAND_SIZE; // Track the current size of the .data section so that we know the memory offset to the variable declaration currently being parsed. Offset the addresses by OPERAND_SIZE because the first OPERAND_SIZE bytes of the binary are used to specify the length of the .data section.

    // GLib singly-linked list of pointers to Instruction structures (see assembler.h).
    GSList *instructions_table = NULL;

    // GLib hash table associating label names to buffers of OPERAND_SIZE bytes containing the address of the instruction that each label points to.
    GHashTable *labels_table;

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

    // Free all dynamically allocated memory in an Instruction structure, given a pointer to that structure. Only frees address operands (because register operands are freed immediately after use in the parser).
    void freeInstruction(Instruction *instruction) {
        switch (instruction->operation) {
            case OPERATION_LOAD:
                g_free(instruction->operand1.operand_address);
                break;
            case OPERATION_CLOAD:
                if (instruction->operation_variant == CLOAD_ADDRESS) {
                    g_free(instruction->operand1.operand_address);
                }
                break;
            case OPERATION_STORE:
                g_free(instruction->operand2.operand_address);
                break;
            case OPERATION_JMPL:
                g_free(instruction->operand1.operand_address);
                break;
            case OPERATION_JMPE:
                g_free(instruction->operand1.operand_address);
                break;
            case OPERATION_JMPG:
                g_free(instruction->operand1.operand_address);
                break;
            default:
                break;
        }

        g_free(instruction);
    }

    // Free all dynamically allocated memory in a Variable structure.
    void freeVariable(Variable *variable) {
        if (variable->variable_type == STRING_VARIABLE) {
            g_free(variable->variable_value.string);
        }
        g_free(variable);
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
%token TOKEN_ISR
%token TOKEN_INT
%token TOKEN_ENDINT
%token TOKEN_MEMORY_ADDRESS
%token TOKEN_RLOAD
%token TOKEN_RSTORE
%token TOKEN_CLOAD
%token TOKEN_MULT
%token TOKEN_DIV
%token TOKEN_OR
%token TOKEN_AND
%token TOKEN_XOR
%token TOKEN_NOT
%token TOKEN_STRING_LITERAL
%token TOKEN_LEFT_SQUARE_BRACKET
%token TOKEN_RIGHT_SQUARE_BRACKET

%start line

%union {
    int intval;
    char *strval;
}

%%

// Each line of the assembly program is represented by a single "line" branch of the parsing tree.
line:
    // Empty lines are allowed.
    | line TOKEN_EOL
    // Lines that denote the start of the data section of the assembly file.
    | line TOKEN_DOT_DATA TOKEN_EOL {
        printf("Start .data section.\n");

        current_section = DATA_SECTION;
    }
    // Lines that denote the start of the code section of the assembly file.
    | line TOKEN_DOT_CODE TOKEN_EOL {
        printf("Start .code section.\n");

        current_section = CODE_SECTION;
    }
    // Lines with labels (identifiers used by jump instructions to set jump destinations).
    | line TOKEN_IDENTIFIER TOKEN_COLON TOKEN_EOL {
        char *label = $<strval>2;

        printf("Label: %s\n", label);

        // Calculate the address of the instruction that this label should jump to, then save that address in a buffer of OPERAND_SIZE bytes.
        uint8_t *label_address_buffer = g_malloc0(OPERAND_SIZE);
        OPERAND_C_TYPE label_address = g_slist_length(instructions_table) * INSTRUCTION_SIZE;
        memcpy(label_address_buffer, &label_address, OPERAND_SIZE);

        // Store the address buffer in the labels_table hash table with the label name as the key.
        g_hash_table_insert(labels_table, label, label_address_buffer);
    }
    // Lines in the .data section that declare variables in RAM.
    | line variable_declaration TOKEN_EOL
    // Lines in the .code section with instructions.
    | line instruction TOKEN_EOL
;

// Lines that declare variables in the .data section.
variable_declaration: TOKEN_IDENTIFIER TOKEN_EQUALS TOKEN_CONSTANT {
    char *variable_name = $<strval>1;
    OPERAND_C_TYPE variable_value = $<intval>3;

    printf("Declaring integer variable \"%s\" as %d.\n", variable_name, variable_value);

    // Create a Variable structure representing the variable declaration.
    Variable *variable = g_new(Variable, 1);
    variable->variable_type = INTEGER_VARIABLE;
    OPERAND_C_TYPE variable_address = variables_address_counter;
    variables_address_counter += OPERAND_SIZE;
    // Create the Variable structure.
    memcpy(variable->variable_value.integer, &variable_value, OPERAND_SIZE);
    memcpy(variable->address, &variable_address, OPERAND_SIZE);

    // Save the Variable structure in the variables_table hash table.
    g_hash_table_insert(variables_table, variable_name, variable);
}
                    | TOKEN_IDENTIFIER TOKEN_EQUALS TOKEN_STRING_LITERAL {
                        char *variable_name = $<strval>1;
                        char *variable_value = $<strval>3;

                        printf("Declaring string variable \"%s\" as \"%s\".\n", variable_name, variable_value);

                        // Create a Variable structure representing the variable declaration.
                        Variable *variable = g_new(Variable, 1);
                        variable->variable_type = STRING_VARIABLE;
                        OPERAND_C_TYPE variable_address = variables_address_counter;
                        variables_address_counter += strlen(variable_value) + 1;
                        // Create the Variable structure.
                        variable->variable_value.string = variable_value;
                        memcpy(variable->address, &variable_address, OPERAND_SIZE);

                        // Save the Variable structure in the variables_table hash table.
                        g_hash_table_insert(variables_table, variable_name, variable);
                    }
;

// Parse lines with actual assembly instructions. Each branch here parses an instruction line into an Instruction structure and saves it in the instructions_table hash table.
instruction: TOKEN_NOP {
        printf("Instruction: NOP\n");

        Instruction *instruction = g_new(Instruction, 1);
        instruction->operation = OPERATION_NOP;
        instructions_table = g_slist_append(instructions_table, instruction);
    }
    | TOKEN_LOAD TOKEN_IDENTIFIER TOKEN_REGISTER {
        printf("Instruction: LOAD (variable) %s,%s\n", $<strval>2, $<strval>3);

        Instruction *instruction = g_new(Instruction, 1);
        instruction->operation = OPERATION_LOAD;
        instruction->operand1.operand_address = $<strval>2;
        instruction->operand2.operand_register = stringToRegister($<strval>3);
        instructions_table = g_slist_append(instructions_table, instruction);

        g_free($<strval>3);
    }
    | TOKEN_LOAD TOKEN_MEMORY_ADDRESS TOKEN_REGISTER {
        printf("Instruction: LOAD (address) %s,%s\n", $<strval>2, $<strval>3);

        Instruction *instruction = g_new(Instruction, 1);
        instruction->operation = OPERATION_LOAD;
        instruction->operand1.operand_address = $<strval>2;
        instruction->operand2.operand_register = stringToRegister($<strval>3);
        instructions_table = g_slist_append(instructions_table, instruction);

        g_free($<strval>3);
    }
    | TOKEN_RLOAD TOKEN_REGISTER TOKEN_REGISTER {
        printf("Instruction: RLOAD %s,%s\n", $<strval>2, $<strval>3);

        Instruction *instruction = g_new(Instruction, 1);
        instruction->operation = OPERATION_RLOAD;
        instruction->operand1.operand_register = stringToRegister($<strval>2);
        instruction->operand2.operand_register = stringToRegister($<strval>3);
        instructions_table = g_slist_append(instructions_table, instruction);

        g_free($<strval>2);
        g_free($<strval>3);
    }
    | TOKEN_STORE TOKEN_REGISTER TOKEN_IDENTIFIER {
        printf("Instruction: STORE (variable) %s,%s\n", $<strval>2, $<strval>3);

        Instruction *instruction = g_new(Instruction, 1);
        instruction->operation = OPERATION_STORE;
        instruction->operand1.operand_register = stringToRegister($<strval>2);
        instruction->operand2.operand_address = $<strval>3;
        instructions_table = g_slist_append(instructions_table, instruction);

        g_free($<strval>2);
    }
    | TOKEN_STORE TOKEN_REGISTER TOKEN_MEMORY_ADDRESS {
        printf("Instruction: STORE (address) %s,%s\n", $<strval>2, $<strval>3);

        Instruction *instruction = g_new(Instruction, 1);
        instruction->operation = OPERATION_STORE;
        instruction->operand1.operand_register = stringToRegister($<strval>2);
        instruction->operand2.operand_address = $<strval>3;
        instructions_table = g_slist_append(instructions_table, instruction);

        g_free($<strval>2);
    }
    | TOKEN_RSTORE TOKEN_REGISTER TOKEN_REGISTER {
        printf("Instruction: RSTORE %s,%s\n", $<strval>2, $<strval>3);

        Instruction *instruction = g_new(Instruction, 1);
        instruction->operation = OPERATION_RSTORE;
        instruction->operand1.operand_register = stringToRegister($<strval>2);
        instruction->operand2.operand_register = stringToRegister($<strval>3);
        instructions_table = g_slist_append(instructions_table, instruction);

        g_free($<strval>2);
        g_free($<strval>3);
    }
    | TOKEN_CLOAD TOKEN_CONSTANT TOKEN_REGISTER {
        printf("Instruction: CLOAD (constant) %d,%s\n", $<intval>2, $<strval>3);

        Instruction *instruction = g_new(Instruction, 1);
        instruction->operation = OPERATION_CLOAD;
        instruction->operation_variant = CLOAD_CONSTANT;
        instruction->operand1.operand_constant = $<intval>2;
        instruction->operand2.operand_register = stringToRegister($<strval>3);
        instructions_table = g_slist_append(instructions_table, instruction);

        g_free($<strval>3);
    }
    | TOKEN_CLOAD TOKEN_LEFT_SQUARE_BRACKET TOKEN_IDENTIFIER TOKEN_RIGHT_SQUARE_BRACKET TOKEN_REGISTER {
        printf("Instruction: CLOAD (address) [%s],%s\n", $<strval>3, $<strval>5);

        Instruction *instruction = g_new(Instruction, 1);
        instruction->operation = OPERATION_CLOAD;
        instruction->operation_variant = CLOAD_ADDRESS;
        instruction->operand1.operand_address = $<strval>3;
        instruction->operand2.operand_register = stringToRegister($<strval>5);
        instructions_table = g_slist_append(instructions_table, instruction);

        g_free($<strval>5);
    }
    | TOKEN_ADD TOKEN_REGISTER TOKEN_REGISTER {
        printf("Instruction: ADD %s,%s\n", $<strval>2, $<strval>3);

        Instruction *instruction = g_new(Instruction, 1);
        instruction->operation = OPERATION_ADD;
        instruction->operand1.operand_register = stringToRegister($<strval>2);
        instruction->operand2.operand_register = stringToRegister($<strval>3);
        instructions_table = g_slist_append(instructions_table, instruction);

        g_free($<strval>2);
        g_free($<strval>3);
    }
    | TOKEN_SUB TOKEN_REGISTER TOKEN_REGISTER {
        printf("Instruction: SUB %s,%s\n", $<strval>2, $<strval>3);

        Instruction *instruction = g_new(Instruction, 1);
        instruction->operation = OPERATION_SUB;
        instruction->operand1.operand_register = stringToRegister($<strval>2);
        instruction->operand2.operand_register = stringToRegister($<strval>3);
        instructions_table = g_slist_append(instructions_table, instruction);

        g_free($<strval>2);
        g_free($<strval>3);
    }
    | TOKEN_MULT TOKEN_REGISTER TOKEN_REGISTER {
        printf("Instruction: MULT %s,%s\n", $<strval>2, $<strval>3);

        Instruction *instruction = g_new(Instruction, 1);
        instruction->operation = OPERATION_MULT;
        instruction->operand1.operand_register = stringToRegister($<strval>2);
        instruction->operand2.operand_register = stringToRegister($<strval>3);
        instructions_table = g_slist_append(instructions_table, instruction);

        g_free($<strval>2);
        g_free($<strval>3);
    }
    | TOKEN_DIV TOKEN_REGISTER TOKEN_REGISTER {
        printf("Instruction: DIV %s,%s\n", $<strval>2, $<strval>3);

        Instruction *instruction = g_new(Instruction, 1);
        instruction->operation = OPERATION_DIV;
        instruction->operand1.operand_register = stringToRegister($<strval>2);
        instruction->operand2.operand_register = stringToRegister($<strval>3);
        instructions_table = g_slist_append(instructions_table, instruction);

        g_free($<strval>2);
        g_free($<strval>3);
    }
    | TOKEN_OUT TOKEN_REGISTER TOKEN_REGISTER {
        printf("Instruction: OUT %s,%s\n", $<strval>2, $<strval>3);

        Instruction *instruction = g_new(Instruction, 1);
        instruction->operation = OPERATION_OUT;
        instruction->operand1.operand_register = stringToRegister($<strval>2);
        instruction->operand2.operand_register = stringToRegister($<strval>3);
        instructions_table = g_slist_append(instructions_table, instruction);

        g_free($<strval>2);
        g_free($<strval>3);
    }
    | TOKEN_MOV TOKEN_REGISTER TOKEN_REGISTER {
        printf("Instruction: MOV %s,%s\n", $<strval>2, $<strval>3);

        Instruction *instruction = g_new(Instruction, 1);
        instruction->operation = OPERATION_MOV;
        instruction->operand1.operand_register = stringToRegister($<strval>2);
        instruction->operand2.operand_register = stringToRegister($<strval>3);
        instructions_table = g_slist_append(instructions_table, instruction);

        g_free($<strval>2);
        g_free($<strval>3);
    }
    | TOKEN_IN TOKEN_REGISTER TOKEN_REGISTER {
        printf("Instruction: IN %s,%s\n", $<strval>2, $<strval>3);

        Instruction *instruction = g_new(Instruction, 1);
        instruction->operation = OPERATION_IN;
        instruction->operand1.operand_register = stringToRegister($<strval>2);
        instruction->operand2.operand_register = stringToRegister($<strval>3);
        instructions_table = g_slist_append(instructions_table, instruction);

        g_free($<strval>2);
        g_free($<strval>3);
    }
    | TOKEN_CMP TOKEN_REGISTER TOKEN_REGISTER {
        printf("Instruction: CMP %s,%s\n", $<strval>2, $<strval>3);

        Instruction *instruction = g_new(Instruction, 1);
        instruction->operation = OPERATION_CMP;
        instruction->operand1.operand_register = stringToRegister($<strval>2);
        instruction->operand2.operand_register = stringToRegister($<strval>3);
        instructions_table = g_slist_append(instructions_table, instruction);

        g_free($<strval>2);
        g_free($<strval>3);
    }
    | TOKEN_OR TOKEN_REGISTER TOKEN_REGISTER {
        printf("Instruction: OR %s,%s\n", $<strval>2, $<strval>3);

        Instruction *instruction = g_new(Instruction, 1);
        instruction->operation = OPERATION_OR;
        instruction->operand1.operand_register = stringToRegister($<strval>2);
        instruction->operand2.operand_register = stringToRegister($<strval>3);
        instructions_table = g_slist_append(instructions_table, instruction);

        g_free($<strval>2);
        g_free($<strval>3);
    }
    | TOKEN_AND TOKEN_REGISTER TOKEN_REGISTER {
        printf("Instruction: AND %s,%s\n", $<strval>2, $<strval>3);

        Instruction *instruction = g_new(Instruction, 1);
        instruction->operation = OPERATION_AND;
        instruction->operand1.operand_register = stringToRegister($<strval>2);
        instruction->operand2.operand_register = stringToRegister($<strval>3);
        instructions_table = g_slist_append(instructions_table, instruction);

        g_free($<strval>2);
        g_free($<strval>3);
    }
    | TOKEN_XOR TOKEN_REGISTER TOKEN_REGISTER {
        printf("Instruction: XOR %s,%s\n", $<strval>2, $<strval>3);

        Instruction *instruction = g_new(Instruction, 1);
        instruction->operation = OPERATION_XOR;
        instruction->operand1.operand_register = stringToRegister($<strval>2);
        instruction->operand2.operand_register = stringToRegister($<strval>3);
        instructions_table = g_slist_append(instructions_table, instruction);

        g_free($<strval>2);
        g_free($<strval>3);
    }
    | TOKEN_NOT TOKEN_REGISTER {
        printf("Instruction: NOT %s\n", $<strval>2);

        Instruction *instruction = g_new(Instruction, 1);
        instruction->operation = OPERATION_NOT;
        instruction->operand1.operand_register = stringToRegister($<strval>2);
        instructions_table = g_slist_append(instructions_table, instruction);

        g_free($<strval>2);
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
    | TOKEN_ISR TOKEN_REGISTER TOKEN_IDENTIFIER {
        printf("Instruction: ISR %s,%s\n", $<strval>2, $<strval>3);

        Instruction *instruction = g_new(Instruction, 1);
        instruction->operation = OPERATION_ISR;
        instruction->operand1.operand_register = stringToRegister($<strval>2);
        instruction->operand2.operand_address = $<strval>3;
        instructions_table = g_slist_append(instructions_table, instruction);

        g_free($<strval>2);
    }
    | TOKEN_INT TOKEN_REGISTER {
        printf("Instruction: INT %s\n", $<strval>2);

        Instruction *instruction = g_new(Instruction, 1);
        instruction->operation = OPERATION_INT;
        instruction->operand1.operand_register = stringToRegister($<strval>2);
        instructions_table = g_slist_append(instructions_table, instruction);

        g_free($<strval>2);
    }
    | TOKEN_ENDINT {
        printf("Instruction: ENDINT\n");

        Instruction *instruction = g_new(Instruction, 1);
        instruction->operation = OPERATION_ENDINT;
        instructions_table = g_slist_append(instructions_table, instruction);
    }
;

%%

// Forward declarations of functions in lexer.l that allow Flex to parse an in-memory buffer instead of a file handle.
void startParseString(const char *);
void endParseString(void);

int main(int argc, char *argv[]) {
    // Initialize the hash tables with strings as keys. Use g_free to automatically free the memory used by keys and values.
    variables_table = g_hash_table_new_full(g_str_hash, g_str_equal, (GDestroyNotify) g_free, (GDestroyNotify) freeVariable);
    labels_table = g_hash_table_new_full(g_str_hash, g_str_equal, (GDestroyNotify) g_free, (GDestroyNotify) g_free);

    // Buffer to store the input assembly code.
    char *input_buffer;

    // Show program usage message and exit.
    if (argc < 2) {
        printf("Usage: ./main program.asm [out.bin]\n");
        return 1;
    }

    // Read in .asm input file.
    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        fprintf(stderr, "Error: Failed to open file \"%s\" for reading.\n", argv[1]);
        return 1;
    }
    fseek(input_file, 0, SEEK_END);
    size_t input_file_size = (size_t) ftell(input_file);
    rewind(input_file);
    input_buffer = g_malloc0(input_file_size + 1);
    size_t bytes_read = fread(input_buffer, 1, input_file_size, input_file);
    input_buffer[bytes_read] = '\0';
    fclose(input_file);

    // If no output filename was provided, default to out.bin.
    if (argc == 2) {
        output_file = fopen("out.bin", "wb");
        if (output_file == NULL) {
            fprintf(stderr, "Error: Failed to open file \"out.bin\" for writing.\n");
            return 1;
        }
    }

    // If an output filename was provided, use it.
    else if (argc == 3) {
        output_file = fopen(argv[2], "wb");
        if (output_file == NULL) {
            fprintf(stderr, "Error: Failed to open file \"%s\" for writing.\n", argv[2]);
            return 1;
        }
    }

    // Run the Flex/Bison lexer and parser.
    startParseString(input_buffer);
    yyparse();
    endParseString();

    ///////////////////////////////////////////////////////////////////////////////////////
    // Take the variables_table hash table and convert it into the final binary format.
    ///////////////////////////////////////////////////////////////////////////////////////
    // Allocate memory to store the final binary format of the variables (.data) section of the output binary.
    gsize variables_binary_size = variables_address_counter - OPERAND_SIZE; // Subtract OPERAND_SIZE to compensate for the first OPERAND_SIZE bytes of the file being used to store the length of the .data section.
    void *variables_binary = g_malloc0(variables_binary_size);
    // Iterate over the variables_table hash table.
    GHashTableIter iter;
    g_hash_table_iter_init(&iter, variables_table);
    Variable *variable;
    while (g_hash_table_iter_next(&iter, NULL, (gpointer) &variable)) {
        if (variable->variable_type == INTEGER_VARIABLE) {
            // Convert the variable->address buffer in the Variable structure back into an integer.
            OPERAND_C_TYPE variable_address;
            memcpy(&variable_address, variable->address, OPERAND_SIZE);
            variable_address -= OPERAND_SIZE; // Compensate for the first OPERAND_SIZE bytes of the file being used to store the length of the .data section.
            // Copy the variable's value into the final binary format at the location specified by variable_address.
            memcpy(variables_binary + variable_address, variable->variable_value.integer, OPERAND_SIZE);
        }
        else if (variable->variable_type == STRING_VARIABLE) {
            // Convert the variable->address buffer in the Variable structure back into an integer.
            OPERAND_C_TYPE variable_address;
            memcpy(&variable_address, variable->address, OPERAND_SIZE);
            variable_address -= OPERAND_SIZE; // Compensate for the first OPERAND_SIZE bytes of the file being used to store the length of the .data section.
            // Copy the variable's value into the final binary format at the location specified by variable_address.
            memcpy(variables_binary + variable_address, variable->variable_value.string, strlen(variable->variable_value.string) + 1);
        }
    }

    ///////////////////////////////////////////////////////////////////////////////////////
    // Take the instructions_table hash table and convert it into the final binary format.
    ///////////////////////////////////////////////////////////////////////////////////////
    // Allocate memory to store the final binary format of the instructions (.code) section of the output binary.
    size_t instructions_binary_size = g_slist_length(instructions_table) * INSTRUCTION_SIZE;
    void *instructions_binary = g_malloc0(instructions_binary_size);
    // Iterate over the instructions_table singly-linked list.
    Instruction *instruction;
    // i counts how many instructions have already been processed by the loop. It is used to calculate where in instructions_binary to place the next instruction.
    int i = 0;
    for (GSList *iterator = instructions_table; iterator; iterator = iterator->next) {
        // Get the instruction.
        instruction = iterator->data;
        // Each instruction takes INSTRUCTION_SIZE bytes. Copy the operation to the binary.
        memcpy(instructions_binary + INSTRUCTION_SIZE * i, &instruction->operation, OPERATION_SIZE);
        // Work out whether the arguments should be registers, memory addresses, or some combination thereof.
        gboolean operand1_is_register = FALSE;
        gboolean operand1_is_address = FALSE;
        gboolean operand2_is_register = FALSE;
        gboolean operand2_is_address = FALSE;
        gboolean operand1_is_constant = FALSE;
        gboolean operand2_is_constant = FALSE;
        switch (instruction->operation) {
            case OPERATION_LOAD:
                operand1_is_address = TRUE;
                operand2_is_register = TRUE;
                break;
            case OPERATION_STORE:
                operand1_is_register = TRUE;
                operand2_is_address = TRUE;
                break;
            case OPERATION_ADD:
                operand1_is_register = TRUE;
                operand2_is_register = TRUE;
                break;
            case OPERATION_SUB:
                operand1_is_register = TRUE;
                operand2_is_register = TRUE;
                break;
            case OPERATION_OUT:
                operand1_is_register = TRUE;
                operand2_is_register = TRUE;
                break;
            case OPERATION_IN:
                operand1_is_register = TRUE;
                operand2_is_register = TRUE;
                break;
            case OPERATION_MOV:
                operand1_is_register = TRUE;
                operand2_is_register = TRUE;
                break;
            case OPERATION_CMP:
                operand1_is_register = TRUE;
                operand2_is_register = TRUE;
                break;
            case OPERATION_JMPL:
                operand1_is_address = TRUE;
                break;
            case OPERATION_JMPE:
                operand1_is_address = TRUE;
                break;
            case OPERATION_JMPG:
                operand1_is_address = TRUE;
                break;
            case OPERATION_ISR:
                operand1_is_register = TRUE;
                break;
            case OPERATION_INT:
                operand1_is_register = TRUE;
                break;
            case OPERATION_RLOAD:
                operand1_is_register = TRUE;
                operand2_is_register = TRUE;
                break;
            case OPERATION_RSTORE:
                operand1_is_register = TRUE;
                operand2_is_register = TRUE;
                break;
            case OPERATION_CLOAD:
                if (instruction->operation_variant == CLOAD_CONSTANT) {
                    operand1_is_constant = TRUE;
                }
                else if (instruction->operation_variant == CLOAD_ADDRESS) {
                    operand1_is_address = TRUE;
                }
                else {
                    printf("\033[1;31mERROR:\033[0m Invalid variant for CLOAD.\n");
                }
                operand2_is_register = TRUE;
                break;
            case OPERATION_MULT:
                operand1_is_register = TRUE;
                operand2_is_register = TRUE;
                break;
            case OPERATION_DIV:
                operand1_is_register = TRUE;
                operand2_is_register = TRUE;
                break;
            default:
                break;
        }
        // Based on what the operands to this specific operation are supposed to be (registers or addresses), copy operands over to the final binary output.
        if (operand1_is_register) {
            memcpy(instructions_binary + INSTRUCTION_SIZE * i + OPERATION_SIZE, &instruction->operand1.operand_register, OPERAND_SIZE);
        }
        else if (operand1_is_constant) {
            memcpy(instructions_binary + INSTRUCTION_SIZE * i + OPERATION_SIZE, &instruction->operand1.operand_constant, OPERAND_SIZE);
        }
        // If the operation is a jump instruction, then look up the label being jumped to using the labels_table hash table. Retrieve the buffer storing the instruction address that the label should jump to.
        else if (instruction->operation == OPERATION_JMPL || instruction->operation == OPERATION_JMPE || instruction->operation == OPERATION_JMPG) {
            uint8_t *binary_instruction_index = g_hash_table_lookup(labels_table, instruction->operand1.operand_address);
            if (binary_instruction_index == NULL) {
                printf("\033[1;31mERROR: Unknown label `%s`.\033[0m\n", instruction->operand1.operand_address);
                return 1;
            }
            memcpy(instructions_binary + INSTRUCTION_SIZE * i + OPERATION_SIZE, binary_instruction_index, OPERAND_SIZE);
        }
        else if (operand1_is_address) {
            char *address_string = instruction->operand1.operand_address;
            // Two kinds of addresses are supported. Addresses can be variable names from the .data section like `var5_second` OR hex memory addresses like `[0xFF]`.
            // Addresses that start with [ must be hex memory addresses.
            if (address_string[0] == '[') {
                OPERAND_C_TYPE address = strtol(address_string + 1, NULL, 16);
                memcpy(instructions_binary + INSTRUCTION_SIZE * i + OPERATION_SIZE, &address, OPERAND_SIZE);
            }
            // Other addresses are variables.
            else {
                Variable *variable = g_hash_table_lookup(variables_table, instruction->operand1.operand_address);
                memcpy(instructions_binary + INSTRUCTION_SIZE * i + OPERATION_SIZE, variable->address, OPERAND_SIZE);
            }
        }
        if (operand2_is_register) {
            memcpy(instructions_binary + INSTRUCTION_SIZE * i + OPERATION_SIZE + OPERAND_SIZE, &instruction->operand2.operand_register, OPERAND_SIZE);
        }
        else if (operand2_is_constant) {
            memcpy(instructions_binary + INSTRUCTION_SIZE * i + OPERATION_SIZE + OPERAND_SIZE, &instruction->operand2.operand_constant, OPERAND_SIZE);
        }
        else if (operand2_is_address) {
            char *address_string = instruction->operand2.operand_address;
            // Two kinds of addresses are supported. Addresses can be variable names from the .data section like `var5_second` OR hex memory addresses like `[0xFF]`.
            // Addresses that start with [ must be hex memory addresses.
            if (address_string[0] == '[') {
                OPERAND_C_TYPE address = strtol(address_string + 1, NULL, 16);
                memcpy(instructions_binary + INSTRUCTION_SIZE * i + OPERATION_SIZE + OPERAND_SIZE, &address, OPERAND_SIZE);
            }
            // Other addresses are variables.
            else {
                Variable *variable = g_hash_table_lookup(variables_table, instruction->operand2.operand_address);
                memcpy(instructions_binary + INSTRUCTION_SIZE * i + OPERATION_SIZE + OPERAND_SIZE, variable->address, OPERAND_SIZE);
            }
        }
        else if (instruction->operation == OPERATION_ISR) {
            uint8_t *binary_instruction_index = g_hash_table_lookup(labels_table, instruction->operand2.operand_address);
            memcpy(instructions_binary + INSTRUCTION_SIZE * i + OPERATION_SIZE + OPERAND_SIZE, binary_instruction_index, OPERAND_SIZE);
        }
        i++;
    }

    // Write the length of the .data (variables) section to the first OPERAND_SIZE bytes of the output binary file.
    if (fwrite(&variables_binary_size, OPERAND_SIZE, 1, output_file) != 1) {
        printf("\033[1;31mERROR:\033[0m Could not write %d bytes of data to the file.\n", OPERAND_SIZE);
    }
    // Write the final binary format of the .data (variables) section to the output binary file.
    if (fwrite(variables_binary, 1, variables_binary_size, output_file) != variables_binary_size) {
        printf("\033[1;31mERROR:\033[0m Could not write %d bytes of data to the file.\n", variables_binary_size);
    }
    // Write the final binary format of the .code (instructions) section to the output binary file.
    if (fwrite(instructions_binary, INSTRUCTION_SIZE, g_slist_length(instructions_table), output_file) != g_slist_length(instructions_table)) {
        printf("\033[1;31mERROR:\033[0m Could not write %d bytes of data to the file.\n", g_slist_length(instructions_table) * INSTRUCTION_SIZE);
    }

    // Clean up resources.
    g_hash_table_destroy(variables_table);
    variables_table = NULL;
    g_slist_free_full(instructions_table, (GDestroyNotify) freeInstruction);
    instructions_table = NULL;
    g_hash_table_destroy(labels_table);
    labels_table = NULL;
    g_free(input_buffer);
    g_free(variables_binary);
    g_free(instructions_binary);
    fclose(output_file);

    return 0;
}

// Function to print out parser errors from Bison.
void yyerror(char *s) {
    fprintf(stderr, "Error: %s\n", s);
}
