/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.3.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "compiler/parser.y" /* yacc.c:337  */

    #include <iostream>
    #include <string>
    #include <sstream>
    #include <fstream>
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
    #include "asmgenerator.h"

    // #define YYDEBUG 1

    // Forward declarations for functions provided by the Flex-generated lexer (or defined later in this program).
    extern "C" {
        int yylex(void);
        void yyerror(char *);
    }

    // Start of the AST.
    ASTRootNode *ast;

#line 105 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/compiler_parser.cpp" /* yacc.c:337  */
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "compiler_parser.hpp".  */
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
#line 36 "compiler/parser.y" /* yacc.c:352  */

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

#line 157 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/compiler_parser.cpp" /* yacc.c:352  */

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
    TOKEN_RIGHT_SQUARE_BRACKET = 284
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 85 "compiler/parser.y" /* yacc.c:352  */

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

#line 216 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/compiler_parser.cpp" /* yacc.c:352  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_HOME_OLIVER_PROJECTS_FPGA_PROJECTS_CPU_TOOLCHAIN_BUILD_COMPILER_PARSER_HPP_INCLUDED  */



#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   130

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  30
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  15
/* YYNRULES -- Number of rules.  */
#define YYNRULES  54
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  111

#define YYUNDEFTOK  2
#define YYMAXUTOK   284

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   121,   121,   124,   129,   132,   135,   138,   141,   144,
     147,   152,   156,   160,   166,   172,   178,   183,   188,   192,
     197,   201,   204,   208,   212,   215,   218,   222,   225,   229,
     232,   236,   240,   244,   248,   252,   256,   260,   265,   270,
     275,   280,   285,   290,   297,   300,   305,   308,   311,   314,
     317,   320,   325,   331,   336
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOKEN_VAR", "TOKEN_EQUALS",
  "TOKEN_IDENTIFIER", "TOKEN_CONSTANT", "TOKEN_SEMICOLON",
  "TOKEN_COLON_EQUALS", "TOKEN_PLUS", "TOKEN_MINUS", "TOKEN_IF",
  "TOKEN_THEN", "TOKEN_BEGIN", "TOKEN_END", "TOKEN_NOT_EQUALS",
  "TOKEN_LESS_THAN", "TOKEN_LESS_THAN_OR_EQUAL_TO", "TOKEN_GREATER_THAN",
  "TOKEN_GREATER_THAN_OR_EQUAL_TO", "TOKEN_CALL", "TOKEN_WHILE",
  "TOKEN_DO", "TOKEN_ASTERISK", "TOKEN_FORWARD_SLASH", "TOKEN_PERCENT",
  "TOKEN_PROCEDURE", "TOKEN_STRING_LITERAL", "TOKEN_LEFT_SQUARE_BRACKET",
  "TOKEN_RIGHT_SQUARE_BRACKET", "$accept", "program", "statement",
  "variable_declaration", "variable_assignment", "buffer_write",
  "conditional", "begin_end_block", "statement_sequence", "term",
  "expression", "condition", "procedure_call", "while_loop", "procedure", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284
};
# endif

