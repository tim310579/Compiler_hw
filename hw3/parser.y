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
%type <type> type standard_type 
%type <value> expression term factor tail boolexpression simple_expression
%type <value> variable num

  

%start prog
%%


prog  : PROGRAM id {
      	TableEntry* tmp = BuildTableEntry($2, symbol_table->current_level, BuildType("program"), yylineno);
	InsertTableEntry(symbol_table,tmp);
	}
      LPAREN {
		symbol_table->current_level++;

	}identifier_list RPAREN{
		AddparaToFunc(symbol_table, $2, yylineno);
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
		TableEntry* tmp=BuildTableEntry($1, symbol_table->current_level, BuildType("void"), yylineno);
		InsertTableEntry(symbol_table,tmp);
}
		| identifier_list COMMA id {
                TableEntry* tmp=BuildTableEntry($3, symbol_table->current_level, BuildType("void"), yylineno);
                InsertTableEntry(symbol_table,tmp);
}
		;

declarations : declarations VAR identifier_list COLON type{
		UpdateType(symbol_table, $5, yylineno);}
	     SEMICOLON
		|
		;


type : standard_type {$$ = $1;}
		| ARRAY LBRAC num DOTDOT num RBRAC OF type {
				//$8->arr_dim++;
				//$$ = $8;
				//printf("%d, %d\n", $3->ival, $5->ival);
				$8->arr_range[($8->arr_dim)*2] = $3->ival;
				$8->arr_range[($8->arr_dim)*2+1] = $5->ival;
				$8->arr_dim++;
				$$ = $8;
				//$$ = BuildType(
				//$$ = BuildArrayType(tmp, $3->ival, $5->ival);
				
				}				
		;

standard_type : INTEGER {$$ = BuildType("integer");}
		| REAL	{$$ = BuildType("real");}	
		| STRING{$$ = BuildType("string");}
		;


subprogram_declarations :
	subprogram_declarations subprogram_declaration SEMICOLON
		| 
		;

subprogram_declaration :
	subprogram_head {symbol_table->current_level++;
			strcpy(symbol_table->scope, "in_func_or_proc");
	}
	declarations 			
	subprogram_declarations
	compound_statement {symbol_table->current_level--;
			strcpy(symbol_table->scope, "global");		
	}
	;

subprogram_head : FUNCTION id {
			TableEntry* tmp = BuildTableEntry($2, symbol_table->current_level, BuildType("function"), yylineno);                           
	  		InsertTableEntry(symbol_table,tmp);
		}arguments{ //printf("%s||", $2);
			AddparaToFunc(symbol_table, $2, yylineno);
		}
		 COLON standard_type SEMICOLON{
			char* tmp;
			tmp = (char*)malloc(sizeof(char)*32);
			//printf("%s", $7);
			strcpy(tmp, $7->name);
			UpdateFunctionRet(symbol_table, $7, yylineno);
                }
		| PROCEDURE id arguments SEMICOLON{
			TableEntry* tmp = BuildTableEntry($2, symbol_table->current_level, BuildType("procedure"), yylineno);
                	InsertTableEntry(symbol_table,tmp);
			AddparaToFunc(symbol_table, $2, yylineno);
		}
		;

arguments : LPAREN {symbol_table->current_level++;}
	  parameter_list RPAREN{symbol_table->current_level--;}
		|
		;

parameter_list : optional_var identifier_list COLON type {
		UpdateType(symbol_table, $4, yylineno);
		}
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
	if(IsFunction(symbol_table, $1) == 1 && strcmp(symbol_table->scope, "in_func_or_proc")){
		printf("In Line %d, Function cannot in left side: %s\n", yylineno, $1);
	}
	
}
		;

tail     : LBRAC expression RBRAC tail {}
		| {}
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

simple_expression : term {$$ = $1; printf("%d  %s|||", $$->ival, $$->sval);}
		| simple_expression addop term { $$ = $3; printf("%d  %s  %s|||", $$->ival, $$->sval, $2);
		$$ = Addtwo($1, $3, $2);
		printf("||||%s}}}}", $$->sval);
		}
		
		;

term : factor {$$ = $1;}
		| term mulop factor { $$ = BuildValue("real", "16");
		/*$$ = Multwo($1, $3, $2);*/}
				
		;

factor : id tail {$$ = BuildValue("integer", "99");}
	| id LPAREN expression_list RPAREN{$$ = BuildValue("integer", "49");}
	| num {
		//$$ = $1;
		//printf("%s", $1->sval);
		char* tmp;
		tmp = (char*)malloc(sizeof(char)*32);
		if(!strcmp($1->type->name, "integer")){
			tmp = itoa($1->ival);
			$$ = BuildValue("integer", tmp);
			//printf("%s", tmp);
		}
		else{
			strcpy(tmp, $1->sval);
			$$ = BuildValue("real", tmp);
		}
		
		//printf("%s  ", $$->sval);
		
		}
        | STRINGCONST {$$ = BuildValue("string", yytext);}
	| LPAREN expression RPAREN {$$ = $2;}
	| NOT factor {$$ = $2;}
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
