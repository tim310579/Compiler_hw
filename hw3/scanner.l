%{
/*
 * scan.l
 *
 * lex input file for pascal scanner
 *
 * extensions: two ways to spell "external" and "->" ok for "^".
 */

#include <stdio.h>
#include <string.h>
#include "y.tab.h"

int line_no = 1;
char buf[256];

%}
%option yylineno
A [aA]
B [bB]
C [cC]
D [dD]
E [eE]
F [fF]
G [gG]
H [hH]
I [iI]
J [jJ]
K [kK]
L [lL]
M [mM]
N [nN]
O [oO]
P [pP]
Q [qQ]
R [rR]
S [sS]
T [tT]
U [uU]
V [vV]
W [wW]
X [xX]
Y [yY]
Z [zZ]
NQUOTE [^']

%%



[/][*][^*]*([/][*][^*]*[*][/])*[^*]*[*][/]	{};

"//".* 	     {};
["][^"\n]*["]   return(STRINGCONST);
{A}{N}{D}                    return(AND);
{A}{R}{R}{A}{Y}              return(ARRAY);
{C}{A}{S}{E}                 return(CASE);
{C}{O}{N}{S}{T}              return(CONST);
{D}{I}{V}                    return(DIV);
{D}{O}                       return(DO);
{D}{O}{W}{N}{T}{O}           return(DOWNTO);
{E}{L}{S}{E}                 return(ELSE);
{E}{N}{D}                    return(END);
{E}{X}{T}{E}{R}{N} |
{E}{X}{T}{E}{R}{N}{A}{L}     return(EXTERNAL);
{F}{O}{R}                    return(FOR);
{F}{O}{R}{W}{A}{R}{D}        return(FORWARD);
{F}{U}{N}{C}{T}{I}{O}{N}     return(FUNCTION);
{G}{O}{T}{O}                 return(GOTO);
{I}{F}                       return(IF);
{I}{N}                       return(IN);
{L}{A}{B}{E}{L}              return(LABEL);
{M}{O}{D}                    return(MOD);
{N}{I}{L}                    return(NIL);
{N}{O}{T}                    return(NOT);
{O}{F}                       return(OF); 
{O}{R}                       return(OR);
{O}{T}{H}{E}{R}{W}{I}{S}{E}  return(OTHERWISE);
{P}{A}{C}{K}{E}{D}           return(PACKED);
{B}{E}{G}{I}{N}              return(PBEGIN);
{F}{I}{L}{E}                 return(PFILE);
{P}{R}{O}{C}{E}{D}{U}{R}{E}  return(PROCEDURE);
{P}{R}{O}{G}{R}{A}{M}        return(PROGRAM);
{R}{E}{C}{O}{R}{D}           return(RECORD);
{R}{E}{P}{E}{A}{T}           return(REPEAT);
{S}{E}{T}                    return(SET);
{T}{H}{E}{N}                 return(THEN);
{T}{O}                       return(TO);
{T}{Y}{P}{E}                 return(TYPE);
{U}{N}{T}{I}{L}              return(UNTIL);
{V}{A}{R}                    return(VAR);
{W}{H}{I}{L}{E}              return(WHILE);
{W}{I}{T}{H}                 return(WITH);
{I}{N}{T}{E}{G}{E}{R}	     {return(INTEGER);}
{R}{E}{A}{L}		     return(REAL);
{S}{T}{R}{I}{N}{G}	     return(STRING);
[a-zA-Z]*		{
	char* tmp;
	tmp = strdup(yytext);
	yylval.str = tmp;
	return(IDENTIFIER);
}
[a-zA-Z_][a-zA-Z0-9_]*	{
	char* tmp;
        tmp = strdup(yytext);
        yylval.str = tmp;
        return(IDENTIFIER);
}
":="                         { yylval.str=strdup(yytext); return(ASSIGNMENT);}
'({NQUOTE}|'')+'             { yylval.str=strdup(yytext); return(CHARACTER_STRING);}
":"                          { yylval.str=strdup(yytext); return(COLON);}
","                          { yylval.str=strdup(yytext); return(COMMA);}
[0-9]+                       { yylval.num = atoi(yytext); return(DIGSEQ);}
"."                          { yylval.str=strdup(yytext); return(DOT); }
".."                         { yylval.str=strdup(yytext); return(DOTDOT); }
"="                          { yylval.str=strdup(yytext); return(EQUAL); }
"!="                         { yylval.str=strdup(yytext); return(notEQUAL); }
">="                         { yylval.str=strdup(yytext); return(GE); }
">"                          { yylval.str=strdup(yytext); return(GT); }
"["                          { yylval.str=strdup(yytext); return(LBRAC); }
"<="                         { yylval.str=strdup(yytext); return(LE); }
"("                          { yylval.str=strdup(yytext); return(LPAREN); }
"<"                          { yylval.str=strdup(yytext); return(LT); }
"-"                          { yylval.str=strdup(yytext); return(MINUS);}
"+"                          { yylval.str=strdup(yytext); return(PLUS);}
"]"                          { yylval.str=strdup(yytext); return(RBRAC);}
[-]?[0-9]+("."[0-9]+)*?({E}("+"|"-")[0-9]+)	{
	yylval.str = strdup(yytext);
     	return(REALNUMBER);
}

[-]?[0-9]+"."[0-9]+  {
	yylval.dnum = atof(yytext);
       	return(REALNUMBER);
}
")"                          { yylval.str=strdup(yytext); return(RPAREN);}
";"                          { yylval.str=strdup(yytext); return(SEMICOLON);}
"/"                          { yylval.str=strdup(yytext); return(SLASH);}
"*"                          { yylval.str=strdup(yytext); return(STAR);}
"**"   		 	     { yylval.str=strdup(yytext); return(STARSTAR);}
"->"    		     { yylval.str=strdup(yytext); return(UPARROW);}

"(*"   |
"{"    { register int c;
	 while ((c = input()))
     {
      if (c == '}')
       break;
      else if (c == '*')
      {
       if ((c = input()) == ')')
        break;
       else
        unput (c);
      }
      else if (c == '\n')
       line_no++;
      else if (c == 0)
        fprintf (stderr, "Unexpected EOF inside comment at line %d\n",line_no);
     }
    }

[ \t\f]    ;

\r         ;
[ \t]+	;
\n    {
	line_no++;
	}

.    {fprintf(stderr,"Lexical analyzer error at line %d : %s\n",line_no,yytext);}

%%
/*
int noth(int argc, char** argv) {
  int i, tok, tmpline = 1;
  //int pre = 1;
  yyin = fopen("argv", "r");  
  //printf("begin of the test\n");
  for (i = 0; 1==1; i ++) {
    tok = yylex();
    if(tmpline > yylineno) tmpline = yylineno;
    //fprintf(stderr, "%3d-th token(type:%d) on line %d : %s\n", i, tok, tmpline, yytext);
    
    tmpline = yylineno+1;
  }
  return(0);
} // end of main 

void set_input(FILE *in){
	yyin = in;
}
int yywrap() {
  //printf("end of the test\n");
  fclose(yyin);
  exit(1);
}
*/
