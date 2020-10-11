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
#line 1 "assembler/parser.y" /* yacc.c:337  */

    #include <stdio.h>
    #include <glib.h>
    #include "processor.h"

    // Forward declarations for functions provided by the Flex-generated lexer (or defined later in this program).
    int yylex(void);
    void yyerror(char *);

    // Variable used to store whether the program is parsing the .data: or the .code: section of the program. Currently not used by the parser.
    AssemblySection current_section = DATA_SECTION;

    // File handle for the binary output file of the assembler.
    FILE *output_file;

    // GLib hash table associating variable names to pointers to Variable structures (see assembler.h).
    GHashTable *variables_table;
    OPERAND_C_TYPE variables_address_counter = OPERAND_SIZE; // Track the current size of the .data section so that we know the memory offset to the variable declaration currently being parsed. Offset the addresses by OPERAND_SIZE because the first OPERAND_SIZE bytes of the binary are used to specify the length of the .data section.

    // GLib singly-linked list of pointers to Instruction structures (see assembler.h).
    GSList *instructions_table = NULL;

    // GLib hash table associating label names to buffers of OPERAND_SIZE bytes containing the address of the instruction that each label points to.
    GHashTable *labels_table;

    // Convert a string like "IP" or "A" to a Register number.
    Register stringToRegister(char *str) {
        if (strcmp(str, "IP") == 0) {
            return IP;
        }
        else if (strcmp(str, "A") == 0) {
            return A;
        }
        else if (strcmp(str, "B") == 0) {
            return B;
        }
        else if (strcmp(str, "C") == 0) {
            return C;
        }
        else if (strcmp(str, "D") == 0) {
            return D;
        }
        else if (strcmp(str, "E") == 0) {
            return E;
        }
        else if (strcmp(str, "F") == 0) {
            return F;
        }
        return G;
    }

    // Free all dynamically allocated memory in an Instruction structure, given a pointer to that structure. Only frees address operands (because register operands are freed immediately after use in the parser).
    void freeInstruction(Instruction *instruction) {
        switch (instruction->operation) {
            case OPERATION_LOAD:
                g_free(instruction->operand1.operand_address);
                break;
            case OPERATION_STORE:
                g_free(instruction->operand2.operand_address);
                break;
            case OPERATION_JMPL:
                g_free(instruction->operand1.operand_address);
                break;
            case OPERATION_JMPE:
                g_free(instruction->operand1.operand_address);
                break;
            case OPERATION_JMPG:
                g_free(instruction->operand1.operand_address);
                break;
            default:
                break;
        }

        g_free(instruction);
    }

    // Free all dynamically allocated memory in a Variable structure.
    void freeVariable(Variable *variable) {
        if (variable->variable_type == STRING_VARIABLE) {
            g_free(variable->variable_value.string);
        }
        g_free(variable);
    }

#line 155 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/assembler_parser.c" /* yacc.c:337  */
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
   by #include "assembler_parser.h".  */
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
    TOKEN_STRING_LITERAL = 293
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 125 "assembler/parser.y" /* yacc.c:352  */

    int intval;
    char *strval;

#line 242 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/assembler_parser.c" /* yacc.c:352  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_HOME_OLIVER_PROJECTS_FPGA_PROJECTS_CPU_TOOLCHAIN_BUILD_ASSEMBLER_PARSER_H_INCLUDED  */



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
#define YYLAST   85

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  4
/* YYNRULES -- Number of rules.  */
#define YYNRULES  38
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  86

#define YYUNDEFTOK  2
#define YYMAXUTOK   293

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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   133,   133,   135,   137,   143,   149,   163,   165,   169,
     187,   208,   215,   226,   237,   249,   260,   271,   283,   294,
     306,   318,   330,   342,   354,   366,   378,   390,   402,   414,
     426,   436,   444,   452,   460,   467,   474,   485,   495
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOKEN_NOP", "TOKEN_LOAD", "TOKEN_STORE",
  "TOKEN_ADD", "TOKEN_SUB", "TOKEN_OUT", "TOKEN_IN", "TOKEN_MOV",
  "TOKEN_CMP", "TOKEN_JMPL", "TOKEN_JMPE", "TOKEN_JMPG", "TOKEN_RST",
  "TOKEN_HALT", "TOKEN_DOT_DATA", "TOKEN_DOT_CODE", "TOKEN_IDENTIFIER",
  "TOKEN_REGISTER", "TOKEN_EQUALS", "TOKEN_CONSTANT", "TOKEN_EOL",
  "TOKEN_COLON", "TOKEN_ISR", "TOKEN_INT", "TOKEN_ENDINT",
  "TOKEN_MEMORY_ADDRESS", "TOKEN_RLOAD", "TOKEN_RSTORE", "TOKEN_CLOAD",
  "TOKEN_MULT", "TOKEN_DIV", "TOKEN_OR", "TOKEN_AND", "TOKEN_XOR",
  "TOKEN_NOT", "TOKEN_STRING_LITERAL", "$accept", "line",
  "variable_declaration", "instruction", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293
};
# endif

