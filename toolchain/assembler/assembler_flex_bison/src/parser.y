%{
    #include <stdio.h>
    #include <glib.h>
    #include "assembler.h"

    int yylex(void);
    void yyerror(char *);

    AssemblySection current_section = DATA_SECTION;

    FILE *output_file;
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
%token TOKEN_LABEL

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
    | line TOKEN_LABEL TOKEN_EOL {
        printf("Label: %s\n", $<strval>1);
    }
    | line variable_declaration TOKEN_EOL
    | line instruction TOKEN_EOL
;

variable_declaration: TOKEN_IDENTIFIER TOKEN_EQUALS TOKEN_CONSTANT {
    printf("Declaring variable \"%s\" as %d.\n", $<strval>1, $<intval>3);
}
;

instruction: TOKEN_NOP
    | TOKEN_LOAD TOKEN_IDENTIFIER TOKEN_REGISTER
    | TOKEN_STORE TOKEN_REGISTER TOKEN_IDENTIFIER
    | TOKEN_ADD TOKEN_REGISTER TOKEN_REGISTER
    | TOKEN_SUB TOKEN_REGISTER TOKEN_REGISTER
    | TOKEN_OUT TOKEN_REGISTER
    | TOKEN_MOV TOKEN_REGISTER TOKEN_REGISTER
    | TOKEN_CMP TOKEN_REGISTER TOKEN_REGISTER
    | TOKEN_JMPL TOKEN_IDENTIFIER
    | TOKEN_JMPE TOKEN_IDENTIFIER
    | TOKEN_JMPG TOKEN_IDENTIFIER
    | TOKEN_RST
    | TOKEN_HALT
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
        fprintf(stderr, "Error: Failed to open file \"%s\" for reading.", argv[1]);
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
            fprintf(stderr, "Error: Failed to open file \"output.bin\" for writing.");
            return 1;
        }
    }
    else if (argc == 3) {
        output_file = fopen(argv[2], "w");
        if (output_file == NULL) {
            fprintf(stderr, "Error: Failed to open file \"%s\" for writing.", argv[2]);
            return 1;
        }
    }

    startParseString(input_buffer);
    yyparse();
    endParseString();
}

void yyerror(char *s) {
    fprintf(stderr, "Error: %s\n", s);
}
