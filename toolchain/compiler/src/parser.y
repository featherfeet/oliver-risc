%{
    #include <stdio.h>
    #include <glib.h>

    // Forward declarations for functions provided by the Flex-generated lexer (or defined later in this program).
    int yylex(void);
    void yyerror(char *);

    // File handle for the .asm output file of the compiler.
    FILE *output_file;

    ////////////////////////////////////////////////////////////////////////////////////////////////
    // Data structures for storing the Abstract Syntax Tree (AST) that the parsing step generates.
    ////////////////////////////////////////////////////////////////////////////////////////////////
    
    // Different types of nodes (variable declaration, variable assignment, etc.) that can be in the parse tree.
    typedef enum {
        VARIABLE_DECLARATION,
        VARIABLE_ASSIGNMENT
    } ASTNodeType;

    // Structure for storing variable declarations like "VAR x = 10;" Does not have a pointer to any sub-node because variable declarations do not have any nested syntax.
    typedef struct {
        char *name;
        int value;
    } VariableDeclarationNode;

    // Structure for storing variable assingments like "VAR x = 10;" TODO: Add pointer to an ASTNode for storing expressions so that the user can do things like "x := x + 5;" 
    typedef struct {
        char *name;
        int value;
    } VariableAssignmentNode;

    // Union that can hold any type of node.
    typedef union {
        VariableDeclarationNode variable_declaration;
        VariableAssignmentNode variable_assignment;
    } ASTNodeUnion;

    // Structure that stores nodes in the parse tree. Stores the type of each node so that the program knows which member of the .node union to access.
    typedef struct {
        ASTNodeType node_type;
        ASTNodeUnion node;
    } ASTNode;

    GSList *ast = NULL;
%}

%token TOKEN_VAR
%token TOKEN_EQUALS
%token TOKEN_IDENTIFIER
%token TOKEN_CONSTANT
%token TOKEN_SEMICOLON

%start statement

%union {
    int intval;
    char *strval;
}

%%

statement:
         | statement TOKEN_SEMICOLON
         | statement variable_declaration TOKEN_SEMICOLON
;

variable_declaration: TOKEN_VAR TOKEN_IDENTIFIER {
                        ASTNode *node = g_new(ASTNode, 1);
                        node->node_type = VARIABLE_DECLARATION;
                        node->node.variable_declaration.name = $<strval>2;
                        node->node.variable_declaration.value = 0;
                        ast = g_slist_append(ast, node);
                    }
                    | TOKEN_VAR TOKEN_IDENTIFIER TOKEN_EQUALS TOKEN_CONSTANT {
                        ASTNode *node = g_new(ASTNode, 1);
                        node->node_type = VARIABLE_DECLARATION;
                        node->node.variable_declaration.name = $<strval>2;
                        node->node.variable_declaration.value = $<intval>4;
                        ast = g_slist_append(ast, node);
                    }
;

%%

// Forward declarations of functions in lexer.l that allow Flex to parse an in-memory buffer instead of a file handle.
void startParseString(const char *);
void endParseString(void);

int main(int argc, char *argv[]) {
    // Buffer to store the input PL/0 code.
    char *input_buffer;

    // Show program usage message and exit.
    if (argc < 2) {
        printf("Usage: ./main program.pl0 [out.asm]\n");
        return 1;
    }

    // Read in .pl0 input file.
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
        output_file = fopen("out.asm", "w");
        if (output_file == NULL) {
            fprintf(stderr, "Error: Failed to open file \"out.asm\" for writing.\n");
            return 1;
        }
    }

    // If an output filename was provided, use it.
    else if (argc == 3) {
        output_file = fopen(argv[2], "w");
        if (output_file == NULL) {
            fprintf(stderr, "Error: Failed to open file \"%s\" for writing.\n", argv[2]);
            return 1;
        }
    }

    // Run the Flex/Bison lexer and parser to generate an AST.
    startParseString(input_buffer);
    yyparse();
    endParseString();

    // Generate the .data section of the assembly file.
    fprintf(output_file, ".data:\n");
    for (GSList *iterator = ast; iterator; iterator = iterator->next) {
        ASTNode *node = iterator->data;

        if (node->node_type == VARIABLE_DECLARATION) {
            fprintf(output_file, "    %s = %d\n", node->node.variable_declaration.name, node->node.variable_declaration.value);
        }
    }

    fclose(output_file);

    return 0;
}

// Function to print out parser errors from Bison.
void yyerror(char *s) {
    fprintf(stderr, "Error: %s\n", s);
}
