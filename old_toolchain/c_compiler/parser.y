%{
    #include <stdio.h>
    #include <glib.h>
    #include "processor.h"

    #define YYDEBUG 1 // TODO: REMOVE.

    // Forward declarations for functions provided by the Flex-generated lexer (or defined later in this program).
    int yylex(void);
    void yyerror(char *);
%}

%start program

%token INT
%token IDENTIFIER
%token I_CONSTANT

%left '+' '-'
%left '*' '/'
%left NEGATE

%%

program
    : statement
    | program statement
    ;

statement
    : variable_declaration
    ;

variable_declaration
    : type_specifier IDENTIFIER '=' expression ';'
    ;

type_specifier
    : INT
    ;

expression
    : term
    | expression '+' expression
    | expression '-' expression
    | expression '*' expression
    | expression '/' expression
    | '-' expression %prec NEGATE
    | '(' expression ')'
    ;

term
    : I_CONSTANT
    | IDENTIFIER
    ;

%%

// Function to print out parser errors from Bison.
void yyerror(char *s) {
    fprintf(stderr, "Error: %s\n", s);
}
