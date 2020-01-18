%{
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
	
	//GenProgramStart($2);
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
		//GenProgramStart($2);
        	//fprintf(outfp, "main:\n");
        	//init_space();
	}
	
	declarations
	subprogram_declarations{symbol_table->current_level--;
        strcpy(symbol_table->scope, symbol_table->scopes[symbol_table->current_level]);
	//printf("Scope '%s' is closed at Line %d\n", $2, yylineno);
	GenProgramStart($2);
        fprintf(outfp, "main:\n");
        init_space();
	}
	compound_statement
 	{printf("Scope '%s' is closed at Line %d\n", $2, yylineno);
	//symbol_table->current_level--;
	//printf("%d\n", symbol_table->current_level);
	//strcpy(symbol_table->scope, symbol_table->scopes[symbol_table->current_level]);	
	}
	DOT{recover_setting();}
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
		UpdateType(symbol_table, $5, yylineno);
		//printf("%d\n", array_space);
		array_space += Request_array_space(symbol_table, $5, yylineno, array_space, array_all);
		int i;
		for(i = 0 ; i < 10; i++){
			//printf("%f ", array_all[i]);
		}
		//printf("%d\n", array_space);
		//if($5->arr_dim > 0) array_cnt ++;
		}
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
	 {
		symbol_table->current_level--;
		strcpy(symbol_table->scope, symbol_table->scopes[symbol_table->current_level]);
	}compound_statement{
		end_func(symbol_table, symbol_table->scope);
		printf("Scope '%s' is closed at Line %d\n", symbol_table->scopes[symbol_table->current_level], yylineno);
	}
	;

subprogram_head : FUNCTION id {
			TableEntry* tmp = BuildTableEntry($2, symbol_table->scope, symbol_table->current_level, BuildType("function"), yylineno, symbol_table->cnt_upd);                           
			tmp->exe_space = exe_space;
			exe_space += 4;
			InsertTableEntry(symbol_table,tmp);
			strcpy(symbol_table->scopes[symbol_table->current_level], $2);
			strcpy(symbol_table->scope, $2);
		}arguments{ //printf("%s||", $2);
			AddparaToFunc(symbol_table, $2, yylineno);
		}
		 COLON standard_type SEMICOLON{
			//symbol_table->current_level++;
			symbol_table->cnt_upd++;
			char* tmp;
			tmp = (char*)malloc(sizeof(char)*32);
			//printf("%s", $7);
			strcpy(tmp, $7->name);
			UpdateFunctionRet(symbol_table, $7, yylineno);
         		//printf("%s\n\n\n\n", $2);
			init_func(symbol_table, $2);
			change_para_value(symbol_table, $2);
			//end_func(symbol_table, $2);
	       }
		| PROCEDURE id{
			TableEntry* tmp = BuildTableEntry($2, symbol_table->scope, symbol_table->current_level, BuildType("procedure"), yylineno, symbol_table->cnt_upd);
      			tmp->exe_space = exe_space;
			exe_space += 4;
			
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
			init_func(symbol_table, $2);
			change_para_value(symbol_table, $2);
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
	TableEntry* tmp = (TableEntry*)malloc(sizeof(TableEntry));
        tmp = FindEntryInScope(symbol_table, $1->name);
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
	
	if(!strcmp($3->type->name, "integer")) array_all[tmp_spaceL] = $3->ival;
	else if(!strcmp($3->type->name, "real")) array_all[tmp_spaceL] = $3->dval;
	else if(!strcmp($3->type->name, "function")){
		if(!strcmp($3->ret, "integer")) array_all[tmp_spaceL] = $3->ival;
		else array_all[tmp_spaceL] = $3->dval;
	}
	//printf("%d  %f\n\n", tmp_spaceL, $3->dval);
	//printf("%fhhhffff%d\n", $1->array_all[tmp_space], tmp_space);
	tmp_spaceL = 0;

}
		| procedure_statement
		| compound_statement
		| IF{nest_if++;} expression{
			//IF_decide();
			fprintf(outfp, "        beq     t0, zero, .IF%d_%dFalse		#pre->ifcnt, next->nest if cnt\n", if_cnt, nest_if);  //condition is false
		}
		 THEN statement{
			fprintf(outfp, "	j	.IF%d_%dend\n", if_cnt, nest_if);
		}
		 ELSE {
			fprintf(outfp, ".IF%d_%dFalse:\n", if_cnt, nest_if);
		}
		statement{
			fprintf(outfp, ".IF%d_%dend:\n", if_cnt, nest_if);
			nest_if--;
			if(nest_if == 0) if_cnt++;
		}
			
		| WHILE { 
			nest_loop ++;
			fprintf(outfp, ".Loop%d_%d:\n", loop_cnt, nest_loop); 
		}
	 	expression{ 
			fprintf(outfp, "	beq	t0, zero, .Loop%d_%dend\n", loop_cnt, nest_loop);// false condition
		}	 
		DO statement{
			fprintf(outfp, "	j	.Loop%d_%d\n", loop_cnt, nest_loop);
			fprintf(outfp, ".Loop%d_%dend:\n", loop_cnt, nest_loop);
			nest_loop --;
			if(nest_loop == 0) loop_cnt ++;
		}
		|
		;

