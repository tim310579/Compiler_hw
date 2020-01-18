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


#include <stdio.h>
#include <stdlib.h>
#include "symtab.h"
#include "gencode.h"
#include <string.h>

extern FILE* outfp;
extern FILE *yyin;
extern char *yytext;
extern int yylineno;
extern char buf[256];
//extern void set_input;
/*
 * grammar.y
 *
 * Pascal grammar in Yacc format, based originally on BNF given
 * in "Standard Pascal -- User Reference Manual", by Doug Cooper.
 * This in turn is the BNF given by the ANSI and ISO Pascal standards,
 * and so, is PUBLIC DOMAIN. The grammar is for ISO Level 0 Pascal.
 * The grammar has been massaged somewhat to make it LALR, and added
 * the following extensions.
 *
 * constant expressions
 * otherwise statement in a case
 * productions to correctly match else's with if's
 * beginnings of a separate compilation facility
 */
int yylex();
int yyerror(char *);

SymbolTable* symbol_table;

int pre_rec = -1;
int loop_cnt = 0;
int nest_loop = 0;
int inexp = 0;
int infunc_exp = 0;
int exe_space = 4;
int cmp_cnt = 0;
int tmp_space = 0;
int tmp_spaceL = 0;
int fl_cnt = 0;
unsigned int ieee[100000] = {0};
int ax = 0;
int has_ret = 0;
int para_cnt = 0;
char para[32];
float parav[32];
char paras[32][192];
char LCSS[32][192];
int tail_cnt = 0;
int tail[32] = {0};
int str_cnt = 0;
int if_cnt = 0;
int nest_if = 0;
char state = 'y';	//y -> can do statement, n-> not..
int array_space = 0;
float array_all[100000] = {0};

int add_sub = -1;
int mul_div = -1;
int op_type = 0;
int cmp = -1;
char fileName[256];


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
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    DIGSEQ = 258,
    AND = 259,
    ARRAY = 260,
    ASSIGNMENT = 261,
    CASE = 262,
    CHARACTER_STRING = 263,
    COLON = 264,
    COMMA = 265,
    CONST = 266,
    DIV = 267,
    DO = 268,
    DOT = 269,
    DOTDOT = 270,
    DOWNTO = 271,
    ELSE = 272,
    END = 273,
    EQUAL = 274,
    EXTERNAL = 275,
    FOR = 276,
    FORWARD = 277,
    FUNCTION = 278,
    GE = 279,
    GOTO = 280,
    GT = 281,
    IDENTIFIER = 282,
    IF = 283,
    IN = 284,
    LABEL = 285,
    LBRAC = 286,
    LE = 287,
    LPAREN = 288,
    LT = 289,
    MINUS = 290,
    MOD = 291,
    NIL = 292,
    NOT = 293,
    notEQUAL = 294,
    OF = 295,
    OR = 296,
    OTHERWISE = 297,
    PACKED = 298,
    PBEGIN = 299,
    PFILE = 300,
    PLUS = 301,
    PROCEDURE = 302,
    PROGRAM = 303,
    RBRAC = 304,
    RECORD = 305,
    REPEAT = 306,
    RPAREN = 307,
    SEMICOLON = 308,
    SET = 309,
    SLASH = 310,
    STAR = 311,
    STARSTAR = 312,
    THEN = 313,
    TO = 314,
    TYPE = 315,
    UNTIL = 316,
    UPARROW = 317,
    VAR = 318,
    WHILE = 319,
    WITH = 320,
    STRING = 321,
    WRONGIDEN = 322,
    ERROR = 323,
    INTEGER = 324,
    REAL = 325,
    STRINGCONST = 326,
    REALNUMBER = 327
  };
#endif
/* Tokens.  */
#define DIGSEQ 258
#define AND 259
#define ARRAY 260
#define ASSIGNMENT 261
#define CASE 262
#define CHARACTER_STRING 263
#define COLON 264
#define COMMA 265
#define CONST 266
#define DIV 267
#define DO 268
#define DOT 269
#define DOTDOT 270
#define DOWNTO 271
#define ELSE 272
#define END 273
#define EQUAL 274
#define EXTERNAL 275
#define FOR 276
#define FORWARD 277
#define FUNCTION 278
#define GE 279
#define GOTO 280
#define GT 281
#define IDENTIFIER 282
#define IF 283
#define IN 284
#define LABEL 285
#define LBRAC 286
#define LE 287
#define LPAREN 288
#define LT 289
#define MINUS 290
#define MOD 291
#define NIL 292
#define NOT 293
#define notEQUAL 294
#define OF 295
#define OR 296
#define OTHERWISE 297
#define PACKED 298
#define PBEGIN 299
#define PFILE 300
#define PLUS 301
#define PROCEDURE 302
#define PROGRAM 303
#define RBRAC 304
#define RECORD 305
#define REPEAT 306
#define RPAREN 307
#define SEMICOLON 308
#define SET 309
#define SLASH 310
#define STAR 311
#define STARSTAR 312
#define THEN 313
#define TO 314
#define TYPE 315
#define UNTIL 316
#define UPARROW 317
#define VAR 318
#define WHILE 319
#define WITH 320
#define STRING 321
#define WRONGIDEN 322
#define ERROR 323
#define INTEGER 324
#define REAL 325
#define STRINGCONST 326
#define REALNUMBER 327

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{


	int num;
	double dnum;
	char* str;
	struct Value* value;
	struct Type* type;
	struct TableEntry* tableentry;
	
	


};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   163

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  73
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  63
/* YYNRULES -- Number of rules.  */
#define YYNRULES  102
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  167

