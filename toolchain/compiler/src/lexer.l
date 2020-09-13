%{
    extern "C" int yylex();
    #include "parser.hpp"

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

"VAR" {
    return TOKEN_VAR;
}

"CALL" {
    return TOKEN_CALL;
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
}
