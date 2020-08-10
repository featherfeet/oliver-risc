%{
    #include <iostream>
    #include <string>
    #include <sstream>
    #include <fstream>
    #include "ast.h"

    #define YYDEBUG 1

    // Forward declarations for functions provided by the Flex-generated lexer (or defined later in this program).
    extern "C" {
        int yylex(void);
        void yyerror(char *);
    }

    // Start of the AST.
    ASTRootNode *ast = new ASTRootNode();

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

%start program

%union {
    int intval;
    char *strval;
    ASTStatementNode *statement_node;
    ASTVariableDeclarationNode *variable_declaration_node;
    ASTVariableAssignmentNode *variable_assignment_node;
    ASTExpressionNode *expression_node;
    ASTTermNode *term_node;
}

%type <strval> TOKEN_IDENTIFIER;
%type <intval> TOKEN_CONSTANT;
%type <statement_node> statement;
%type <variable_declaration_node> variable_declaration;
%type <variable_assignment_node> variable_assignment;
%type <expression_node> expression;
%type <term_node> term;

%%

program:
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
;

variable_declaration: TOKEN_VAR TOKEN_IDENTIFIER {
                        $$ = new ASTVariableDeclarationNode($2);
                    }
                    | TOKEN_VAR TOKEN_IDENTIFIER TOKEN_EQUALS TOKEN_CONSTANT {
                        $$ = new ASTVariableDeclarationNode($2, $4);
                    }
;

variable_assignment: TOKEN_IDENTIFIER TOKEN_COLON_EQUALS expression {
                   $$ = new ASTVariableAssignmentNode($1, $3);
}
;

expression: {
          $$ = new ASTExpressionNode();
}
          | expression term {
              $1->addTerm($2);
          }
;

term: TOKEN_IDENTIFIER {
    $$ = new ASTTermNode(POSITIVE, $1);
}
    | TOKEN_CONSTANT {
        $$ = new ASTTermNode(POSITIVE, $1);
    }
    | TOKEN_PLUS TOKEN_IDENTIFIER {
        $$ = new ASTTermNode(POSITIVE, $2);
    }
    | TOKEN_MINUS TOKEN_IDENTIFIER {
        $$ = new ASTTermNode(NEGATIVE, $2);
    }
    | TOKEN_PLUS TOKEN_CONSTANT {
        $$ = new ASTTermNode(POSITIVE, $2);
    }
    | TOKEN_MINUS TOKEN_CONSTANT {
        $$ = new ASTTermNode(NEGATIVE, $2);
    }
;

%%

// Forward declarations of functions in lexer.l that allow Flex to parse an in-memory buffer instead of a file handle.
void startParseString(const char *);
void endParseString(void);

int main(int argc, char *argv[]) {
    yydebug = 1;

    if (argc != 2) {
        std::cout << "Usage: ./main program.pl0" << std::endl;
        return 1;
    }

    std::ifstream input_file(argv[1]);
    std::stringstream input_file_stringstream;
    input_file_stringstream << input_file.rdbuf();
    std::string input_buffer = input_file_stringstream.str();
    input_file.close();

    startParseString(input_buffer.c_str());
    yyparse();
    endParseString();

    ast->showGraph();

    return 0;
}

// Function to print out parser errors from Bison.
void yyerror(char *s) {
    std::cerr << "Error: " << s << std::endl;
}
