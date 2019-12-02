#include "symtab.h"
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

SymbolTable* BuildSymbolTable()
{
    SymbolTable* new = (SymbolTable*)malloc(sizeof(SymbolTable));
    new->current_level = 0;
    new->pos = 0;
    new->cnt_upd = 0;
    new->capacity = 4;
    strcpy(new->scope, "global");
    strcpy(new->scope, "global");
    new->Entries = (TableEntry**)malloc(sizeof(TableEntry*) * 4);
    return new;
}


TableEntry* BuildTableEntry(char* name, int level, Type* type, int line, int cnt_upd)
{
//printf("%d  ", level);
    TableEntry* new = (TableEntry*)malloc(sizeof(TableEntry));
    strcpy(new->name, name);
    new->level = level;
    new->line = 0;
    new->cnt_upd = cnt_upd;
    new->type = type;
    new->line = line;
    new->arr_dim = 0;
    new->para_cnt = 0;
    //new->arr_range = (int*)malloc(sizeof(int)*10);
    new->para = (char**)malloc(sizeof(char*)*4);
    new->value = (Value*)malloc(sizeof(Value));
    new->value->sval =  strdup("0");
    new->init = 0;
    new->iarray = (int*)malloc(sizeof(int)*32);
    new->farray = (float*)malloc(sizeof(float)*32);
    new->sarray = (char*)malloc(sizeof(char)*32);
    new->value->index = (int**)malloc(sizeof(int*)*32);
    new->value->indexf = (double**)malloc(sizeof(double*)*32);
    int i = 0;
    for(i = 0; i < 32; i++){
        new->value->index[i] = (int*)malloc(sizeof(int)*32);
        new->value->indexf[i] = (double*)malloc(sizeof(double)*32);
    }

    return new;
}

void InsertTableEntry(SymbolTable* t, TableEntry* e)
{
	//printf("%s %s %d \n ", e->name, e->kind, e->level);
     
    if (FindEntryInScope(t, e->name) != NULL && FindEntryInScope(t, e->name)->level == t->current_level) {
	    printf("Error at Line#%d: '%s' is redeclared\n", yylineno, e->name);
        return;
    }
    //printf("%s %s %d \n ", e->name, e->kind, e->level);
    //grow the capacity
    if (t->pos == t->capacity) {
        t->capacity *= 2;
        TableEntry** tmp_entries = t->Entries;
        t->Entries = (TableEntry**)malloc(sizeof(TableEntry*) * (t->capacity));
        int i;
        for (i = 0; i < t->pos; i++) {
            (t->Entries)[i] = tmp_entries[i];
        }
        free(tmp_entries);
    }
	//printf("%s %s %d \n ", e->name, e->kind, e->level);
    t->Entries[t->pos++] = e;
}

void PopTableEntry(SymbolTable* s)
{
    int i;
    TableEntry* ptr;
    for (i = 0; i < s->pos; i++) {
        ptr = s->Entries[i];
        if (ptr->level == s->current_level) {
            free(ptr);
            if (i < (s->pos) - 1) {                     //如果不是最後的話
                s->Entries[i] = s->Entries[--(s->pos)]; //把最後的拿過來
                i--;                                    //同一個
                continue;                               //再檢查一次
            } else {
                s->pos--;
            }
        }
    }
}

void PopTableEntryByName(SymbolTable* s, char* name)
{
    int i;
    TableEntry* ptr;
    for (i = 0; i < s->pos; i++) {
        ptr = s->Entries[i];
        if (ptr->level == s->current_level && strcmp(ptr->name, name) == 0) {
            free(ptr);
            if (i < (s->pos) - 1) {                     //如果不是最後的話
                s->Entries[i] = s->Entries[--(s->pos)]; //把最後的拿過來
                i--;                                    //同一個
                continue;                               //再檢查一次
            } else {
                s->pos--;
            }
        }
    }
}