variable : id tail {
	 $$ = ReturnIdValue(symbol_table, $1, tail, tail_cnt, 'l');
	//printf("hfhf");		
		int j, k, tmp = 0;
		//tmp_space = $$->array_space;
                for(j = tail_cnt-2; j >= 0; j--){
			int tmp2 = 1;
			for(k = j; k >= 0; k--){
				//printf("array length  %d  ", $$->array_length[k]);
				tmp2 *= $$->array_length[k];
				//printf("%d  ", tmp2);
			}
			//printf("%d  ", tail[j+1]);
			printf("tmp2 %d  tailj %d range %d ", tmp2, tail[j+1], $$->type->arr_range[(j+1)*2]);   
			tmp += tmp2*(tail[j+1]-$$->type->arr_range[(j+1)*2]);
		}
		tmp += tail[0];
		printf("tmp %d tail %d ", tmp, tail[tail_cnt-1]);
		tmp_spaceL = tmp;
		//printf("%d\nh\n\n", tmp_spaceL);
		if(tail_cnt > 0) Compute_Array_Space(tail, tail_cnt, $$);	//in a4
		
                for(j = 0; j < tail_cnt; j++){
                        //printf("%d  ", tail[j]);
                        tail[j] = 0;
                }
                //printf("\n");
	//fprintf(outfp, "	addi	s1, s1, %d\n", tail_cnt*4);
                tail_cnt = 0;
		//fprintf(outfp, "	addi	s1, s1, 40\n");
}
		;

tail     : LBRAC expression{
		fprintf(outfp, "	sw	t0, 0(s1)\n");
		fprintf(outfp, "	addi	s1, s1, -4\n"); 
	} RBRAC tail {
	 	//printf("%f ", $2->dval);
		
		if(!strcmp($2->type->name, "integer")){
			tail[tail_cnt] = $2->ival;
			tail_cnt++;
		}
		else{//printf("8787\n\n");
			printf("Non integer cannot be index, Wrong in Line: %d\n", yylineno);
			tail[tail_cnt] = -1;
			tail_cnt++;
		}
	}
		| {$$ = NULL;}
		;

procedure_statement : id {
		    
		    BuildProcId(symbol_table, $1, para, para_cnt);
		    para_cnt = 0;
			fprintf(outfp, "	call	%s\n", $1);
			}
		| id LPAREN{//fprintf(outfp, "	addi	s1, s1, -40\n");
		} expression_list RPAREN{
			ax = 0;
		    if((!strncmp("PrintInt", $1, 8)) || (!strncmp("printInt", $1, 8))){
			int i = 0;
		//	for(i = 0; i < para_cnt; i++){
				ready_printi(para_cnt);
		//	}
		    }
		    else if((!strncmp("PrintReal", $1, 9)) || (!strncmp("printReal", $1, 9))){
			int i = 0;	
			ready_printr(para_cnt);
			//for(i = 0; i < para_cnt; i++){
                          //      ieee[fl_cnt] = ready_printr(parav[i], fl_cnt);
                        //	fl_cnt ++;
			//}
		    }
		    else if((!strncmp("PrintString", $1, 11)) || (!strncmp("printString", $1, 11)) || (!strncmp("printlnString", $1, 13))){
			//Print_String(para_cnt, para, paras);
			int i = 0;
                        for(i = 0; i < para_cnt; i++){
				ready_prints(str_cnt, paras[i]);
				strcpy(LCSS[str_cnt], paras[i]);
				str_cnt++;
			}
		    }
		    else{
		    	BuildProcId(symbol_table, $1, para, para_cnt);
			fprintf(outfp, "	call	%s\n", $1);
                    }
		    para_cnt = 0;
			}
		;

