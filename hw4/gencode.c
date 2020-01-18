#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "symtab.h"
#include "gencode.h"

#include <stdio.h>


void Get754Field32(float v, uint* sign, uint* exp, uint* mat)
{
     uint value = *(uint*)&v; // dump 到unsigned
     *sign = (value & FLT_SIGN_MASK) >> (FLT_MAT_BITS + FLT_EXP_BITS);
     *exp  = (value & FLT_EXP_MASK) >> (FLT_MAT_BITS);
     *mat  = (value & FLT_MAT_MASK);
}

unsigned int Set754Field32(uint sign, uint exp, uint mat){
     unsigned x;

     x = (sign << (FLT_MAT_BITS + FLT_EXP_BITS) ) |
           (exp  << FLT_MAT_BITS) |
           (mat	 );
     //printf("%d %d %d\n", sign, exp, mat);
     //printf("%d\n", x);
     //printf("%x\n", x);
     return x;

}
void Build_printint(SymbolTable* s){
	TableEntry* new = BuildTableEntry("PrintInt", s->scopes[s->current_level], s->current_level, BuildType("procedure"), yylineno, s->cnt_upd);
	InsertTableEntry(s, new);
}
void Build_printreal(SymbolTable* s){
	TableEntry* new = BuildTableEntry("PrintReal", s->scopes[s->current_level], s->current_level, BuildType("procedure"), yylineno, s->cnt_upd);
        InsertTableEntry(s, new);
}
void Build_printstring(SymbolTable* s){
	TableEntry* new = BuildTableEntry("PrintString", s->scopes[s->current_level], s->current_level, BuildType("procedure"), yylineno, s->cnt_upd);
        InsertTableEntry(s, new);
}

void ready_printi(int cnt){
	int i;
	//fprintf(outfp, "        lui     a0, %%hi(.LCI)\n");
	//fprintf(outfp, "        addi    s1, s1, %d\n", cnt*4);
	for(i = 2; i < cnt+2; i++){
		//fprintf(outfp, "	addi	s1, s1, 4\n");
		//fprintf(outfp, "	lw	a1, 0(s1)\n");
        	fprintf(outfp, "	mv	a1, s%d\n", i);
		fprintf(outfp, "        lui     a0, %%hi(.LCI)\n");
		//fprintf(outfp, "        mv      a1, s%d\n", i);
	        fprintf(outfp, "        addi    a0, a0, %%lo(.LCI)\n");
		fprintf(outfp, "        call    printf\n");
		//fprintf(outfp, "	addi	s1, s1, -4\n");
	}
	fprintf(outfp, "        lui     a0, %%hi(.LCendl)\n");
        fprintf(outfp, "        addi    a0, a0, %%lo(.LCendl)\n");
        fprintf(outfp, "        call    printf\n");
	//fprintf(outfp, "        addi    s1, s1, %d\n", cnt*4);
}
void ready_printr(int cnt){
	int i;
	//fprintf(outfp, "	addi	s1, s1, %d\n", cnt*4);
	for(i = 2; i < cnt+2; i++){
		//fprintf(outfp, "	addi	s1, s1, 4\n");
		//fprintf(outfp, "	lui	t3, %%hi(.FL%d)\n", 
		fprintf(outfp, "	lui	a0, %%hi(.LCR)\n");
	//fprintf(outfp, "	flw	f2, 0(s1)\n");
		//fprintf(outfp, "	flw	f2, s%d\n", i);
	//fprintf(outfp, "	fcvt.d.s	f1, f2\n");
		fprintf(outfp, "	mv	a1, s%d\n", i);
		//fprintf(outfp, "	ld	a1, 0(s0)\n");
		//fprintf(outfp, "	fcvt.d.s	f5, f1\n");
	//fprintf(outfp, "	fmv.x.d	a1, f1\n");
		fprintf(outfp, "        addi    a0, a0, %%lo(.LCR)\n");
		fprintf(outfp, "	call printf\n");
		//fprintf(outfp, "        addi    s1, s1, -4\n");
	}
	fprintf(outfp, "        lui     a0, %%hi(.LCendl)\n");
        fprintf(outfp, "        addi    a0, a0, %%lo(.LCendl)\n");
        fprintf(outfp, "        call    printf\n");
	//fprintf(outfp, "        addi    s1, s1, %d\n", cnt*4);

}

void ready_prints(int cnt, char* string){
	
	fprintf(outfp, "        lui     a0, %%hi(.LCS%d)\n", cnt);        
        fprintf(outfp, "        addi    a0, a0, %%lo(.LCS%d)\n", cnt);
	fprintf(outfp, "        call    printf\n");
}

void GenProgramStart(char* name){
	//loopStack.top=-1;
	//condStack.top=-1;
	fprintf(outfp, ".LCmain:\n");
	fprintf(outfp, "	.text\n");
	fprintf(outfp, "	.section	.rodata\n");
	fprintf(outfp, "	.align 3\n\n");
	fprintf(outfp, ".LC0:\n");
	//fprintf(outfp, "	.string \"print some %%d test\\n\"\n");
	fprintf(outfp, "	.text\n");
	fprintf(outfp, "	.align 1\n");
	fprintf(outfp, "	.globl main\n");
	fprintf(outfp, "	.type main, @function\n");
}
void init_space(){
	fprintf(outfp, "	addi   	sp, sp, -1024\n");
	fprintf(outfp, "	sd     	ra, -1016(sp)\n");
	fprintf(outfp, "	sd     	s0, -1008(sp)\n");
	fprintf(outfp, "	sd     	s1, -1000(sp)\n");
	fprintf(outfp, "	addi	s0, sp, 400	#stack point(240 stack entries)\n");
	fprintf(outfp, "	addi	s1, sp, 200	#define 12 local variable\n");
	//fprintf(outfp, "	lw	a5, 8(s0)\n");
	//fprintf(outfp, "	mv	a1, a5\n");
	//fprintf(outfp, "	lui 	a0, %%hi(.LCPrintInt)\n");
	//fprintf(outfp, "	addi	sp, sp, -16\n");
	//fprintf(outfp, "	addi	a0, a0, %%lo(.LCPrintInt)\n");
	//fprintf(outfp, "	call	printf\n");
}

