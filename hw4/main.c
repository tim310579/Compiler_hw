#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtab.h"
#include "gencode.h"

extern int yyparse();	/* declared by yacc */
extern int inexp;
extern FILE* yyin;	/* declared by lex */
extern char* yytext;
extern SymbolTable* symbol_table;
extern char fileName[256];
FILE *outfp;
extern char LCSS[32][192];
extern int str_cnt;
extern unsigned int ieee[100000];
extern int fl_cnt;

int  main( int argc, char **argv )
{
	//str_cnt = 0;
	symbol_table=BuildSymbolTable();
	Build_printint(symbol_table);
        Build_printreal(symbol_table);
        Build_printstring(symbol_table);
	//Print_Int();      

	if( argc != 2 ) {
		fprintf(  stdout,  "Usage:  ./parser  [filename]\n"  );
		exit(0);
	}

	FILE *fp = fopen( argv[1], "r" );
  	
	if( fp == NULL )  {
		fprintf( stdout, "Open  file  error\n" );
		exit(-1);
	}

	char output[64];
	strcpy(output, argv[1]);
	output[strlen(output)-1] = 's';
	
	outfp = fopen(output, "w");
	printf("%s\n\n\n\n", output);
        //Print_Int();  
   	//Print_Real();
	//Print_String();	
	yyin = fp;
	yyparse();	/* primary procedure of parser */
	//last_for_print(str_cnt, paras);
	
	fprintf(outfp, ".LCI:\n");
	fprintf(outfp, "	.string \"%%d \"\n");
	fprintf(outfp, ".LCR:\n");
	fprintf(outfp, "	.string \"%%f \"\n");
	fprintf(outfp, ".LCS:\n");
	fprintf(outfp, "	.string \"%%s\\n\"\n");	
	fprintf(outfp, ".LCendl:\n");
	fprintf(outfp, "	.string \"\\n\"\n");
	int i;
	for(i = 0; i < fl_cnt; i++){
		printf("%d\n", ieee[i]);
		fprintf(outfp, ".FL%d:\n", i);
		fprintf(outfp, "	.word	%d\n", ieee[i]);
	}

	for(i = 0; i < str_cnt; i++){
		//printf("%s\n\n", LCSS[i]);
		fprintf(outfp, ".LCS%d:\n", i);
        	fprintf(outfp, "        .string %s\n", LCSS[i]);
	}
	TableEntry* ptr;
	for(i = 0; i < symbol_table->pos; i++){
		ptr = symbol_table->Entries[i];
		fprintf(outfp, "### %s, space : %d\n", ptr->name, ptr->exe_space);
	}
	//fprintf( stdout, "\nMy Symbol Table------------------------------------------------------------");
	PrintSymbolTable(symbol_table);
	free(symbol_table);
	//printf("%d\n\n", inexp);
	fprintf( stdout, "\n-------------------------------------------------------------------------");
	fprintf( stdout, "\n|--------------------------------|\n" );
	fprintf( stdout, "|  There is no syntactic error!  |\n" );
	fprintf( stdout, "|--------------------------------|\n" );
	fprintf( stdout, "-----------------end-------------------\n\n");
	//printf("%s\n\n", output);
	exit(0);
}
