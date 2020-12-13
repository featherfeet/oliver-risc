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

#ifndef YY_YY_HOME_OLIVER_PROJECTS_FPGA_PROJECTS_CPU_TOOLCHAIN_BUILD_COMPILER_PARSER_HPP_INCLUDED
# define YY_YY_HOME_OLIVER_PROJECTS_FPGA_PROJECTS_CPU_TOOLCHAIN_BUILD_COMPILER_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 36 "compiler/parser.y" /* yacc.c:1921  */

    #include "ast.h"
    #include "astnode.h"
    #include "aststatementnode.h"
    #include "astrootnode.h"
    #include "astvariabledeclarationnode.h"
    #include "astexpressionnode.h"
    #include "astvariableassignmentnode.h"
    #include "astbufferwritenode.h"
    #include "asttermnode.h"
    #include "astbeginendblocknode.h"
    #include "astconditionnode.h"
    #include "astconditionalnode.h"
    #include "astprocedurecallnode.h"
    #include "astwhileloopnode.h"
    #include "astprocedurenode.h"
    #include "astbufferreadnode.h"
    #include "astinlineassemblynode.h"

#line 68 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/compiler_parser.hpp" /* yacc.c:1921  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TOKEN_VAR = 258,
    TOKEN_EQUALS = 259,
    TOKEN_IDENTIFIER = 260,
    TOKEN_CONSTANT = 261,
    TOKEN_SEMICOLON = 262,
    TOKEN_COLON_EQUALS = 263,
    TOKEN_PLUS = 264,
    TOKEN_MINUS = 265,
    TOKEN_IF = 266,
    TOKEN_THEN = 267,
    TOKEN_BEGIN = 268,
    TOKEN_END = 269,
    TOKEN_NOT_EQUALS = 270,
    TOKEN_LESS_THAN = 271,
    TOKEN_LESS_THAN_OR_EQUAL_TO = 272,
    TOKEN_GREATER_THAN = 273,
    TOKEN_GREATER_THAN_OR_EQUAL_TO = 274,
    TOKEN_CALL = 275,
    TOKEN_WHILE = 276,
    TOKEN_DO = 277,
    TOKEN_ASTERISK = 278,
    TOKEN_FORWARD_SLASH = 279,
    TOKEN_PERCENT = 280,
    TOKEN_PROCEDURE = 281,
    TOKEN_STRING_LITERAL = 282,
    TOKEN_LEFT_SQUARE_BRACKET = 283,
    TOKEN_RIGHT_SQUARE_BRACKET = 284,
    TOKEN_ISR = 285,
    TOKEN_ASM = 286,
    TOKEN_LEFT_PARENTHESIS = 287,
    TOKEN_RIGHT_PARENTHESIS = 288
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 90 "compiler/parser.y" /* yacc.c:1921  */

    int intval;
    char *strval;
    ASTStatementNode *statement_node;
    ASTVariableDeclarationNode *variable_declaration_node;
    ASTVariableAssignmentNode *variable_assignment_node;
    ASTBufferWriteNode *buffer_write_node;
    ASTExpressionNode *expression_node;
    ASTNode *term_node; // NOTE: Since a term can be either an ASTTermNode or an ASTBufferReadNode, we use the ASTNode type to store them.
    ASTConditionalNode *conditional_node;
    ASTConditionNode *condition_node;
    ASTBeginEndBlockNode *begin_end_block_node;
    ASTProcedureCallNode *procedure_call_node;
    ASTWhileLoopNode *while_loop_node;
    ASTProcedureNode *procedure_node;
    ASTInlineAssemblyNode *inline_assembly_node;

#line 132 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/compiler_parser.hpp" /* yacc.c:1921  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_HOME_OLIVER_PROJECTS_FPGA_PROJECTS_CPU_TOOLCHAIN_BUILD_COMPILER_PARSER_HPP_INCLUDED  */