expression_list : expression {
		if(!strcmp($1->type->name, "integer")) {
			para[para_cnt] = 'i';
			
			parav[para_cnt] = $1->ival;
			//printf("\n|%c|\n",para[para_cnt]);
			push_value_to_stack(symbol_table, $1, ax, fl_cnt);		
			
		}
		else if(!strcmp($1->type->name, "real")){
			para[para_cnt] = 'r';
			parav[para_cnt] = $1->dval;
			push_value_to_stack(symbol_table, $1, ax, fl_cnt);
			//fl_cnt ++;
			
		}
		else if(!strcmp($1->type->name, "string")){
			para[para_cnt] = 's';
			strcpy(paras[para_cnt], $1->sval);
			//printf("%s\n\n\n", $1->sval);
		}
		//push_value_to_stack($1, ax);
		ax ++;
		//else printf("8787%s%d8787\n", $1->name, yylineno);
		//printf("|%s|%s|%d|||||||||", $1->type->name, $1->ret, para_cnt);
		para_cnt++;
		
		}
		| expression_list COMMA expression {
		if(!strcmp($3->type->name, "integer")) {
                	para[para_cnt] =  'i';
                	parav[para_cnt] = $3->ival;
			push_value_to_stack(symbol_table, $3, ax, fl_cnt);
                }
                else if(!strcmp($3->type->name, "real")){
                	para[para_cnt] = 'r';
                	parav[para_cnt] = $3->dval;
			push_value_to_stack(symbol_table, $3, ax, fl_cnt);
			//fl_cnt ++;
			
                }
		else if(!strcmp($3->type->name, "string")){
                        para[para_cnt] = 's';
                        strcpy(paras[para_cnt], $3->sval);
                }
		//push_value_to_stack($3, ax);
		ax ++;
		//printf("|%s|%s|%d||||||||", $3->type->name, $3->ret, para_cnt);
		para_cnt++;
		}
		;

expression : boolexpression {$$ = $1;} 
		| boolexpression{
			fprintf(outfp, "	mv	s11, t0\n");
		}
		 AND boolexpression {
			fprintf(outfp, "	and	t0, s11, t0\n");
		}
		| boolexpression{
			fprintf(outfp, "        mv      s11, t0\n");
		}
		 OR boolexpression {
			fprintf(outfp, "        or	t0, s11, t0\n");
		}
		;

boolexpression : simple_expression {$$ = $1;}
	       | simple_expression relop simple_expression {
			char* tmp = compare_two($1, $3, $2);
			$$ = BuildValue("boolean", tmp);
			Exe_cmp($2, cmp_cnt);
			cmp_cnt++;
		}

simple_expression : term {$$ = $1; }
		| simple_expression addop{/*Prevent_rec(add_sub, mul_div);*/} term { 
		$$ = Addtwo($1, $4, $2, yylineno);
		infunc_exp --;
		Exe_add_sub(add_sub, $2, $1);
		//Prevent_rec_end();
		add_sub = -1;
	}
		
		;

term : factor {$$ = $1;
     		if(!strcmp($$->type->name, "integer")) op_type = 0;	//int operation
		else	op_type = 1;	//for real
	}
		| term mulop { /*Prevent_rec(add_sub, mul_div);*/}factor {
			$$ = Multwo($1, $4, $2, yylineno);
			Exe_mul_div(mul_div, $2, $1);
			//Prevent_rec_end();
			mul_div = -1;
		}
				
		;