#define YYPACT_NINF -20

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-20)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -20,     0,   -20,   -20,    19,   -19,   -18,     1,     8,    23,
      24,    26,     3,    22,    30,   -20,   -20,    -3,    27,    21,
     -20,    31,    32,   -20,    33,    34,    35,    36,    38,    39,
      40,    41,    42,    43,    44,    45,    48,    20,    49,    50,
      51,    52,    53,    54,   -20,   -20,   -20,   -20,   -20,     2,
      55,    56,   -20,    57,    59,    60,    61,    62,    63,    64,
      65,   -20,   -20,   -20,   -20,   -20,   -20,   -20,   -20,   -20,
     -20,   -20,   -20,   -20,   -20,   -20,   -20,   -20,   -20,   -20,
     -20,   -20,   -20,   -20,   -20,   -20
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,    11,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    34,    35,     0,     0,     0,
       3,     0,     0,    38,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    31,    32,    33,     4,     5,     0,
       0,     0,    37,     0,     0,     0,     0,     0,     0,     0,
       0,    30,     7,     8,    12,    13,    15,    16,    19,    20,
      23,    25,    24,    26,     9,    10,     6,    36,    14,    17,
      18,    21,    22,    27,    28,    29
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -20,   -20,   -20,   -20
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,    33,    34
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       2,    37,    38,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      47,    39,    44,    20,    74,    21,    22,    23,    40,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    35,    66,
      75,    45,    49,    41,    42,    50,    43,    36,    67,    46,
      48,    51,    52,    53,    54,     0,    56,    55,    57,    58,
      59,    60,    61,     0,     0,    64,    62,    63,    65,    68,
      69,    70,    71,    72,    73,    77,     0,    78,    76,    79,
      80,    81,    82,    83,    84,    85
};

