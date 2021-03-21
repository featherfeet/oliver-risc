L [a-zA-Z_]
A [a-zA-Z_0-9]

%{
    #include <stdlib.h>
    #include <glib.h>
    #include "c_compiler_parser.h"
%}

%%

"int" {
    return INT;
}

{L}{A}* {
    return IDENTIFIER;
}

[0-9_]* {
    return I_CONSTANT;
}

"=" {
    return '=';
}

"(" {
    return '(';
}

")" {
    return ')';
}

"+" {
    return '+';
}

"-" {
    return '-';
}

"*" {
    return '*';
}

"/" {
    return '/';
}

"%" {
    return '%';
}

";" {
    return ';';
}

[ \t\n] {
}

%%

void flex_start_parsing_string(const char *str) {
    yy_scan_string(str);
}

void flex_finish_parsing_string() {
    yy_delete_buffer(YY_CURRENT_BUFFER);
    yylex_destroy();
}
