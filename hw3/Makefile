TARGET   = parser
OBJECT   = lex.yy.c y.tab.c y.output parser y.tab.h
CC       = gcc
CCFLAGS  = -Wall -Wextra -pedantic -g3
LEX      = flex
YACC     = yacc -v -t
YACCFLAG = -d
LIBS     = -lfl

all: $(TARGET)

$(TARGET): y.tab.c lex.yy.c main.c symtab.c
	$(CC) $^ -g -o $(TARGET) $(CCFLAGS) $(LIBS)

y.tab.c: parser.y
	$(YACC) $(YACCFLAG) $<

lex.yy.c: scanner.l
	$(LEX) $<

.PHONY: clean

clean:
	$(RM) -f $(TARGET) $(OBJECT)