static const yytype_int8 yycheck[] =
{
       0,    20,    20,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      23,    20,    19,    23,    22,    25,    26,    27,    20,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    19,    19,
      38,    19,    21,    20,    20,    24,    20,    28,    28,    19,
      23,    20,    20,    20,    20,    -1,    20,    22,    20,    20,
      20,    20,    20,    -1,    -1,    20,    23,    23,    20,    20,
      20,    20,    20,    20,    20,    19,    -1,    20,    23,    20,
      20,    20,    20,    20,    20,    20
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    40,     0,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      23,    25,    26,    27,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    41,    42,    19,    28,    20,    20,    20,
      20,    20,    20,    20,    19,    19,    19,    23,    23,    21,
      24,    20,    20,    20,    20,    22,    20,    20,    20,    20,
      20,    20,    23,    23,    20,    20,    19,    28,    20,    20,
      20,    20,    20,    20,    22,    38,    23,    19,    20,    20,
      20,    20,    20,    20,    20,    20
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    39,    40,    40,    40,    40,    40,    40,    40,    41,
      41,    42,    42,    42,    42,    42,    42,    42,    42,    42,
      42,    42,    42,    42,    42,    42,    42,    42,    42,    42,
      42,    42,    42,    42,    42,    42,    42,    42,    42
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     3,     3,     4,     3,     3,     3,
       3,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     2,     2,     1,     1,     3,     2,     1
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
        case 4:
#line 137 "assembler/parser.y" /* yacc.c:1652  */
    {
        printf("Start .data section.\n");

        current_section = DATA_SECTION;
    }
#line 1390 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/assembler_parser.c" /* yacc.c:1652  */
    break;

  case 5:
#line 143 "assembler/parser.y" /* yacc.c:1652  */
    {
        printf("Start .code section.\n");

        current_section = CODE_SECTION;
    }
#line 1400 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/assembler_parser.c" /* yacc.c:1652  */
    break;

  case 6:
#line 149 "assembler/parser.y" /* yacc.c:1652  */
    {
        char *label = (yyvsp[-2].strval);

        printf("Label: %s\n", label);

        // Calculate the address of the instruction that this label should jump to, then save that address in a buffer of OPERAND_SIZE bytes.
        uint8_t *label_address_buffer = g_malloc0(OPERAND_SIZE);
        OPERAND_C_TYPE label_address = g_slist_length(instructions_table) * INSTRUCTION_SIZE;
        memcpy(label_address_buffer, &label_address, OPERAND_SIZE);

        // Store the address buffer in the labels_table hash table with the label name as the key.
        g_hash_table_insert(labels_table, label, label_address_buffer);
    }
#line 1418 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/assembler_parser.c" /* yacc.c:1652  */
    break;

  case 9:
#line 169 "assembler/parser.y" /* yacc.c:1652  */
    {
    char *variable_name = (yyvsp[-2].strval);
    OPERAND_C_TYPE variable_value = (yyvsp[0].intval);

    printf("Declaring integer variable \"%s\" as %d.\n", variable_name, variable_value);

    // Create a Variable structure representing the variable declaration.
    Variable *variable = g_new(Variable, 1);
    variable->variable_type = INTEGER_VARIABLE;
    OPERAND_C_TYPE variable_address = variables_address_counter;
    variables_address_counter += OPERAND_SIZE;
    // Create the Variable structure.
    memcpy(variable->variable_value.integer, &variable_value, OPERAND_SIZE);
    memcpy(variable->address, &variable_address, OPERAND_SIZE);

    // Save the Variable structure in the variables_table hash table.
    g_hash_table_insert(variables_table, variable_name, variable);
}
#line 1441 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/assembler_parser.c" /* yacc.c:1652  */
    break;

  case 10:
#line 187 "assembler/parser.y" /* yacc.c:1652  */
    {
                        char *variable_name = (yyvsp[-2].strval);
                        char *variable_value = (yyvsp[0].strval);

                        printf("Declaring string variable \"%s\" as \"%s\".\n", variable_name, variable_value);

                        // Create a Variable structure representing the variable declaration.
                        Variable *variable = g_new(Variable, 1);
                        variable->variable_type = STRING_VARIABLE;
                        OPERAND_C_TYPE variable_address = variables_address_counter;
                        variables_address_counter += strlen(variable_value);
                        // Create the Variable structure.
                        variable->variable_value.string = variable_value;
                        memcpy(variable->address, &variable_address, OPERAND_SIZE);

                        // Save the Variable structure in the variables_table hash table.
                        g_hash_table_insert(variables_table, variable_name, variable);
                    }
#line 1464 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/assembler_parser.c" /* yacc.c:1652  */
    break;

  case 11:
#line 208 "assembler/parser.y" /* yacc.c:1652  */
    {
        printf("Instruction: NOP\n");

        Instruction *instruction = g_new(Instruction, 1);
        instruction->operation = OPERATION_NOP;
        instructions_table = g_slist_append(instructions_table, instruction);
    }
#line 1476 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/assembler_parser.c" /* yacc.c:1652  */
    break;

  case 12:
#line 215 "assembler/parser.y" /* yacc.c:1652  */
    {
        printf("Instruction: LOAD (variable) %s,%s\n", (yyvsp[-1].strval), (yyvsp[0].strval));

        Instruction *instruction = g_new(Instruction, 1);
        instruction->operation = OPERATION_LOAD;
        instruction->operand1.operand_address = (yyvsp[-1].strval);
        instruction->operand2.operand_register = stringToRegister((yyvsp[0].strval));
        instructions_table = g_slist_append(instructions_table, instruction);

        g_free((yyvsp[0].strval));
    }
#line 1492 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/assembler_parser.c" /* yacc.c:1652  */
    break;

  case 13:
#line 226 "assembler/parser.y" /* yacc.c:1652  */
    {
        printf("Instruction: LOAD (address) %s,%s\n", (yyvsp[-1].strval), (yyvsp[0].strval));

        Instruction *instruction = g_new(Instruction, 1);
        instruction->operation = OPERATION_LOAD;
        instruction->operand1.operand_address = (yyvsp[-1].strval);
        instruction->operand2.operand_register = stringToRegister((yyvsp[0].strval));
        instructions_table = g_slist_append(instructions_table, instruction);

        g_free((yyvsp[0].strval));
    }
#line 1508 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/assembler_parser.c" /* yacc.c:1652  */
    break;

  case 14:
#line 237 "assembler/parser.y" /* yacc.c:1652  */
    {
        printf("Instruction: RLOAD %s,%s\n", (yyvsp[-1].strval), (yyvsp[0].strval));

        Instruction *instruction = g_new(Instruction, 1);
        instruction->operation = OPERATION_RLOAD;
        instruction->operand1.operand_register = stringToRegister((yyvsp[-1].strval));
        instruction->operand2.operand_register = stringToRegister((yyvsp[0].strval));
        instructions_table = g_slist_append(instructions_table, instruction);

        g_free((yyvsp[-1].strval));
        g_free((yyvsp[0].strval));
    }
#line 1525 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/assembler_parser.c" /* yacc.c:1652  */
    break;

  case 15:
#line 249 "assembler/parser.y" /* yacc.c:1652  */
    {
        printf("Instruction: STORE (variable) %s,%s\n", (yyvsp[-1].strval), (yyvsp[0].strval));

        Instruction *instruction = g_new(Instruction, 1);
        instruction->operation = OPERATION_STORE;
        instruction->operand1.operand_register = stringToRegister((yyvsp[-1].strval));
        instruction->operand2.operand_address = (yyvsp[0].strval);
        instructions_table = g_slist_append(instructions_table, instruction);

        g_free((yyvsp[-1].strval));
    }
#line 1541 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/assembler_parser.c" /* yacc.c:1652  */
    break;

  case 16:
#line 260 "assembler/parser.y" /* yacc.c:1652  */
    {
        printf("Instruction: STORE (address) %s,%s\n", (yyvsp[-1].strval), (yyvsp[0].strval));

        Instruction *instruction = g_new(Instruction, 1);
        instruction->operation = OPERATION_STORE;
        instruction->operand1.operand_register = stringToRegister((yyvsp[-1].strval));
        instruction->operand2.operand_address = (yyvsp[0].strval);
        instructions_table = g_slist_append(instructions_table, instruction);

        g_free((yyvsp[-1].strval));
    }
#line 1557 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/assembler_parser.c" /* yacc.c:1652  */
    break;

  case 17:
#line 271 "assembler/parser.y" /* yacc.c:1652  */
    {
        printf("Instruction: RSTORE %s,%s\n", (yyvsp[-1].strval), (yyvsp[0].strval));

        Instruction *instruction = g_new(Instruction, 1);
        instruction->operation = OPERATION_RSTORE;
        instruction->operand1.operand_register = stringToRegister((yyvsp[-1].strval));
        instruction->operand2.operand_register = stringToRegister((yyvsp[0].strval));
        instructions_table = g_slist_append(instructions_table, instruction);

        g_free((yyvsp[-1].strval));
        g_free((yyvsp[0].strval));
    }
#line 1574 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/assembler_parser.c" /* yacc.c:1652  */
    break;

  case 18:
#line 283 "assembler/parser.y" /* yacc.c:1652  */
    {
        printf("Instruction: CLOAD %d,%s\n", (yyvsp[-1].intval), (yyvsp[0].strval));

        Instruction *instruction = g_new(Instruction, 1);
        instruction->operation = OPERATION_CLOAD;
        instruction->operand1.operand_constant = (yyvsp[-1].intval);
        instruction->operand2.operand_register = stringToRegister((yyvsp[0].strval));
        instructions_table = g_slist_append(instructions_table, instruction);

        g_free((yyvsp[0].strval));
    }
#line 1590 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/assembler_parser.c" /* yacc.c:1652  */
    break;

  case 19:
#line 294 "assembler/parser.y" /* yacc.c:1652  */
    {
        printf("Instruction: ADD %s,%s\n", (yyvsp[-1].strval), (yyvsp[0].strval));

        Instruction *instruction = g_new(Instruction, 1);
        instruction->operation = OPERATION_ADD;
        instruction->operand1.operand_register = stringToRegister((yyvsp[-1].strval));
        instruction->operand2.operand_register = stringToRegister((yyvsp[0].strval));
        instructions_table = g_slist_append(instructions_table, instruction);

        g_free((yyvsp[-1].strval));
        g_free((yyvsp[0].strval));
    }
#line 1607 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/assembler_parser.c" /* yacc.c:1652  */
    break;

  case 20:
#line 306 "assembler/parser.y" /* yacc.c:1652  */
    {
        printf("Instruction: SUB %s,%s\n", (yyvsp[-1].strval), (yyvsp[0].strval));

        Instruction *instruction = g_new(Instruction, 1);
        instruction->operation = OPERATION_SUB;
        instruction->operand1.operand_register = stringToRegister((yyvsp[-1].strval));
        instruction->operand2.operand_register = stringToRegister((yyvsp[0].strval));
        instructions_table = g_slist_append(instructions_table, instruction);

        g_free((yyvsp[-1].strval));
        g_free((yyvsp[0].strval));
    }
#line 1624 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/assembler_parser.c" /* yacc.c:1652  */
    break;

  case 21:
#line 318 "assembler/parser.y" /* yacc.c:1652  */
    {
        printf("Instruction: MULT %s,%s\n", (yyvsp[-1].strval), (yyvsp[0].strval));

        Instruction *instruction = g_new(Instruction, 1);
        instruction->operation = OPERATION_MULT;
        instruction->operand1.operand_register = stringToRegister((yyvsp[-1].strval));
        instruction->operand2.operand_register = stringToRegister((yyvsp[0].strval));
        instructions_table = g_slist_append(instructions_table, instruction);

        g_free((yyvsp[-1].strval));
        g_free((yyvsp[0].strval));
    }
#line 1641 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/assembler_parser.c" /* yacc.c:1652  */
    break;

  case 22:
#line 330 "assembler/parser.y" /* yacc.c:1652  */
    {
        printf("Instruction: DIV %s,%s\n", (yyvsp[-1].strval), (yyvsp[0].strval));

        Instruction *instruction = g_new(Instruction, 1);
        instruction->operation = OPERATION_DIV;
        instruction->operand1.operand_register = stringToRegister((yyvsp[-1].strval));
        instruction->operand2.operand_register = stringToRegister((yyvsp[0].strval));
        instructions_table = g_slist_append(instructions_table, instruction);

        g_free((yyvsp[-1].strval));
        g_free((yyvsp[0].strval));
    }
#line 1658 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/assembler_parser.c" /* yacc.c:1652  */
    break;

  case 23:
#line 342 "assembler/parser.y" /* yacc.c:1652  */
    {
        printf("Instruction: OUT %s,%s\n", (yyvsp[-1].strval), (yyvsp[0].strval));

        Instruction *instruction = g_new(Instruction, 1);
        instruction->operation = OPERATION_OUT;
        instruction->operand1.operand_register = stringToRegister((yyvsp[-1].strval));
        instruction->operand2.operand_register = stringToRegister((yyvsp[0].strval));
        instructions_table = g_slist_append(instructions_table, instruction);

        g_free((yyvsp[-1].strval));
        g_free((yyvsp[0].strval));
    }
#line 1675 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/assembler_parser.c" /* yacc.c:1652  */
    break;

  case 24:
#line 354 "assembler/parser.y" /* yacc.c:1652  */
    {
        printf("Instruction: MOV %s,%s\n", (yyvsp[-1].strval), (yyvsp[0].strval));

        Instruction *instruction = g_new(Instruction, 1);
        instruction->operation = OPERATION_MOV;
        instruction->operand1.operand_register = stringToRegister((yyvsp[-1].strval));
        instruction->operand2.operand_register = stringToRegister((yyvsp[0].strval));
        instructions_table = g_slist_append(instructions_table, instruction);

        g_free((yyvsp[-1].strval));
        g_free((yyvsp[0].strval));
    }
#line 1692 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/assembler_parser.c" /* yacc.c:1652  */
    break;

  case 25:
#line 366 "assembler/parser.y" /* yacc.c:1652  */
    {
        printf("Instruction: IN %s,%s\n", (yyvsp[-1].strval), (yyvsp[0].strval));

        Instruction *instruction = g_new(Instruction, 1);
        instruction->operation = OPERATION_IN;
        instruction->operand1.operand_register = stringToRegister((yyvsp[-1].strval));
        instruction->operand2.operand_register = stringToRegister((yyvsp[0].strval));
        instructions_table = g_slist_append(instructions_table, instruction);

        g_free((yyvsp[-1].strval));
        g_free((yyvsp[0].strval));
    }
#line 1709 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/assembler_parser.c" /* yacc.c:1652  */
    break;

  case 26:
#line 378 "assembler/parser.y" /* yacc.c:1652  */
    {
        printf("Instruction: CMP %s,%s\n", (yyvsp[-1].strval), (yyvsp[0].strval));

        Instruction *instruction = g_new(Instruction, 1);
        instruction->operation = OPERATION_CMP;
        instruction->operand1.operand_register = stringToRegister((yyvsp[-1].strval));
        instruction->operand2.operand_register = stringToRegister((yyvsp[0].strval));
        instructions_table = g_slist_append(instructions_table, instruction);

        g_free((yyvsp[-1].strval));
        g_free((yyvsp[0].strval));
    }
#line 1726 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/assembler_parser.c" /* yacc.c:1652  */
    break;

  case 27:
#line 390 "assembler/parser.y" /* yacc.c:1652  */
    {
        printf("Instruction: OR %s,%s\n", (yyvsp[-1].strval), (yyvsp[0].strval));

        Instruction *instruction = g_new(Instruction, 1);
        instruction->operation = OPERATION_OR;
        instruction->operand1.operand_register = stringToRegister((yyvsp[-1].strval));
        instruction->operand2.operand_register = stringToRegister((yyvsp[0].strval));
        instructions_table = g_slist_append(instructions_table, instruction);

        g_free((yyvsp[-1].strval));
        g_free((yyvsp[0].strval));
    }
#line 1743 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/assembler_parser.c" /* yacc.c:1652  */
    break;

  case 28:
#line 402 "assembler/parser.y" /* yacc.c:1652  */
    {
        printf("Instruction: AND %s,%s\n", (yyvsp[-1].strval), (yyvsp[0].strval));

        Instruction *instruction = g_new(Instruction, 1);
        instruction->operation = OPERATION_AND;
        instruction->operand1.operand_register = stringToRegister((yyvsp[-1].strval));
        instruction->operand2.operand_register = stringToRegister((yyvsp[0].strval));
        instructions_table = g_slist_append(instructions_table, instruction);

        g_free((yyvsp[-1].strval));
        g_free((yyvsp[0].strval));
    }
#line 1760 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/assembler_parser.c" /* yacc.c:1652  */
    break;

  case 29:
#line 414 "assembler/parser.y" /* yacc.c:1652  */
    {
        printf("Instruction: XOR %s,%s\n", (yyvsp[-1].strval), (yyvsp[0].strval));

        Instruction *instruction = g_new(Instruction, 1);
        instruction->operation = OPERATION_XOR;
        instruction->operand1.operand_register = stringToRegister((yyvsp[-1].strval));
        instruction->operand2.operand_register = stringToRegister((yyvsp[0].strval));
        instructions_table = g_slist_append(instructions_table, instruction);

        g_free((yyvsp[-1].strval));
        g_free((yyvsp[0].strval));
    }
#line 1777 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/assembler_parser.c" /* yacc.c:1652  */
    break;

  case 30:
#line 426 "assembler/parser.y" /* yacc.c:1652  */
    {
        printf("Instruction: NOT %s\n", (yyvsp[0].strval));

        Instruction *instruction = g_new(Instruction, 1);
        instruction->operation = OPERATION_NOT;
        instruction->operand1.operand_register = stringToRegister((yyvsp[0].strval));
        instructions_table = g_slist_append(instructions_table, instruction);

        g_free((yyvsp[0].strval));
    }
#line 1792 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/assembler_parser.c" /* yacc.c:1652  */
    break;

  case 31:
#line 436 "assembler/parser.y" /* yacc.c:1652  */
    {
        printf("Instruction: JMPL %s\n", (yyvsp[0].strval));

        Instruction *instruction = g_new(Instruction, 1);
        instruction->operation = OPERATION_JMPL;
        instruction->operand1.operand_address = (yyvsp[0].strval);
        instructions_table = g_slist_append(instructions_table, instruction);
    }
#line 1805 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/assembler_parser.c" /* yacc.c:1652  */
    break;

  case 32:
#line 444 "assembler/parser.y" /* yacc.c:1652  */
    {
        printf("Instruction: JMPE %s\n", (yyvsp[0].strval));

        Instruction *instruction = g_new(Instruction, 1);
        instruction->operation = OPERATION_JMPE;
        instruction->operand1.operand_address = (yyvsp[0].strval);
        instructions_table = g_slist_append(instructions_table, instruction);
    }
#line 1818 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/assembler_parser.c" /* yacc.c:1652  */
    break;

  case 33:
#line 452 "assembler/parser.y" /* yacc.c:1652  */
    {
        printf("Instruction: JMPG %s\n", (yyvsp[0].strval));

        Instruction *instruction = g_new(Instruction, 1);
        instruction->operation = OPERATION_JMPG;
        instruction->operand1.operand_address = (yyvsp[0].strval);
        instructions_table = g_slist_append(instructions_table, instruction);
    }
#line 1831 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/assembler_parser.c" /* yacc.c:1652  */
    break;

  case 34:
#line 460 "assembler/parser.y" /* yacc.c:1652  */
    {
        printf("Instruction: RST\n");

        Instruction *instruction = g_new(Instruction, 1);
        instruction->operation = OPERATION_RST;
        instructions_table = g_slist_append(instructions_table, instruction);
    }
#line 1843 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/assembler_parser.c" /* yacc.c:1652  */
    break;

  case 35:
#line 467 "assembler/parser.y" /* yacc.c:1652  */
    {
        printf("Instruction: HALT\n");

        Instruction *instruction = g_new(Instruction, 1);
        instruction->operation = OPERATION_HALT;
        instructions_table = g_slist_append(instructions_table, instruction);
    }
#line 1855 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/assembler_parser.c" /* yacc.c:1652  */
    break;

  case 36:
#line 474 "assembler/parser.y" /* yacc.c:1652  */
    {
        printf("Instruction: ISR %s,%s\n", (yyvsp[-1].strval), (yyvsp[0].strval));

        Instruction *instruction = g_new(Instruction, 1);
        instruction->operation = OPERATION_ISR;
        instruction->operand1.operand_register = stringToRegister((yyvsp[-1].strval));
        instruction->operand2.operand_address = (yyvsp[0].strval);
        instructions_table = g_slist_append(instructions_table, instruction);

        g_free((yyvsp[-1].strval));
    }
#line 1871 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/assembler_parser.c" /* yacc.c:1652  */
    break;

  case 37:
#line 485 "assembler/parser.y" /* yacc.c:1652  */
    {
        printf("Instruction: INT %s\n", (yyvsp[0].strval));

        Instruction *instruction = g_new(Instruction, 1);
        instruction->operation = OPERATION_INT;
        instruction->operand1.operand_register = stringToRegister((yyvsp[0].strval));
        instructions_table = g_slist_append(instructions_table, instruction);

        g_free((yyvsp[0].strval));
    }
#line 1886 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/assembler_parser.c" /* yacc.c:1652  */
    break;

  case 38:
#line 495 "assembler/parser.y" /* yacc.c:1652  */
    {
        printf("Instruction: ENDINT\n");

        Instruction *instruction = g_new(Instruction, 1);
        instruction->operation = OPERATION_ENDINT;
        instructions_table = g_slist_append(instructions_table, instruction);
    }
#line 1898 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/assembler_parser.c" /* yacc.c:1652  */
    break;


#line 1902 "/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/assembler_parser.c" /* yacc.c:1652  */
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
#line 504 "assembler/parser.y" /* yacc.c:1918  */


// Forward declarations of functions in lexer.l that allow Flex to parse an in-memory buffer instead of a file handle.
void startParseString(const char *);
void endParseString(void);

int main(int argc, char *argv[]) {
    // Initialize the hash tables with strings as keys. Use g_free to automatically free the memory used by keys and values.
    variables_table = g_hash_table_new_full(g_str_hash, g_str_equal, (GDestroyNotify) g_free, (GDestroyNotify) freeVariable);
    labels_table = g_hash_table_new_full(g_str_hash, g_str_equal, (GDestroyNotify) g_free, (GDestroyNotify) g_free);

    // Buffer to store the input assembly code.
    char *input_buffer;

    // Show program usage message and exit.
    if (argc < 2) {
        printf("Usage: ./main program.asm [out.bin]\n");
        return 1;
    }

    // Read in .asm input file.
    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        fprintf(stderr, "Error: Failed to open file \"%s\" for reading.\n", argv[1]);
        return 1;
    }
    fseek(input_file, 0, SEEK_END);
    size_t input_file_size = (size_t) ftell(input_file);
    rewind(input_file);
    input_buffer = g_malloc0(input_file_size + 1);
    size_t bytes_read = fread(input_buffer, 1, input_file_size, input_file);
    input_buffer[bytes_read] = '\0';
    fclose(input_file);

    // If no output filename was provided, default to out.bin.
    if (argc == 2) {
        output_file = fopen("out.bin", "wb");
        if (output_file == NULL) {
            fprintf(stderr, "Error: Failed to open file \"out.bin\" for writing.\n");
            return 1;
        }
    }

    // If an output filename was provided, use it.
    else if (argc == 3) {
        output_file = fopen(argv[2], "wb");
        if (output_file == NULL) {
            fprintf(stderr, "Error: Failed to open file \"%s\" for writing.\n", argv[2]);
            return 1;
        }
    }

    // Run the Flex/Bison lexer and parser.
    startParseString(input_buffer);
    yyparse();
    endParseString();

    ///////////////////////////////////////////////////////////////////////////////////////
    // Take the variables_table hash table and convert it into the final binary format.
    ///////////////////////////////////////////////////////////////////////////////////////
    // Allocate memory to store the final binary format of the variables (.data) section of the output binary.
    size_t variables_binary_size = variables_address_counter - OPERAND_SIZE; // Subtract OPERAND_SIZE to compensate for the first OPERAND_SIZE bytes of the file being used to store the length of the .data section.
    void *variables_binary = g_malloc0(variables_binary_size);
    // Iterate over the variables_table hash table.
    GHashTableIter iter;
    g_hash_table_iter_init(&iter, variables_table);
    Variable *variable;
    while (g_hash_table_iter_next(&iter, NULL, (gpointer) &variable)) {
        if (variable->variable_type == INTEGER_VARIABLE) {
            // Convert the variable->address buffer in the Variable structure back into an integer.
            OPERAND_C_TYPE variable_address;
            memcpy(&variable_address, variable->address, OPERAND_SIZE);
            variable_address -= OPERAND_SIZE; // Compensate for the first OPERAND_SIZE bytes of the file being used to store the length of the .data section.
            // Copy the variable's value into the final binary format at the location specified by variable_address.
            memcpy(variables_binary + variable_address, variable->variable_value.integer, OPERAND_SIZE);
        }
        else if (variable->variable_type == STRING_VARIABLE) {
            // Convert the variable->address buffer in the Variable structure back into an integer.
            OPERAND_C_TYPE variable_address;
            memcpy(&variable_address, variable->address, OPERAND_SIZE);
            variable_address -= OPERAND_SIZE; // Compensate for the first OPERAND_SIZE bytes of the file being used to store the length of the .data section.
            // Copy the variable's value into the final binary format at the location specified by variable_address.
            memcpy(variables_binary + variable_address, variable->variable_value.string, strlen(variable->variable_value.string) + 1);
        }
    }

    ///////////////////////////////////////////////////////////////////////////////////////
    // Take the instructions_table hash table and convert it into the final binary format.
    ///////////////////////////////////////////////////////////////////////////////////////
    // Allocate memory to store the final binary format of the instructions (.code) section of the output binary.
    size_t instructions_binary_size = g_slist_length(instructions_table) * INSTRUCTION_SIZE;
    void *instructions_binary = g_malloc0(instructions_binary_size);
    // Iterate over the instructions_table singly-linked list.
    Instruction *instruction;
    // i counts how many instructions have already been processed by the loop. It is used to calculate where in instructions_binary to place the next instruction.
    int i = 0;
    for (GSList *iterator = instructions_table; iterator; iterator = iterator->next) {
        // Get the instruction.
        instruction = iterator->data;
        // Each instruction takes INSTRUCTION_SIZE bytes. Copy the operation to the binary.
        memcpy(instructions_binary + INSTRUCTION_SIZE * i, &instruction->operation, OPERATION_SIZE);
        // Work out whether the arguments should be registers, memory addresses, or some combination thereof.
        gboolean operand1_is_register = FALSE;
        gboolean operand1_is_address = FALSE;
        gboolean operand2_is_register = FALSE;
        gboolean operand2_is_address = FALSE;
        gboolean operand1_is_constant = FALSE;
        gboolean operand2_is_constant = FALSE;
        switch (instruction->operation) {
            case OPERATION_LOAD:
                operand1_is_address = TRUE;
                operand2_is_register = TRUE;
                break;
            case OPERATION_STORE:
                operand1_is_register = TRUE;
                operand2_is_address = TRUE;
                break;
            case OPERATION_ADD:
                operand1_is_register = TRUE;
                operand2_is_register = TRUE;
                break;
            case OPERATION_SUB:
                operand1_is_register = TRUE;
                operand2_is_register = TRUE;
                break;
            case OPERATION_OUT:
                operand1_is_register = TRUE;
                operand2_is_register = TRUE;
                break;
            case OPERATION_IN:
                operand1_is_register = TRUE;
                operand2_is_register = TRUE;
                break;
            case OPERATION_MOV:
                operand1_is_register = TRUE;
                operand2_is_register = TRUE;
                break;
            case OPERATION_CMP:
                operand1_is_register = TRUE;
                operand2_is_register = TRUE;
                break;
            case OPERATION_JMPL:
                operand1_is_address = TRUE;
                break;
            case OPERATION_JMPE:
                operand1_is_address = TRUE;
                break;
            case OPERATION_JMPG:
                operand1_is_address = TRUE;
                break;
            case OPERATION_ISR:
                operand1_is_register = TRUE;
                break;
            case OPERATION_INT:
                operand1_is_register = TRUE;
                break;
            case OPERATION_RLOAD:
                operand1_is_register = TRUE;
                operand2_is_register = TRUE;
                break;
            case OPERATION_RSTORE:
                operand1_is_register = TRUE;
                operand2_is_register = TRUE;
                break;
            case OPERATION_CLOAD:
                operand1_is_constant = TRUE;
                operand2_is_register = TRUE;
                break;
            case OPERATION_MULT:
                operand1_is_register = TRUE;
                operand2_is_register = TRUE;
                break;
            case OPERATION_DIV:
                operand1_is_register = TRUE;
                operand2_is_register = TRUE;
                break;
            default:
                break;
        }
        // Based on what the operands to this specific operation are supposed to be (registers or addresses), copy operands over to the final binary output.
        if (operand1_is_register) {
            memcpy(instructions_binary + INSTRUCTION_SIZE * i + OPERATION_SIZE, &instruction->operand1.operand_register, OPERAND_SIZE);
        }
        else if (operand1_is_constant) {
            memcpy(instructions_binary + INSTRUCTION_SIZE * i + OPERATION_SIZE, &instruction->operand1.operand_constant, OPERAND_SIZE);
        }
        // If the operation is a jump instruction, then look up the label being jumped to using the labels_table hash table. Retrieve the buffer storing the instruction address that the label should jump to.
        else if (instruction->operation == OPERATION_JMPL || instruction->operation == OPERATION_JMPE || instruction->operation == OPERATION_JMPG) {
            uint8_t *binary_instruction_index = g_hash_table_lookup(labels_table, instruction->operand1.operand_address);
            if (binary_instruction_index == NULL) {
                printf("\033[1;31mERROR: Unknown label `%s`.\033[0m\n", instruction->operand1.operand_address);
                return 1;
            }
            memcpy(instructions_binary + INSTRUCTION_SIZE * i + OPERATION_SIZE, binary_instruction_index, OPERAND_SIZE);
        }
        else if (operand1_is_address) {
            char *address_string = instruction->operand1.operand_address;
            // Two kinds of addresses are supported. Addresses can be variable names from the .data section like `var5_second` OR hex memory addresses like `[0xFF]`.
            // Addresses that start with [ must be hex memory addresses.
            if (address_string[0] == '[') {
                OPERAND_C_TYPE address = strtol(address_string + 1, NULL, 16);
                memcpy(instructions_binary + INSTRUCTION_SIZE * i + OPERATION_SIZE, &address, OPERAND_SIZE);
            }
            // Other addresses are variables.
            else {
                Variable *variable = g_hash_table_lookup(variables_table, instruction->operand1.operand_address);
                memcpy(instructions_binary + INSTRUCTION_SIZE * i + OPERATION_SIZE, variable->address, OPERAND_SIZE);
            }
        }
        if (operand2_is_register) {
            memcpy(instructions_binary + INSTRUCTION_SIZE * i + OPERATION_SIZE + OPERAND_SIZE, &instruction->operand2.operand_register, OPERAND_SIZE);
        }
        else if (operand2_is_constant) {
            memcpy(instructions_binary + INSTRUCTION_SIZE * i + OPERATION_SIZE + OPERAND_SIZE, &instruction->operand2.operand_constant, OPERAND_SIZE);
        }
        else if (operand2_is_address) {
            char *address_string = instruction->operand2.operand_address;
            // Two kinds of addresses are supported. Addresses can be variable names from the .data section like `var5_second` OR hex memory addresses like `[0xFF]`.
            // Addresses that start with [ must be hex memory addresses.
            if (address_string[0] == '[') {
                OPERAND_C_TYPE address = strtol(address_string + 1, NULL, 16);
                memcpy(instructions_binary + INSTRUCTION_SIZE * i + OPERATION_SIZE + OPERAND_SIZE, &address, OPERAND_SIZE);
            }
            // Other addresses are variables.
            else {
                Variable *variable = g_hash_table_lookup(variables_table, instruction->operand2.operand_address);
                memcpy(instructions_binary + INSTRUCTION_SIZE * i + OPERATION_SIZE + OPERAND_SIZE, variable->address, OPERAND_SIZE);
            }
        }
        else if (instruction->operation == OPERATION_ISR) {
            uint8_t *binary_instruction_index = g_hash_table_lookup(labels_table, instruction->operand2.operand_address);
            memcpy(instructions_binary + INSTRUCTION_SIZE * i + OPERATION_SIZE + OPERAND_SIZE, binary_instruction_index, OPERAND_SIZE);
        }
        i++;
    }

    // Write the length of the .data (variables) section to the first OPERAND_SIZE bytes of the output binary file.
    if (fwrite(&variables_binary_size, OPERAND_SIZE, 1, output_file) != 1) {
        printf("\033[1;31mERROR:\033[0m Could not write %d bytes of data to the file.\n", OPERAND_SIZE);
    }
    // Write the final binary format of the .data (variables) section to the output binary file.
    if (fwrite(variables_binary, 1, variables_binary_size, output_file) != variables_binary_size) {
        printf("\033[1;31mERROR:\033[0m Could not write %d bytes of data to the file.\n", variables_binary_size);
    }
    // Write the final binary format of the .code (instructions) section to the output binary file.
    if (fwrite(instructions_binary, INSTRUCTION_SIZE, g_slist_length(instructions_table), output_file) != g_slist_length(instructions_table)) {
        printf("\033[1;31mERROR:\033[0m Could not write %d bytes of data to the file.\n", g_slist_length(instructions_table) * INSTRUCTION_SIZE);
    }

    // Clean up resources.
    g_hash_table_destroy(variables_table);
    variables_table = NULL;
    g_slist_free_full(instructions_table, (GDestroyNotify) freeInstruction);
    instructions_table = NULL;
    g_hash_table_destroy(labels_table);
    labels_table = NULL;
    g_free(input_buffer);
    g_free(variables_binary);
    g_free(instructions_binary);
    fclose(output_file);

    return 0;
}

// Function to print out parser errors from Bison.
void yyerror(char *s) {
    fprintf(stderr, "Error: %s\n", s);
}
