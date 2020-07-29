%{
    #include <stdio.h>
    #include <glib.h>

    #define YYDEBUG 1

    // Forward declarations for functions provided by the Flex-generated lexer (or defined later in this program).
    int yylex(void);
    void yyerror(char *);

    // File handle for the .asm output file of the compiler.
    FILE *output_file;

    ////////////////////////////////////////////////////////////////////////////////////////////////
    // Data structures for storing the Abstract Syntax Tree (AST) that the parsing step generates.
    ////////////////////////////////////////////////////////////////////////////////////////////////

    typedef struct ast_node ASTNode;
    typedef struct expression_node ExpressionNode;

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
        ExpressionNode *value;
    } VariableAssignmentNode;

    // Structure for storing expressions like "var1 + 16 - var2".
    typedef struct expression_node {
        GSList *terms;
    } ExpressionNode;

    // Structure for storing terms in an expression.
    typedef enum {
        POSITIVE,
        NEGATIVE
    } TermSign;
    typedef enum {
        VARIABLE,
        CONSTANT
    } TermType;
    typedef union {
        char *variable_name;
        int constant;
    } TermValue;
    typedef struct term_node {
        TermSign sign;
        TermType type;
        TermValue value;
    } TermNode;

    // Union that can hold any type of node.
    typedef union {
        VariableDeclarationNode variable_declaration;
        VariableAssignmentNode variable_assignment;
    } ASTNodeUnion;

    // Structure that stores nodes in the parse tree. Stores the type of each node so that the program knows which member of the .node union to access.
    typedef struct ast_node {
        ASTNodeType node_type;
        ASTNodeUnion node;
    } ASTNode;

    GSList *ast = NULL;

    ///////////////////////////////////////////////////////
    // Functions for generating assembly from AST nodes.
    ///////////////////////////////////////////////////////
    // Function that takes a file pointer and a pointer to an ExpressionNode in order to generate the assembly to evaluate the expression into register A.
    void evaluateExpression(FILE *output_file, ExpressionNode *node) {
        for (GSList *iterator = node->terms; iterator; iterator->next) {
            TermNode *term = iterator->data;
        }
    }
%}

%token TOKEN_VAR
%token TOKEN_EQUALS
%token TOKEN_IDENTIFIER
%token TOKEN_CONSTANT
%token TOKEN_SEMICOLON
%token TOKEN_COLON_EQUALS
%token TOKEN_PLUS
%token TOKEN_MINUS

%start statement

%union {
    int intval;
    char *strval;
    struct ast_node *node;
    struct expression_node *expression_node;
    struct term_node *term_node;
}

%type <node> variable_declaration;
%type <node> variable_assignment;
%type <expression_node> expression;
%type <term_node> term;

%%

statement:
         | statement TOKEN_SEMICOLON
         | statement variable_declaration TOKEN_SEMICOLON {
            ast = g_slist_append(ast, $2);
         }
         | statement variable_assignment TOKEN_SEMICOLON {
            ast = g_slist_append(ast, $2);
         }
;

variable_declaration: TOKEN_VAR TOKEN_IDENTIFIER {
                        ASTNode *node = g_new(ASTNode, 1);
                        node->node_type = VARIABLE_DECLARATION;
                        node->node.variable_declaration.name = $<strval>2;
                        node->node.variable_declaration.value = 0;
                        $$ = node;
                    }
                    | TOKEN_VAR TOKEN_IDENTIFIER TOKEN_EQUALS TOKEN_CONSTANT {
                        ASTNode *node = g_new(ASTNode, 1);
                        node->node_type = VARIABLE_DECLARATION;
                        node->node.variable_declaration.name = $<strval>2;
                        node->node.variable_declaration.value = $<intval>4;
                        $$ = node;
                    }
;

variable_assignment: TOKEN_IDENTIFIER TOKEN_COLON_EQUALS expression {
                       ASTNode *node = g_new(ASTNode, 1);
                       node->node_type = VARIABLE_ASSIGNMENT;
                       node->node.variable_assignment.name = $<strval>1;
                       node->node.variable_assignment.value = $3;
                       $$ = node;
                   }
;

expression: {
    ExpressionNode *expression_node = g_new(ExpressionNode, 1);
    expression_node->terms = NULL;
    $$ = expression_node;
}
          | expression term {
              $1->terms = g_slist_append($1->terms, $2);
          }
;

term: TOKEN_IDENTIFIER {
    TermNode *term_node = g_new(TermNode, 1);
    term_node->sign = POSITIVE;
    term_node->type = VARIABLE;
    term_node->value.variable_name = $<strval>1;
    $$ = term_node;
}
    | TOKEN_CONSTANT {
        TermNode *term_node = g_new(TermNode, 1);
        term_node->sign = POSITIVE;
        term_node->type = CONSTANT;
        term_node->value.constant = $<intval>1;
        $$ = term_node;
    }
    | TOKEN_PLUS TOKEN_IDENTIFIER {
        TermNode *term_node = g_new(TermNode, 1);
        term_node->sign = POSITIVE;
        term_node->type = VARIABLE;
        term_node->value.variable_name = $<strval>2;
        $$ = term_node;
    }
    | TOKEN_MINUS TOKEN_IDENTIFIER {
        TermNode *term_node = g_new(TermNode, 1);
        term_node->sign = NEGATIVE;
        term_node->type = VARIABLE;
        term_node->value.variable_name = $<strval>2;
        $$ = term_node;
    }
    | TOKEN_PLUS TOKEN_CONSTANT {
        TermNode *term_node = g_new(TermNode, 1);
        term_node->sign = POSITIVE;
        term_node->type = CONSTANT;
        term_node->value.constant = $<intval>2;
        $$ = term_node;
    }
    | TOKEN_MINUS TOKEN_CONSTANT {
        TermNode *term_node = g_new(TermNode, 1);
        term_node->sign = NEGATIVE;
        term_node->type = CONSTANT;
        term_node->value.constant = $<intval>2;
        $$ = term_node;
    }
;

%%

// Forward declarations of functions in lexer.l that allow Flex to parse an in-memory buffer instead of a file handle.
void startParseString(const char *);
void endParseString(void);

int main(int argc, char *argv[]) {
    yydebug = 1;

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
            fprintf(output_file, "    // Declaring variable `%s`.\n", node->node.variable_declaration.name);
            fprintf(output_file, "    %s = %d\n", node->node.variable_declaration.name, node->node.variable_declaration.value);
        }
    }

    // Generate the .code section of the assembly file.
    fprintf(output_file, ".code:\n");
    for (GSList *iterator = ast; iterator; iterator = iterator->next) {
        ASTNode *node = iterator->data;

        if (node->node_type == VARIABLE_ASSIGNMENT) {
            evaluateExpression(output_file, node->node.variable_assignment.value);
        }
    }

    fclose(output_file);

    return 0;
}

// Function to print out parser errors from Bison.
void yyerror(char *s) {
    fprintf(stderr, "Error: %s\n", s);
}