void PrintSymbolTable(SymbolTable* t)
{
    int i;
    TableEntry* ptr;

    printf("\n");
    printf("%s       %s       %s       %s      %s       %s       %s\n", "Name", "Level", "Type", "Return", "Parameter", "Dim", "Array_range");
    for (i = 0; i < t->pos; i++) {
        ptr = t->Entries[i]; 
        printf("|%s|     ", ptr->name);
        PrintLevel(ptr->level);
        printf("|%s|     |%s|     |", ptr->type->name, ptr->ret);
        int j;
	printf("(");
	for(j = 0; j < ptr->para_cnt; j++){
		printf("%s, ", ptr->para[j]);
	}
	printf(")");
	printf("|     |");
	//printf("%d|||\n", ptr->type->arr_dim);
	if(ptr->type->arr_dim != 0) printf("%d", ptr->type->arr_dim);
	printf("|     |");
	if(ptr->type->arr_dim != 0){
		int k;
		//printf("%d|||||||||", ptr->type->arr_dim);
		for( k = ptr->type->arr_dim-1; k >= 0; k--){
			printf("(%d, %d) ",ptr->type->arr_range[k*2], ptr->type->arr_range[k*2+1]);
		}
	}
	printf("|");
        printf("\n"); 
        
    }
    
}


TableEntry* FindEntryInScope(SymbolTable* tbl, char* name)
{
    int i;
    TableEntry* it;
    for (i = 0; i < tbl->pos; i++) {
        it = tbl->Entries[i];
        int j;
	for(j = 0; j <= tbl->current_level; j++){
		if (strcmp(name, it->name) == 0 && it->level == (tbl->current_level-j)) {
            		return it;
        	}
	}

    }
    return NULL;
}

