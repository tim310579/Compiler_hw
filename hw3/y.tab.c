/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include "symtab.h"
#include <string.h>

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

int has_ret=0;
int para_cnt = 0;
char para[32];
float parav[32];
int tail_cnt = 0;
int tail[32] = {0};


#line 106 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
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
#line 41 "parser.y" /* yacc.c:355  */

	int num;
	double dnum;
	char* str;
	struct Value* value;
	struct Type* type;
	struct TableEntry* tableentry;
	
	

#line 301 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 318 "y.tab.c" /* yacc.c:358  */

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
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
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
#  define YYSIZE_T unsigned int
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

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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
#define YYLAST   141

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  73
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  49
/* YYNRULES -- Number of rules.  */
#define YYNRULES  88
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  153

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   327

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
       0,    72,    72,    76,    81,    87,    94,    98,    72,   105,
     107,   109,   116,   120,   124,   130,   130,   133,   137,   138,
     152,   153,   154,   159,   160,   164,   169,   170,   164,   175,
     180,   175,   191,   199,   191,   206,   206,   216,   219,   223,
     227,   223,   233,   234,   237,   237,   250,   251,   254,   255,
     255,   259,   263,   264,   265,   266,   267,   270,   280,   292,
     295,   299,   305,   321,   337,   338,   339,   342,   343,   345,
     346,   354,   355,   362,   370,   375,   393,   395,   396,   399,
     399,   402,   402,   406,   407,   408,   409,   410,   411
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
  "$@10", "subprogram_head", "$@11", "$@12", "$@13", "$@14", "arguments",
  "$@15", "parameter_list", "$@16", "$@17", "optional_var",
  "compound_statement", "$@18", "optional_statements", "statement_list",
  "$@19", "statement", "variable", "tail", "procedure_statement",
  "expression_list", "expression", "boolexpression", "simple_expression",
  "term", "factor", "addop", "mulop", "relop", YY_NULLPTR
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

#define YYPACT_NINF -101

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-101)))

