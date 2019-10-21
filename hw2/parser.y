%{
#include <stdio.h>
#include <stdlib.h>

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
void yyerror(const char *s);
%}

%token AND ARRAY ASSIGNMENT CASE CHARACTER_STRING COLON COMMA CONST DIGSEQ
%token DIV DO DOT DOTDOT DOWNTO ELSE END EQUAL EXTERNAL FOR FORWARD FUNCTION
%token GE GOTO GT IDENTIFIER IF IN LABEL LBRAC LE LPAREN LT MINUS MOD NIL NOT
%token NOTEQUAL OF OR OTHERWISE PACKED PBEGIN PFILE PLUS PROCEDURE PROGRAM RBRAC
%token REALNUMBER RECORD REPEAT RPAREN SEMICOLON SET SLASH STAR STARSTAR THEN
%token TO TYPE UNTIL UPARROW VAR WHILE WITH
%token STRING WRONGIDEN ERROR INTEGER REAL
%token num
%%


prog  : PROGRAM id '(' identifier_list ')' ';'
	declarations
	subprogram_declarations
	compound_statement
 	'.'
	;


id : IDENTIFIER
	;


identifier_list : id
		| identifier_list ',' id
		;

type : standard_type
		| ARRAY '[' num '.''.' num ']' OF type
		;

standard_type : INTEGER
		| REAL
        	| STRING
		;

declarations :
	     ;
subprogram_declarations :
	subprogram_declarations subprogram_declaration ';'
		| 
		;

subprogram_declaration :
	subprogram_head 
	declarations 			
        compound_statement
	;

subprogram_head : FUNCTION id arguments ':' standard_type ';'
		| PROCEDURE id arguments ';'
		;

arguments : '(' parameter_list ')'
		|
		;

parameter_list : optional_var identifier_list ':' type
		| optional_var identifier_list ':' type ';' parameter_list 
		;

optional_var   : VAR
        	| 
		;

compound_statement : PBEGIN
		       optional_statements
		       END
		;

optional_statements : statement_list
		|
		;

statement_list : statement
		| statement_list ';' statement
		;

statement : variable ':''=' expression
		| procedure_statement
		| compound_statement
		| IF expression THEN statement ELSE statement
		| WHILE expression DO statement
		|
		;

variable : id tail
		;

tail     : '[' expression ']' tail
		|
		;

procedure_statement : id
		| id '(' expression_list ')'
		;

expression_list : expression
		| expression_list ',' expression
		;

expression : simple_expression
		| simple_expression relop simple_expression
		;

simple_expression : term
		| simple_expression addop term
		;

term : factor
		| term mulop factor
		;

factor : id tail
	| id '(' expression_list ')'
	| num
        | STRING
	| '(' expression ')'
	| NOT factor
	;

addop : '+' | '-'
	;

mulop : '*' | '/'
	;


relop : '<'
	| '>'
	| '='
	| '<''='
	| '>''='
	| '!''='
	;