TableEntry* FindEntryInGlobal(SymbolTable* tbl, char* name)
{
    int i;
    TableEntry* it;
    for (i = 0; i < tbl->pos; i++) {
        it = tbl->Entries[i];
        if (strcmp(name, it->name) == 0 && it->level == 0) {
            return it;
        }
    }
    return NULL;
}
Type* BuildType(char* typename)
{
    Type* new = (Type*)malloc(sizeof(Type));
    strcpy(new->name, typename);
    return new;
}
void PrintLevel(int l)
{
    if (l == 0) {
        printf("|%d%s|\t", l, "(global)");
    } else {
        printf("|%d%s|\t", l, "(local)");
    }
}
void UpdateType(SymbolTable* s, Type* type, int line){
	int i;
	TableEntry* ptr;
	for(i = 0; i < s->pos; i++){
		ptr = s->Entries[i];
		if(ptr->line == line && s->current_level == ptr->level && s->cnt_upd == ptr->cnt_upd){
			ptr->type = type;
			//printf("%s ",ptr->name);
		}
	}
}
int IsFunction(SymbolTable* s, char* name){
	int i;
	TableEntry* ptr;
	for(i = 0; i < s->pos; i++){
		ptr = s->Entries[i];
		if(!strcmp(ptr->name, name) && !strcmp(ptr->type->name, "function" )){
			return 1;
		}
		if(!strcmp(ptr->name, name) && !strcmp(ptr->type->name, "procedure")){
			return 1;
		}
	}
	return 0;
}
void UpdateFunctionRet(SymbolTable* s, Type* ret, int line){
	int i;
	TableEntry* ptr;
        for(i = 0; i < s->pos; i++){
                ptr = s->Entries[i];
                if(!strcmp(ptr->type->name, "function") && ptr->line == line){
                        strcpy(ptr->ret, ret->name);
			return;
                }
        }
}
void AddparaToFunc(SymbolTable* s, char* name, int line){	
	int i;
	TableEntry* ptr;
	for(i = 0; i < s->pos; i++){
		ptr = s->Entries[i];
		if(!strcmp(ptr->name, name) && ptr->line == line) break;
	}
	TableEntry* par;
	for(i = 0; i < s->pos; i++){
		par = s->Entries[i];
		if(par->line == line && strcmp(par->type->name, ptr->type->name) && par->level != ptr->level){	//count parameter
			ptr->para_cnt++;
		}
	}
	ptr->para = (char**)malloc(sizeof(char*)*ptr->para_cnt);
	for(i = 0; i < ptr->para_cnt; i++) {
		ptr->para[i] = (char*)malloc(sizeof(char)*32);
	}
	
	int j = 0;
	for(i = 0; i < s->pos; i++){
                par = s->Entries[i];
                if(par->line == line && strcmp(par->type->name, ptr->type->name) && par->level != ptr->level){      //add parameter
                        strcpy(ptr->para[j], par->name);
			j++;
                }
        }
}
Type* BuildArrayType(char* typename, int begin, int end){
	Type* new = (Type*)malloc(sizeof(Type));
	strcpy(new->name, typename);
	new->arr_dim++;
	int y = new->arr_dim;
	//new->arr_range = (int*)malloc(sizeof(int)*10);
	new->arr_range[y*2-2] = begin;
	new->arr_range[y*2-1] = end;
	
	return new;
}
Value* BuildNegValue(char* typename, char* val){
	Type* t = BuildType(typename);
    Value* v = (Value*)malloc(sizeof(Value));
    //v->tail = (int*)malloc(sizeof(int)*32);
    v->tail_cnt = 0;
    v->type = t;
    v->sval = "";
    v->ival = 0;
    v->dval = 0;
    if(!strcmp(t->name, "integer")){
	v->ival = atoi(val);
	v->ival*= -1;
    }
    return v;
}
Value* BuildValue(char* typename, char* val)
{
    Type* t = BuildType(typename);
    Value* v = (Value*)malloc(sizeof(Value));
    //v->tail = (int*)malloc(sizeof(int)*32);
    v->tail_cnt = 0;
    v->type = t;
    v->sval = "";
    v->ival = 0;
    v->dval = 0;
    v->is_array = 0;
    if(!strcmp(t->name, "null")){
	v->sval = strdup(val);
    }
    else if (strcmp(t->name, "real") == 0) {
        v->dval = atof(val);
        v->sval = strdup(val);
    } 
    else if (strcmp(t->name, "string") == 0) {
        v->sval = strdup(val);
    } 
    else if (strcmp(t->name, "integer") == 0) {
        v->ival = atoi(val);
    } 
    else if (strcmp(t->name, "octal") == 0) {
        v->ival = strtol(val, NULL, 8);
    } 
    else if (strcmp(t->name, "scientific") == 0) {
        v->sval = strdup(val);
    } 
    else if (strcmp(t->name, "boolean") == 0) {
        v->sval = strdup(val);
    }
    return v;
}
char* itoa (int n)
{
	char s[32];
	int i, sign;
	if((sign = n)<0) n=-n;
	i = 0;
	do{
    	  s[i++] = n % 10 + '0';
	}
	while ((n /= 10) > 0);
	if(sign < 0){
		s[i++]='-';
		s[i]='\0';
	}
      //printf("%s",s);
    char* ne;
    ne = (char*)malloc(sizeof(char)*32);
    int k = 0;
    int cnt = 0;
	for(k = i-1; k >= 0; k--){	//reverse
		ne[cnt] = s[k];
		cnt++;
	}
	//printf("%s",ne);
	return ne;
}
Value* Addtwo(Value* n1, Value* n2, char* op, int line){
	Type* t;
	if(strcmp(n1->type->name, "function")) t = BuildType(n1->type->name);
	else if(strcmp(n2->type->name, "function")) t = BuildType(n2->type->name);
	else {	//above are functions
		t = BuildType(n2->ret);
	}
        Value* v = (Value*)malloc(sizeof(Value));
        v->type = t;
        v->sval = "";
        v->ival = 0;
	if(!strcmp(n1->type->name, "null")){
		printf("Undeclared var cannot add or minus at Line %d : %s\n", yylineno, n1->name);
		v = n1;
		return v;
	}
	if(!strcmp(n2->type->name, "null")){
                printf("Undeclared var cannot add or minus at Line %d : %s\n", yylineno, n2->name);
                v->type = n2->type;
                return v;
        }
	if(!strcmp(n1->type->name, "function") && !strcmp(n2->type->name, "function")){	//function can add
			if(strcmp(n1->ret, n2->ret)){
				printf("Different type cannot add or minus at Line: %d\n", line);	//return value diffenent
				return v;
			}
	}
	if(!strcmp(n1->type->name, "function")){
		if(strcmp(n1->ret, n2->type->name)){
			printf("Different type cannot add or minus at Line: %d\n", line);
			return v;
		}
	}
	if(!strcmp(n2->type->name, "function")){
		if(strcmp(n2->ret, n1->type->name)){
                        printf("Different type cannot add or minus at Line: %d\n", line);
                        return v;
                }
	}
	if(strcmp(n1->type->name, n2->type->name) && strcmp(n1->type->name, "function") && strcmp(n1->type->name, "function")){	//function can be add
		//printf("%s %s\n", n1->type->name, n2->type->name);
		printf("Different type cannot add or minus at Line: %d\n", line);
		return v;
	}
	if(!strcmp(n1->type->name, "string")) {
		printf("String cannot add or minus at Line: %d\n", line);
		return v;
	}
	if(n1->is_array > 0 || n2->is_array > 0) {
		printf("Cannot add or minus array at Line: %d\n", line);
		return v;
	}
	if(!strcmp(n1->type->name, "null")){return v;}
	if(!strcmp(op, "+")) { 
		if(!strcmp(n1->type->name, "integer") || !strcmp(n2->type->name, "integer") || !strcmp(n1->ret, "integer") || !strcmp(n2->ret, "integer")){
			v->ival = n1->ival + n2->ival;
		}
		else{
			double t1, t2;
			t1 = atof(n1->sval);
			t2 = atof(n2->sval);
			v->dval = t1+t2;
			char* tmp;
			tmp = (char*)malloc(sizeof(char)*32);
			sprintf(tmp, "%f", v->dval);
			//printf("%s", tmp);
			v->sval = strdup(tmp);
		}
	}
	else if(!strcmp(op, "-")) {
		if(!strcmp(n1->type->name, "integer") || !strcmp(n2->type->name, "integer") || !strcmp(n1->ret, "integer") || !strcmp(n2->ret, "integer")){
                        v->ival = n1->ival - n2->ival;
                }
                else {
                        double t1, t2;
                        t1 = atof(n1->sval);
                        t2 = atof(n2->sval);
                        v->dval = t1-t2;
                        char* tmp;
                        tmp = (char*)malloc(sizeof(char)*32);
                        sprintf(tmp, "%f", v->dval);
                        //printf("%s", tmp);
                        v->sval = strdup(tmp);
                }
        }
	return v;
}
Value* Multwo(Value* n1, Value* n2, char* op, int line){
	Type* t = BuildType(n1->type->name);
        Value* v = (Value*)malloc(sizeof(Value));
        v->type = t;
        v->sval = NULL;
        v->ival = 0;

	if(!strcmp(n1->type->name, "null")){
                printf("Undeclared var cannot mul or div at Line: %d\n", yylineno);
                v->type = n1->type;
                return v;
        }
        if(!strcmp(n2->type->name, "null")){
                printf("Undeclared var cannot mul or div at Line: %d\n", yylineno);
                v->type = n2->type;
                return v;
        }
	
	if(!strcmp(n1->type->name, "string")) {
		printf("String cannot mul or div at Line: %d\n", line);
		return NULL;
	}
	if(n1->is_array > 0 || n2->is_array > 0) {
                printf("Cannot mul array at Line: %d\n", yylineno);
                return NULL;
        }
	if(!strcmp(op, "*")) {
		if(!strcmp(n1->type->name, "integer")){
			v->ival = n1->ival * n2->ival;
		}
		else  if(!strcmp(n1->type->name, "real")){
			double t1, t2;
			t1 = atof(n1->sval);
			t2 = atof(n2->sval);
			v->dval = t1*t2;
			char* tmp;
			tmp = (char*)malloc(sizeof(char)*32);
			sprintf(tmp, "%f", v->dval);
			//printf("%s", tmp);
			v->sval = strdup(tmp);
		}
	}
	else if(!strcmp(op, "/")) {
		if(!strcmp(n1->type->name, "integer")){
                        v->ival = n1->ival / n2->ival;
                }
                else  if(!strcmp(n1->type->name, "real")){
                        double t1, t2;
                        t1 = atof(n1->sval);
                        t2 = atof(n2->sval);
                        v->dval = t1/t2;
                        char* tmp;
                        tmp = (char*)malloc(sizeof(char)*32);
                        sprintf(tmp, "%f", v->dval);
                        //printf("%s", tmp);
                        v->sval = strdup(tmp);
                }
        }
	return v;	
}
Value* BuildValueTail(char* typename){
	Type* t = BuildType(typename);
    	Value* v = (Value*)malloc(sizeof(Value));
   	v->type = t;
    	v->sval = NULL;
    	v->ival = 0;
	v->index = (int**)malloc(sizeof(int*)*32);
	v->indexf = (double**)malloc(sizeof(double*)*32);
	int i = 0;
	for(i = 0; i < 32; i++){
		v->index[i] = (int*)malloc(sizeof(int)*32);
		v->indexf[i] = (double*)malloc(sizeof(double)*32);
	}
	v->has_tail = 0;
	return v;
}
int CheckAssignCanOrNot(Value* v1, Value* v2){
	//printf("%s ||%s\n", v1->type->name, v2->type->name);
	if(!strcmp(v1->type->name, v2->type->name)){
		return 1;
	}
	if(!strcmp(v1->type->name, "function")){
		if(!strcmp(v1->ret, v2->type->name)){	//return value == RHS type
			return 1;
		}
	}
	if(!strcmp(v2->type->name, "function")){
		if(!strcmp(v2->ret, v1->type->name)){   //return LHS == return value type
                     return 1;
                }
	}
	
	printf("Type mismatch for return value at Line : %d\n", yylineno);
	
	return 0;
}
void UpdateValue(SymbolTable* s, Value* v){
	TableEntry* tmp = FindEntryInScope(s, v->name);
	if(tmp == NULL) tmp = FindEntryInGlobal(s, v->name);
	if(tmp == NULL) return;
	if(!strcmp(v->type->name, "null")){
		printf("Cannot update value because RHS is illegal at Line : %d\n", yylineno);
		return;
	}
	
	if(strcmp(v->type->name, tmp->type->name)) {	//type erroe
		printf("%s  %s  \n", v->type->name, tmp->type->name);
		printf("Type assign error in Line: %d\n", yylineno);
		return;
	}
	if(!strcmp(v->type->name, "real")){
		tmp->value->dval = v->dval;
		tmp->value->sval = strdup(v->sval);
	}
	else if(!strcmp(v->type->name, "integer")){
                tmp->value->ival = v->ival;
        }
	else if(!strcmp(v->type->name, "srting")){
                tmp->value->sval = strdup(v->sval);
        }	
}
void UpdateIndex(TableEntry* t, int* tail, int tail_cnt){
	int i;
	int tmp = t->value->has_tail;
	for(i = 0; i < tail_cnt; i++){
		t->value->index[tmp][i] = tail[i];
	}
	t->value->has_tail++;
}
void UpdateIndexValue(SymbolTable* s, Value* v){
	TableEntry* tmp = FindEntryInScope(s, v->name);
        if(tmp == NULL) tmp = FindEntryInGlobal(s, v->name);
        if(tmp == NULL) return;
        if(strcmp(v->type->name, tmp->type->name)) {    //type erroe
                printf("Type assign error in Line: %d\n", yylineno);
                return;
        }
	int index = tmp->value->has_tail;
	int tail_cnt = tmp->value->tail_cnt;
        if(!strcmp(v->type->name, "real")){
                tmp->value->indexf[index][tail_cnt] = v->dval;
        }
        else if(!strcmp(v->type->name, "integer")){
                tmp->value->index[index][tail_cnt] = v->ival;
        }

}
Value* ReturnIdValue(SymbolTable* symbol_table, char* name, int* tail, int tail_cnt, char lr){
	Value* v = (Value*)malloc(sizeof(Value));
	int flag = 0;
        if(FindEntryInGlobal(symbol_table, name) == NULL){	//is not already existed
		if(FindEntryInScope(symbol_table, name) == NULL){

			printf("Undeclared variable in Line %d : %s\n", yylineno, name);
			flag = 1; //no need to continie
		}
	}
	if(IsFunction(symbol_table, name) == 1 && strcmp(symbol_table->scope, name) && lr == 'l'){
		printf("In Line %d, Function cannot in left side: %s\n", yylineno, name);
		flag = 1;
	}
	if(flag == 1) {
		v = BuildValue("null", "null");
		strcpy(v->name, name);
	}
	if(flag == 0){
	//int  flag2 = 0;
		TableEntry* tmp = FindEntryInScope(symbol_table, name);
		if(tmp == NULL) {
		tmp = FindEntryInGlobal(symbol_table, name);
		}
	        //printf("%s", tmp->type->name);

		if(!strcmp(tmp->type->name, "integer")){
                       	char* tmp1;
       	       	        tmp1 = (char*)malloc(sizeof(char)*32);
       	                tmp1 = itoa(tmp->value->ival);
                       	v = BuildValue(tmp->type->name, tmp1);
               	}
               	else if(!strcmp(tmp->type->name, "real")){
                       	v = BuildValue(tmp->type->name, tmp->value->sval);
               	}
		else if(!strcmp(tmp->type->name, "function")){
			if(!strcmp(tmp->ret, "integer")){
				char* tmp1;
                        	tmp1 = (char*)malloc(sizeof(char)*32);
                        	tmp1 = itoa(tmp->value->ival);
				v = BuildValue(tmp->type->name, tmp1);
				strcpy(v->ret, "integer");
			}
			else{
				v = BuildValue(tmp->type->name, tmp->value->sval);
				strcpy(v->ret, "real");
			}
		}
		strcpy(v->ret, tmp->ret); 
		if(tmp->type->arr_dim > 0) v->is_array = 1;
               	//printf("%d", tail_cnt);
               	v->tail_cnt = tail_cnt;	
		strcpy(v->name, name);
		int j;
               	for(j = 0; j < tail_cnt; j++){
                       	v->tail[j] = tail[j];
               	}
               	if(tmp->type->arr_dim != v->tail_cnt && v->tail_cnt > 0) {
                       	printf("Wrong array dimention at Line: %d\n", yylineno);
          		//flag2 = 1;	//means no need to continuw
		}
		if(v->tail_cnt > 0){
			for(j = tmp->type->arr_dim-1; j>=0; j--){
					//printf("%d  %d  %d\n", tmp->type->arr_range[j*2], tmp->type->arr_range[j*2+1], $$->tail[j]);
				if(v->tail[j] < tmp->type->arr_range[j*2] || v->tail[j] > tmp->type->arr_range[j*2+1]){	//out of bound
				printf("Array out of bound at Line: %d\n", yylineno);
					//flag2 = 1;
				}
			}
		}
		
	}
	return v;
}
TableEntry* FindEntryFuncInScope(SymbolTable* s, char* name){
	int i;
	TableEntry* tmp;
	for(i = 0; i < s->pos; i++){
		tmp = s->Entries[i];
		if(!strcmp(tmp->name, name) && !strcmp(tmp->type->name, "function")){
			return tmp;
		}
		if(!strcmp(tmp->name, name) && !strcmp(tmp->type->name, "procedure")){
			return tmp;
		}
	}
	return NULL;
}
char* FindTypeOfPara(SymbolTable* s, char* name, int line){
	int i;
	TableEntry* tmp;
	for(i = 0; i < s->pos; i++){
		tmp = s->Entries[i];
		if(!strcmp(tmp->name, name) && tmp->line == line){
			if(!strcmp(tmp->type->name, "function")) return tmp->ret;
			else return tmp->type->name;
		}
	}
	return NULL;
}
Value* BuildFuncId(SymbolTable* symbol_table, char* name, char* para, int para_cnt){
	Value* v = (Value*)malloc(sizeof(Value));
	TableEntry* tmp = FindEntryFuncInScope(symbol_table, name);
		if(tmp == NULL) {
			printf("Undeclared function at Line %d: %s\n", yylineno, name);
			v = BuildValue("null", "null");
		}
		else {
			if(tmp->para_cnt != para_cnt){
				printf("Wrong function parameters at Line %d : %s\n", yylineno, name);
				v = BuildValue("null", "null");
			}
			else{
				int j;
				for(j = 0; j < para_cnt; j++){
					char* type;
					type = (char*)malloc(sizeof(char)*32);
					type = FindTypeOfPara(symbol_table, tmp->para[j], tmp->line);
					if(para[j] != type[0]){	//error type
						printf("Error type of parameter at Line : %d \n", yylineno);
					}
				}
				//printf("corrext %s\n\n", tmp->ret);
				v = BuildValue(tmp->type->name, tmp->value->sval);
				strcpy(v->ret, tmp->value->ret);
				
				v->ival = tmp->value->ival;
				strcpy(v->sval, tmp->value->sval);
			}
		}
	return v;
}
void BuildProcId(SymbolTable* symbol_table, char* name, char* para, int para_cnt){
        TableEntry* tmp = FindEntryFuncInScope(symbol_table, name);
                if(tmp == NULL) {
                        printf("Undeclared procedure at Line %d: %s\n", yylineno, name);
                }
                else {
                        if(tmp->para_cnt != para_cnt){
                                printf("Wrong procedure parameters at Line %d : %s\n", yylineno, name);
                        }
                        else{
                                int j;
                                for(j = 0; j < para_cnt; j++){
                                        char* type;
                                        type = (char*)malloc(sizeof(char)*32);
                                        type = FindTypeOfPara(symbol_table, tmp->para[j], tmp->line);
                                        if(para[j] != type[0]){ //error type
						printf("Error type of parameter at Line : %d \n", yylineno);
                                        }
                                }
                        }
                }
}
void CopyValue(Value* v1, Value* v2){
	//strcpy(v1->name, v2->name);
	v1->ival = v2->ival;
	v1->dval = v2->dval;
	v1->sval = strdup(v2->sval);
	//v1->tail_cnt = v2->tail_cnt;	//dimension
	//v1->tail = v2->tail;
	v1->index = v2->index;
	v1->indexf = v2->indexf;
	v1->has_tail = v2->has_tail;
	//v1->is_array = v2->is_array;
	v1->para_cnt = v2->para_cnt;
	//v1->para = v2->para;
	//v1->paraf = v2->paraf;
	//strcpy(v1->ret, v2->ret);
}
