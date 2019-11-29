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
    strcpy(new->scope, "global");
    strcpy(new->pre_scope, "global");
    return new;
}


TableEntry* BuildTableEntry(char* name, char* scope, int level, char* type, int line)
{
//printf("%d  ", level);
    TableEntry* new = (TableEntry*)malloc(sizeof(TableEntry));
    strcpy(new->name, name);
    strcpy(new->scope, scope);
    new->level = level;
    new->line = 0;
    strcpy(new->type, type);
    new->line = line;
    new->arr_dim = 0;
    new->arr_begin = 0;
    new->arr_end = 0;
    if(!strcmp(scope, "para")) strcpy(new->para, "yes");
    else strcpy(new->para, "no");
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
    printf("%s%18s%18s%18s%18s\n", "Name", "Level", "Type", "return", "Line");
    for (i = 0; i < t->pos; i++) {
        ptr = t->Entries[i]; 
            printf("%s\t\t", ptr->name);
            PrintLevel(ptr->level);
            printf("%8s%16s", ptr->type, ptr->ret);
            printf("%16d", ptr->line);
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
        printf("%d%s\t", l, "(global)");
    } else {
        printf("%d%s\t", l, "(local)");
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
void UpdateFunctionRet(SymbolTable* s, char* name, char* ret, int line){
	int i;
	TableEntry* ptr;
        for(i = 0; i < s->pos; i++){
                ptr = s->Entries[i];
                if(!strcmp(ptr->name, name) && !strcmp(ptr->type, "function") && ptr->line == line){
                        strcpy(ptr->ret, ret);
			return;
                }
        }
}
