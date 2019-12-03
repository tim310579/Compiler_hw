/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 41 "parser.y" /* yacc.c:1909  */

	int num;
	double dnum;
	char* str;
	struct Value* value;
	struct Type* type;
	struct TableEntry* tableentry;
	
	

#line 209 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
