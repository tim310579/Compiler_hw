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
    new->capacity = 4;
    new->Entries = (TableEntry**)malloc(sizeof(TableEntry*) * 4);
    return new;
}


TableEntry* BuildTableEntry(char* name, int level, char* type, int line)
{
//printf("%d  ", level);
    TableEntry* new = (TableEntry*)malloc(sizeof(TableEntry));
    strcpy(new->name, name);
    new->level = level;
    new->line = 0;
    strcpy(new->type, type);
    new->line = line;
    new->arr_dim = 0;
    new->para_cnt = 0;
    new->arr_range = (int**)malloc(sizeof(int*)*4);
    new->para = (char**)malloc(sizeof(char*)*4);
    return new;
}

void InsertTableEntry(SymbolTable* t, TableEntry* e)
{
	//printf("%s %s %d \n ", e->name, e->kind, e->level);
     
    if (FindEntryInScope(t, e->name) != NULL) {
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
        printf("|%s|     |%s|     |", ptr->type, ptr->ret);
        int j;
	printf("(");
	for(j = 0; j < ptr->para_cnt; j++){
		printf("%s, ", ptr->para[j]);
	}
	printf(")");
	printf("|     |");
	if(ptr->arr_dim != 0) printf("%d", ptr->arr_dim);
	printf("|     |");
	if(ptr->arr_dim != 0){
		int k;
		for(k = 0; k < ptr->arr_dim; k++){
			printf("(%d, %d) ",ptr->arr_range[k][0], ptr->arr_range[k][1]);
		}
	}
	printf("|");
        printf("\n"); 
        
    }
    
    printf("\n");
}


Value* BuildValue(const char* typename, const char* val)
{
    Type* t = BuildType(typename);
    Value* v = (Value*)malloc(sizeof(Value));
    v->type = t;
    v->sval = NULL;
    v->ival = 0;
    if (strcmp(t->name, "real") == 0) {
        v->dval = atof(val);
        v->sval = strdup(val);
    } else if (strcmp(t->name, "string") == 0) {
        v->sval = strdup(val);
    } else if (strcmp(t->name, "integer") == 0) {
        v->ival = atoi(val);
    } else if (strcmp(t->name, "octal") == 0) {
        v->ival = strtol(val, NULL, 8);
    } else if (strcmp(t->name, "scientific") == 0) {
        v->sval = strdup(val);
    } else if (strcmp(t->name, "boolean") == 0) {
        v->sval = strdup(val);
    }
    return v;
}

TableEntry* FindEntryInScope(SymbolTable* tbl, char* name)
{
    int i;
    for (i = 0; i < tbl->pos; i++) {
        TableEntry* it = tbl->Entries[i];
        if (strcmp(name, it->name) == 0 && it->level == tbl->current_level) {
            return it;
        }
    }
    return NULL;
}

TableEntry* FindEntryInGlobal(SymbolTable* tbl, char* name)
{
    int i;
    for (i = 0; i < tbl->pos; i++) {
        TableEntry* it = tbl->Entries[i];
        if (strcmp(name, it->name) == 0 && it->level == 0) {
            return it;
        }
    }
    return NULL;
}
Type* BuildType(const char* typename)
{
    Type* new = (Type*)malloc(sizeof(Type));
    strcpy(new->name, typename);
    new->array_signature = NULL; /*TODO*/
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
void UpdateType(SymbolTable* s, char* type, int line){
	int i;
	TableEntry* ptr;
	for(i = 0; i < s->pos; i++){
		ptr = s->Entries[i];
		if(ptr->line == line && s->current_level == ptr->level){
			strcpy(ptr->type, type);
		}
	}
}
int IsFunction(SymbolTable* s, char* name){
	int i;
	TableEntry* ptr;
	for(i = 0; i < s->pos; i++){
		ptr = s->Entries[i];
		if(!strcmp(ptr->name, name) && !strcmp(ptr->type, "function")){
			return 1;
		}
	}
	return 0;
}
void UpdateFunctionRet(SymbolTable* s, char* ret, int line){
	int i;
	TableEntry* ptr;
        for(i = 0; i < s->pos; i++){
                ptr = s->Entries[i];
                if(!strcmp(ptr->type, "function") && ptr->line == line){
                        strcpy(ptr->ret, ret);
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
		if(par->line == line && strcmp(par->type, ptr->type) && par->level != ptr->level){	//count parameter
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
                if(par->line == line && strcmp(par->type, ptr->type) && par->level != ptr->level){      //add parameter
                        strcpy(ptr->para[j], par->name);
			j++;
                }
        }
}

