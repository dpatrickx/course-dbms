LEX = flex
YACC = bison
CC = g++
OBJECT = main

$(OBJECT): lex.yy.o  yacc.tab.o main.cpp
	$(CC) lex.yy.o yacc.tab.o main.cpp -o $(OBJECT)

lex.yy.o: lex.yy.c  yacc.tab.h  main.h ../db/dbManager.h ../db/sql.h ../db/auxSql.h
	$(CC) -c lex.yy.c

yacc.tab.o: yacc.tab.c  main.h ../db/dbManager.h ../db/sql.h ../db/auxSql.h
	$(CC) -c yacc.tab.c

yacc.tab.c  yacc.tab.h: yacc.y
	$(YACC) -d yacc.y

lex.yy.c: lex.l
	$(LEX) lex.l

clean:
	@rm -f $(OBJECT)  *.OBJECT