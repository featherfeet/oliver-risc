%{
    #include <iostream>
    #include <string>
    #include <memory>

    #define YYDEBUG 1

    // Forward declarations for functions provided by the Flex-generated lexer (or defined later in this program).
    extern "C" {
        int yylex(void);
        void yyerror(char *);
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
    std::string strval;
    std::shared_ptr<ASTNode> node;
}

%type <strval> TOKEN_IDENTIFIER;
%type <intval> TOKEN_CONSTANT;
%type <node> variable_declaration;
%type <node> variable_assignment;
%type <node> expression;
%type <node> term;

%%

statement:
         | statement TOKEN_SEMICOLON
         | statement variable_declaration TOKEN_SEMICOLON {
         }
         | statement variable_assignment TOKEN_SEMICOLON {
         }
;

variable_declaration: TOKEN_VAR TOKEN_IDENTIFIER {
                    }
                    | TOKEN_VAR TOKEN_IDENTIFIER TOKEN_EQUALS TOKEN_CONSTANT {
                    }
;

variable_assignment: TOKEN_IDENTIFIER TOKEN_COLON_EQUALS expression {
                   }
;

expression: {
}
          | expression term {
          }
;

term: TOKEN_IDENTIFIER {
}
    | TOKEN_CONSTANT {
    }
    | TOKEN_PLUS TOKEN_IDENTIFIER {
    }
    | TOKEN_MINUS TOKEN_IDENTIFIER {
    }
    | TOKEN_PLUS TOKEN_CONSTANT {
    }
    | TOKEN_MINUS TOKEN_CONSTANT {
    }
;

%%

// Forward declarations of functions in lexer.l that allow Flex to parse an in-memory buffer instead of a file handle.
void startParseString(const char *);
void endParseString(void);

int main(int argc, char *argv[]) {
    yydebug = 1;
}

// Function to print out parser errors from Bison.
void yyerror(char *s) {
    std::cerr << "Error: " << s << std::endl;
}