void recover_setting(){
	fprintf(outfp, ".L2:\n");

	fprintf(outfp, "	li	a0, 0\n");
      	//fprintf(outfp, "	mv 	a0, a5\n");
      	fprintf(outfp, "	ld 	ra, -1016(sp)\n");
      	fprintf(outfp, "	ld 	s0, -1008(sp)\n");
      	fprintf(outfp, "	ld 	s1, -1000(sp)\n");
      	fprintf(outfp, "	addi 	sp, sp, 1024\n");
      	fprintf(outfp, "	jr 	ra\n");
      	fprintf(outfp, "	.size 	main, .-main\n");
}
void init_func(SymbolTable* s, char* name){
	/*
	fprintf(outfp, ".LC%s_set:\n", name);
	fprintf(outfp, "	.text\n");
	fprintf(outfp, "	.section	.rodata\n");
	fprintf(outfp, "	.align 3\n\n");*/

	fprintf(outfp, ".LC%s:\n", name);
	fprintf(outfp, "        .text\n");
        fprintf(outfp, "        .align 1\n");
        fprintf(outfp, "        .globl %s\n", name);
        fprintf(outfp, "        .type %s, @function\n", name);
	fprintf(outfp, "%s:\n", name);
	fprintf(outfp, "        addi    sp, sp, -1024\n");
        fprintf(outfp, "        sd      ra, -1016(sp)\n");
        fprintf(outfp, "        sd      s0, -1008(sp)\n");
        fprintf(outfp, "        sd      s1, -1000(sp)\n");
	int i;
	for(i = 1; i <= 5; i++){
		fprintf(outfp, "	sd	t%d, -%d(sp)\n", i, 1000-8*i);
	}
	for(i = 1; i <= 5; i++){
                fprintf(outfp, "        fsd      f%d, -%d(sp)\n", i, 960-8*i);
        }
	for(i = 1; i <= 7; i++){
		fprintf(outfp, "	sd	a%d, -%d(sp)\n", i, 920-8*i);
	}
		//912
	TableEntry* tmp = (TableEntry*)malloc(sizeof(TableEntry));
	TableEntry* new = (TableEntry*)malloc(sizeof(TableEntry));
	tmp = FindEntryInScope(s, name);
	fprintf(outfp, "	addi	s1, s1, %d\n", tmp->para_cnt*4);
	for(i = 0; i < tmp->para_cnt; i++){
		//fprintf(outfp, "	lw	a0, 0(s1)\n");
		//fprintf(outfp, "	addi	s1, s1, -4\n");
		//fprintf(outfp, "	mv	a0, s%d\n", i+2);
		new = FindEntryInFunc(s, tmp->para[i]);
		//printf("\n%s\n", tmp->name);
		if(!strcmp(tmp->ret, "integer")){
			//printf("\n\nint\n\n");
			fprintf(outfp, "	mv      a0, s%d\n", i+2);
			fprintf(outfp, "	sd	a0, -%d(sp)\n", 856-8*i);
		}
		else{
			//printf("\n\nreal\n\n");
			fprintf(outfp, "	fmv.d.x	fa0, s%d\n", i+2);
			fprintf(outfp, "	fsd	fa0, -%d(sp)\n", 856-8*i);
		}
	}
	//fprintf(outfp, "        addi    s1, s1, %d\n", tmp->para_cnt*4);
        //fprintf(outfp, "		s0, sp\n");
	//fprintf(outfp, "        addi    s0, sp, 40      #stack point(240 stack entries)\n");
        //fprintf(outfp, "        addi    s1, sp, 0       #define 12 local variable\n");
	
	/*int i;
	TableEntry* tmp = FindEntryFuncInScope(s, name);
	for(i = 0; i < tmp->para_cnt; i++){
		fprintf(outfp, "	sw	a%d, %d(s1)\n", i, i*4);
	}*/	
	//fprintf(outfp, "	addi	a0, a1, 17\n");
}
void end_func(SymbolTable* s, char* name){
	fprintf(outfp, ".LC%send:\n", name);
	TableEntry* tmp = (TableEntry*)malloc(sizeof(TableEntry));
	tmp = FindEntryInScope(s, name);
	fprintf(outfp, "        li      a1, %d\n", tmp->exe_space);
        fprintf(outfp, "        add     s0, s0, a1\n");
	if(!strcmp(tmp->ret, "integer")) fprintf(outfp, "	lw	t0, 0(s0)\n");
	else fprintf(outfp, "	flw	f0, 0(s0)\n");
	fprintf(outfp, "        sub     s0, s0, a1\n");
	fprintf(outfp, "	mv	a0, t0\n");
	fprintf(outfp, "	ld	ra, -1016(sp)\n");
	fprintf(outfp, "        ld      s0, -1008(sp)\n");
        fprintf(outfp, "        ld      s1, -1000(sp)\n");
	int i;
	for(i = 1; i <= 5; i++){
                fprintf(outfp, "        ld      t%d, -%d(sp)\n", i, 1000-8*i);
        }
	for(i = 1; i <= 5; i++){
                fprintf(outfp, "        fld      f%d, -%d(sp)\n", i, 960-8*i);
        }
	//for(i = 1; i <= 7; i++){
	//	fprintf(outfp, "	ld	a%d, -%d(sp)\n", i, 920-8*i);
	//}
	TableEntry* new = (TableEntry*)malloc(sizeof(TableEntry));
	for(i = 0; i < tmp->para_cnt; i++){
		new = FindEntryInFunc(s, tmp->para[i]);
		if(!strcmp(new->type->name, "integer")){
			fprintf(outfp, "	ld	a0, -%d(sp)\n", 856-8*i);
			//fprintf(outfp, "        ld      a0, -%d(sp)\n", 856-8*i);
                        fprintf(outfp, "        li      a1, %d\n", new->exe_space);
                        fprintf(outfp, "        add     s0, s0, a1\n");
                        fprintf(outfp, "        sw      a0, 0(s0)\n");
                        fprintf(outfp, "        sub     s0, s0, a1\n");

		}
		else{
			fprintf(outfp, "        fld	fa0, -%d(sp)\n", 856-8*i);
                        fprintf(outfp, "        li      a1, %d\n", new->exe_space);
                        fprintf(outfp, "        add     s0, s0, a1\n");
			fprintf(outfp, "        fcvt.s.d        fa0, fa0\n");
			fprintf(outfp, "        fsw	fa0, 0(s0)\n");
			fprintf(outfp, "        sub     s0, s0, a1\n");
		}
	}
	for(i = 1; i <= 7; i++){
                fprintf(outfp, "        ld      a%d, -%d(sp)\n", i, 920-8*i);
        }
        fprintf(outfp, "        addi    sp, sp, 1024\n");
        fprintf(outfp, "        jr      ra\n");
	fprintf(outfp, "	.size	%s, .-%s\n", name, name);
}
void push_value_to_stack(SymbolTable *s, Value* v, int ax, int cnt){
	int tmp = 0;
	//fprintf(outfp, "	addi	s1, s1, -%d\n", cnt*4);
	if(!strcmp(v->type->name, "integer")){
		//fprintf(outfp, "        sw      t0, 0(s1)\n");
        	//fprintf(outfp, "        addi    s1, s1, -4\n");
		fprintf(outfp, "	mv	s%d, t0\n", ax+2);
	}
	else{
		//fprintf(outfp, "	fsw	f0, 0(s1)\n");
		//fprintf(outfp, "	flw	f3, 0(s1)\n");
	fprintf(outfp, "	fcvt.d.s	f0, f0\n");
		//fprintf(outfp, "	sd	t0, 0(s1)\n");
	fprintf(outfp, "      fmv.x.d	s%d, f0\n", ax+2);
        	//fprintf(outfp, "      fcvt.d.s        fa5, fa0\n");

		//fprintf(outfp, "        lui     a0, %%hi(.LCR)\n");
		
		//fprintf(outfp, "	fmv.s	fa1, fa5\n");
		//fprintf(outfp, "	mv	a1, s%d\n", ax+2);
                       //fprintf(outfp, "        addi    a0, a0, %%lo(.LCR)\n");
                       //fprintf(outfp, "        call    printf\n");
	
				
                //fprintf(outfp, "        addi    s1, s1, -4\n");
	}
}

