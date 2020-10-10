%{
    #include <iostream>
    #include <string>
    #include <sstream>
    #include <fstream>
    #include "ast.h"
    #include "asmgenerator.h"

    // #define YYDEBUG 1

    // Forward declarations for functions provided by the Flex-generated lexer (or defined later in this program).
    extern "C" {
        int yylex(void);
        void yyerror(char *);
    }

    // Start of the AST.
    ASTRootNode *ast;
%}

%code requires {
    #include "ast.h"
}

%token TOKEN_VAR
%token TOKEN_EQUALS
%token TOKEN_IDENTIFIER
%token TOKEN_CONSTANT
%token TOKEN_SEMICOLON
%token TOKEN_COLON_EQUALS
%token TOKEN_PLUS
%token TOKEN_MINUS
%token TOKEN_IF
%token TOKEN_THEN
%token TOKEN_BEGIN
%token TOKEN_END
%token TOKEN_NOT_EQUALS
%token TOKEN_LESS_THAN
%token TOKEN_LESS_THAN_OR_EQUAL_TO
%token TOKEN_GREATER_THAN
%token TOKEN_GREATER_THAN_OR_EQUAL_TO
%token TOKEN_CALL
%token TOKEN_WHILE
%token TOKEN_DO
%token TOKEN_ASTERISK
%token TOKEN_FORWARD_SLASH
%token TOKEN_PERCENT
%token TOKEN_PROCEDURE

%start program

%union {
    int intval;
    char *strval;
    ASTStatementNode *statement_node;
    ASTVariableDeclarationNode *variable_declaration_node;
    ASTVariableAssignmentNode *variable_assignment_node;
    ASTExpressionNode *expression_node;
    ASTTermNode *term_node;
    ASTConditionalNode *conditional_node;
    ASTConditionNode *condition_node;
    ASTBeginEndBlockNode *begin_end_block_node;
    ASTProcedureCallNode *procedure_call_node;
    ASTWhileLoopNode *while_loop_node;
    ASTProcedureNode *procedure_node;
}

%type <strval> TOKEN_IDENTIFIER;
%type <intval> TOKEN_CONSTANT;
%type <statement_node> statement;
%type <variable_declaration_node> variable_declaration;
%type <variable_assignment_node> variable_assignment;
%type <expression_node> expression;
%type <term_node> term;
%type <conditional_node> conditional;
%type <condition_node> condition;
%type <begin_end_block_node> begin_end_block;
%type <begin_end_block_node> statement_sequence;
%type <procedure_call_node> procedure_call;
%type <while_loop_node> while_loop;
%type <procedure_node> procedure;

%%

program: {
    ast = new ASTRootNode();
}
       | program statement {
           ast->addStatement($2);
       }
;

statement: variable_declaration TOKEN_SEMICOLON {
            $$ = $1;
         }
         | variable_assignment TOKEN_SEMICOLON {
            $$ = $1;
         }
         | conditional TOKEN_SEMICOLON {
            $$ = $1;
         }
         | procedure_call TOKEN_SEMICOLON {
            $$ = $1;
         }
         | while_loop TOKEN_SEMICOLON {
            $$ = $1;
         }
         | procedure TOKEN_SEMICOLON {
            $$ = $1;
         }
;

variable_declaration: TOKEN_VAR TOKEN_IDENTIFIER {
                        $$ = new ASTVariableDeclarationNode($2);
                        free($2);
                    }
                    | TOKEN_VAR TOKEN_IDENTIFIER TOKEN_EQUALS TOKEN_CONSTANT {
                        $$ = new ASTVariableDeclarationNode($2, $4);
                        free($2);
                    }
;

variable_assignment: TOKEN_IDENTIFIER TOKEN_COLON_EQUALS expression {
                   $$ = new ASTVariableAssignmentNode($1, $3);
                   free($1);
}
;

conditional: TOKEN_IF condition TOKEN_THEN begin_end_block {
    $$ = new ASTConditionalNode($2, $4);
}
;

begin_end_block: TOKEN_BEGIN statement_sequence TOKEN_END {
    $$ = $2;
}
;

statement_sequence: statement {
    $$ = new ASTBeginEndBlockNode();
    $$->addStatement($1);
}
                  | statement_sequence statement {
                      $1->addStatement($2);
                  }
;

