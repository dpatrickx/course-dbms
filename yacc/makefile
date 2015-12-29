LEX = flex
YACC = bison
CC = g++
OBJECT = main
CFLAGS = -g
CXXFLAGS = -g

$(OBJECT): lex.yy.o  yacc.tab.o ../db/dbManager.o  main.cpp
	$(CC) lex.yy.o yacc.tab.o ../db/dbManager.o  main.cpp -o $(OBJECT)

lex.yy.c: lex.l
	$(LEX) lex.l

yacc.tab.c  yacc.tab.h: yacc.y
	$(YACC) -d yacc.y

clean:
	@rm -f $(OBJECT)  *.OBJECT *.o