#define YYTABLE_NINF -60

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -34,    -8,    37,  -101,  -101,  -101,    42,  -101,    -8,  -101,
       5,    -8,  -101,  -101,    24,  -101,  -101,    22,    -8,     7,
      40,    -8,    -8,    46,    39,  -101,     0,  -101,  -101,  -101,
    -101,  -101,  -101,    64,  -101,  -101,  -101,  -101,  -101,    66,
      66,    -2,    86,    22,     9,    48,  -101,  -101,  -101,     8,
       8,    28,  -101,    84,    50,  -101,    98,  -101,  -101,     7,
    -101,   102,  -101,    91,  -101,    44,    99,    56,     8,     8,
    -101,  -101,    -4,    53,    14,    52,    17,  -101,    97,     8,
       8,  -101,  -101,  -101,     8,  -101,  -101,     9,  -101,    61,
      -8,    -6,  -101,    62,  -101,     8,  -101,     4,     8,     8,
    -101,  -101,  -101,  -101,  -101,  -101,  -101,  -101,     8,     8,
    -101,  -101,     8,     4,    68,     6,  -101,     4,  -101,    46,
      69,  -101,    73,    67,  -101,    13,   104,  -101,  -101,    17,
       1,  -101,  -101,    88,     8,  -101,  -101,  -101,    75,     0,
    -101,  -101,     4,  -101,  -101,     0,    70,  -101,  -101,    71,
    -101,    44,  -101
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    12,     2,     1,     0,     3,     0,    13,
       0,     0,     4,    14,     0,     5,    17,    24,     0,     6,
       0,     0,     0,     0,     0,    25,     0,    29,    32,    44,
       7,    23,    17,     0,    22,    20,    21,    15,    18,    37,
      37,    47,     0,    24,     0,     0,    35,    30,    33,     0,
       0,    60,    53,     0,    46,    48,     0,    52,     8,    26,
       9,     0,    10,     0,    16,    43,     0,     0,     0,     0,
      76,    75,    59,     0,    64,    67,    69,    71,     0,     0,
       0,    57,    45,    49,     0,    27,    11,     0,    42,     0,
       0,     0,    34,     0,    78,     0,    73,    56,     0,     0,
      85,    87,    84,    86,    83,    80,    88,    79,     0,     0,
      82,    81,     0,    56,     0,     0,    62,    56,    51,     0,
       0,    36,     0,     0,    77,     0,     0,    65,    66,    70,
      68,    72,    55,    59,     0,    61,    50,    28,     0,     0,
      31,    74,    56,    58,    63,     0,    38,    54,    19,     0,
      40,    43,    41
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -101,  -101,  -101,  -101,  -101,  -101,  -101,  -101,   -35,    -1,
     -16,    90,  -101,  -100,    34,    83,  -101,  -101,  -101,  -101,
    -101,  -101,  -101,  -101,  -101,    87,  -101,   -23,  -101,  -101,
    -101,   -22,  -101,  -101,  -101,  -101,   -89,  -101,   -66,  -101,
      35,   -46,    -5,    20,    23,   -56,  -101,  -101,  -101
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     6,     8,    14,    16,    23,    42,    71,    72,
      10,    17,    45,    37,    38,    19,    24,    32,    85,   119,
      25,    39,    66,    40,    67,    47,    65,    89,   149,   151,
      90,    52,    41,    53,    54,   117,    55,    56,    81,    57,
     115,   116,    74,    75,    76,    77,   108,   112,   109
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       4,    30,    20,    73,    78,    33,    96,     9,   126,    63,
      13,    60,    60,    94,     1,    11,   134,     9,    98,     3,
      27,    28,    93,   134,   132,     3,    49,    79,   136,    95,
      21,     3,    49,   114,   -59,     3,   105,     5,   118,   146,
      51,    68,    29,    61,    61,   148,    69,   107,    29,    26,
      11,   -56,   120,   147,    22,    99,   131,    12,   135,    79,
      34,    80,    50,    35,    36,   141,    34,   143,    50,    35,
      36,   100,   110,   111,   122,     7,   101,    15,   102,    70,
      62,    62,   139,    11,   103,    18,   104,   105,   144,     9,
      29,   106,    31,   127,   128,    44,    51,   137,   107,    46,
      58,    64,    82,    83,    84,    86,    87,    88,    91,    92,
     113,    97,    51,   121,   124,   145,    51,   133,   138,    79,
     140,   142,    43,   -39,   150,   123,    59,    48,   152,   130,
     125,   129,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    51
};

