#include "symtab.h"
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

SymbolTable* BuildSymbolTable(){
	SymbolTable* new = (SymbolTable*)malloc(sizeof(SymbolTable));
	strcpy(new->name, "name");
	strcpy(new->type, "type");
	strcpy(new->scope, "scope");
	//new->name = "name";
	//new->type = "type";
	new->address = 0;
	new->level = 0;
	new->pos = 0;
	new->depth = 0;
	new->Entries = (TableEntry**)malloc(sizeof(TableEntry*) * 4);
	int i = 0;
	for(i = 0; i < 4; i++){
		new->Entries[i] = (TableEntry*)malloc(sizeof(TableEntry));
	}
	return new;
}
TableEntry* BuildTableEntry(char* name, char* type, char* scope, int address){
	//printf("%s %s %s\n", name, type, scope);
	TableEntry* new = (TableEntry*)malloc(sizeof(TableEntry));
	strcpy(new->name, name);
	strcpy(new->type, type);
	strcpy(new->scope, scope);
	new->address = address;
	//printf("%s %s", new->name, new->scope);
	return new;
}

void InsertTableEntry(SymbolTable* s, TableEntry* t){
	if(t->type == NULL) return;	//no need to insert
	if(FindEntryInScope(s, t->name, t->scope)){
		printf("Find duplicate declaration in line %d: %s\n", yylineno, t->name);
		return;		
	}
	//grow depth
	if(s->pos == s->depth){
		s->depth *= 2;
		TableEntry** tmp = s->Entries;
		s->Entries = (TableEntry**)malloc(sizeof(TableEntry*) * (s->depth));
		int i = 0;
		for(i = 0; i < s->pos; i++){
			(s->Entries)[i] = tmp[i];
		}
		free(tmp);
	}
	s->Entries[s->pos++] = t;
}

int FindEntryInScope(SymbolTable* s, char* name, char* scope){
	int i = 0;
	for(i = 0; i < s->pos; i++){
		TableEntry* tmp = s->Entries[i];
		if(strcmp(name, tmp->name) == 0 && strcmp(scope, tmp->scope) == 0){
			return 1;
		}
	}
	return 0;
}
void PrintSymbolTable(SymbolTable* s){
	int i;
    TableEntry* ptr;
    printf("%s, %s, %s, %s\n", "Name", "Type", "Address", "scope");
    printf("\n");
    for(i = 0; i < s->pos; i++){
        ptr = s->Entries[i];
        
            printf("%s, %s, %d, %s", ptr->name, ptr->type, ptr->address, ptr->scope);
            printf("\n");
    }
    
    printf("\n");
}

