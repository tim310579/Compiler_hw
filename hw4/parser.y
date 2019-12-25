%{
#include <stdio.h>
#include <stdlib.h>
#include "symtab.h"
#include "gencode.h"
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

char fileName[256];
%}

%union	{
	int num;
	double dnum;
	char* str;
	struct Value* value;
	struct Type* type;
	struct TableEntry* tableentry;
	
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
%type <type> type standard_type identifier_list
%type <value> expression term factor boolexpression simple_expression expression_list 
%type <value> num
%type <value> variable 
%type <value> tail
  

%start prog
%%


prog  : PROGRAM id {
      	TableEntry* tmp = BuildTableEntry($2, symbol_table->scopes[symbol_table->current_level], symbol_table->current_level, BuildType("program"), yylineno, symbol_table->cnt_upd);
	InsertTableEntry(symbol_table,tmp);
	strcpy(fileName, $2);
	GenProgramStart(fileName);
	//printf("%s\n\n", fileName);
	}
      LPAREN {
		symbol_table->current_level++;
		strcpy(symbol_table->scope, $2);
		strcpy(symbol_table->scopes[symbol_table->current_level], $2);
		printf("New scope '%s' is generated at Line %d\n", $2, yylineno);
	}identifier_list RPAREN{
		AddparaToFunc(symbol_table, $2, yylineno);
		symbol_table->current_level--;
		strcpy(symbol_table->scope, symbol_table->scopes[symbol_table->current_level]);
	
	}
	 SEMICOLON{
		symbol_table->cnt_upd++;
		symbol_table->current_level++;
		strcpy(symbol_table->scopes[symbol_table->current_level], $2);
		strcpy(symbol_table->scope, symbol_table->scopes[symbol_table->current_level]);
	}
	declarations
	subprogram_declarations{symbol_table->current_level--;
        strcpy(symbol_table->scope, symbol_table->scopes[symbol_table->current_level]);
	//printf("Scope '%s' is closed at Line %d\n", $2, yylineno);
	}
	compound_statement
 	{printf("Scope '%s' is closed at Line %d\n", $2, yylineno);
	//symbol_table->current_level--;
	//printf("%d\n", symbol_table->current_level);
	//strcpy(symbol_table->scope, symbol_table->scopes[symbol_table->current_level]);	
	}
	DOT
	;

num : DIGSEQ {$$ = BuildValue("integer", yytext);
    		$$->is_const = 1;}
	| REALNUMBER	{$$ = BuildValue("real", yytext);
		$$->is_const = 1;}
	| MINUS DIGSEQ{
	//printf("%s|||", yytext);
		$$ = BuildNegValue("integer", yytext);
		$$->is_const = 1;}
	;


id : IDENTIFIER
	;


identifier_list : id{
		TableEntry* tmp=BuildTableEntry($1, symbol_table->scope, symbol_table->current_level, BuildType("void"), yylineno, symbol_table->cnt_upd);
		InsertTableEntry(symbol_table,tmp);
}
		| identifier_list COMMA id {
                TableEntry* tmp=BuildTableEntry($3, symbol_table->scope, symbol_table->current_level, BuildType("void"), yylineno, symbol_table->cnt_upd);
                InsertTableEntry(symbol_table,tmp);
}
		;

declarations : declarations VAR identifier_list COLON type{
		UpdateType(symbol_table, $5, yylineno);}
	     SEMICOLON{symbol_table->cnt_upd++;}
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
	subprogram_declarations subprogram_declaration SEMICOLON{symbol_table->cnt_upd++;}
		| 
		;

subprogram_declaration :
	subprogram_head {
		printf("New scope '%s' is generated at Line %d\n", symbol_table->scopes[symbol_table->current_level], yylineno);
		symbol_table->current_level++;
	}
	declarations
	subprogram_declarations
	{/*compound_statement*/}
	 {
		symbol_table->current_level--;
		strcpy(symbol_table->scope, symbol_table->scopes[symbol_table->current_level]);
	}compound_statement{
		printf("Scope '%s' is closed at Line %d\n", symbol_table->scopes[symbol_table->current_level], yylineno);
	}
	;

subprogram_head : FUNCTION id {
			TableEntry* tmp = BuildTableEntry($2, symbol_table->scope, symbol_table->current_level, BuildType("function"), yylineno, symbol_table->cnt_upd);                           
	  		InsertTableEntry(symbol_table,tmp);
			strcpy(symbol_table->scopes[symbol_table->current_level], $2);
			strcpy(symbol_table->scope, $2);
		}arguments{ //printf("%s||", $2);
			AddparaToFunc(symbol_table, $2, yylineno);
		}
		 COLON standard_type SEMICOLON{
			symbol_table->cnt_upd++;
			char* tmp;
			tmp = (char*)malloc(sizeof(char)*32);
			//printf("%s", $7);
			strcpy(tmp, $7->name);
			UpdateFunctionRet(symbol_table, $7, yylineno);
                }
		| PROCEDURE id{
			TableEntry* tmp = BuildTableEntry($2, symbol_table->scope, symbol_table->current_level, BuildType("procedure"), yylineno, symbol_table->cnt_upd);
                	InsertTableEntry(symbol_table,tmp);
			//AddparaToFunc(symbol_table, $2, yylineno);
			symbol_table->cnt_upd++;
			strcpy(symbol_table->scopes[symbol_table->current_level], $2);
                        strcpy(symbol_table->scope, $2);
		}
		arguments {
			AddparaToFunc(symbol_table, $2, yylineno);
		}SEMICOLON{
			symbol_table->cnt_upd++;
		}
		;

arguments : LPAREN {
	  symbol_table->current_level++;
	//printf("2.%s  \n", symbol_table->scopes[symbol_table->current_level]);
	  strcpy(symbol_table->scopes[symbol_table->current_level], symbol_table->scopes[symbol_table->current_level-1]);
	  strcpy(symbol_table->scope, symbol_table->scopes[symbol_table->current_level]);
	//printf("1.%s  \n", symbol_table->scopes[symbol_table->current_level]);
	}
	  parameter_list RPAREN{symbol_table->current_level--;
	  strcpy(symbol_table->scope, symbol_table->scopes[symbol_table->current_level]);
	}
		|
		;

parameter_list : optional_var identifier_list COLON type {
			UpdateType(symbol_table, $4, yylineno);
			//printf("}}%d{{", symbol_table->cnt_upd);
		}
		| optional_var identifier_list COLON type{
			//printf("}}%d{{", symbol_table->cnt_upd);
                        UpdateType(symbol_table, $4, yylineno);
		}
		 SEMICOLON{
			symbol_table->cnt_upd++;
		}
		parameter_list
		;

optional_var   : VAR
        	| 
		;

compound_statement : PBEGIN {symbol_table->current_level++;
	strcpy(symbol_table->scopes[symbol_table->current_level], symbol_table->scopes[symbol_table->current_level-1]);
	strcpy(symbol_table->scope, symbol_table->scopes[symbol_table->current_level]);   
	//symbol_table->current_level++;
		}
		     optional_statements
		     END {symbol_table->current_level--;
		strcpy(symbol_table->scope, symbol_table->scopes[symbol_table->current_level]);
		//symbol_table->current_level--;
		}
		;


optional_statements : statement_list
		|
		;

statement_list : statement
		| statement_list SEMICOLON {symbol_table->cnt_upd++;}
		statement
		;

statement : variable ASSIGNMENT expression {
	//TableEntry* tmp = FindEntryInScope(symbol_table, $1->name);
	UpdateValue(symbol_table, $1->name, $3);
	}
		| procedure_statement
		| compound_statement
		| IF expression THEN statement ELSE statement
		| WHILE expression DO statement
		|
		;

variable : id tail {
	 $$ = ReturnIdValue(symbol_table, $1, tail, tail_cnt, 'l');
		int j;
		for(j = 0; j < tail_cnt; j++){
                        tail[j] = 0;
                }
		tail_cnt = 0;
}
		;

tail     : LBRAC expression RBRAC tail {
	 	//printf("%f ", $2->dval);
		if(!strcmp($2->type->name, "integer")){
			tail[tail_cnt] = $2->ival;
			tail_cnt++;
		}
		else{
			printf("Real cannot be index, Wrong in Line: %d\n", yylineno);
			tail[tail_cnt] = -1;
			tail_cnt++;
		}
	}
		| {$$ = NULL;}
		;

procedure_statement : id {
		    BuildProcId(symbol_table, $1, para, para_cnt);
		    para_cnt = 0;
			}
		| id LPAREN expression_list RPAREN{
		    BuildProcId(symbol_table, $1, para, para_cnt);
                    para_cnt = 0;
			}
		;

expression_list : expression {
		if(!strcmp($1->type->name, "integer")) {
			para[para_cnt] = 'i';
			parav[para_cnt] = $1->ival;
			//printf("\n|%c|\n",para[para_cnt]);
		}
		else if(!strcmp($1->type->name, "real")){
			para[para_cnt] = 'r';
			parav[para_cnt] = $1->dval;
			//printf("\n%c\n",para[para_cnt]);
		}
		//else printf("8787%s%d8787\n", $1->name, yylineno);
		//printf("|%s|%s|%d|||||||||", $1->type->name, $1->ret, para_cnt);
		para_cnt++;
		
		}
		| expression_list COMMA expression {
		if(!strcmp($3->type->name, "integer")) {
                	para[para_cnt] =  'i';
                	parav[para_cnt] = $3->ival;
			//printf("\n|%c|\n",para[para_cnt]);
                }
                else if(!strcmp($3->type->name, "real")){
                	para[para_cnt] = 'r';
                	parav[para_cnt] = $3->dval;
                }
		
		//printf("|%s|%s|%d||||||||", $3->type->name, $3->ret, para_cnt);
		para_cnt++;
		}
		;

expression : boolexpression {$$ = $1;} 
		| boolexpression AND boolexpression 
		| boolexpression OR boolexpression 
		;

boolexpression : simple_expression {$$ = $1;}
	       | simple_expression relop simple_expression 

simple_expression : term {$$ = $1; }
		| simple_expression addop term { 
		//printf("%s %s||\n", $1->type->name, $3->type->name);
		$$ = Addtwo($1, $3, $2, yylineno);
		//printf("%doepwo",$$->ival);
	}
		
		;

term : factor {$$ = $1;}
		| term mulop factor {
		$$ = Multwo($1, $3, $2, yylineno);
		//`printf("%s", $$->sval);
		}
				
		;

factor : id tail {
	$$ = ReturnIdValue(symbol_table, $1, tail, tail_cnt, 'r');
		int j;
		for(j = 0; j < tail_cnt; j++){
        	        tail[j] = 0;
                }
		tail_cnt = 0;
	}
	| id LPAREN expression_list RPAREN{//$$ = BuildValue("integer", "-88");
		$$ = BuildFuncId(symbol_table, $1, para, para_cnt);
		//printf("%d", para_cnt);
		para_cnt = 0;
	}
	| num {
		//$$ = $1;
		//printf("%s", $1->sval);
		char* tmp;
		tmp = (char*)malloc(sizeof(char)*32);
		if(!strcmp($1->type->name, "integer")){
			tmp = itoa($1->ival);
			$$ = BuildValue("integer", tmp);
			$$->is_const = 1;
			//printf("%s", tmp);
		}
		else{
			strcpy(tmp, $1->sval);
			$$ = BuildValue("real", tmp);
			$$->is_const = 1;
		}
		//printf("%skkkk%d %d\n", $$->type->name, $$->ival, yylineno);
		}
        | STRINGCONST {$$ = BuildValue("string", yytext);
			$$->is_const = 1;}
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
