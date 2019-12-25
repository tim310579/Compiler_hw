#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtab.h"


extern int yyparse();	/* declared by yacc */

extern FILE* yyin;	/* declared by lex */
extern char* yytext;
extern SymbolTable* symbol_table;
extern char fileName[256];
FILE *outfp;

int  main( int argc, char **argv )
{
	symbol_table=BuildSymbolTable();
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
	
        fprintf(outfp, "        .text\n");
        fprintf(outfp, "        .section .rodata\n");
        fprintf(outfp, "        .align  3\n");
       
	yyin = fp;
	yyparse();	/* primary procedure of parser */
	
	//fprintf( stdout, "\nMy Symbol Table------------------------------------------------------------");
	//PrintSymbolTable(symbol_table);
	//free(symbol_table);
	fprintf( stdout, "\n-------------------------------------------------------------------------");
	fprintf( stdout, "\n|--------------------------------|\n" );
	fprintf( stdout, "|  There is no syntactic error!  |\n" );
	fprintf( stdout, "|--------------------------------|\n" );
	fprintf( stdout, "-----------------end-------------------\n\n");
	printf("%s\n\n", output);
	exit(0);
}
