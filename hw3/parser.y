%{
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
TableEntry* entry_buf;
IdList* idlist_buf;
Type* return_buf;
int has_ret=0;
int loop_cnt =0;
%}

%union	{
	int num;
	double dnum;
	char* str;
	int nodetype;
	struct Value* value;
	struct Type* type;
	struct TableEntry* tableentry;
	struct TypeList* typelist;
	struct Expr* expression;
	struct ExprList* exprlist;
		}
%token <num> DIGSEQ 
%token <str> AND ARRAY ASSIGNMENT CASE CHARACTER_STRING COLON COMMA CONST 
%token <str> DIV DO DOT DOTDOT DOWNTO ELSE END EQUAL EXTERNAL FOR FORWARD FUNCTION
%token <str> GE GOTO GT IDENTIFIER IF IN LABEL LBRAC LE LPAREN LT MINUS MOD NIL NOT
%token <str> notEQUAL OF OR OTHERWISE PACKED PBEGIN PFILE PLUS PROCEDURE PROGRAM RBRAC
%token <str> RECORD REPEAT RPAREN SEMICOLON SET SLASH STAR STARSTAR THEN
%token <str> TO TYPE UNTIL UPARROW VAR WHILE WITH
%token <str> STRING WRONGIDEN ERROR INTEGER REAL STRINGCONST

%token <str> REALNUMBER 
%type <str> relop mulop addop id 
%type <str> type standard_type 

%type <value> num variable

  

%start prog
%%


prog  : PROGRAM id {
      	TableEntry* tmp = BuildTableEntry($2,symbol_table->scope, symbol_table->current_level, "void", yylineno);
	InsertTableEntry(symbol_table,tmp);
	}
      LPAREN {
		symbol_table->current_level++;

	}identifier_list RPAREN{
		symbol_table->current_level--;
	}
	 SEMICOLON
	declarations
	subprogram_declarations
	compound_statement
 	DOT
	;

num : DIGSEQ {$$ = BuildValue("integer", yytext);}
	| REALNUMBER	{$$ = BuildValue("real", yytext);}
	;


id : IDENTIFIER
	;


identifier_list : id{
		TableEntry* tmp=BuildTableEntry($1, symbol_table->scope, symbol_table->current_level, "void", yylineno);
		InsertTableEntry(symbol_table,tmp);
}
		| identifier_list COMMA id {
                TableEntry* tmp=BuildTableEntry($3, symbol_table->scope, symbol_table->current_level, "void", yylineno);
                InsertTableEntry(symbol_table,tmp);
}
		;

declarations : declarations VAR identifier_list COLON type {UpdateType(symbol_table, $5, yylineno);}
	     SEMICOLON
		|
		;


type : standard_type {$$ = $1;}
		| ARRAY LBRAC num DOTDOT num RBRAC OF type {
				strcpy($$, "array");
				}				
		;

standard_type : INTEGER {strcpy($$, "integer");}
		| REAL	{strcpy($$, "real");}	
		| STRING{strcpy($$, "string");}
		;


subprogram_declarations :
	subprogram_declarations subprogram_declaration SEMICOLON
		| 
		;

subprogram_declaration :
	subprogram_head {symbol_table->current_level++;}
	declarations 			
	subprogram_declarations
	compound_statement
	;

subprogram_head : FUNCTION id
		arguments COLON standard_type{
		TableEntry* tmp = BuildTableEntry($2, symbol_table->scope, symbol_table->current_level, "function", yylineno);          
                InsertTableEntry(symbol_table,tmp);
		UpdateFunctionRet(symbol_table, $2, $5, yylineno);
                } SEMICOLON
		| PROCEDURE id arguments SEMICOLON
		;

arguments : LPAREN parameter_list RPAREN
		|
		;

parameter_list : optional_var identifier_list COLON type {UpdateType(symbol_table, $4, yylineno);}
		| optional_var identifier_list COLON type SEMICOLON parameter_list 
		;

optional_var   : VAR
        	| 
		;

compound_statement : PBEGIN {symbol_table->current_level++;}
		     optional_statements
		     END {symbol_table->current_level--;}
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

variable : id tail {
	 if(FindEntryInGlobal(symbol_table, $1) == NULL){	//is not already existed
		printf("Undeclared variable in Line %d : %s\n", yylineno, $1);
	}
	if(IsFunction(symbol_table, $1) == 1){
		printf("In Line %d, Function cannot in left side: %s\n", yylineno, $1);
	}
	
}
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
