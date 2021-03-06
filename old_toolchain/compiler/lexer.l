%{
    extern "C" int yylex();
    #include "compiler_parser.hpp"

    #include <string.h>
%}

%x SINGLE_LINE_COMMENT
%x MULTILINE_COMMENT

%%

"//" {
    BEGIN(SINGLE_LINE_COMMENT);
}

<SINGLE_LINE_COMMENT>. {
}

<SINGLE_LINE_COMMENT>\n {
    BEGIN(INITIAL);
}

"/*" {
    BEGIN(MULTILINE_COMMENT);
}

<MULTILINE_COMMENT>. {
}

<MULTILINE_COMMENT>\n {
}

<MULTILINE_COMMENT>"*/" {
    BEGIN(INITIAL);
}

\"[^"\n]*["\n] {
    yylval.strval = strdup(yytext + 1);
    if (yylval.strval[yyleng - 2] != '"') {
        printf("\033[1;31mERROR:\033[0m String not terminated with quotes.\n");
    }
    else {
        yylval.strval[yyleng - 2] = '\0';
    }
    return TOKEN_STRING_LITERAL;
}

"VAR" {
    return TOKEN_VAR;
}

"CALL" {
    return TOKEN_CALL;
}

"RETURN" {
    return TOKEN_RETURN;
}

"+" {
    return TOKEN_PLUS;
}

"-" {
    return TOKEN_MINUS;
}

"*" {
    return TOKEN_ASTERISK;
}

"/" {
    return TOKEN_FORWARD_SLASH;
}

"%" {
    return TOKEN_PERCENT;
}

"=" {
    return TOKEN_EQUALS;
}

":=" {
    return TOKEN_COLON_EQUALS;
}

"[" {
    return TOKEN_LEFT_SQUARE_BRACKET;
}

"]" {
    return TOKEN_RIGHT_SQUARE_BRACKET;
}

"IF" {
    return TOKEN_IF;
}

"THEN" {
    return TOKEN_THEN;
}

"BEGIN" {
    return TOKEN_BEGIN;
}

"END" {
    return TOKEN_END;
}

"WHILE" {
    return TOKEN_WHILE;
}

"DO" {
    return TOKEN_DO;
}

"PROCEDURE" {
    return TOKEN_PROCEDURE;
}

"ISR" {
    return TOKEN_ISR;
}

"__ASM__" {
    return TOKEN_ASM;
}

"(" {
    return TOKEN_LEFT_PARENTHESIS;
}

")" {
    return TOKEN_RIGHT_PARENTHESIS;
}

"#" {
    return TOKEN_NOT_EQUALS;
}

"<" {
    return TOKEN_LESS_THAN;
}

"<=" {
    return TOKEN_LESS_THAN_OR_EQUAL_TO;
}

">" {
    return TOKEN_GREATER_THAN;
}

">=" {
    return TOKEN_GREATER_THAN_OR_EQUAL_TO;
}

[a-zA-Z]+[a-zA-Z0-9_]* {
    yylval.strval = strdup(yytext);
    return TOKEN_IDENTIFIER;
}

[0-9]+ {
    yylval.intval = atoi(yytext);
    return TOKEN_CONSTANT;
}

";" {
    return TOKEN_SEMICOLON;
}

[ \t\n] {
    // Ignore whitespace characters (spaces and tabs and newlines). TODO: USE NEWLINES.
}

. {
    printf("Unknown character %c\n", *yytext);
}
%%

void startParseString(const char *str) {
    yy_scan_string(str);
}

void endParseString() {
    yy_delete_buffer(YY_CURRENT_BUFFER);
    yylex_destroy();
}
