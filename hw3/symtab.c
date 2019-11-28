#include "symtab.h"
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

SymbolTable* BuildSymbolTable(){
	SymbolTable* new = (SymbolTable*)malloc(sizeof(SymbolTable));
	strcpy(new->name, "name");
	strcpy(new->type, "type");
	strcpy(new->scope, "global");
	strcpy(new->pre_scope, "global");
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
	if(!strcmp(scope, "in_prog")) strcpy(new->scope, "prog_para");
	else if(!strcmp(scope, "in_func")) strcpy(new->scope, "func_para");
	else if(!strcmp(scope, "global")) strcpy(new->scope, "global");
	//else printf("%s777\n", scope);
	new->address = address;
	new->value = 0;
	strcpy(new->sval, "");
	//new->array = (float*)malloc(sizeof(float));

	
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
int FindEntryInAll(SymbolTable* s, char* name){
	int i;
	printf("JJJ");
	for (i = 0; i < s->pos; i++){
		TableEntry* tmp = s->Entries[i];
		if(!strcmp(name, tmp->name)) return 1;
	}
	return 0;
}
void PrintSymbolTable(SymbolTable* s){
	int i;
    TableEntry* ptr;
    printf("%10s %10s %10s %10s %10s\n", "Name", "Type", "Address", "Scope", "Value");
    
    for(i = 0; i < s->pos; i++){
        ptr = s->Entries[i];    
        printf("%10s %10s %10d %10s %10g", ptr->name, ptr->type, ptr->address, ptr->scope, ptr->value);
	
        printf("\n");
    }
}
void UpdateType(SymbolTable* s, char* new_type, int line){
	int i;
	printf("RRR");
	TableEntry* ptr;
	for(i = 0; i < s->pos; i++){
		ptr = s->Entries[i];
       		if(ptr->address == line && !strcmp(ptr->type, "var")) {
			if(!strcmp(new_type, "integer")){
				strcpy(ptr->type, new_type);
				ptr->value = 0;
			}
			else if(!strcmp(new_type, "real")){
				strcpy(ptr->type, new_type);
				ptr->value  = 0;
			}
			else if(!strcmp(new_type, "string")){
				strcpy(ptr->type, new_type);
                                strcpy(ptr->sval, "");
			}
			//else if(!strcmp(new_type, "array")){
			//	strcpy(ptr->type, new_type);
			//	int i;
				//for(i = 0; i < ptr->value->array_size; i++){
					//ptr->value->array[i] = 0;
				//}
			//}
		}
	}
	
}
void popall(SymbolTable* s){
	free(s);
}
/*
Value* AddArraySize(Value* value, int d){
	if(d < 0) {
		printf("Wrong array size");
	}
	else{
		value->array_size = d;
		int i;
		value->array = (float*)malloc(sizeof(float)*d);
		for(i = 0; i < d; i++){
			value->array[i] = 0;
		}
	}
	return value;
}
void PrintValue(Value* value, char* type){
	if(value == NULL){
		return;
	}
	else{
		if(!strcmp(type, "integer")) printf("%d", value->ival);
		else if(!strcmp(type, "real")) printf("%g", value->fval);
		else if(!strcmp(type, "array")) {
			int i;
			for(i = 0; i < value->array_size; i++){
				printf("%g, ", value->array[i]);
			}
		}
		else if(!strcmp(type, "string")) printf("%s", value->sval);
	}
	printf("KKK");
}
*/
