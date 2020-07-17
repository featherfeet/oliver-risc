%{
    #include <stdlib.h>
    #include <glib.h>
    #include "parser.tab.h"
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

"=" {
    return TOKEN_EQUALS;
}

[a-zA-Z]+[a-zA-Z0-9_]* {
    yylval.strval = g_strdup(yytext);
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
