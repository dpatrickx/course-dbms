LEX = flex
YACC = bison
CC = g++
OBJECT = main
CFLAGS = -g
CXXFLAGS = -g

$(OBJECT): lex.yy.o  yacc.tab.o ../db/dbManager.o main.o
	$(CC) lex.yy.o yacc.tab.o ../db/dbManager.o main.o -o $(OBJECT)

yacc.tab.c  yacc.tab.h: yacc.y
	$(YACC) -d yacc.y

lex.yy.c: lex.l
	$(LEX) lex.l

clean:
	@rm -f $(OBJECT)  *.OBJECT yacc.tab.c yacc.tab.h