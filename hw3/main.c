#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtab.h"

extern int yyparse();	/* declared by yacc */
extern FILE* yyin;	/* declared by lex */
extern char* yytext;
extern SymbolTable* symbol_table;

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

	yyin = fp;
	yyparse();	/* primary procedure of parser */
	PrintSymbolTable(symbol_table);
	
	printf("%s\n", yytext);
	fprintf( stdout, "\n|--------------------------------|\n" );
	fprintf( stdout, "|  There is no syntactic error!  |\n" );
	fprintf( stdout, "|--------------------------------|\n" );
	exit(0);
}