#define YYUNDEFTOK  2
#define YYMAXUTOK   327

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    99,    99,   106,   111,   117,   128,   136,    99,   144,
     146,   148,   155,   159,   163,   169,   169,   181,   185,   186,
     200,   201,   202,   207,   208,   212,   218,   212,   227,   234,
     227,   250,   261,   250,   270,   270,   280,   283,   287,   291,
     287,   297,   298,   301,   301,   314,   315,   318,   319,   319,
     323,   387,   388,   389,   389,   393,   396,   389,   405,   409,
     405,   418,   421,   454,   454,   470,   473,   479,   479,   513,
     541,   565,   566,   566,   572,   572,   580,   581,   588,   589,
     589,   599,   603,   603,   612,   690,   690,   690,   711,   735,
     737,   737,   740,   749,   753,   759,   763,   770,   771,   772,
     773,   774,   775
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DIGSEQ", "AND", "ARRAY", "ASSIGNMENT",
  "CASE", "CHARACTER_STRING", "COLON", "COMMA", "CONST", "DIV", "DO",
  "DOT", "DOTDOT", "DOWNTO", "ELSE", "END", "EQUAL", "EXTERNAL", "FOR",
  "FORWARD", "FUNCTION", "GE", "GOTO", "GT", "IDENTIFIER", "IF", "IN",
  "LABEL", "LBRAC", "LE", "LPAREN", "LT", "MINUS", "MOD", "NIL", "NOT",
  "notEQUAL", "OF", "OR", "OTHERWISE", "PACKED", "PBEGIN", "PFILE", "PLUS",
  "PROCEDURE", "PROGRAM", "RBRAC", "RECORD", "REPEAT", "RPAREN",
  "SEMICOLON", "SET", "SLASH", "STAR", "STARSTAR", "THEN", "TO", "TYPE",
  "UNTIL", "UPARROW", "VAR", "WHILE", "WITH", "STRING", "WRONGIDEN",
  "ERROR", "INTEGER", "REAL", "STRINGCONST", "REALNUMBER", "$accept",
  "prog", "$@1", "$@2", "$@3", "$@4", "$@5", "$@6", "num", "id",
  "identifier_list", "declarations", "$@7", "type", "standard_type",
  "subprogram_declarations", "subprogram_declaration", "$@8", "$@9",
  "subprogram_head", "$@10", "$@11", "$@12", "$@13", "arguments", "$@14",
  "parameter_list", "$@15", "$@16", "optional_var", "compound_statement",
  "$@17", "optional_statements", "statement_list", "$@18", "statement",
  "$@19", "$@20", "$@21", "$@22", "$@23", "$@24", "variable", "tail",
  "$@25", "procedure_statement", "$@26", "expression_list", "expression",
  "$@27", "$@28", "boolexpression", "simple_expression", "$@29", "term",
  "$@30", "factor", "$@31", "$@32", "$@33", "addop", "mulop", "relop", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327
};
# endif

#define YYPACT_NINF -113

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-113)))

#define YYTABLE_NINF -86

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -17,     8,    38,  -113,  -113,  -113,    15,  -113,     8,  -113,
       9,     8,  -113,  -113,   -10,  -113,  -113,   -18,     8,    10,
      20,     8,     8,    27,    23,  -113,     0,  -113,  -113,  -113,
    -113,  -113,  -113,    22,  -113,  -113,  -113,  -113,  -113,    53,
      53,    -2,    42,   -18,     6,    47,  -113,  -113,  -113,  -113,
    -113,    21,  -113,    83,    49,  -113,    97,  -113,  -113,    10,
    -113,   102,  -113,    91,  -113,    44,    99,    56,     1,     1,
       1,  -113,  -113,  -113,  -113,     1,    27,  -113,     6,  -113,
      59,     8,    25,  -113,  -113,     1,  -113,  -113,    54,  -113,
      40,    58,     3,  -113,  -113,  -113,     1,    19,  -113,  -113,
      61,  -113,    79,    60,     1,  -113,  -113,    81,    57,   108,
      75,  -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,
       1,  -113,  -113,  -113,   104,    69,    12,  -113,  -113,    80,
       0,  -113,    67,  -113,    19,     1,     1,     1,   -22,     1,
      19,    90,     1,  -113,     0,    70,  -113,     1,  -113,  -113,
    -113,     3,  -113,  -113,  -113,  -113,  -113,    71,    13,   105,
    -113,  -113,  -113,    44,    19,  -113,  -113
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    12,     2,     1,     0,     3,     0,    13,
       0,     0,     4,    14,     0,     5,    17,    24,     0,     6,
       0,     0,     0,     0,     0,    25,     0,    28,    31,    43,
       7,    23,    17,     0,    22,    20,    21,    15,    18,    36,
      36,    46,     0,    24,     0,     0,    34,    29,    32,    53,
      58,    66,    52,     0,    45,    47,     0,    51,     8,    26,
       9,     0,    10,     0,    16,    42,     0,     0,     0,     0,
       0,    67,    62,    44,    48,     0,     0,    11,     0,    41,
       0,     0,     0,    33,    90,     0,    89,    88,    65,    54,
      71,    76,    78,    81,    59,    63,     0,    61,    50,    27,
       0,    35,     0,     0,     0,    92,    84,     0,     0,     0,
       0,    99,   101,    98,   100,    97,    94,   102,    93,    79,
       0,    96,    95,    82,     0,     0,     0,    69,    49,     0,
       0,    30,     0,    86,    61,     0,     0,     0,    77,     0,
      61,    65,     0,    68,     0,    37,    91,     0,    55,    73,
      75,    80,    83,    60,    64,    70,    19,     0,     0,     0,
      39,    87,    56,    42,    61,    40,    57
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,   -28,    -1,
      -7,    93,  -113,  -112,    45,    85,  -113,  -113,  -113,  -113,
    -113,  -113,  -113,  -113,    86,  -113,   -34,  -113,  -113,  -113,
      -9,  -113,  -113,  -113,  -113,   -85,  -113,  -113,  -113,  -113,
    -113,  -113,  -113,   -73,  -113,  -113,  -113,   -16,   -67,  -113,
    -113,   -37,    14,  -113,    -5,  -113,   -79,  -113,  -113,  -113,
    -113,  -113,  -113
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     6,     8,    14,    16,    23,    42,    87,    88,
      10,    17,    45,    37,    38,    19,    24,    32,    76,    25,
      39,    66,    40,    67,    47,    65,    80,   157,   163,    81,
      52,    41,    53,    54,    97,    55,    68,   108,   159,   164,
      69,   124,    56,    72,   125,    57,    96,   126,   127,   109,
     110,    90,    91,   137,    92,   139,    93,   107,   147,   104,
     119,   123,   120
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       4,    89,    94,    95,    60,    33,   105,     9,    98,    60,
      13,    20,   128,   116,    30,   106,    63,     9,   145,    11,
      27,    28,   142,   142,   118,     3,    49,   -65,     3,    26,
      11,     1,   156,    21,    84,     3,    61,   132,     5,    85,
      51,    61,    29,    15,   -72,    18,     3,    49,     7,   148,
     100,   -61,    70,    44,    71,   153,    58,    22,   121,   122,
     152,    12,    50,    29,   143,   161,    34,    99,   154,    35,
      36,    29,    86,    62,   102,   155,    31,   111,    62,   166,
       9,   -74,   112,    50,   113,    70,    46,   -85,   130,    11,
     114,    34,   115,   116,    35,    36,    51,   117,   149,   150,
      64,    73,    74,    75,   118,    77,    78,    79,    82,    83,
     129,   101,   135,   131,   133,   134,   136,   140,   141,   146,
     144,    70,   162,   -38,   160,    43,    48,   103,    59,   165,
       0,   158,   151,    51,   138,     0,     0,     0,     0,    51,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    51
};

