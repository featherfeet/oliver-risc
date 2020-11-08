/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_HOME_OLIVER_PROJECTS_FPGA_PROJECTS_CPU_TOOLCHAIN_BUILD_ASSEMBLER_PARSER_H_INCLUDED
# define YY_YY_HOME_OLIVER_PROJECTS_FPGA_PROJECTS_CPU_TOOLCHAIN_BUILD_ASSEMBLER_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TOKEN_NOP = 258,
    TOKEN_LOAD = 259,
    TOKEN_STORE = 260,
    TOKEN_ADD = 261,
    TOKEN_SUB = 262,
    TOKEN_OUT = 263,
    TOKEN_IN = 264,
    TOKEN_MOV = 265,
    TOKEN_CMP = 266,
    TOKEN_JMPL = 267,
    TOKEN_JMPE = 268,
    TOKEN_JMPG = 269,
    TOKEN_RST = 270,
    TOKEN_HALT = 271,
    TOKEN_DOT_DATA = 272,
    TOKEN_DOT_CODE = 273,
    TOKEN_IDENTIFIER = 274,
    TOKEN_REGISTER = 275,
    TOKEN_EQUALS = 276,
    TOKEN_CONSTANT = 277,
    TOKEN_EOL = 278,
    TOKEN_COLON = 279,
    TOKEN_ISR = 280,
    TOKEN_INT = 281,
    TOKEN_ENDINT = 282,
    TOKEN_MEMORY_ADDRESS = 283,
    TOKEN_RLOAD = 284,
    TOKEN_RSTORE = 285,
    TOKEN_CLOAD = 286,
    TOKEN_MULT = 287,
    TOKEN_DIV = 288,
    TOKEN_OR = 289,
    TOKEN_AND = 290,
    TOKEN_XOR = 291,
    TOKEN_NOT = 292,
    TOKEN_STRING_LITERAL = 293,
    TOKEN_LEFT_SQUARE_BRACKET = 294,
    TOKEN_RIGHT_SQUARE_BRACKET = 295
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 134 "assembler/parser.y" /* yacc.c:1921  */

    int intval;
    char *strval;

#line 104 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/assembler_parser.h" /* yacc.c:1921  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_HOME_OLIVER_PROJECTS_FPGA_PROJECTS_CPU_TOOLCHAIN_BUILD_ASSEMBLER_PARSER_H_INCLUDED  */