static const yytype_int16 yycheck[] =
{
       1,    23,    18,    49,    50,     5,    72,     8,    97,    44,
      11,     3,     3,    69,    48,    10,    10,    18,     4,    27,
      21,    22,    68,    10,   113,    27,    28,    31,   117,    33,
      23,    27,    28,    79,     6,    27,    35,     0,    84,   139,
      41,    33,    44,    35,    35,   145,    38,    46,    44,     9,
      10,    53,    87,   142,    47,    41,   112,    52,    52,    31,
      66,    33,    64,    69,    70,    52,    66,   133,    64,    69,
      70,    19,    55,    56,    90,    33,    24,    53,    26,    71,
      72,    72,     9,    10,    32,    63,    34,    35,   134,    90,
      44,    39,    53,    98,    99,    31,    97,   119,    46,    33,
      14,    53,    18,    53,     6,     3,    15,    63,     9,    53,
      13,    58,   113,    52,    52,    40,   117,    49,    49,    31,
      53,    17,    32,    53,    53,    91,    43,    40,   151,   109,
      95,   108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   142
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    48,    74,    27,    82,     0,    75,    33,    76,    82,
      83,    10,    52,    82,    77,    53,    78,    84,    63,    88,
      83,    23,    47,    79,    89,    93,     9,    82,    82,    44,
     104,    53,    90,     5,    66,    69,    70,    86,    87,    94,
      96,   105,    80,    84,    31,    85,    33,    98,    98,    28,
      64,    82,   104,   106,   107,   109,   110,   112,    14,    88,
       3,    35,    72,    81,    53,    99,    95,    97,    33,    38,
      71,    81,    82,   114,   115,   116,   117,   118,   114,    31,
      33,   111,    18,    53,     6,    91,     3,    15,    63,   100,
     103,     9,    53,   114,   118,    33,   111,    58,     4,    41,
      19,    24,    26,    32,    34,    35,    39,    46,   119,   121,
      55,    56,   120,    13,   114,   113,   114,   108,   114,    92,
      81,    52,    83,    87,    52,   113,   109,   115,   115,   117,
     116,   118,   109,    49,    10,    52,   109,   104,    49,     9,
      53,    52,    17,   111,   114,    40,    86,   109,    86,   101,
      53,   102,   100
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    73,    75,    76,    77,    78,    79,    80,    74,    81,
      81,    81,    82,    83,    83,    85,    84,    84,    86,    86,
      87,    87,    87,    88,    88,    90,    91,    92,    89,    94,
      95,    93,    96,    97,    93,    99,    98,    98,   100,   101,
     102,   100,   103,   103,   105,   104,   106,   106,   107,   108,
     107,   109,   109,   109,   109,   109,   109,   110,   111,   111,
     112,   112,   113,   113,   114,   114,   114,   115,   115,   116,
     116,   117,   117,   118,   118,   118,   118,   118,   118,   119,
     119,   120,   120,   121,   121,   121,   121,   121,   121
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     0,     0,     0,     0,    16,     1,
       1,     2,     1,     1,     3,     0,     7,     0,     1,     8,
       1,     1,     1,     3,     0,     0,     0,     0,     7,     0,
       0,     8,     0,     0,     6,     0,     4,     0,     4,     0,
       0,     8,     1,     0,     0,     4,     1,     0,     1,     0,
       4,     3,     1,     1,     6,     4,     0,     2,     4,     0,
       1,     4,     1,     3,     1,     3,     3,     1,     3,     1,
       3,     1,     3,     2,     4,     1,     1,     3,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
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
  unsigned long int yylno = yyrline[yyrule];
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
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
            /* Fall through.  */
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

  return yystpcpy (yyres, yystr) - yyres;
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
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
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
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
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
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

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
| yyreduce -- Do a reduction.  |
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
#line 72 "parser.y" /* yacc.c:1646  */
    {
      	TableEntry* tmp = BuildTableEntry((yyvsp[0].str), symbol_table->scopes[symbol_table->current_level], symbol_table->current_level, BuildType("program"), yylineno, symbol_table->cnt_upd);
	InsertTableEntry(symbol_table,tmp);
	}
#line 1522 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 76 "parser.y" /* yacc.c:1646  */
    {
		symbol_table->current_level++;
		strcpy(symbol_table->scope, (yyvsp[-2].str));
		strcpy(symbol_table->scopes[symbol_table->current_level], (yyvsp[-2].str));

	}
#line 1533 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 81 "parser.y" /* yacc.c:1646  */
    {
		AddparaToFunc(symbol_table, (yyvsp[-5].str), yylineno);
		symbol_table->current_level--;
		strcpy(symbol_table->scope, symbol_table->scopes[symbol_table->current_level]);
	
	}
#line 1544 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 87 "parser.y" /* yacc.c:1646  */
    {
		symbol_table->cnt_upd++;
		symbol_table->current_level++;
		strcpy(symbol_table->scopes[symbol_table->current_level], (yyvsp[-7].str));
		strcpy(symbol_table->scope, symbol_table->scopes[symbol_table->current_level]);
	}
#line 1555 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 94 "parser.y" /* yacc.c:1646  */
    {symbol_table->current_level--;
        strcpy(symbol_table->scope, symbol_table->scopes[symbol_table->current_level]);
	}
#line 1563 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 98 "parser.y" /* yacc.c:1646  */
    {//symbol_table->current_level--;
	//printf("%d\n", symbol_table->current_level);
	//strcpy(symbol_table->scope, symbol_table->scopes[symbol_table->current_level]);	
	}
#line 1572 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 105 "parser.y" /* yacc.c:1646  */
    {(yyval.value) = BuildValue("integer", yytext);
    		(yyval.value)->is_const = 1;}
#line 1579 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 107 "parser.y" /* yacc.c:1646  */
    {(yyval.value) = BuildValue("real", yytext);
		(yyval.value)->is_const = 1;}
#line 1586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 109 "parser.y" /* yacc.c:1646  */
    {
	//printf("%s|||", yytext);
		(yyval.value) = BuildNegValue("integer", yytext);
		(yyval.value)->is_const = 1;}
#line 1595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 120 "parser.y" /* yacc.c:1646  */
    {
		TableEntry* tmp=BuildTableEntry((yyvsp[0].str), symbol_table->scope, symbol_table->current_level, BuildType("void"), yylineno, symbol_table->cnt_upd);
		InsertTableEntry(symbol_table,tmp);
}
#line 1604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 124 "parser.y" /* yacc.c:1646  */
    {
                TableEntry* tmp=BuildTableEntry((yyvsp[0].str), symbol_table->scope, symbol_table->current_level, BuildType("void"), yylineno, symbol_table->cnt_upd);
                InsertTableEntry(symbol_table,tmp);
}
#line 1613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 130 "parser.y" /* yacc.c:1646  */
    {
		UpdateType(symbol_table, (yyvsp[0].type), yylineno);}
#line 1620 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 132 "parser.y" /* yacc.c:1646  */
    {symbol_table->cnt_upd++;}
#line 1626 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 137 "parser.y" /* yacc.c:1646  */
    {(yyval.type) = (yyvsp[0].type);}
#line 1632 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 138 "parser.y" /* yacc.c:1646  */
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
#line 1649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 152 "parser.y" /* yacc.c:1646  */
    {(yyval.type) = BuildType("integer");}
#line 1655 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 153 "parser.y" /* yacc.c:1646  */
    {(yyval.type) = BuildType("real");}
#line 1661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 154 "parser.y" /* yacc.c:1646  */
    {(yyval.type) = BuildType("string");}
#line 1667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 159 "parser.y" /* yacc.c:1646  */
    {symbol_table->cnt_upd++;}
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 164 "parser.y" /* yacc.c:1646  */
    {symbol_table->current_level++;
			
	}
#line 1681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 169 "parser.y" /* yacc.c:1646  */
    {/*compound_statement*/}
#line 1687 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 170 "parser.y" /* yacc.c:1646  */
    {symbol_table->current_level--;
			strcpy(symbol_table->scope, symbol_table->scopes[symbol_table->current_level]);
	}
#line 1695 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 175 "parser.y" /* yacc.c:1646  */
    {
			TableEntry* tmp = BuildTableEntry((yyvsp[0].str), symbol_table->scope, symbol_table->current_level, BuildType("function"), yylineno, symbol_table->cnt_upd);                           
	  		InsertTableEntry(symbol_table,tmp);
			strcpy(symbol_table->scopes[symbol_table->current_level], (yyvsp[0].str));
			strcpy(symbol_table->scope, (yyvsp[0].str));
		}
#line 1706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 180 "parser.y" /* yacc.c:1646  */
    { //printf("%s||", $2);
			AddparaToFunc(symbol_table, (yyvsp[-2].str), yylineno);
		}
#line 1714 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 183 "parser.y" /* yacc.c:1646  */
    {
			symbol_table->cnt_upd++;
			char* tmp;
			tmp = (char*)malloc(sizeof(char)*32);
			//printf("%s", $7);
			strcpy(tmp, (yyvsp[-1].type)->name);
			UpdateFunctionRet(symbol_table, (yyvsp[-1].type), yylineno);
                }
#line 1727 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 191 "parser.y" /* yacc.c:1646  */
    {
			TableEntry* tmp = BuildTableEntry((yyvsp[0].str), symbol_table->scope, symbol_table->current_level, BuildType("procedure"), yylineno, symbol_table->cnt_upd);
                	InsertTableEntry(symbol_table,tmp);
			//AddparaToFunc(symbol_table, $2, yylineno);
			symbol_table->cnt_upd++;
			strcpy(symbol_table->scopes[symbol_table->current_level], (yyvsp[0].str));
                        strcpy(symbol_table->scope, (yyvsp[0].str));
		}
#line 1740 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 199 "parser.y" /* yacc.c:1646  */
    {
			AddparaToFunc(symbol_table, (yyvsp[-2].str), yylineno);
		}
#line 1748 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 201 "parser.y" /* yacc.c:1646  */
    {
			symbol_table->cnt_upd++;
		}
#line 1756 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 206 "parser.y" /* yacc.c:1646  */
    {
	  symbol_table->current_level++;
	//printf("2.%s  \n", symbol_table->scopes[symbol_table->current_level]);
	  strcpy(symbol_table->scopes[symbol_table->current_level], symbol_table->scopes[symbol_table->current_level-1]);
	  strcpy(symbol_table->scope, symbol_table->scopes[symbol_table->current_level]);
	//printf("1.%s  \n", symbol_table->scopes[symbol_table->current_level]);
	}
#line 1768 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 213 "parser.y" /* yacc.c:1646  */
    {symbol_table->current_level--;
	  strcpy(symbol_table->scope, symbol_table->scopes[symbol_table->current_level]);
	}
#line 1776 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 219 "parser.y" /* yacc.c:1646  */
    {
			UpdateType(symbol_table, (yyvsp[0].type), yylineno);
			//printf("}}%d{{", symbol_table->cnt_upd);
		}
#line 1785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 223 "parser.y" /* yacc.c:1646  */
    {
			//printf("}}%d{{", symbol_table->cnt_upd);
                        UpdateType(symbol_table, (yyvsp[0].type), yylineno);
		}
#line 1794 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 227 "parser.y" /* yacc.c:1646  */
    {
			symbol_table->cnt_upd++;
		}
#line 1802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 237 "parser.y" /* yacc.c:1646  */
    {symbol_table->current_level++;
	strcpy(symbol_table->scopes[symbol_table->current_level], symbol_table->scopes[symbol_table->current_level-1]);
	strcpy(symbol_table->scope, symbol_table->scopes[symbol_table->current_level]);   
	//symbol_table->current_level++;
		}
#line 1812 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 243 "parser.y" /* yacc.c:1646  */
    {symbol_table->current_level--;
		strcpy(symbol_table->scope, symbol_table->scopes[symbol_table->current_level]);
		//symbol_table->current_level--;
		}
#line 1821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 255 "parser.y" /* yacc.c:1646  */
    {symbol_table->cnt_upd++;}
#line 1827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 259 "parser.y" /* yacc.c:1646  */
    {
	//TableEntry* tmp = FindEntryInScope(symbol_table, $1->name);
	UpdateValue(symbol_table, (yyvsp[-2].value)->name, (yyvsp[0].value));
	}
#line 1836 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 270 "parser.y" /* yacc.c:1646  */
    {
	 (yyval.value) = ReturnIdValue(symbol_table, (yyvsp[-1].str), tail, tail_cnt, 'l');
		int j;
		for(j = 0; j < tail_cnt; j++){
                        tail[j] = 0;
                }
		tail_cnt = 0;
}
#line 1849 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 280 "parser.y" /* yacc.c:1646  */
    {
	 	//printf("%f ", $2->dval);
		if(!strcmp((yyvsp[-2].value)->type->name, "integer")){
			tail[tail_cnt] = (yyvsp[-2].value)->ival;
			tail_cnt++;
		}
		else{
			printf("Real cannot be index, Wrong in Line: %d\n", yylineno);
			tail[tail_cnt] = -1;
			tail_cnt++;
		}
	}
#line 1866 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 292 "parser.y" /* yacc.c:1646  */
    {(yyval.value) = NULL;}
#line 1872 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 295 "parser.y" /* yacc.c:1646  */
    {
		    BuildProcId(symbol_table, (yyvsp[0].str), para, para_cnt);
		    para_cnt = 0;
			}
#line 1881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 299 "parser.y" /* yacc.c:1646  */
    {
		    BuildProcId(symbol_table, (yyvsp[-3].str), para, para_cnt);
                    para_cnt = 0;
			}
#line 1890 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 305 "parser.y" /* yacc.c:1646  */
    {
		if(!strcmp((yyvsp[0].value)->type->name, "integer")) {
			para[para_cnt] = 'i';
			parav[para_cnt] = (yyvsp[0].value)->ival;
			//printf("\n|%c|\n",para[para_cnt]);
		}
		else if(!strcmp((yyvsp[0].value)->type->name, "real")){
			para[para_cnt] = 'r';
			parav[para_cnt] = (yyvsp[0].value)->dval;
			//printf("\n%c\n",para[para_cnt]);
		}
		//else printf("8787%s%d8787\n", $1->name, yylineno);
		//printf("|%s|%s|%d|||||||||", $1->type->name, $1->ret, para_cnt);
		para_cnt++;
		
		}
#line 1911 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 321 "parser.y" /* yacc.c:1646  */
    {
		if(!strcmp((yyvsp[0].value)->type->name, "integer")) {
                	para[para_cnt] =  'i';
                	parav[para_cnt] = (yyvsp[0].value)->ival;
			//printf("\n|%c|\n",para[para_cnt]);
                }
                else if(!strcmp((yyvsp[0].value)->type->name, "real")){
                	para[para_cnt] = 'r';
                	parav[para_cnt] = (yyvsp[0].value)->dval;
                }
		
		//printf("|%s|%s|%d||||||||", $3->type->name, $3->ret, para_cnt);
		para_cnt++;
		}
#line 1930 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 337 "parser.y" /* yacc.c:1646  */
    {(yyval.value) = (yyvsp[0].value);}
#line 1936 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 342 "parser.y" /* yacc.c:1646  */
    {(yyval.value) = (yyvsp[0].value);}
#line 1942 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 345 "parser.y" /* yacc.c:1646  */
    {(yyval.value) = (yyvsp[0].value); }
#line 1948 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 346 "parser.y" /* yacc.c:1646  */
    { 
		//printf("%s %s||\n", $1->type->name, $3->type->name);
		(yyval.value) = Addtwo((yyvsp[-2].value), (yyvsp[0].value), (yyvsp[-1].str), yylineno);
		//printf("%doepwo",$$->ival);
	}
#line 1958 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 354 "parser.y" /* yacc.c:1646  */
    {(yyval.value) = (yyvsp[0].value);}
#line 1964 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 355 "parser.y" /* yacc.c:1646  */
    {
		(yyval.value) = Multwo((yyvsp[-2].value), (yyvsp[0].value), (yyvsp[-1].str), yylineno);
		//`printf("%s", $$->sval);
		}
#line 1973 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 362 "parser.y" /* yacc.c:1646  */
    {
	(yyval.value) = ReturnIdValue(symbol_table, (yyvsp[-1].str), tail, tail_cnt, 'r');
		int j;
		for(j = 0; j < tail_cnt; j++){
        	        tail[j] = 0;
                }
		tail_cnt = 0;
	}
#line 1986 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 370 "parser.y" /* yacc.c:1646  */
    {//$$ = BuildValue("integer", "-88");
		(yyval.value) = BuildFuncId(symbol_table, (yyvsp[-3].str), para, para_cnt);
		//printf("%d", para_cnt);
		para_cnt = 0;
	}
#line 1996 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 375 "parser.y" /* yacc.c:1646  */
    {
		//$$ = $1;
		//printf("%s", $1->sval);
		char* tmp;
		tmp = (char*)malloc(sizeof(char)*32);
		if(!strcmp((yyvsp[0].value)->type->name, "integer")){
			tmp = itoa((yyvsp[0].value)->ival);
			(yyval.value) = BuildValue("integer", tmp);
			(yyval.value)->is_const = 1;
			//printf("%s", tmp);
		}
		else{
			strcpy(tmp, (yyvsp[0].value)->sval);
			(yyval.value) = BuildValue("real", tmp);
			(yyval.value)->is_const = 1;
		}
		//printf("%skkkk%d %d\n", $$->type->name, $$->ival, yylineno);
		}
#line 2019 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 393 "parser.y" /* yacc.c:1646  */
    {(yyval.value) = BuildValue("string", yytext);
			(yyval.value)->is_const = 1;}
#line 2026 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 395 "parser.y" /* yacc.c:1646  */
    {(yyval.value) = (yyvsp[-1].value);}
#line 2032 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 396 "parser.y" /* yacc.c:1646  */
    {(yyval.value) = (yyvsp[0].value);}
#line 2038 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2042 "y.tab.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
#line 414 "parser.y" /* yacc.c:1906  */


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
