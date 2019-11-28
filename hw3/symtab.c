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

IdList* BuildIdList()
{
    IdList* new = (IdList*)malloc(sizeof(IdList));
    new->pos = 0;
    new->capacity = 4;
    new->Ids = (char**)malloc(sizeof(char*) * 4);
    return new;
}

void InsertIdList(IdList* l, char* id)
{
    char* id_tmp = strdup(id);

    if (l->pos == l->capacity) {
        l->capacity *= 2;
        char** tmp_Ids = l->Ids;
        l->Ids = (char**)malloc(sizeof(char*) * l->capacity);
        int i;
        for (i = 0; i < l->pos; i++) {
            (l->Ids)[i] = tmp_Ids[i];
        }
        free(tmp_Ids);
    }

    l->Ids[l->pos++] = id_tmp;
}

void PrintIdList(IdList* l)
{
    int i;
    for (i = 0; i < l->pos; i++) {
        printf("%s ", l->Ids[i]);
    }
    printf("\n");
}

void ResetIdList(IdList* l)
{
    int i;
    for (i = (l->pos) - 1; i >= 0; i--) {
        free(l->Ids[i]);
    }
    l->pos = 0;
    l->capacity = 4;
    l->Ids = (char**)malloc(sizeof(char*) * 4);
}

TableEntry* BuildTableEntry(char* name, const char* kind, int level, Type* type, Attribute* attri, int line)
{
//printf("%d  ", level);
    TableEntry* new = (TableEntry*)malloc(sizeof(TableEntry));
    strcpy(new->name, name);
    strcpy(new->kind, kind);
    new->level = level;
    new->line = 0;
    new->type = type;
    new->attri = attri;
    new->line = line;
    return new;
}

void InsertTableEntry(SymbolTable* t, TableEntry* e)
{
	//printf("%s %s %d \n ", e->name, e->kind, e->level);
     
    if (FindEntryInScope(t, e->name) != NULL) {
	    printf("Error at Line#%d: %s '%s' is redeclared\n", yylineno, e->kind, e->name);
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
    printf("%s\t\t%s\t\t%s\t\t%s\t\t%s\n", "Name", "Kind", "Level", "Type", "Line");
    for (i = 0; i < t->pos; i++) {
        ptr = t->Entries[i];
        
            printf("%s\t\t%s\t\t", ptr->name, ptr->kind);
            PrintLevel(ptr->level);
            printf("%s\t\t", PrintType(ptr->type, 0));
            printf("%d", ptr->line);
        printf("\n"); 
        
    }
    
    printf("\n");
}

char* PrintType(const Type* t, int current_dim)
{
    if (t == NULL)
        return "type_error";
    ArraySig* ptr = t->array_signature;
    char* output_buf = (char*)malloc(sizeof(char) * 18);
    char tmp_buf[5];
    int name_len = strlen(t->name) + 1;
    memset(output_buf, 0, 18);
    snprintf(output_buf, name_len, "%s", t->name);

    while (ptr != NULL) {
        if (current_dim) {
            current_dim--;
        } else {
            snprintf(tmp_buf, 4, "[%d]", ptr->capacity);
            strcat(output_buf, tmp_buf);
        }
        ptr = ptr->next_dimension;
    }
    return output_buf;
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
void UpdateType(SymbolTable* s, Type* type, int line){
	int i;
	TableEntry* ptr;
	for(i = 0; i < s->pos; i++){
		ptr = s->Entries[i];
		if(ptr->line == line && s->current_level == ptr->level){
			ptr->type = type;
		}
	}
}
