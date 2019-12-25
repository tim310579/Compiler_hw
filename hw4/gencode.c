#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "symtab.h"
#include "gencode.h"

void GenProgramStart(char* pname){
	//loopStack.top=-1;
	//condStack.top=-1;
	fprintf(outfp, "; %s\n",pname);
	fprintf(outfp, ".class public %s\n",pname);
	fprintf(outfp, ".super java/lang/Object\n\n");
	fprintf(outfp, ".field public static _sc Ljava/util/Scanner;\n ");
}