void change_para_value(SymbolTable* s, char* name){
	TableEntry* tmp = (TableEntry*)malloc(sizeof(TableEntry));
	TableEntry* new = (TableEntry*)malloc(sizeof(TableEntry));
	tmp = FindEntryInScope(s, name);
	//printf("%s\n", tmp->para[0]);
	//fprintf(outfp, "	addi	s1, s1, %d\n", tmp->para_cnt*4);
	int i = 0;
	for(i = 0; i < tmp->para_cnt; i++){
		new = FindEntryInFunc(s, tmp->para[i]);
		//printf("%s\n", new->name);
		
		if(!strcmp(new->type->name, "integer")){
			//fprintf(outfp, "	lw	a0, 0(s1)\n");
			//fprintf(outfp, "	sw      a0, %d(s0)\n", new->exe_space);
			fprintf(outfp, "	li	a1, %d\n", new->exe_space);
			fprintf(outfp, "	add	s0, s0, a1\n");
			//fprintf(outfp, "	sw	a0, 0(s0)\n");
			fprintf(outfp, "	sw	s%d, 0(s0)\n", i+2);
			fprintf(outfp, "	sub	s0, s0, a1\n");
		//fprintf(outfp, "	mv	a1, a0\n");
		//fprintf(outfp, "        lui     a0, %%hi(.LCI)\n");
	
	        //fprintf(outfp, "        addi    a0, a0, %%lo(.LCI)\n");
		//fprintf(outfp, "        call    printf\n");
			//fprintf(outfp, "        addi    s1, s1, -4\n");
		}
		else{
			//fprintf(outfp, "	flw	f0, 0(s1)\n");
			//fprintf(outfp, "	fsw	f0, %d(s0)\n", new->exe_space);
		//	fprintf(outfp, "	addi	s1, s1, -4\n");
		//	fprintf(outfp, "	sd	s%d, %d(s0)\n", i+2, new->exe_space);
			//fprintf(outfp, "	fmv.d.x	f1, s%d\n", i+2);
			//fprintf(outfp, "        lui     a0, %%hi(.LCR)\n");
		
	        	//fprintf(outfp, "        addi    a0, a0, %%lo(.LCR)\n");
			//fprintf(outfp, "        call    printf\n");
			//fprintf(outfp, "	fcvt.d.s	f5, f0\n");
			//fprintf(outfp, "	fmv.d.x	f0, s%d\n", i+2);
			//fprintf(outfp, "      	fcvt.d.s        f5, f0\n");
			//fprintf(outfp, "	fsd	f1, %d(s0)\n", new->exe_space);
			//fprintf(outfp, "	fld	f2, 0(s1)\n");
		fprintf(outfp, "	fmv.d.x	f0, s%d\n", i+2);
		fprintf(outfp, "	fcvt.s.d	f0, f0\n");
		fprintf(outfp, "	fmv.x.d	s%d, f0\n", i+2);
		fprintf(outfp, "        li      a1, %d\n", new->exe_space);
                fprintf(outfp, "        add     s0, s0, a1\n");
		fprintf(outfp, "	sd	s%d, 0(s0)\n", i+2);
		//fprintf(outfp, "	fsd	f0, 0(s0)\n");
		fprintf(outfp, "        sub     s0, s0, a1\n");
		//fprintf(outfp, "	addi	s1, s1, -4\n");
			//fprintf(outfp, "	ld	a1, %d(s0)\n", new->exe_space);
			//printf("\n%d see  \n\n", new->exe_space);
			//fprintf(outfp, "	fcvt.d.s	f5, f0\n");
			//fprintf(outfp, "	fmv.x.d	a1, f1\n");
		//	fprintf(outfp, "	mv	a1, s%d\n", i+2);
		//	fprintf(outfp, "        lui     a0, %%hi(.LCR)\n");
                  //      fprintf(outfp, "        addi    a0, a0, %%lo(.LCR)\n");
                    //    fprintf(outfp, "        call    printf\n");
			
			//fprintf(outfp, "	flw	f1, -100(s0)\n");
			//fprintf(outfp, "	fsw	f1, %d(s0)\n", new->exe_space);
			
		}
	}
	//fprintf(outfp, "	addi	s1, s1, %d\n", tmp->para_cnt*4);	//restore s1
	//fprintf(outfp, "        addi    s1, sp, 0       #define 12 local variable\n");
}
TableEntry* FindEntryInFunc(SymbolTable* tbl, char* name){
    int i;
    TableEntry* it;
    for (i = 0; i < tbl->pos; i++) {
        it = tbl->Entries[i];
        int j;
	for(j = 0; j <= tbl->current_level; j++){
		if (strcmp(name, it->name) == 0 && !strcmp(tbl->scope, it->scope)) {
            		return it;
        	}
	}
    }
    
    return NULL;
}
char* compare_two(Value* v1, Value* v2, char* cmp){
	char ret[5] = "";
	if(!strcmp(v1->type->name, "integer")){
		if(!strcmp(cmp, ">")){
			if(v1->ival > v2->ival){
				strcpy(ret, "yes");
			}
			else strcpy(ret, "no");	
		}
		else if(!strcmp(cmp, "<")){
                        if(v1->ival < v2->ival){
                                strcpy(ret, "yes");
                        }
                        else strcpy(ret, "no"); 
                }
		else if(!strcmp(cmp, ">=")){
                        if(v1->ival >= v2->ival){
                                strcpy(ret, "yes");
                        }
                        else strcpy(ret, "no"); 
                }
		else if(!strcmp(cmp, "<=")){
                        if(v1->ival <= v2->ival){
                                strcpy(ret, "yes");
                        }
                        else strcpy(ret, "no");
                }
		else if(!strcmp(cmp, "=")){
                        if(v1->ival == v2->ival){
                                strcpy(ret, "yes");
                        }
                        else strcpy(ret, "no");
                }
		else if(!strcmp(cmp, "!=")){
                        if(v1->ival != v2->ival){
                                strcpy(ret, "yes");
                        }
                        else strcpy(ret, "no");
                }
	}
	else if(!strcmp(v1->type->name, "real")){
		if(!strcmp(cmp, ">")){
                        if(v1->dval > v2->dval){
                                strcpy(ret, "yes");
                        }
                        else strcpy(ret, "no");
                }
                else if(!strcmp(cmp, "<")){
                        if(v1->dval < v2->dval){
                                strcpy(ret, "yes");
                        }
                        else strcpy(ret, "no");
                }
                else if(!strcmp(cmp, ">=")){
                        if(v1->dval >= v2->dval){
                                strcpy(ret, "yes");
                        }
                        else strcpy(ret, "no");
                }
                else if(!strcmp(cmp, "<=")){
                        if(v1->dval <= v2->dval){
                                strcpy(ret, "yes");
                        }
                        else strcpy(ret, "no");
                }
		else if(!strcmp(cmp, "=")){
                        if(v1->dval == v2->dval){
                                strcpy(ret, "yes");
                        }
                        else strcpy(ret, "no");
                }
                else if(!strcmp(cmp, "!=")){
                        if(v1->dval != v2->dval){
                                strcpy(ret, "yes");
                        }
                        else strcpy(ret, "no");
                }
	}
	char* real_ret;
	real_ret = strdup(ret);
	return real_ret;
}
int Request_array_space(SymbolTable* s, Type* t, int line, int sp, float* array){
	int i;
	int all_space = 0;
	int is_array = 0;
	TableEntry* ptr;
	for(i = 0; i < s->pos; i++){
		ptr = s->Entries[i];
		if(ptr->line == line && s->current_level == ptr->level && s->cnt_upd == ptr->cnt_upd && ptr->type->arr_dim > 0){
			//int space = 1;
			int j;
			int space = 1;
			is_array = 1;
			ptr->type->array_space = sp;
			//ptr->type->array_cnt = cnt;
			//ptr->type->array_space = space*4;
			for(j = 0; j < ptr->type->arr_dim; j++){
				//printf("pre%d  next%d\n", ptr->type->arr_range[j*2+1], ptr->type->arr_range[j*2]);
				space *= (ptr->type->arr_range[j*2+1]-ptr->type->arr_range[j*2]+1);
				ptr->type->array_length[j] = ptr->type->arr_range[j*2+1]-ptr->type->arr_range[j*2]+1;
				printf("%d|||", ptr->type->array_length[j]);
			}
			//ptr->type->array_space = space;	
			printf("sp %d \n", space);
			//sp += space*4;
			//int j;
			all_space += space;
			for(j = 0 ; j < space; j++){
				array[j] = 0;
			}
		}
	}		
	if(is_array == 0) return 0;
	else return all_space;
}
unsigned int assign_float(float target, int cnt){
	float f = target;
	unsigned int ieee754 = 0;
	uint f_sign, f_exp, f_mat;
	Get754Field32(f, &f_sign, &f_exp, &f_mat); 
     	ieee754 = Set754Field32(f_sign, f_exp, f_mat);
	
	fprintf(outfp, "        lui     a5, %%hi(.FL%d)\n", cnt);
	fprintf(outfp, "	flw	f0, %%lo(.FL%d)(a5)\n", cnt);
	//fprintf(outfp, "	fmv.s	f1, f0\n");
	//fprintf(outfp, "	fcvt.d.s	f0, f0\n");
	//fprintf(outfp, "	fmv.x.d	t0, f5\n");
	return ieee754;
}
unsigned int re_print_float(float target, int cnt){
	float f = target;
	unsigned int ieee754 = 0;
	uint f_sign, f_exp, f_mat;
	Get754Field32(f, &f_sign, &f_exp, &f_mat);
     	ieee754 = Set754Field32(f_sign, f_exp, f_mat);

	//fprintf(outfp, "        lui     a5, %%hi(.FL%d)\n", cnt);
	//fprintf(outfp, "	flw	f0, %%lo(.FL%d)(a5)\n", cnt);
	//fprintf(outfp, "	fcvt.d.s	f5, f0\n");
	//fprintf(outfp, "	fmv.x.d	t0, f5\n");
	//fprintf(outfp, "	fsw	f5, 0(s1)\n");
	//fprintf(outfp, "	addi	s1, s1, 4\n");
	return ieee754;
}
void Mul_Div_prepare(int op_type){
	//mul_div = 0;
	if(inexp > 0){	//in (expression)
		if(op_type == 0)	fprintf(outfp, "        mv      t5, t0\n");                  
      		else	fprintf(outfp, "        fmv.s   f5, f0\n");	
	}
	else{
		if(op_type == 0)        fprintf(outfp, "        mv      t2, t0\n");
                else    fprintf(outfp, "        fmv.s   f2, f0\n");
	}
}
void Add_Sub_prepare(int op_type){
	if(inexp > 0){
		if(op_type == 0)        fprintf(outfp, "        mv      t4, t0\n");
                else    fprintf(outfp, "        fmv.s   f4, f0\n");
	}
	else{
		if(op_type == 0)	fprintf(outfp, "        mv      t1, t0\n");
        	else	fprintf(outfp, "        fmv.s   f1, f0\n");
	}
}

