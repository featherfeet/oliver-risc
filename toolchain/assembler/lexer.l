%{
    #include <stdlib.h>
    #include <glib.h>
    #include "assembler_parser.h"
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
    return TOKEN_EOL;
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
    return TOKEN_EOL;
}

".data:" {
    return TOKEN_DOT_DATA;
}

".code:" {
    return TOKEN_DOT_CODE;
}

\n {
    return TOKEN_EOL;
}

[, \t] {
    // Ignore whitespace characters (spaces and tabs), as well as commas.
}

"NOP" {
    return TOKEN_NOP;
}

"LOAD" {
    return TOKEN_LOAD;
}

"STORE" {
    return TOKEN_STORE;
}

"ADD" {
    return TOKEN_ADD;
}

"SUB" {
    return TOKEN_SUB;
}

"OUT" {
    return TOKEN_OUT;
}

"IN" {
    return TOKEN_IN;
}

"MOV" {
    return TOKEN_MOV;
}

"CMP" {
    return TOKEN_CMP;
}

"JMPL" {
    return TOKEN_JMPL;
}

"JMPE" {
    return TOKEN_JMPE;
}

"JMPG" {
    return TOKEN_JMPG;
}

"RST" {
    return TOKEN_RST;
}

"HALT" {
    return TOKEN_HALT;
}

"ISR" {
    return TOKEN_ISR;
}

"INT" {
    return TOKEN_INT;
}

"ENDINT" {
    return TOKEN_ENDINT;
}

"RLOAD" {
    return TOKEN_RLOAD;
}

"RSTORE" {
    return TOKEN_RSTORE;
}

"CLOAD" {
    return TOKEN_CLOAD;
}

"MULT" {
    return TOKEN_MULT;
}

"DIV" {
    return TOKEN_DIV;
}

"OR" {
    return TOKEN_OR;
}

"AND" {
    return TOKEN_AND;
}

"XOR" {
    return TOKEN_XOR;
}

"NOT" {
    return TOKEN_NOT;
}

(IP|A|B|C|D|E|F|G) {
    yylval.strval = g_strdup(yytext);
    return TOKEN_REGISTER;
}

[a-zA-Z]+[a-zA-Z0-9_]* {
    yylval.strval = g_strdup(yytext);
    return TOKEN_IDENTIFIER;
}

\[0x[A-Fa-f0-9_]+\] {
    yylval.strval = g_strdup(yytext);
    return TOKEN_MEMORY_ADDRESS;
}

":" {
    return TOKEN_COLON;
}

"=" {
    return TOKEN_EQUALS;
}

[0-9]+ {
    yylval.intval = atoi(yytext);
    return TOKEN_CONSTANT;
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
}