#define YYPACT_NINF -71

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-71)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -71,     7,   -71,     4,     8,   -71,     6,   -71,    16,   -71,
      38,    40,    53,    79,    80,    81,    88,    28,   -71,   -71,
      66,    31,   -71,    76,    92,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,     2,    87,    25,   -71,    45,   -71,    -2,     0,
     -71,   -71,   -71,   -71,   -71,    14,    32,    34,   -71,    89,
      89,    89,   -71,   -71,    86,    87,    36,    73,   -71,    75,
     -71,    87,    87,    87,    87,    87,    77,   -71,    78,   -71,
      85,   -71,    48,   -71,   -71,   -71,   -71,    71,    90,    51,
      58,    60,    72,    74,   -71,    41,    87,   -71,   -71,    91,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,     0,    44,     0,    44,     0,     3,
       0,     0,     0,     0,     0,     0,     0,    11,    44,    44,
       0,     0,    52,     0,     0,     4,     5,     6,     7,     8,
       9,    10,     0,    14,     0,    44,    20,    21,     0,     0,
      44,    44,    44,    44,    44,     0,     0,     0,    45,     0,
       0,     0,    12,    13,     0,    47,     0,    22,    24,    23,
      25,    46,    48,    49,    50,    51,    26,    27,    28,    29,
      30,    31,     0,    16,    53,    54,    44,     0,     0,     0,
       0,     0,     0,     0,    18,     0,    15,    38,    32,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    17,
      19,    39,    33,    40,    34,    41,    35,    42,    36,    43,
      37
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -71,   -71,   -70,   -71,   -71,   -71,   -71,   -37,   -71,   -71,
     -18,   102,   -71,   -71,   -71
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     9,    10,    11,    12,    13,    73,    85,    48,
      20,    21,    14,    15,    16
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      33,    34,    84,    57,    58,    59,    60,     2,    52,    17,
       3,    22,     4,    74,    75,   100,    18,    55,     5,    66,
      67,    24,    61,    62,    63,    64,    65,     6,     7,    53,
      36,    37,    32,     8,    38,    39,    19,    68,    69,    70,
      71,    77,    78,    49,     3,    25,     4,    26,    45,    46,
      47,     3,     5,     4,    54,    99,    89,    90,    86,     5,
      27,     6,     7,    91,    92,    93,    94,     8,     6,     7,
      35,    36,    37,    56,     8,    38,    39,    95,    96,    97,
      98,    40,    41,    42,    43,    44,    28,    29,    30,    45,
      46,    47,    36,    37,    76,    31,    38,    39,    50,    51,
      87,    79,    72,    80,     0,    81,    82,     0,     0,    23,
      45,    46,    47,    83,     0,     0,     0,     0,     0,    88,
     101,     0,   102,   103,   104,   105,   106,   107,   108,   109,
     110
};