void Exe_mul_div(int mul_div, char* op, Value* v){
	if(inexp > 0){
		if(!strcmp(op, "*")){       //multiply
                        if(!strcmp(v->type->name, "integer")){
                                fprintf(outfp, "        mul      t0, t5, t0\n");
                        }
                        else    fprintf(outfp, "        fmul.s   f0, f5, f0\n");
                }
                else{
                        if(!strcmp(v->type->name, "integer")){
                                fprintf(outfp, "        div      t0, t5, t0\n");
                        }
                        else    fprintf(outfp, "        fdiv.s   f0, f5, f0\n");
                }
	}
	else{
		if(!strcmp(op, "*")){	//multiply
			if(!strcmp(v->type->name, "integer")){
                      		fprintf(outfp, "        mul      t0, t2, t0\n");
	                }
        	        else    fprintf(outfp, "        fmul.s   f0, f2, f0\n");
		}
		else{
			if(!strcmp(v->type->name, "integer")){
	      			fprintf(outfp, "        div      t0, t2, t0\n");
	                }
        	        else    fprintf(outfp, "        fdiv.s   f0, f2, f0\n");
		}
	}
}
void Exe_add_sub(int add_sub, char* op, Value* v){
	if(inexp > 0 || infunc_exp > 0){
		if(!strcmp(op, "+")){       //add
                        if(!strcmp(v->type->name, "integer")){
                                fprintf(outfp, "        add      t0, t4, t0\n");
                        }
                        else    fprintf(outfp, "        fadd.s   f0, f4, f0\n");
                }
                else{
                        if(!strcmp(v->type->name, "integer")){
                                fprintf(outfp, "        sub      t0, t4, t0\n");
                        }
                        else    fprintf(outfp, "        fsub.s   f0, f4, f0\n");
                }
	}
	else{
		if(!strcmp(op, "+")){       //add
  		      	if(!strcmp(v->type->name, "integer")){
                		fprintf(outfp, "        add      t0, t1, t0\n");
	              	}
        	      	else    fprintf(outfp, "        fadd.s   f0, f1, f0\n");
	        }
        	else{
	 		if(!strcmp(v->type->name, "integer")){
                		fprintf(outfp, "        sub      t0, t1, t0\n");
	              	}
        	        else    fprintf(outfp, "        fsub.s   f0, f1, f0\n");
        	}
	}
}
void cmp_prepare(){
	if(op_type == 0) fprintf(outfp, "        mv      t3, t0\n");
	else 	fprintf(outfp, "	fmv.s	f3, f0\n");
}
void Exe_cmp(char* op, int cnt){
	if(op_type == 0){	//int compare
		if(!strcmp(op, "<")){
			fprintf(outfp, "	bge	t3, t0, .Cmp%dFalse\n", cnt);
		}
		else if(!strcmp(op, ">")){
                        fprintf(outfp, "        ble     t3, t0, .Cmp%dFalse\n", cnt);
                }
		else if(!strcmp(op, "=")){
                        fprintf(outfp, "        bne     t3, t0, .Cmp%dFalse\n", cnt);
                }
		else if(!strcmp(op, "<=")){
                        fprintf(outfp, "        bgt     t3, t0, .Cmp%dFalse\n", cnt);
                }
		else if(!strcmp(op, ">=")){
                        fprintf(outfp, "        blt     t3, t0, .Cmp%dFalse\n", cnt);
                }
		else if(!strcmp(op, "!=")){
                        fprintf(outfp, "        beq     t3, t0, .Cmp%dFalse\n", cnt);
                }
		fprintf(outfp, "        li      t0, 1\n");              // condition is true
                fprintf(outfp, "        j       .Cmp%dend\n", cnt);
                fprintf(outfp, ".Cmp%dFalse:\n", cnt);
                fprintf(outfp, "        li      t0, 0\n");
                fprintf(outfp, ".Cmp%dend:\n", cnt);
	}
	else{
		if(!strcmp(op, "<")){
                        fprintf(outfp, "        flt.s	a1, f3, f0\n");	//a1 = 0->false, 1->true
			fprintf(outfp, "	beq	a1, zero, .Cmp%dFalse\n", cnt);
                }
                else if(!strcmp(op, ">")){
                        fprintf(outfp, "        fgt.s	a1, f3, f0\n");
		       	fprintf(outfp, "	beq	a1, zero, .Cmp%dFalse\n", cnt);
                }
                else if(!strcmp(op, "=")){
                        fprintf(outfp, "        feq.s	a1, f3, f0\n");
		       	fprintf(outfp, "	beq	a1, zero, .Cmp%dFalse\n", cnt);
                }
                else if(!strcmp(op, "<=")){
                        fprintf(outfp, "        fle.s   a1, f3, f0\n");
		       	fprintf(outfp, "	beq	a1, zero, .Cmp%dFalse\n", cnt);
                }
                else if(!strcmp(op, ">=")){
                        fprintf(outfp, "        fge.s   a1, f3, f0\n");
		       	fprintf(outfp, "	beq	a1, zero, .Cmp%dFalse\n", cnt);
                }
                else if(!strcmp(op, "!=")){
                        fprintf(outfp, "        feq.s   a1, f3, f0\n");
			fprintf(outfp, "	li	a0, 1\n");
		       	fprintf(outfp, "	beq	a1, a0, .Cmp%dFalse\n", cnt);
                }
                fprintf(outfp, "        li      t0, 1\n");              // condition is true
                fprintf(outfp, "        j       .Cmp%dend\n", cnt);
                fprintf(outfp, ".Cmp%dFalse:\n", cnt);
                fprintf(outfp, "        li      t0, 0\n");
                fprintf(outfp, ".Cmp%dend:\n", cnt);		
	}

}
void Compute_Array_Space(int* tail, int tail_cnt, Value* v){
	int j, k;
	fprintf(outfp, "	li	a4, 0\n");
	fprintf(outfp, "	addi	s1, s1, %d\n", tail_cnt*4);
	for(j = tail_cnt-2; j >= 0; j--){
		int tmp2 = 1;
		for(k = j; k >= 0; k--){
			tmp2 *= v->array_length[k];
		}
		//printf("\nLL  %d  LL\n", tail[j]);
		//fprintf(outfp, "	lw	a1, 0(s1)\n");
		//fprintf(outfp, "        lui     a0, %%hi(.LCI)\n");
		//fprintf(outfp, "        addi    a0, a0, %%lo(.LCI)\n");
		//fprintf(outfp, "        call    printf\n");

		//fprintf(outfp, "        addi    s1, s1, -4\n");
		fprintf(outfp, "	lw	a2, 0(s1)\n");
		fprintf(outfp, "	li	a5, %d\n", tmp2);	//a5->tmp2
		fprintf(outfp, "	li	a3, %d\n", v->type->arr_range[(j+1)*2]);
		fprintf(outfp, "	li	a1, %d\n", tail[j+1]);
		fprintf(outfp, "	sub	a1, a1, a3\n");
		fprintf(outfp, "	mul	a1, a1, a5\n");
		fprintf(outfp, "	add	a4, a4, a1\n");	//a4->tmp
		//fprintf(outfp, "	sw	a4, 0(s0)\n");
		//fprintf(outfp, "        mv      a1, a4\n");
                //fprintf(outfp, "        lui     a0, %%hi(.LCI)\n");
                //fprintf(outfp, "        addi    a0, a0, %%lo(.LCI)\n");
                //fprintf(outfp, "        call    printf\n");
		//fprintf(outfp, "	lw	a4, 0(s0)\n");
		fprintf(outfp, "	addi	s1, s1, -4\n");
	}
	//fprintf(outfp, "        lw      a1, 0(s1)\n");
        //fprintf(outfp, "        lui     a0, %%hi(.LCI)\n");
	//fprintf(outfp, "        addi    a0, a0, %%lo(.LCI)\n");
        //fprintf(outfp, "        call    printf\n");

	//fprintf(outfp, "        addi    s1, s1, -4\n");
        fprintf(outfp, "        lw      a2, 0(s1)\n");
	fprintf(outfp, "	add	a4, a4, a2\n");
	fprintf(outfp, "	addi	a4, a4, -%d\n", v->type->arr_range[0]);	
	//fprintf(outfp, "        mv      a1, a4\n");
        //fprintf(outfp, "        lui     a0, %%hi(.LCI)\n");
        //fprintf(outfp, "        addi    a0, a0, %%lo(.LCI)\n");
        //fprintf(outfp, "        call    printf\n");

	//fprintf(outfp, "	addi	a4, a4, 1\n");
	//fprintf(outfp, "	addi	s1, s1, -4\n");
	fprintf(outfp, "        addi    s1, s1, %d\n", tail_cnt*4);
}
void Assign_for_array(TableEntry* tmp){
	//fprintf(outfp, "        mv      a1, a4\n");
                        //fprintf(outfp, "        lui     a0, %%hi(.LCI)\n");
                        //fprintf(outfp, "        addi    a0, a0, %%lo(.LCI)\n");
                        //fprintf(outfp, "        call    printf\n");

			fprintf(outfp, "	mv	a0, t0\n");
			//tmp->exe_space = tmp->exe_space + tmp_spaceL*4;
			//printf("%d spaceL\n\n", temp);
			//fprintf(outfp, "	addi	a4, a4, -%d\n", tmp->type->arr_range[0]);	
			fprintf(outfp, "        li      a5, 4\n");
                        fprintf(outfp, "        mul     a4, a4, a5\n");
			
			fprintf(outfp, "        li      a1, %d\n", tmp->exe_space);
		        fprintf(outfp, "        add     a4, a4, a1\n");

			//fprintf(outfp, "        addi    a4, a4, %d\n", tmp->exe_space);

			//fprintf(outfp, "	mv	a1, a0\n");
			//fprintf(outfp, "	sw	a1, 0(s1)\n");
			//fprintf(outfp, "	addi	a1, a1, %d\n", tmp->exe_space);
			//fprintf(outfp, "	mv	a1, a4\n");
			//fprintf(outfp, "        lui     a0, %%hi(.LCI)\n");
                        //fprintf(outfp, "        addi    a0, a0, %%lo(.LCI)\n");
                        //fprintf(outfp, "        call    printf\n");

			//fprintf(outfp, "	lui	a6, s0\n");
			//fprintf(outfp, "	addi	a6, s0, 0\n");

			//fprintf(outfp, "	lui	s0, 0\n");
			//fprintf(outfp, "	addi	s0, s0, %d\n", tmp->exe_space);
			fprintf(outfp, "	add	s0, s0, a4\n");
			//fprintf(outfp, "	mv	a1, a0\n");
			fprintf(outfp, "	sw	a0, 0(s0)\n");
			//fprintf(outfp, "	sub	s0, s0, a4\n");
			//fprintf(outfp, "	addi	s0, s0, -%d\n", tmp->exe_space);
			
			//fprintf(outfp, "	ld	s0, 1008(sp)\n");
			fprintf(outfp, "	sub	s0, s0, a4\n");
			//fprintf(outfp, "	lui     a0, %%hi(.LCI)\n");
			//fprintf(outfp, "	addi	a1, a1, 0\n");
			//fprintf(outfp, "	lw	a1, 88(s0)\n");
			//fprintf(outfp, "	addi    a0, a0, %%lo(.LCI)\n");
			//fprintf(outfp, "	call	printf\n");
			//printf("\n\n%d\n\n", temp);
}
void Assign_for_arrayF(TableEntry* tmp){
	//fprintf(outfp, "        mv      a0, t0\n");
        fprintf(outfp, "        li      a5, 4\n");
        fprintf(outfp, "        mul     a4, a4, a5\n");
        fprintf(outfp, "        li      a1, %d\n", tmp->exe_space);
        fprintf(outfp, "        add     a4, a4, a1\n");
	//fprintf(outfp, "        addi    a4, a4, %d\n", tmp->exe_space);
	fprintf(outfp, "        add     s0, s0, a4\n");
        fprintf(outfp, "        fsd     f0, 0(s0)\n");
        fprintf(outfp, "        sub     s0, s0, a4\n");

}
void Compute_Array_Space_R(int* tail, int tail_cnt, Value* v){
	int j, k;
	fprintf(outfp, "	li	a6, 0\n");
		fprintf(outfp, "	addi	s1, s1, %d\n", tail_cnt*4);
		for(j = tail_cnt-2; j >= 0; j--){
			int tmp2 = 1;
			for(k = j; k >= 0; k--){
				tmp2 *= v->array_length[k];
			}
			//fprintf(outfp, "        addi    s1, s1, -4\n");
			fprintf(outfp, "	lw	a2, 0(s1)\n");
			fprintf(outfp, "	li	a7, %d\n", tmp2);	//a7->tmp2
			fprintf(outfp, "	li	a3, %d\n", v->type->arr_range[(j+1)*2]);
			fprintf(outfp, "	li	a1, %d\n", tail[j+1]);
			fprintf(outfp, "	sub	a1, a1, a3\n");
			fprintf(outfp, "	mul	a1, a1, a7\n");
			fprintf(outfp, "	add	a6, a6, a1\n");
			fprintf(outfp, "	addi	s1, s1, -4\n");
		}
		//fprintf(outfp, "        addi    s1, s1, -4\n");
                fprintf(outfp, "        lw      a2, 0(s1)\n");
		fprintf(outfp, "	add	a6, a6, a2\n");
		fprintf(outfp, "	addi	a6, a6, -%d\n", v->type->arr_range[0]);
		fprintf(outfp, "        addi    s1, s1, %d\n", tail_cnt*4);
}
void Find_array_value(TableEntry* t){
	fprintf(outfp, "	li	a7, 4\n");
	fprintf(outfp, "	mul	a6, a6, a7\n");
	fprintf(outfp, "        li      a1, %d\n", t->exe_space);
        fprintf(outfp, "        add     a6, a6, a1\n");

	//fprintf(outfp, "      	addi    a6, a6, %d\n", t->exe_space);
	//fprintf(outfp, "	mv	a1, a6\n");
	
	//fprintf(outfp, "	mv	a1, a0\n");
	//fprintf(outfp, "	sw	a1, 0(s1)\n");
	fprintf(outfp, "	add	s0, s0, a6\n");
	//fprintf(outfp, "	mv	a1, a0\n");
	fprintf(outfp, "	lw	a0, 0(s0)\n");
	fprintf(outfp, "	mv	t0, a0\n");
	fprintf(outfp, "	sub	s0, s0, a6\n");
}
void Find_array_valueF(TableEntry* t){
	fprintf(outfp, "        li      a7, 4\n");
        fprintf(outfp, "        mul     a6, a6, a7\n");

        fprintf(outfp, "        li      a1, %d\n", t->exe_space);
        fprintf(outfp, "        add     a6, a6, a1\n");
	
	//fprintf(outfp, "        addi    a6, a6, %d\n", t->exe_space);
	fprintf(outfp, "        add     s0, s0, a6\n");
	fprintf(outfp, "        fld     f0, 0(s0)\n");
	//fprintf(outfp, "	ld	t0, 0(s0)\n");
	fprintf(outfp, "	fcvt.d.s	f6, f0\n");
	fprintf(outfp, "	fmv.x.d	t0, f6\n");
        //fprintf(outfp, "        fmv      t0, a0\n");
        fprintf(outfp, "        sub     s0, s0, a6\n");
}
void Prevent_rec(int add_sub, int mul_div){
	if(add_sub == 0 || add_sub == 1){	//add, sub
		if(op_type == 0){	//int
			if(inexp == 0){	//not in expression
				fprintf(outfp, "	sw	t1, 0(s1)\n");
				//fprintf(outfp, "	addi	s1, s1, -4\n");
				pre_rec = 1;
				printf("11111111\n\n\n");
			}
			else{
				fprintf(outfp, "        sw      t4, 0(s1)\n");
                                //fprintf(outfp, "        addi    s1, s1, -4\n");
				pre_rec = 4;
				printf("44444444\n\n");
			}
		}
		else{
			if(inexp == 0){
				//fprintf(outfp, "        fcvt.d.s        f1, f1\n");
				fprintf(outfp, "	fsw	f1, 0(s1)\n");
				//fpritnf(outfp, "	addi	s1, s1, -4\n");
				pre_rec = 11;
			}
			else{
				//fprintf(outfp, "        fcvt.d.s        f4, f4\n");
				fprintf(outfp, "        fsw     f4, 0(s1)\n");
                                //fpritnf(outfp, "        addi    s1, s1, -4\n");
				pre_rec = 14;
			}
		}
	}
	else if(mul_div == 0 || mul_div == 1){	//mul, div
		if(op_type == 0){       //int
                        if(inexp == 0){ //not in expression
                                fprintf(outfp, "        sw      t2, 0(s1)\n");
                                //fprintf(outfp, "        addi    s1, s1, -4\n");
				pre_rec = 2;
                        }
                        else{
                                fprintf(outfp, "        sw      t5, 0(s1)\n");
                                //fprintf(outfp, "        addi    s1, s1, -4\n");
                        	pre_rec = 5;
			}
                }
                else{
                        if(inexp == 0){
                                fprintf(outfp, "        fsw     f2, 0(s1)\n");
                                //fpritnf(outfp, "        addi    s1, s1, -4\n");
                        	pre_rec = 12;
			}
                        else{
                                fprintf(outfp, "        fsw     f5, 0(s1)\n");
                                //fpritnf(outfp, "        addi    s1, s1, -4\n");
                        	pre_rec = 15;
			}
                }
	
	}
	fprintf(outfp, "        addi    s1, s1, -4\n");
}
void Prevent_rec_end(){
	fprintf(outfp, "	addi	s1, s1, 4\n");
	switch(pre_rec){
		case 1:
		       	fprintf(outfp, "	lw	t1, 0(s1)\n");
			break;
		case 2:
			fprintf(outfp, "        lw      t2, 0(s1)\n");
                        break;
		case 4:
			fprintf(outfp, "        lw      t4, 0(s1)\n");
                        break;
		case 5:
			fprintf(outfp, "        lw      t5, 0(s1)\n");
                        break;
		case 11:
			fprintf(outfp, "	flw	f1, 0(s1)\n");
			break;
		case 12:
			fprintf(outfp, "        flw     f2, 0(s1)\n");
                        break;
		case 14:
			fprintf(outfp, "        flw     f4, 0(s1)\n");
                        break;
		case 15:
			fprintf(outfp, "        flw     f5, 0(s1)\n");
                        break;
	}
}
void Reload_para(SymbolTable* s, char* name){
	TableEntry* tmp = (TableEntry*)malloc(sizeof(TableEntry));
	TableEntry* new = (TableEntry*)malloc(sizeof(TableEntry));
	tmp = FindEntryInScope(s, name);
	//printf("%d\n", tmp->para_cnt);
	int i;
	for(i = 0; i < tmp->para_cnt; i++){
		new = FindEntryInScope(s, tmp->para[i]);
		//printf("%s\n", new->name);
		if(!strcmp(new->type->name, "integer")){
			fprintf(outfp, "	ld	a0, -%d(sp)\n", 856-8*i);
			fprintf(outfp, "        li      a1, %d\n", new->exe_space);
                        fprintf(outfp, "        add     s0, s0, a1\n");
			fprintf(outfp, "	sw	a0, 0(s0)\n");
			fprintf(outfp, "        sub     s0, s0, a1\n");
		}
		else{
			fprintf(outfp, "        fld      fa0, -%d(sp)\n", 856-8*i);
			fprintf(outfp, "        li      a1, %d\n", new->exe_space);
                        fprintf(outfp, "        add     s0, s0, a1\n");
			fprintf(outfp, "	fcvt.s.d	fa0, fa0\n");
                        fprintf(outfp, "        fsw      fa0, 0(s0)\n");
			fprintf(outfp, "        sub     s0, s0, a1\n");
		}
	}

}
