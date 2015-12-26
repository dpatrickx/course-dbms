LEX = flex
YACC = bison
CC = g++
OBJECT = main #生成的目标文件

$(OBJECT): lex.yy.o  yacc.tab.o main.cpp
	$(CC) lex.yy.o yacc.tab.o main.cpp -o $(OBJECT)

lex.yy.o: lex.yy.c  yacc.tab.h  main.h ../db/sql.h ../db/dbManager.h ../db/db.h
	$(CC) -c lex.yy.c

yacc.tab.o: yacc.tab.c  main.h ../db/sql.h ../db/dbManager.h ../db/db.h
	$(CC) -c yacc.tab.c

yacc.tab.c  yacc.tab.h: yacc.y
# bison使用-d参数编译.y文件
	$(YACC) -d yacc.y

lex.yy.c: lex.l
	$(LEX) lex.l

clean:
	@rm -f $(OBJECT)  *.OBJECT