term: TOKEN_IDENTIFIER {
    $$ = new ASTTermNode(ADDITION, $1);
    free($1);
}
    | TOKEN_CONSTANT {
        $$ = new ASTTermNode(ADDITION, $1);
    }
    | TOKEN_PLUS TOKEN_IDENTIFIER {
        $$ = new ASTTermNode(ADDITION, $2);
        free($2);
    }
    | TOKEN_MINUS TOKEN_IDENTIFIER {
        $$ = new ASTTermNode(SUBTRACTION, $2);
        free($2);
    }
    | TOKEN_PLUS TOKEN_CONSTANT {
        $$ = new ASTTermNode(ADDITION, $2);
    }
    | TOKEN_MINUS TOKEN_CONSTANT {
        $$ = new ASTTermNode(SUBTRACTION, $2);
    }
    | TOKEN_ASTERISK TOKEN_IDENTIFIER {
        $$ = new ASTTermNode(MULTIPLICATION, $2);
        free($2);
    }
    | TOKEN_ASTERISK TOKEN_CONSTANT {
        $$ = new ASTTermNode(MULTIPLICATION, $2);
    }
    | TOKEN_FORWARD_SLASH TOKEN_IDENTIFIER {
        $$ = new ASTTermNode(DIVISION, $2);
        free($2);
    }
    | TOKEN_FORWARD_SLASH TOKEN_CONSTANT {
        $$ = new ASTTermNode(DIVISION, $2);
    }
    | TOKEN_PERCENT TOKEN_IDENTIFIER {
        $$ = new ASTTermNode(MODULUS, $2);
        free($2);
    }
    | TOKEN_PERCENT TOKEN_CONSTANT {
        $$ = new ASTTermNode(MODULUS, $2);
    }
;

expression: {
    $$ = new ASTExpressionNode();
}
          | expression term {
              $1->addTerm($2);
          }
;

condition: expression TOKEN_NOT_EQUALS expression {
    $$ = new ASTConditionNode(NOT_EQUALS, $1, $3);
}
         | expression TOKEN_EQUALS expression {
             $$ = new ASTConditionNode(EQUALS, $1, $3);
         }
         | expression TOKEN_LESS_THAN expression {
             $$ = new ASTConditionNode(LESS_THAN, $1, $3);
         }
         | expression TOKEN_LESS_THAN_OR_EQUAL_TO expression {
             $$ = new ASTConditionNode(LESS_THAN_OR_EQUAL_TO, $1, $3);
         }
         | expression TOKEN_GREATER_THAN expression {
             $$ = new ASTConditionNode(GREATER_THAN, $1, $3);
         }
         | expression TOKEN_GREATER_THAN_OR_EQUAL_TO expression {
             $$ = new ASTConditionNode(GREATER_THAN_OR_EQUAL_TO, $1, $3);
         }
;

procedure_call: TOKEN_CALL TOKEN_IDENTIFIER {
    $$ = new ASTProcedureCallNode($2);
    free($2);
}
;

while_loop: TOKEN_WHILE condition TOKEN_DO begin_end_block {
    $$ = new ASTWhileLoopNode($2, $4);
}
;

procedure: TOKEN_PROCEDURE TOKEN_IDENTIFIER TOKEN_SEMICOLON begin_end_block {
    $$ = new ASTProcedureNode($2, $4);
    free($2);
}
;

%%

// Forward declarations of functions in lexer.l that allow Flex to parse an in-memory buffer instead of a file handle.
void startParseString(const char *);
void endParseString(void);

int main(int argc, char *argv[]) {
    // yydebug = 1;

    if (argc < 2) {
        std::cout << "Usage: ./main program.pl0 [output.asm]" << std::endl;
        return 1;
    }

    const char *input_filename = argv[1];
    const char *output_filename = "output.asm";
    if (argc == 3) {
        output_filename = argv[2];
    }

    std::ifstream input_file(input_filename);
    std::stringstream input_file_stringstream;
    input_file_stringstream << input_file.rdbuf();
    std::string input_buffer = input_file_stringstream.str();
    input_file.close();

    startParseString(input_buffer.c_str());
    yyparse();
    endParseString();

    // Uncomment to display Graphviz-based AST visualization.
    // ast->showGraph();

    AssemblyGenerator asmGenerator;

    std::ofstream output_file(output_filename, std::ofstream::out);
    output_file << asmGenerator.getGeneratedAssembly(ast);
    output_file.close();

    delete ast;

    return 0;
}

// Function to print out parser errors from Bison.
void yyerror(char *s) {
    std::cerr << "Error: " << s << std::endl;
}