static const yytype_int16 yycheck[] =
{
       1,    68,    69,    70,     3,     5,    85,     8,    75,     3,
      11,    18,    97,    35,    23,    88,    44,    18,   130,    10,
      21,    22,    10,    10,    46,    27,    28,     6,    27,     9,
      10,    48,   144,    23,    33,    27,    35,   104,     0,    38,
      41,    35,    44,    53,     4,    63,    27,    28,    33,   134,
      78,    53,    31,    31,    33,   140,    14,    47,    55,    56,
     139,    52,    64,    44,    52,    52,    66,    76,   141,    69,
      70,    44,    71,    72,    81,   142,    53,    19,    72,   164,
      81,    41,    24,    64,    26,    31,    33,    33,     9,    10,
      32,    66,    34,    35,    69,    70,    97,    39,   135,   136,
      53,    18,    53,     6,    46,     3,    15,    63,     9,    53,
      49,    52,     4,    53,    33,    58,    41,    13,    49,    52,
      40,    31,    17,    53,    53,    32,    40,    82,    43,   163,
      -1,   147,   137,   134,   120,    -1,    -1,    -1,    -1,   140,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   164
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    48,    74,    27,    82,     0,    75,    33,    76,    82,
      83,    10,    52,    82,    77,    53,    78,    84,    63,    88,
      83,    23,    47,    79,    89,    92,     9,    82,    82,    44,
     103,    53,    90,     5,    66,    69,    70,    86,    87,    93,
      95,   104,    80,    84,    31,    85,    33,    97,    97,    28,
      64,    82,   103,   105,   106,   108,   115,   118,    14,    88,
       3,    35,    72,    81,    53,    98,    94,    96,   109,   113,
      31,    33,   116,    18,    53,     6,    91,     3,    15,    63,
      99,   102,     9,    53,    33,    38,    71,    81,    82,   121,
     124,   125,   127,   129,   121,   121,   119,   107,   121,   103,
      81,    52,    83,    87,   132,   129,   116,   130,   110,   122,
     123,    19,    24,    26,    32,    34,    35,    39,    46,   133,
     135,    55,    56,   134,   114,   117,   120,   121,   108,    49,
       9,    53,   121,    33,    58,     4,    41,   126,   125,   128,
      13,    49,    10,    52,    40,    86,    52,   131,   108,   124,
     124,   127,   129,   108,   116,   121,    86,   100,   120,   111,
      53,    52,    17,   101,   112,    99,   108
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    73,    75,    76,    77,    78,    79,    80,    74,    81,
      81,    81,    82,    83,    83,    85,    84,    84,    86,    86,
      87,    87,    87,    88,    88,    90,    91,    89,    93,    94,
      92,    95,    96,    92,    98,    97,    97,    99,   100,   101,
      99,   102,   102,   104,   103,   105,   105,   106,   107,   106,
     108,   108,   108,   109,   110,   111,   112,   108,   113,   114,
     108,   108,   115,   117,   116,   116,   118,   119,   118,   120,
     120,   121,   122,   121,   123,   121,   124,   124,   125,   126,
     125,   127,   128,   127,   129,   130,   131,   129,   129,   129,
     132,   129,   129,   133,   133,   134,   134,   135,   135,   135,
     135,   135,   135
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     0,     0,     0,     0,    16,     1,
       1,     2,     1,     1,     3,     0,     7,     0,     1,     8,
       1,     1,     1,     3,     0,     0,     0,     6,     0,     0,
       8,     0,     0,     6,     0,     4,     0,     4,     0,     0,
       8,     1,     0,     0,     4,     1,     0,     1,     0,     4,
       3,     1,     1,     0,     0,     0,     0,    10,     0,     0,
       6,     0,     2,     0,     5,     0,     1,     0,     5,     1,
       3,     1,     0,     4,     0,     4,     1,     3,     1,     0,
       4,     1,     0,     4,     2,     0,     0,     6,     1,     1,
       0,     4,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1
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

    {
      	TableEntry* tmp = BuildTableEntry((yyvsp[0].str), symbol_table->scopes[symbol_table->current_level], symbol_table->current_level, BuildType("program"), yylineno, symbol_table->cnt_upd);
	InsertTableEntry(symbol_table,tmp);
	
	//GenProgramStart($2);
	//printf("%s\n\n", fileName);
	}

    break;

  case 3:

    {
		symbol_table->current_level++;
		strcpy(symbol_table->scope, (yyvsp[-2].str));
		strcpy(symbol_table->scopes[symbol_table->current_level], (yyvsp[-2].str));
		printf("New scope '%s' is generated at Line %d\n", (yyvsp[-2].str), yylineno);
	}

    break;

  case 4:

    {
		AddparaToFunc(symbol_table, (yyvsp[-5].str), yylineno);
		symbol_table->current_level--;
		strcpy(symbol_table->scope, symbol_table->scopes[symbol_table->current_level]);
	
	}

    break;

  case 5:

    {
		symbol_table->cnt_upd++;
		symbol_table->current_level++;
		strcpy(symbol_table->scopes[symbol_table->current_level], (yyvsp[-7].str));
		strcpy(symbol_table->scope, symbol_table->scopes[symbol_table->current_level]);
		//GenProgramStart($2);
        	//fprintf(outfp, "main:\n");
        	//init_space();
	}

    break;

  case 6:

    {symbol_table->current_level--;
        strcpy(symbol_table->scope, symbol_table->scopes[symbol_table->current_level]);
	//printf("Scope '%s' is closed at Line %d\n", $2, yylineno);
	GenProgramStart((yyvsp[-10].str));
        fprintf(outfp, "main:\n");
        init_space();
	}

    break;

  case 7:

    {printf("Scope '%s' is closed at Line %d\n", (yyvsp[-12].str), yylineno);
	//symbol_table->current_level--;
	//printf("%d\n", symbol_table->current_level);
	//strcpy(symbol_table->scope, symbol_table->scopes[symbol_table->current_level]);	
	}

    break;

  case 8:

    {recover_setting();}

    break;

  case 9:

    {(yyval.value) = BuildValue("integer", yytext);
    		(yyval.value)->is_const = 1;}

    break;

  case 10:

    {(yyval.value) = BuildValue("real", yytext);
		(yyval.value)->is_const = 1;}

    break;

  case 11:

    {
	//printf("%s|||", yytext);
		(yyval.value) = BuildNegValue("integer", yytext);
		(yyval.value)->is_const = 1;}

    break;

  case 13:

    {
		TableEntry* tmp=BuildTableEntry((yyvsp[0].str), symbol_table->scope, symbol_table->current_level, BuildType("void"), yylineno, symbol_table->cnt_upd);
		InsertTableEntry(symbol_table,tmp);
}

    break;

  case 14:

    {
                TableEntry* tmp=BuildTableEntry((yyvsp[0].str), symbol_table->scope, symbol_table->current_level, BuildType("void"), yylineno, symbol_table->cnt_upd);
                InsertTableEntry(symbol_table,tmp);
}

    break;

  case 15:

    {
		UpdateType(symbol_table, (yyvsp[0].type), yylineno);
		//printf("%d\n", array_space);
		array_space += Request_array_space(symbol_table, (yyvsp[0].type), yylineno, array_space, array_all);
		int i;
		for(i = 0 ; i < 10; i++){
			//printf("%f ", array_all[i]);
		}
		//printf("%d\n", array_space);
		//if($5->arr_dim > 0) array_cnt ++;
		}

    break;

  case 16:

    {symbol_table->cnt_upd++;}

    break;

  case 18:

    {(yyval.type) = (yyvsp[0].type);}

    break;

  case 19:

    {
				//$8->arr_dim++;
				//$$ = $8;
				//printf("%d, %d\n", $3->ival, $5->ival);
				(yyvsp[0].type)->arr_range[((yyvsp[0].type)->arr_dim)*2] = (yyvsp[-5].value)->ival;
				(yyvsp[0].type)->arr_range[((yyvsp[0].type)->arr_dim)*2+1] = (yyvsp[-3].value)->ival;
				(yyvsp[0].type)->arr_dim++;
				(yyval.type) = (yyvsp[0].type);
				//$$ = BuildType(
				//$$ = BuildArrayType(tmp, $3->ival, $5->ival);
				
				}

    break;

  case 20:

    {(yyval.type) = BuildType("integer");}

    break;

  case 21:

    {(yyval.type) = BuildType("real");}

    break;

  case 22:

    {(yyval.type) = BuildType("string");}

    break;

  case 23:

    {symbol_table->cnt_upd++;}

    break;

  case 25:

    {
		printf("New scope '%s' is generated at Line %d\n", symbol_table->scopes[symbol_table->current_level], yylineno);
		symbol_table->current_level++;
	}

    break;

  case 26:

    {
		symbol_table->current_level--;
		strcpy(symbol_table->scope, symbol_table->scopes[symbol_table->current_level]);
	}

    break;

  case 27:

    {
		end_func(symbol_table, symbol_table->scope);
		printf("Scope '%s' is closed at Line %d\n", symbol_table->scopes[symbol_table->current_level], yylineno);
	}

    break;

  case 28:

    {
			TableEntry* tmp = BuildTableEntry((yyvsp[0].str), symbol_table->scope, symbol_table->current_level, BuildType("function"), yylineno, symbol_table->cnt_upd);                           
			tmp->exe_space = exe_space;
			exe_space += 4;
			InsertTableEntry(symbol_table,tmp);
			strcpy(symbol_table->scopes[symbol_table->current_level], (yyvsp[0].str));
			strcpy(symbol_table->scope, (yyvsp[0].str));
		}

    break;

  case 29:

    { //printf("%s||", $2);
			AddparaToFunc(symbol_table, (yyvsp[-2].str), yylineno);
		}

    break;

  case 30:

    {
			//symbol_table->current_level++;
			symbol_table->cnt_upd++;
			char* tmp;
			tmp = (char*)malloc(sizeof(char)*32);
			//printf("%s", $7);
			strcpy(tmp, (yyvsp[-1].type)->name);
			UpdateFunctionRet(symbol_table, (yyvsp[-1].type), yylineno);
         		//printf("%s\n\n\n\n", $2);
			init_func(symbol_table, (yyvsp[-6].str));
			change_para_value(symbol_table, (yyvsp[-6].str));
			//end_func(symbol_table, $2);
	       }

    break;

  case 31:

    {
			TableEntry* tmp = BuildTableEntry((yyvsp[0].str), symbol_table->scope, symbol_table->current_level, BuildType("procedure"), yylineno, symbol_table->cnt_upd);
      			tmp->exe_space = exe_space;
			exe_space += 4;
			
			InsertTableEntry(symbol_table,tmp);
			//AddparaToFunc(symbol_table, $2, yylineno);
			symbol_table->cnt_upd++;
			strcpy(symbol_table->scopes[symbol_table->current_level], (yyvsp[0].str));
                        strcpy(symbol_table->scope, (yyvsp[0].str));
		}

    break;

  case 32:

    {
			AddparaToFunc(symbol_table, (yyvsp[-2].str), yylineno);
		}

    break;

  case 33:

    {
			symbol_table->cnt_upd++;
			init_func(symbol_table, (yyvsp[-4].str));
			change_para_value(symbol_table, (yyvsp[-4].str));
		}

    break;

  case 34:

    {
	  symbol_table->current_level++;
	//printf("2.%s  \n", symbol_table->scopes[symbol_table->current_level]);
	  strcpy(symbol_table->scopes[symbol_table->current_level], symbol_table->scopes[symbol_table->current_level-1]);
	  strcpy(symbol_table->scope, symbol_table->scopes[symbol_table->current_level]);
	//printf("1.%s  \n", symbol_table->scopes[symbol_table->current_level]);
	}

    break;

  case 35:

    {symbol_table->current_level--;
	  strcpy(symbol_table->scope, symbol_table->scopes[symbol_table->current_level]);
	}

    break;

  case 37:

    {
			UpdateType(symbol_table, (yyvsp[0].type), yylineno);
			//printf("}}%d{{", symbol_table->cnt_upd);
		}

    break;

  case 38:

    {
			//printf("}}%d{{", symbol_table->cnt_upd);
                        UpdateType(symbol_table, (yyvsp[0].type), yylineno);
		}

    break;

  case 39:

    {
			symbol_table->cnt_upd++;
		}

    break;

  case 43:

    {symbol_table->current_level++;
	strcpy(symbol_table->scopes[symbol_table->current_level], symbol_table->scopes[symbol_table->current_level-1]);
	strcpy(symbol_table->scope, symbol_table->scopes[symbol_table->current_level]);   
	//symbol_table->current_level++;
		}

    break;

  case 44:

    {symbol_table->current_level--;
		strcpy(symbol_table->scope, symbol_table->scopes[symbol_table->current_level]);
		//symbol_table->current_level--;
		}

    break;

  case 48:

    {symbol_table->cnt_upd++;}

    break;

  case 50:

    {
	//TableEntry* tmp = FindEntryInScope(symbol_table, $1->name);
	UpdateValue(symbol_table, (yyvsp[-2].value)->name, (yyvsp[0].value));
	TableEntry* tmp = (TableEntry*)malloc(sizeof(TableEntry));
        tmp = FindEntryInScope(symbol_table, (yyvsp[-2].value)->name);
	if(tmp->type->arr_dim == 0){
		if(!strcmp(tmp->type->name, "integer")){
			fprintf(outfp, "        mv      a0, t0\n");
			fprintf(outfp, "	li	a1, %d\n", tmp->exe_space);
			fprintf(outfp, "	add	s0, s0, a1\n");
        		fprintf(outfp, "        sw      a0, 0(s0)\n");
			fprintf(outfp, "	sub	s0, s0, a1\n");
		}
		else if(!strcmp(tmp->type->name, "real")){
			//fprintf(outfp, "	fcvt.d.s	f0, f0\n");
			//fprintf(outfp, "	fmv.x.d	a0, f0\n");
			fprintf(outfp, "        li      a1, %d\n", tmp->exe_space);
                        fprintf(outfp, "        add     s0, s0, a1\n");
			//fprintf(outfp, "	sd	a0, 0(s0)\n");
			//fprintf(outfp, "        fcvt.d.s        f0, f0\n");
			fprintf(outfp, "	fsw	f0, 0(s0)\n");
			fprintf(outfp, "        sub     s0, s0, a1\n");
		}
		else if(!strcmp(tmp->type->name, "function")){
			if(!strcmp(tmp->ret, "integer")){
				fprintf(outfp, "        mv      a0, t0\n");
				fprintf(outfp, "        li      a1, %d\n", tmp->exe_space);
                        	fprintf(outfp, "        add     s0, s0, a1\n");
	                        fprintf(outfp, "        sw      a0, 0(s0)\n");
				fprintf(outfp, "        sub     s0, s0, a1\n");
			}
			else	{
				//fprintf(outfp, "	fmv.x.d a0, f0\n");
				fprintf(outfp, "        li      a1, %d\n", tmp->exe_space);
                        	fprintf(outfp, "        add     s0, s0, a1\n");
				//fprintf(outfp, "	sd	a0, 0(s0)\n");
				//fprintf(outfp, "        fcvt.d.s        f0, f0\n");
				fprintf(outfp, "        fsw     f0, 0(s0)\n");
				fprintf(outfp, "        sub     s0, s0, a1\n");
			}		
		}
	}
	else{ //printf("%d spaceL\n\n", tmp_spaceL);
		tmp_spaceL -= tmp->type->arr_range[0];
		printf(" %d  %d spaceL\n\n",tmp->type->arr_range[0], tmp_spaceL);
		if(!strcmp(tmp->type->name, "integer")){
			Assign_for_array(tmp);
		}
		else{
			Assign_for_arrayF(tmp);
		}
	}
	
	if(!strcmp((yyvsp[0].value)->type->name, "integer")) array_all[tmp_spaceL] = (yyvsp[0].value)->ival;
	else if(!strcmp((yyvsp[0].value)->type->name, "real")) array_all[tmp_spaceL] = (yyvsp[0].value)->dval;
	else if(!strcmp((yyvsp[0].value)->type->name, "function")){
		if(!strcmp((yyvsp[0].value)->ret, "integer")) array_all[tmp_spaceL] = (yyvsp[0].value)->ival;
		else array_all[tmp_spaceL] = (yyvsp[0].value)->dval;
	}
	//printf("%d  %f\n\n", tmp_spaceL, $3->dval);
	//printf("%fhhhffff%d\n", $1->array_all[tmp_space], tmp_space);
	tmp_spaceL = 0;

}

    break;

  case 53:

    {nest_if++;}

    break;

  case 54:

    {
			//IF_decide();
			fprintf(outfp, "        beq     t0, zero, .IF%d_%dFalse		#pre->ifcnt, next->nest if cnt\n", if_cnt, nest_if);  //condition is false
		}

    break;

  case 55:

    {
			fprintf(outfp, "	j	.IF%d_%dend\n", if_cnt, nest_if);
		}

    break;

  case 56:

    {
			fprintf(outfp, ".IF%d_%dFalse:\n", if_cnt, nest_if);
		}

    break;

  case 57:

    {
			fprintf(outfp, ".IF%d_%dend:\n", if_cnt, nest_if);
			nest_if--;
			if(nest_if == 0) if_cnt++;
		}

    break;

  case 58:

    { 
			nest_loop ++;
			fprintf(outfp, ".Loop%d_%d:\n", loop_cnt, nest_loop); 
		}

    break;

  case 59:

    { 
			fprintf(outfp, "	beq	t0, zero, .Loop%d_%dend\n", loop_cnt, nest_loop);// false condition
		}

    break;

  case 60:

    {
			fprintf(outfp, "	j	.Loop%d_%d\n", loop_cnt, nest_loop);
			fprintf(outfp, ".Loop%d_%dend:\n", loop_cnt, nest_loop);
			nest_loop --;
			if(nest_loop == 0) loop_cnt ++;
		}

    break;

  case 62:

    {
	 (yyval.value) = ReturnIdValue(symbol_table, (yyvsp[-1].str), tail, tail_cnt, 'l');
	//printf("hfhf");		
		int j, k, tmp = 0;
		//tmp_space = $$->array_space;
                for(j = tail_cnt-2; j >= 0; j--){
			int tmp2 = 1;
			for(k = j; k >= 0; k--){
				//printf("array length  %d  ", $$->array_length[k]);
				tmp2 *= (yyval.value)->array_length[k];
				//printf("%d  ", tmp2);
			}
			//printf("%d  ", tail[j+1]);
			printf("tmp2 %d  tailj %d range %d ", tmp2, tail[j+1], (yyval.value)->type->arr_range[(j+1)*2]);   
			tmp += tmp2*(tail[j+1]-(yyval.value)->type->arr_range[(j+1)*2]);
		}
		tmp += tail[0];
		printf("tmp %d tail %d ", tmp, tail[tail_cnt-1]);
		tmp_spaceL = tmp;
		//printf("%d\nh\n\n", tmp_spaceL);
		if(tail_cnt > 0) Compute_Array_Space(tail, tail_cnt, (yyval.value));	//in a4
		
                for(j = 0; j < tail_cnt; j++){
                        //printf("%d  ", tail[j]);
                        tail[j] = 0;
                }
                //printf("\n");
	//fprintf(outfp, "	addi	s1, s1, %d\n", tail_cnt*4);
                tail_cnt = 0;
		//fprintf(outfp, "	addi	s1, s1, 40\n");
}

    break;

  case 63:

    {
		fprintf(outfp, "	sw	t0, 0(s1)\n");
		fprintf(outfp, "	addi	s1, s1, -4\n"); 
	}

    break;

  case 64:

    {
	 	//printf("%f ", $2->dval);
		
		if(!strcmp((yyvsp[-3].value)->type->name, "integer")){
			tail[tail_cnt] = (yyvsp[-3].value)->ival;
			tail_cnt++;
		}
		else{//printf("8787\n\n");
			printf("Non integer cannot be index, Wrong in Line: %d\n", yylineno);
			tail[tail_cnt] = -1;
			tail_cnt++;
		}
	}

    break;

  case 65:

    {(yyval.value) = NULL;}

    break;

  case 66:

    {
		    
		    BuildProcId(symbol_table, (yyvsp[0].str), para, para_cnt);
		    para_cnt = 0;
			fprintf(outfp, "	call	%s\n", (yyvsp[0].str));
			}

    break;

  case 67:

    {//fprintf(outfp, "	addi	s1, s1, -40\n");
		}

    break;

  case 68:

    {
			ax = 0;
		    if((!strncmp("PrintInt", (yyvsp[-4].str), 8)) || (!strncmp("printInt", (yyvsp[-4].str), 8))){
			int i = 0;
		//	for(i = 0; i < para_cnt; i++){
				ready_printi(para_cnt);
		//	}
		    }
		    else if((!strncmp("PrintReal", (yyvsp[-4].str), 9)) || (!strncmp("printReal", (yyvsp[-4].str), 9))){
			int i = 0;	
			ready_printr(para_cnt);
			//for(i = 0; i < para_cnt; i++){
                          //      ieee[fl_cnt] = ready_printr(parav[i], fl_cnt);
                        //	fl_cnt ++;
			//}
		    }
		    else if((!strncmp("PrintString", (yyvsp[-4].str), 11)) || (!strncmp("printString", (yyvsp[-4].str), 11)) || (!strncmp("printlnString", (yyvsp[-4].str), 13))){
			//Print_String(para_cnt, para, paras);
			int i = 0;
                        for(i = 0; i < para_cnt; i++){
				ready_prints(str_cnt, paras[i]);
				strcpy(LCSS[str_cnt], paras[i]);
				str_cnt++;
			}
		    }
		    else{
		    	BuildProcId(symbol_table, (yyvsp[-4].str), para, para_cnt);
			fprintf(outfp, "	call	%s\n", (yyvsp[-4].str));
                    }
		    para_cnt = 0;
			}

    break;

  case 69:

    {
		if(!strcmp((yyvsp[0].value)->type->name, "integer")) {
			para[para_cnt] = 'i';
			
			parav[para_cnt] = (yyvsp[0].value)->ival;
			//printf("\n|%c|\n",para[para_cnt]);
			push_value_to_stack(symbol_table, (yyvsp[0].value), ax, fl_cnt);		
			
		}
		else if(!strcmp((yyvsp[0].value)->type->name, "real")){
			para[para_cnt] = 'r';
			parav[para_cnt] = (yyvsp[0].value)->dval;
			push_value_to_stack(symbol_table, (yyvsp[0].value), ax, fl_cnt);
			//fl_cnt ++;
			
		}
		else if(!strcmp((yyvsp[0].value)->type->name, "string")){
			para[para_cnt] = 's';
			strcpy(paras[para_cnt], (yyvsp[0].value)->sval);
			//printf("%s\n\n\n", $1->sval);
		}
		//push_value_to_stack($1, ax);
		ax ++;
		//else printf("8787%s%d8787\n", $1->name, yylineno);
		//printf("|%s|%s|%d|||||||||", $1->type->name, $1->ret, para_cnt);
		para_cnt++;
		
		}

    break;

  case 70:

    {
		if(!strcmp((yyvsp[0].value)->type->name, "integer")) {
                	para[para_cnt] =  'i';
                	parav[para_cnt] = (yyvsp[0].value)->ival;
			push_value_to_stack(symbol_table, (yyvsp[0].value), ax, fl_cnt);
                }
                else if(!strcmp((yyvsp[0].value)->type->name, "real")){
                	para[para_cnt] = 'r';
                	parav[para_cnt] = (yyvsp[0].value)->dval;
			push_value_to_stack(symbol_table, (yyvsp[0].value), ax, fl_cnt);
			//fl_cnt ++;
			
                }
		else if(!strcmp((yyvsp[0].value)->type->name, "string")){
                        para[para_cnt] = 's';
                        strcpy(paras[para_cnt], (yyvsp[0].value)->sval);
                }
		//push_value_to_stack($3, ax);
		ax ++;
		//printf("|%s|%s|%d||||||||", $3->type->name, $3->ret, para_cnt);
		para_cnt++;
		}

    break;

  case 71:

    {(yyval.value) = (yyvsp[0].value);}

    break;

  case 72:

    {
			fprintf(outfp, "	mv	s11, t0\n");
		}

    break;

  case 73:

    {
			fprintf(outfp, "	and	t0, s11, t0\n");
		}

    break;

  case 74:

    {
			fprintf(outfp, "        mv      s11, t0\n");
		}

    break;

  case 75:

    {
			fprintf(outfp, "        or	t0, s11, t0\n");
		}

    break;

  case 76:

    {(yyval.value) = (yyvsp[0].value);}

    break;

  case 77:

    {
			char* tmp = compare_two((yyvsp[-2].value), (yyvsp[0].value), (yyvsp[-1].str));
			(yyval.value) = BuildValue("boolean", tmp);
			Exe_cmp((yyvsp[-1].str), cmp_cnt);
			cmp_cnt++;
		}

    break;

  case 78:

    {(yyval.value) = (yyvsp[0].value); }

    break;

  case 79:

    {/*Prevent_rec(add_sub, mul_div);*/}

    break;

  case 80:

    { 
		(yyval.value) = Addtwo((yyvsp[-3].value), (yyvsp[0].value), (yyvsp[-2].str), yylineno);
		infunc_exp --;
		Exe_add_sub(add_sub, (yyvsp[-2].str), (yyvsp[-3].value));
		//Prevent_rec_end();
		add_sub = -1;
	}

    break;

  case 81:

    {(yyval.value) = (yyvsp[0].value);
     		if(!strcmp((yyval.value)->type->name, "integer")) op_type = 0;	//int operation
		else	op_type = 1;	//for real
	}

    break;

  case 82:

    { /*Prevent_rec(add_sub, mul_div);*/}

    break;

  case 83:

    {
			(yyval.value) = Multwo((yyvsp[-3].value), (yyvsp[0].value), (yyvsp[-2].str), yylineno);
			Exe_mul_div(mul_div, (yyvsp[-2].str), (yyvsp[-3].value));
			//Prevent_rec_end();
			mul_div = -1;
		}

    break;

  case 84:

    {
	(yyval.value) = ReturnIdValue(symbol_table, (yyvsp[-1].str), tail, tail_cnt, 'r');
		
		int j, k, tmp = 0;
		//tmp_space = $$->array_space;
                for(j = tail_cnt-2; j >= 0; j--){
			int tmp2 = 1;
			for(k = j; k >= 0; k--){
				printf("%d  ", (yyval.value)->array_length[k]);
				tmp2 *= (yyval.value)->array_length[k];
				//printf("%d  ", tmp2);
			}
			//printf("%d  ", tail[j+1]);
			tmp += tmp2*tail[j+1];
		}
		tmp += tail[0];

		//printf("tmp %d  \n", tmp);
		tmp_space = tmp;
		if(tail_cnt > 0) { //printf("bababa\n\n\n");
			if(!strcmp((yyval.value)->type->name, "integer")) (yyval.value)->ival = array_all[tmp_space];
			else (yyval.value)->dval = array_all[tmp_space];
		}
		
		if(tail_cnt > 0){
			Compute_Array_Space_R(tail, tail_cnt, (yyval.value));
			
		}

		
		for(j = 0; j < tail_cnt; j++){
        	        tail[j] = 0;
                }

		TableEntry* t = (TableEntry*)malloc(sizeof(TableEntry));
		t = FindEntryInScope(symbol_table, (yyvsp[-1].str));
	if(t->type->arr_dim == 0){
		if(!strcmp(t->type->name, "integer")){
			fprintf(outfp, "        li      a1, %d\n", t->exe_space);
                                fprintf(outfp, "        add     s0, s0, a1\n");
                                fprintf(outfp, "        lw      t0, 0(s0)\n");
                                fprintf(outfp, "        sub     s0, s0, a1\n");
        		//fprintf(outfp, "        sw      a0, %d(s0)\n", tmp->exe_space);
		}
		else if(!strcmp(t->type->name, "real")){
			fprintf(outfp, "        li      a1, %d\n", t->exe_space);
                        fprintf(outfp, "        add     s0, s0, a1\n");
			fprintf(outfp, "	flw	f0, 0(s0)\n");
			//fprintf(outfp, "	ld	t0, 0(s0)\n");
			//fprintf(outfp, "	ld	0, %d(s0)\n", t->exe_space);
			//fprintf(outfp, "	fmv.d.x	f0, t0\n");
			fprintf(outfp, "        sub     s0, s0, a1\n");
			//fprintf(outfp, "	sw	a0, %d(s0)\n", tmp->exe_space);
		}
		else if(!strcmp(t->type->name, "function")){
			//Prevent_rec(add_sub, mul_div);
			fprintf(outfp, "	call	%s\n", (yyvsp[-1].str));
			//Prevent_rec_end();
		}
	}
	else{ //printf("%d spaceR\n\n", tmp_space);
		tmp -= t->type->arr_range[0];
		if(!strcmp(t->type->name, "integer")){
			//fprintf(outfp, "	mv	a0, t0\n");
			
			int temp = t->exe_space + tmp*4;
			Find_array_value(t);
		}
		else{
			Find_array_valueF(t);		
			int temp = t->exe_space + tmp*4;
			printf("%d spaceR\n\n", temp);
		}
	}
		//fprintf(outfp, "        addi    s1, s1, %d\n", tail_cnt*4);
		tmp_space = 0;
		tail_cnt = 0;
	}

    break;

  case 85:

    { /*Prevent_rec(add_sub, mul_div);*/ }

    break;

  case 86:

    {inexp++;}

    break;

  case 87:

    {
		inexp --;
		infunc_exp ++;
		//$$ = BuildValue("integer", "-88");
		(yyval.value) = BuildFuncId(symbol_table, (yyvsp[-5].str), para, para_cnt);
		//printf("%d", para_cnt);
		//fprintf(outfp, "	call 	%s\n", $1);
		//print_outcome();
		para_cnt = 0;
		ax = 0;
		//printf("WTFWTFFfsfs?????\n\n\n");
		fprintf(outfp, "	call	%s\n", (yyvsp[-5].str));
		printf("name %s\n\n", (yyvsp[-5].str));
		//Prevent_rec_end();
		//fprintf(outfp, "	ld	a0, -912(sp)\n");
		//fprintf(outfp, "	sw	a0, %d(s0)\n", 28);
		if(!strcmp(symbol_table->scope, (yyvsp[-5].str))){
			Reload_para(symbol_table, (yyvsp[-5].str));
		}
		pre_rec = -1;
	}

    break;

  case 88:

    {
		//$$ = $1;
		//printf("%dmul\n\n\n\n", $1->ival);
		char* tmp;
		tmp = (char*)malloc(sizeof(char)*32);
		if(!strcmp((yyvsp[0].value)->type->name, "integer")){
			tmp = itoa((yyvsp[0].value)->ival);
			(yyval.value) = BuildValue("integer", tmp);
			(yyval.value)->is_const = 1;
			//printf("%s\n\n\n", tmp);
			fprintf(outfp, "	li	t0, %d\n", (yyvsp[0].value)->ival);
		}
		else{
			strcpy(tmp, (yyvsp[0].value)->sval);
			(yyval.value) = BuildValue("real", tmp);
			(yyval.value)->is_const = 1;
			ieee[fl_cnt] = assign_float((yyvsp[0].value)->dval, fl_cnt);
			//fl_cnt ++;
			//fprintf(outfp, "	

			fl_cnt++;
		}
		//printf("%skkkk%d %d\n", $$->type->name, $$->ival, yylineno);
		}

    break;

  case 89:

    {(yyval.value) = BuildValue("string", yytext);
			(yyval.value)->is_const = 1;}

    break;

  case 90:

    {inexp++;}

    break;

  case 91:

    {(yyval.value) = (yyvsp[-1].value);
		inexp--;
	}

    break;

  case 92:

    {(yyval.value) = (yyvsp[0].value);
		fprintf(outfp, "	xor	t0, t0, 1\n");
		//fprintf(outfp, "        lui     a0, %%hi(.LCI)\n");
		//fprintf(outfp, "        mv      a1, t0\n");
	        //fprintf(outfp, "        addi    a0, a0, %%lo(.LCI)\n");
		//fprintf(outfp, "        call    printf\n");
	}

    break;

  case 93:

    {
      	add_sub = 0;
	Add_Sub_prepare(op_type);
	}

    break;

  case 94:

    {
	add_sub = 1;
	Add_Sub_prepare(op_type);
        }

    break;

  case 95:

    {
        Mul_Div_prepare(op_type);
	mul_div = 0;
	}

    break;

  case 96:

    {
	Mul_Div_prepare(op_type);
	mul_div = 1;
}

    break;

  case 97:

    { cmp = 1; cmp_prepare();}

    break;

  case 98:

    { cmp = 2; cmp_prepare();}

    break;

  case 99:

    { cmp = 3; cmp_prepare();}

    break;

  case 100:

    { cmp = 4; cmp_prepare();}

    break;

  case 101:

    { cmp = 5; cmp_prepare();}

    break;

  case 102:

    { cmp = 6; cmp_prepare();}

    break;



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



//fprintf("%d", yyparse());

int yyerror(char *msg)
{
	fprintf( stderr, "--------------------------------------------------------------------------\n" );
	fprintf( stderr, " Error found in Line #%d: %s\n", yylineno, msg );
	//fprintf( stderr, "\n" );
	fprintf( stderr, " line %d: error token: %s\n", yylineno, yytext );
		fprintf( stderr, "--------------------------------------------------------------------------\n" );
	exit(-1);
}

/*
int main(int argc, char **argv)
{
	if(argc != 2){
		fprintf(  stdout,  "Usage:  ./parser  [filename]\n"  );
		exit(0);
	}
	fprintf(stdout, "  test for %s\n", argv[1]);	
	FILE *fp = fopen(argv[1], "r");
	if( fp == NULL )  {
		fprintf( stdout, "Open  file  error\n" );
		exit(-1);
	}
	yyin = fp;
	yyparse();	
	int i = 0, tok = 0;
	//for(i = 0;1==1; i++){
	//	tok = yylex();
		//fprintf(stdout, "%d  ", tok);
	//}
	
	fprintf( stdout, "--------------------------------\n" );
	fprintf( stdout, "  OK!!\n" );
	fprintf( stdout, "--------------------------------\n" );
	exit(0);
}*/