static const yytype_int8 yycheck[] =
{
      18,    19,    72,     5,     6,     5,     6,     0,     6,     5,
       3,     5,     5,    50,    51,    85,     8,    35,    11,     5,
       6,     5,    40,    41,    42,    43,    44,    20,    21,    27,
       5,     6,     4,    26,     9,    10,    28,     5,     6,     5,
       6,     5,     6,    12,     3,     7,     5,     7,    23,    24,
      25,     3,    11,     5,    29,    14,     5,     6,    76,    11,
       7,    20,    21,     5,     6,     5,     6,    26,    20,    21,
       4,     5,     6,    28,    26,     9,    10,     5,     6,     5,
       6,    15,    16,    17,    18,    19,     7,     7,     7,    23,
      24,    25,     5,     6,     8,     7,     9,    10,    22,     7,
      29,    28,    13,    28,    -1,    28,    28,    -1,    -1,     7,
      23,    24,    25,    28,    -1,    -1,    -1,    -1,    -1,    29,
      29,    -1,    29,    29,    29,    29,    29,    29,    29,    29,
      29
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    31,     0,     3,     5,    11,    20,    21,    26,    32,
      33,    34,    35,    36,    42,    43,    44,     5,     8,    28,
      40,    41,     5,    41,     5,     7,     7,     7,     7,     7,
       7,     7,     4,    40,    40,     4,     5,     6,     9,    10,
      15,    16,    17,    18,    19,    23,    24,    25,    39,    12,
      22,     7,     6,    27,    29,    40,    28,     5,     6,     5,
       6,    40,    40,    40,    40,    40,     5,     6,     5,     6,
       5,     6,    13,    37,    37,    37,     8,     5,     6,    28,
      28,    28,    28,    28,    32,    38,    40,    29,    29,     5,
       6,     5,     6,     5,     6,     5,     6,     5,     6,    14,
      32,    29,    29,    29,    29,    29,    29,    29,    29,    29,
      29
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    30,    31,    31,    32,    32,    32,    32,    32,    32,
      32,    33,    33,    33,    34,    35,    36,    37,    38,    38,
      39,    39,    39,    39,    39,    39,    39,    39,    39,    39,
      39,    39,    39,    39,    39,    39,    39,    39,    39,    39,
      39,    39,    39,    39,    40,    40,    41,    41,    41,    41,
      41,    41,    42,    43,    44
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     4,     4,     3,     6,     4,     3,     1,     2,
       1,     1,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     4,     5,     5,     5,     5,     5,     4,     5,
       5,     5,     5,     5,     0,     2,     3,     3,     3,     3,
       3,     3,     2,     4,     4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 121 "compiler/parser.y" /* yacc.c:1652  */
    {
    ast = new ASTRootNode();
}
#line 1389 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/compiler_parser.cpp" /* yacc.c:1652  */
    break;

  case 3:
#line 124 "compiler/parser.y" /* yacc.c:1652  */
    {
           ast->addStatement((yyvsp[0].statement_node));
       }
#line 1397 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/compiler_parser.cpp" /* yacc.c:1652  */
    break;

  case 4:
#line 129 "compiler/parser.y" /* yacc.c:1652  */
    {
            (yyval.statement_node) = (yyvsp[-1].variable_declaration_node);
         }
#line 1405 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/compiler_parser.cpp" /* yacc.c:1652  */
    break;

  case 5:
#line 132 "compiler/parser.y" /* yacc.c:1652  */
    {
            (yyval.statement_node) = (yyvsp[-1].variable_assignment_node);
         }
#line 1413 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/compiler_parser.cpp" /* yacc.c:1652  */
    break;

  case 6:
#line 135 "compiler/parser.y" /* yacc.c:1652  */
    {
            (yyval.statement_node) = (yyvsp[-1].buffer_write_node);
         }
#line 1421 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/compiler_parser.cpp" /* yacc.c:1652  */
    break;

  case 7:
#line 138 "compiler/parser.y" /* yacc.c:1652  */
    {
            (yyval.statement_node) = (yyvsp[-1].conditional_node);
         }
#line 1429 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/compiler_parser.cpp" /* yacc.c:1652  */
    break;

  case 8:
#line 141 "compiler/parser.y" /* yacc.c:1652  */
    {
            (yyval.statement_node) = (yyvsp[-1].procedure_call_node);
         }
#line 1437 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/compiler_parser.cpp" /* yacc.c:1652  */
    break;

  case 9:
#line 144 "compiler/parser.y" /* yacc.c:1652  */
    {
            (yyval.statement_node) = (yyvsp[-1].while_loop_node);
         }
#line 1445 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/compiler_parser.cpp" /* yacc.c:1652  */
    break;

  case 10:
#line 147 "compiler/parser.y" /* yacc.c:1652  */
    {
            (yyval.statement_node) = (yyvsp[-1].procedure_node);
         }
#line 1453 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/compiler_parser.cpp" /* yacc.c:1652  */
    break;

  case 11:
#line 152 "compiler/parser.y" /* yacc.c:1652  */
    {
                        (yyval.variable_declaration_node) = new ASTVariableDeclarationNode((yyvsp[0].strval));
                        free((yyvsp[0].strval));
                    }
#line 1462 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/compiler_parser.cpp" /* yacc.c:1652  */
    break;

  case 12:
#line 156 "compiler/parser.y" /* yacc.c:1652  */
    {
                        (yyval.variable_declaration_node) = new ASTVariableDeclarationNode((yyvsp[-2].strval), (yyvsp[0].intval));
                        free((yyvsp[-2].strval));
                    }
#line 1471 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/compiler_parser.cpp" /* yacc.c:1652  */
    break;

  case 13:
#line 160 "compiler/parser.y" /* yacc.c:1652  */
    {
                        (yyval.variable_declaration_node) = new ASTVariableDeclarationNode((yyvsp[-2].strval), (yyvsp[0].strval));
                        free((yyvsp[0].strval));
                    }
#line 1480 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/compiler_parser.cpp" /* yacc.c:1652  */
    break;

  case 14:
#line 166 "compiler/parser.y" /* yacc.c:1652  */
    {
                   (yyval.variable_assignment_node) = new ASTVariableAssignmentNode((yyvsp[-2].strval), (yyvsp[0].expression_node));
                   free((yyvsp[-2].strval));
}
#line 1489 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/compiler_parser.cpp" /* yacc.c:1652  */
    break;

  case 15:
#line 172 "compiler/parser.y" /* yacc.c:1652  */
    {
            (yyval.buffer_write_node) = new ASTBufferWriteNode((yyvsp[-5].strval), (yyvsp[-3].expression_node), (yyvsp[0].expression_node));
            free((yyvsp[-5].strval));
}
#line 1498 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/compiler_parser.cpp" /* yacc.c:1652  */
    break;

  case 16:
#line 178 "compiler/parser.y" /* yacc.c:1652  */
    {
    (yyval.conditional_node) = new ASTConditionalNode((yyvsp[-2].condition_node), (yyvsp[0].begin_end_block_node));
}
#line 1506 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/compiler_parser.cpp" /* yacc.c:1652  */
    break;

  case 17:
#line 183 "compiler/parser.y" /* yacc.c:1652  */
    {
    (yyval.begin_end_block_node) = (yyvsp[-1].begin_end_block_node);
}
#line 1514 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/compiler_parser.cpp" /* yacc.c:1652  */
    break;

  case 18:
#line 188 "compiler/parser.y" /* yacc.c:1652  */
    {
    (yyval.begin_end_block_node) = new ASTBeginEndBlockNode();
    (yyval.begin_end_block_node)->addStatement((yyvsp[0].statement_node));
}
#line 1523 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/compiler_parser.cpp" /* yacc.c:1652  */
    break;

  case 19:
#line 192 "compiler/parser.y" /* yacc.c:1652  */
    {
                      (yyvsp[-1].begin_end_block_node)->addStatement((yyvsp[0].statement_node));
                  }
#line 1531 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/compiler_parser.cpp" /* yacc.c:1652  */
    break;

  case 20:
#line 197 "compiler/parser.y" /* yacc.c:1652  */
    {
    (yyval.term_node) = new ASTTermNode(ADDITION, (yyvsp[0].strval));
    free((yyvsp[0].strval));
}
#line 1540 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/compiler_parser.cpp" /* yacc.c:1652  */
    break;

  case 21:
#line 201 "compiler/parser.y" /* yacc.c:1652  */
    {
        (yyval.term_node) = new ASTTermNode(ADDITION, (yyvsp[0].intval));
    }
#line 1548 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/compiler_parser.cpp" /* yacc.c:1652  */
    break;

  case 22:
#line 204 "compiler/parser.y" /* yacc.c:1652  */
    {
        (yyval.term_node) = new ASTTermNode(ADDITION, (yyvsp[0].strval));
        free((yyvsp[0].strval));
    }
#line 1557 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/compiler_parser.cpp" /* yacc.c:1652  */
    break;

  case 23:
#line 208 "compiler/parser.y" /* yacc.c:1652  */
    {
        (yyval.term_node) = new ASTTermNode(SUBTRACTION, (yyvsp[0].strval));
        free((yyvsp[0].strval));
    }
#line 1566 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/compiler_parser.cpp" /* yacc.c:1652  */
    break;

  case 24:
#line 212 "compiler/parser.y" /* yacc.c:1652  */
    {
        (yyval.term_node) = new ASTTermNode(ADDITION, (yyvsp[0].intval));
    }
#line 1574 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/compiler_parser.cpp" /* yacc.c:1652  */
    break;

  case 25:
#line 215 "compiler/parser.y" /* yacc.c:1652  */
    {
        (yyval.term_node) = new ASTTermNode(SUBTRACTION, (yyvsp[0].intval));
    }
#line 1582 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/compiler_parser.cpp" /* yacc.c:1652  */
    break;

  case 26:
#line 218 "compiler/parser.y" /* yacc.c:1652  */
    {
        (yyval.term_node) = new ASTTermNode(MULTIPLICATION, (yyvsp[0].strval));
        free((yyvsp[0].strval));
    }
#line 1591 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/compiler_parser.cpp" /* yacc.c:1652  */
    break;

  case 27:
#line 222 "compiler/parser.y" /* yacc.c:1652  */
    {
        (yyval.term_node) = new ASTTermNode(MULTIPLICATION, (yyvsp[0].intval));
    }
#line 1599 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/compiler_parser.cpp" /* yacc.c:1652  */
    break;

  case 28:
#line 225 "compiler/parser.y" /* yacc.c:1652  */
    {
        (yyval.term_node) = new ASTTermNode(DIVISION, (yyvsp[0].strval));
        free((yyvsp[0].strval));
    }
#line 1608 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/compiler_parser.cpp" /* yacc.c:1652  */
    break;

  case 29:
#line 229 "compiler/parser.y" /* yacc.c:1652  */
    {
        (yyval.term_node) = new ASTTermNode(DIVISION, (yyvsp[0].intval));
    }
#line 1616 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/compiler_parser.cpp" /* yacc.c:1652  */
    break;

  case 30:
#line 232 "compiler/parser.y" /* yacc.c:1652  */
    {
        (yyval.term_node) = new ASTTermNode(MODULUS, (yyvsp[0].strval));
        free((yyvsp[0].strval));
    }
#line 1625 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/compiler_parser.cpp" /* yacc.c:1652  */
    break;

  case 31:
#line 236 "compiler/parser.y" /* yacc.c:1652  */
    {
        (yyval.term_node) = new ASTTermNode(MODULUS, (yyvsp[0].intval));
    }
#line 1633 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/compiler_parser.cpp" /* yacc.c:1652  */
    break;

  case 32:
#line 240 "compiler/parser.y" /* yacc.c:1652  */
    {
        (yyval.term_node) = new ASTBufferReadNode(ADDITION, (yyvsp[-3].strval), (yyvsp[-1].intval));
        free((yyvsp[-3].strval));
    }
#line 1642 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/compiler_parser.cpp" /* yacc.c:1652  */
    break;

  case 33:
#line 244 "compiler/parser.y" /* yacc.c:1652  */
    {
        (yyval.term_node) = new ASTBufferReadNode(ADDITION, (yyvsp[-3].strval), (yyvsp[-1].intval));
        free((yyvsp[-3].strval));
    }
#line 1651 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/compiler_parser.cpp" /* yacc.c:1652  */
    break;

  case 34:
#line 248 "compiler/parser.y" /* yacc.c:1652  */
    {
        (yyval.term_node) = new ASTBufferReadNode(SUBTRACTION, (yyvsp[-3].strval), (yyvsp[-1].intval));
        free((yyvsp[-3].strval));
    }
#line 1660 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/compiler_parser.cpp" /* yacc.c:1652  */
    break;

  case 35:
#line 252 "compiler/parser.y" /* yacc.c:1652  */
    {
        (yyval.term_node) = new ASTBufferReadNode(MULTIPLICATION, (yyvsp[-3].strval), (yyvsp[-1].intval));
        free((yyvsp[-3].strval));
    }
#line 1669 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/compiler_parser.cpp" /* yacc.c:1652  */
    break;

  case 36:
#line 256 "compiler/parser.y" /* yacc.c:1652  */
    {
        (yyval.term_node) = new ASTBufferReadNode(DIVISION, (yyvsp[-3].strval), (yyvsp[-1].intval));
        free((yyvsp[-3].strval));
    }
#line 1678 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/compiler_parser.cpp" /* yacc.c:1652  */
    break;

  case 37:
#line 260 "compiler/parser.y" /* yacc.c:1652  */
    {
        (yyval.term_node) = new ASTBufferReadNode(MODULUS, (yyvsp[-3].strval), (yyvsp[-1].intval));
        free((yyvsp[-3].strval));
    }
#line 1687 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/compiler_parser.cpp" /* yacc.c:1652  */
    break;

  case 38:
#line 265 "compiler/parser.y" /* yacc.c:1652  */
    {
        (yyval.term_node) = new ASTBufferReadNode(ADDITION, (yyvsp[-3].strval), (yyvsp[-1].strval));
        free((yyvsp[-3].strval));
        free((yyvsp[-1].strval));
    }
#line 1697 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/compiler_parser.cpp" /* yacc.c:1652  */
    break;

  case 39:
#line 270 "compiler/parser.y" /* yacc.c:1652  */
    {
        (yyval.term_node) = new ASTBufferReadNode(ADDITION, (yyvsp[-3].strval), (yyvsp[-1].strval));
        free((yyvsp[-3].strval));
        free((yyvsp[-1].strval));
    }
#line 1707 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/compiler_parser.cpp" /* yacc.c:1652  */
    break;

  case 40:
#line 275 "compiler/parser.y" /* yacc.c:1652  */
    {
        (yyval.term_node) = new ASTBufferReadNode(SUBTRACTION, (yyvsp[-3].strval), (yyvsp[-1].strval));
        free((yyvsp[-3].strval));
        free((yyvsp[-1].strval));
    }
#line 1717 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/compiler_parser.cpp" /* yacc.c:1652  */
    break;

  case 41:
#line 280 "compiler/parser.y" /* yacc.c:1652  */
    {
        (yyval.term_node) = new ASTBufferReadNode(MULTIPLICATION, (yyvsp[-3].strval), (yyvsp[-1].strval));
        free((yyvsp[-3].strval));
        free((yyvsp[-1].strval));
    }
#line 1727 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/compiler_parser.cpp" /* yacc.c:1652  */
    break;

  case 42:
#line 285 "compiler/parser.y" /* yacc.c:1652  */
    {
        (yyval.term_node) = new ASTBufferReadNode(DIVISION, (yyvsp[-3].strval), (yyvsp[-1].strval));
        free((yyvsp[-3].strval));
        free((yyvsp[-1].strval));
    }
#line 1737 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/compiler_parser.cpp" /* yacc.c:1652  */
    break;

  case 43:
#line 290 "compiler/parser.y" /* yacc.c:1652  */
    {
        (yyval.term_node) = new ASTBufferReadNode(MODULUS, (yyvsp[-3].strval), (yyvsp[-1].strval));
        free((yyvsp[-3].strval));
        free((yyvsp[-1].strval));
    }
#line 1747 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/compiler_parser.cpp" /* yacc.c:1652  */
    break;

  case 44:
#line 297 "compiler/parser.y" /* yacc.c:1652  */
    {
    (yyval.expression_node) = new ASTExpressionNode();
}
#line 1755 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/compiler_parser.cpp" /* yacc.c:1652  */
    break;

  case 45:
#line 300 "compiler/parser.y" /* yacc.c:1652  */
    {
              (yyvsp[-1].expression_node)->addTerm((yyvsp[0].term_node));
          }
#line 1763 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/compiler_parser.cpp" /* yacc.c:1652  */
    break;

  case 46:
#line 305 "compiler/parser.y" /* yacc.c:1652  */
    {
    (yyval.condition_node) = new ASTConditionNode(NOT_EQUALS, (yyvsp[-2].expression_node), (yyvsp[0].expression_node));
}
#line 1771 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/compiler_parser.cpp" /* yacc.c:1652  */
    break;

  case 47:
#line 308 "compiler/parser.y" /* yacc.c:1652  */
    {
             (yyval.condition_node) = new ASTConditionNode(EQUALS, (yyvsp[-2].expression_node), (yyvsp[0].expression_node));
         }
#line 1779 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/compiler_parser.cpp" /* yacc.c:1652  */
    break;

  case 48:
#line 311 "compiler/parser.y" /* yacc.c:1652  */
    {
             (yyval.condition_node) = new ASTConditionNode(LESS_THAN, (yyvsp[-2].expression_node), (yyvsp[0].expression_node));
         }
#line 1787 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/compiler_parser.cpp" /* yacc.c:1652  */
    break;

  case 49:
#line 314 "compiler/parser.y" /* yacc.c:1652  */
    {
             (yyval.condition_node) = new ASTConditionNode(LESS_THAN_OR_EQUAL_TO, (yyvsp[-2].expression_node), (yyvsp[0].expression_node));
         }
#line 1795 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/compiler_parser.cpp" /* yacc.c:1652  */
    break;

  case 50:
#line 317 "compiler/parser.y" /* yacc.c:1652  */
    {
             (yyval.condition_node) = new ASTConditionNode(GREATER_THAN, (yyvsp[-2].expression_node), (yyvsp[0].expression_node));
         }
#line 1803 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/compiler_parser.cpp" /* yacc.c:1652  */
    break;

  case 51:
#line 320 "compiler/parser.y" /* yacc.c:1652  */
    {
             (yyval.condition_node) = new ASTConditionNode(GREATER_THAN_OR_EQUAL_TO, (yyvsp[-2].expression_node), (yyvsp[0].expression_node));
         }
#line 1811 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/compiler_parser.cpp" /* yacc.c:1652  */
    break;

  case 52:
#line 325 "compiler/parser.y" /* yacc.c:1652  */
    {
    (yyval.procedure_call_node) = new ASTProcedureCallNode((yyvsp[0].strval));
    free((yyvsp[0].strval));
}
#line 1820 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/compiler_parser.cpp" /* yacc.c:1652  */
    break;

  case 53:
#line 331 "compiler/parser.y" /* yacc.c:1652  */
    {
    (yyval.while_loop_node) = new ASTWhileLoopNode((yyvsp[-2].condition_node), (yyvsp[0].begin_end_block_node));
}
#line 1828 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/compiler_parser.cpp" /* yacc.c:1652  */
    break;

  case 54:
#line 336 "compiler/parser.y" /* yacc.c:1652  */
    {
    (yyval.procedure_node) = new ASTProcedureNode((yyvsp[-2].strval), (yyvsp[0].begin_end_block_node));
    free((yyvsp[-2].strval));
}
#line 1837 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/compiler_parser.cpp" /* yacc.c:1652  */
    break;


#line 1841 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/compiler_parser.cpp" /* yacc.c:1652  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 342 "compiler/parser.y" /* yacc.c:1918  */


// Forward declarations of functions in lexer.l that allow Flex to parse an in-memory buffer instead of a file handle.
void startParseString(const char *);
void endParseString(void);

int main(int argc, char *argv[]) {
    // yydebug = 1;

    if (argc < 2) {
        std::cout << "Usage: ./main program.pl0 [output.asm]" << std::endl;
        return 1;
    }

    const char *input_filename = argv[1];
    const char *output_filename = "output.asm";
    if (argc == 3) {
        output_filename = argv[2];
    }

    std::ifstream input_file(input_filename);
    std::stringstream input_file_stringstream;
    input_file_stringstream << input_file.rdbuf();
    std::string input_buffer = input_file_stringstream.str();
    input_file.close();

    startParseString(input_buffer.c_str());
    yyparse();
    endParseString();

    // Uncomment to display Graphviz-based AST visualization.
    ast->showGraph();

    AssemblyGenerator asmGenerator;

    std::ofstream output_file(output_filename, std::ofstream::out);
    output_file << asmGenerator.getGeneratedAssembly(ast);
    output_file.close();

    delete ast;

    return 0;
}

// Function to print out parser errors from Bison.
void yyerror(char *s) {
    std::cerr << "Error: " << s << std::endl;
}
