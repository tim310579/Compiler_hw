%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtab.h"

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
TableEntry* entry_buf;
IdList* idlist;
%}
%union	{
	int num;
	double dnum;
	char* str;
	char** idlist;
	//idlist* idlist;
	//node *expr;
	
	//Value* value;
	char* type;
	//TableEntry* tableentry;
	//TypeList* typelist;
	//Expr* expression;
	//ExprList* exprlist;
		}

%token AND ARRAY ASSIGNMENT CASE CHARACTER_STRING COLON COMMA CONST DIGSEQ
%token DIV DO DOT DOTDOT DOWNTO ELSE END EQUAL EXTERNAL FOR FORWARD FUNCTION
%token GE GOTO GT 
%token IDENTIFIER 
%token IF IN LABEL LBRAC LE LPAREN LT MINUS MOD NIL NOT
%token notEQUAL OF OR OTHERWISE PACKED PBEGIN PFILE PLUS PROCEDURE PROGRAM RBRAC
%token REALNUMBER RECORD REPEAT RPAREN SEMICOLON SET SLASH STAR STARSTAR THEN
%token TO TYPE UNTIL UPARROW VAR WHILE WITH
%token STRING WRONGIDEN ERROR INTEGER REAL

%type <str> id standard_type type

%type <str> AND ARRAY ASSIGNMENT CASE CHARACTER_STRING COLON COMMA CONST DIGSEQ
%type <str> DIV DO DOT DOTDOT DOWNTO ELSE END EQUAL EXTERNAL FOR FORWARD FUNCTION
%type <str> GE GOTO GT
%type <str> IDENTIFIER
%type <str> IF IN LABEL LBRAC LE LPAREN LT MINUS MOD NIL NOT
%type <str> notEQUAL OF OR OTHERWISE PACKED PBEGIN PFILE PLUS PROCEDURE PROGRAM RBRAC
%type <str>REALNUMBER RECORD REPEAT RPAREN SEMICOLON SET SLASH STAR STARSTAR THEN
%type <str> TO TYPE UNTIL UPARROW VAR WHILE WITH
%type <str> STRING WRONGIDEN ERROR INTEGER REAL

%%


prog  : PROGRAM id {
		TableEntry* tmp = BuildTableEntry($2, "program", "global", yylineno);
		InsertTableEntry(symbol_table, tmp);
	}
	 LPAREN {
		strcpy(symbol_table->scope, "in_prog");
		}
	identifier_list

		
	 RPAREN {
		strcpy(symbol_table->scope, symbol_table->pre_scope);
	}
	SEMICOLON
       
	declarations
	subprogram_declarations
	compound_statement
 	DOT
	;

identifier_list : id {
			TableEntry* tmp = BuildTableEntry($1, "var", symbol_table->scope, yylineno);
                        InsertTableEntry(symbol_table, tmp);
                }
                | identifier_list COMMA id{
			TableEntry* tmp = BuildTableEntry($3, "var", symbol_table->scope, yylineno);
                        InsertTableEntry(symbol_table, tmp);
                }
                ;
num : DIGSEQ
	| REALNUMBER
	| MINUS REALNUMBER
	| MINUS DIGSEQ	
	;


id : IDENTIFIER
	;

declarations : declarations VAR identifier_list{
	    				
						}
		 COLON type SEMICOLON
	 
		|
		;


type : standard_type {
			$$ = $1;	
			printf("%siii\n", $1);
			}
		| ARRAY LBRAC num DOTDOT num RBRAC OF type {
						//$8 = strcat($8, "array");
						printf("%s\n", $8);
								}
		;

standard_type : INTEGER {$$ = "integer";}
		| REAL	{$$ = "real"; }
		| STRING{$$ = "string";}
		;


subprogram_declarations :
	subprogram_declarations subprogram_declaration SEMICOLON
		| 
		;

subprogram_declaration :
	subprogram_head 
	declarations 			
	subprogram_declarations
	compound_statement
	;

subprogram_head : FUNCTION id arguments COLON standard_type SEMICOLON{
			
		}
		| PROCEDURE id arguments SEMICOLON
		;

arguments : LPAREN{strcpy(symbol_table->scope, "in_func");}
	  parameter_list RPAREN{strcpy(symbol_table->scope, symbol_table->pre_scope);}
		|
		;

parameter_list : optional_var identifier_list COLON type
		| optional_var identifier_list COLON type SEMICOLON parameter_list 
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
		| statement_list SEMICOLON statement
		;

statement : variable ASSIGNMENT expression
		| procedure_statement
		| compound_statement
		| IF expression THEN statement ELSE statement
		| WHILE expression DO statement
		|
		;

variable : id tail
		;

tail     : LBRAC expression RBRAC tail
		|
		;

procedure_statement : id
		| id LPAREN expression_list RPAREN
		;

expression_list : expression
		| expression_list COMMA expression
		;

expression : boolexpression
		| boolexpression AND boolexpression
		| boolexpression OR boolexpression
		;

boolexpression : simple_expression
	       | simple_expression relop simple_expression

simple_expression : term
		| simple_expression addop term
		;

term : factor
		| term mulop factor
		;

factor : id tail
	| id LPAREN expression_list RPAREN
	| num
        | STRING
	| LPAREN expression RPAREN
	| NOT factor
	;

addop : PLUS | MINUS
	;

mulop : STAR | SLASH
	;


relop : LT
	| GT
	| EQUAL
	| LE
	| GE
	| notEQUAL
	;

%%

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