factor : id tail {
	$$ = ReturnIdValue(symbol_table, $1, tail, tail_cnt, 'r');
		
		int j, k, tmp = 0;
		//tmp_space = $$->array_space;
                for(j = tail_cnt-2; j >= 0; j--){
			int tmp2 = 1;
			for(k = j; k >= 0; k--){
				printf("%d  ", $$->array_length[k]);
				tmp2 *= $$->array_length[k];
				//printf("%d  ", tmp2);
			}
			//printf("%d  ", tail[j+1]);
			tmp += tmp2*tail[j+1];
		}
		tmp += tail[0];

		//printf("tmp %d  \n", tmp);
		tmp_space = tmp;
		if(tail_cnt > 0) { //printf("bababa\n\n\n");
			if(!strcmp($$->type->name, "integer")) $$->ival = array_all[tmp_space];
			else $$->dval = array_all[tmp_space];
		}
		
		if(tail_cnt > 0){
			Compute_Array_Space_R(tail, tail_cnt, $$);
			
		}

		
		for(j = 0; j < tail_cnt; j++){
        	        tail[j] = 0;
                }

		TableEntry* t = (TableEntry*)malloc(sizeof(TableEntry));
		t = FindEntryInScope(symbol_table, $1);
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
			fprintf(outfp, "	call	%s\n", $1);
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
	| id { /*Prevent_rec(add_sub, mul_div);*/ }LPAREN{inexp++;} expression_list RPAREN{
		inexp --;
		infunc_exp ++;
		//$$ = BuildValue("integer", "-88");
		$$ = BuildFuncId(symbol_table, $1, para, para_cnt);
		//printf("%d", para_cnt);
		//fprintf(outfp, "	call 	%s\n", $1);
		//print_outcome();
		para_cnt = 0;
		ax = 0;
		//printf("WTFWTFFfsfs?????\n\n\n");
		fprintf(outfp, "	call	%s\n", $1);
		printf("name %s\n\n", $1);
		//Prevent_rec_end();
		//fprintf(outfp, "	ld	a0, -912(sp)\n");
		//fprintf(outfp, "	sw	a0, %d(s0)\n", 28);
		if(!strcmp(symbol_table->scope, $1)){
			Reload_para(symbol_table, $1);
		}
		pre_rec = -1;
	}
	| num {
		//$$ = $1;
		//printf("%dmul\n\n\n\n", $1->ival);
		char* tmp;
		tmp = (char*)malloc(sizeof(char)*32);
		if(!strcmp($1->type->name, "integer")){
			tmp = itoa($1->ival);
			$$ = BuildValue("integer", tmp);
			$$->is_const = 1;
			//printf("%s\n\n\n", tmp);
			fprintf(outfp, "	li	t0, %d\n", $1->ival);
		}
		else{
			strcpy(tmp, $1->sval);
			$$ = BuildValue("real", tmp);
			$$->is_const = 1;
			ieee[fl_cnt] = assign_float($1->dval, fl_cnt);
			//fl_cnt ++;
			//fprintf(outfp, "	

			fl_cnt++;
		}
		//printf("%skkkk%d %d\n", $$->type->name, $$->ival, yylineno);
		}
        | STRINGCONST {$$ = BuildValue("string", yytext);
			$$->is_const = 1;}
	| LPAREN {inexp++;}expression RPAREN {$$ = $3;
		inexp--;
	}
	| NOT factor {$$ = $2;
		fprintf(outfp, "	xor	t0, t0, 1\n");
		//fprintf(outfp, "        lui     a0, %%hi(.LCI)\n");
		//fprintf(outfp, "        mv      a1, t0\n");
	        //fprintf(outfp, "        addi    a0, a0, %%lo(.LCI)\n");
		//fprintf(outfp, "        call    printf\n");
	}
	;

addop : PLUS {
      	add_sub = 0;
	Add_Sub_prepare(op_type);
	}
	| MINUS{
	add_sub = 1;
	Add_Sub_prepare(op_type);
        }
	;

mulop : STAR {
        Mul_Div_prepare(op_type);
	mul_div = 0;
	}
	| SLASH {
	Mul_Div_prepare(op_type);
	mul_div = 1;
}
	;


relop : LT { cmp = 1; cmp_prepare();}
	| GT { cmp = 2; cmp_prepare();}
	| EQUAL { cmp = 3; cmp_prepare();}
	| LE { cmp = 4; cmp_prepare();}
	| GE { cmp = 5; cmp_prepare();}
	| notEQUAL { cmp = 6; cmp_prepare();}
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
