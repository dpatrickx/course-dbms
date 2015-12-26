/*  yacc file
    author: dpatrickx*/

%{
    #include "main.h"
    #include "../db/sql.h"
    extern "C"
    {
        void yyerror(const char *s);
        extern int yylex(void);
    }
%}

%token<m_sId>  INTEGER
%token<m_sId>  DATABASE SHOW DATABASES TABLES
%token<m_sId>  IDENTIFIER INSERT INTO VALUES YIN VALUEIT
%token<m_sId>  CREATE TABLE PRIMARY KEY TYPE NULLL IS
%token<m_sId>  KIND IOKIND SELECT FROM WHERE EXPRESSION
%token<m_sId>  JOIN ON USE IF EXISTS DROP
%token<m_sId>  JUDGEOP CONNOP UPDATE SET
%token<m_sId>  DELETE
%token<m_sId>  '%'  '='  '>'  '<'  '.' '+' '-' '*' '/'
%token<m_sId>  ','  ';'  '!'  '('  ')'  '['  ']'  '{'  '}' '?'
%token<m_cOp>  OPERATOR
%type<m_sql>   sqllist
%type<m_usedb>   usedbsql
%type<m_dropdb>  dropdbsql
%type<m_credb>   createdbsql
%type<m_showdb>  showdbsql
%type<m_cretb>   createtbsql
%type<m_droptb>  droptbsql
%type<m_showtb>  showtbsql
%type<m_con>   tablecon
%type<m_ins>   insertsql
%type<m_strv>  tableitems valueitems tables
%type<m_vecv>  valuesql
%type<m_sel>   selectsql
%type<m_join>  joinsql
%type<m_cond>  condsql
%type<m_attr>  attrsql
%type<m_sitem> attritem
%type<m_citem> conditem
%type<m_expr>  expression expr
%type<m_dele>  deletesql
%type<m_upda>  updatesql
%type<m_set>   setsql
%type<m_sId>   valueitem exprop

%start sqllist

%%
sqllist:
    {}
    | usedbsql sqllist
    | dropdbsql sqllist
    | createdbsql sqllist
    | showdbsql sqllist
    | createtbsql sqllist
    | droptbsql sqllist
    | showtbsql sqllist
    | insertsql sqllist
    | selectsql sqllist
    | deletesql sqllist
    | updatesql sqllist;

usedbsql:
    USE DATABASE IDENTIFIER ';' {
        $$.init($3);
        $$.display();
    }
    | USE IDENTIFIER ';' {
        $$.init($2);
        $$.display();
    };
dropdbsql:
    DROP DATABASE IDENTIFIER ';' {
        $$.init($3);
        $$.display();
    };
showdbsql:
    SHOW DATABASES ';' {
        $$.init("");
        $$.display();
        $$.work();
    }
    | SHOW DATABASE IDENTIFIER ';' {
        $$.init($3);
        $$.display();
        $$.work();
    };
createdbsql:
    CREATE DATABASE IDENTIFIER ';' {
        $$.init($3);
        $$.display();
    };

droptbsql:
    DROP TABLE IDENTIFIER ';' {
        $$.init($3);
        $$.display();
    };
showtbsql:
    SHOW TABLES ';' {
        $$.init("");
        $$.display();
        $$.work();
    }
    | SHOW TABLE IDENTIFIER ';' {
        $$.init($3);
        $$.display();
        $$.work();
    };
createtbsql:
    CREATE TABLE IDENTIFIER '(' tablecon ';' {
        $$.init($3, $5);
        $$.display();
    };
tablecon:
    IDENTIFIER TYPE '(' INTEGER ')' CONNOP NULLL ',' tablecon {
        $$.length.push_back($4);
        $$.name.push_back($1);
        $$.type.push_back($2);
        $$.notNull.push_back(true);
        $$.length.insert($$.length.end(), $9.length.begin(), $9.length.end());
        $$.name.insert($$.name.end(), $9.name.begin(), $9.name.end());
        $$.type.insert($$.type.end(), $9.type.begin(), $9.type.end());
        $$.notNull.insert($$.notNull.end(), $9.notNull.begin(), $9.notNull.end());
    }
    | IDENTIFIER TYPE '(' INTEGER ')' ',' tablecon {
        $$.length.push_back($4);
        $$.name.push_back($1);
        $$.type.push_back($2);
        $$.notNull.push_back(false);
        $$.length.insert($$.length.end(), $7.length.begin(), $7.length.end());
        $$.name.insert($$.name.end(), $7.name.begin(), $7.name.end());
        $$.type.insert($$.type.end(), $7.type.begin(), $7.type.end());
        $$.notNull.insert($$.notNull.end(), $7.notNull.begin(), $7.notNull.end());
    }
    | IDENTIFIER TYPE CONNOP NULLL ',' tablecon {
        $$.length.push_back("0");
        $$.name.push_back($1);
        $$.type.push_back($2);
        $$.notNull.push_back(true);
        $$.length.insert($$.length.end(), $6.length.begin(), $6.length.end());
        $$.name.insert($$.name.end(), $6.name.begin(), $6.name.end());
        $$.type.insert($$.type.end(), $6.type.begin(), $6.type.end());
        $$.notNull.insert($$.notNull.end(), $6.notNull.begin(), $6.notNull.end());
    }
    | IDENTIFIER TYPE ',' tablecon {
        $$.length.push_back("0");
        $$.name.push_back($1);
        $$.type.push_back($2);
        $$.notNull.push_back(false);
        $$.length.insert($$.length.end(), $4.length.begin(), $4.length.end());
        $$.name.insert($$.name.end(), $4.name.begin(), $4.name.end());
        $$.type.insert($$.type.end(), $4.type.begin(), $4.type.end());
        $$.notNull.insert($$.notNull.end(), $4.notNull.begin(), $4.notNull.end());
    }
    | IDENTIFIER TYPE '(' INTEGER ')' CONNOP NULLL ')' {
        $$.name.push_back($1);
        $$.type.push_back($2);
        $$.length.push_back($4);
        $$.notNull.push_back(true);
    }
    | IDENTIFIER TYPE '(' INTEGER ')' ')' {
        $$.name.push_back($1);
        $$.type.push_back($2);
        $$.length.push_back($4);
        $$.notNull.push_back(false);
    }
    | IDENTIFIER TYPE CONNOP NULLL ')' {
        $$.name.push_back($1);
        $$.type.push_back($2);
        $$.length.push_back("0");
        $$.notNull.push_back(true);
    }
    | IDENTIFIER TYPE ')' {
        $$.name.push_back($1);
        $$.type.push_back($2);
        $$.length.push_back("0");
        $$.notNull.push_back(false);
    }
    | PRIMARY KEY '(' IDENTIFIER ')' ')' {
        $$.priKey = $4;
    };

insertsql:
    INSERT INTO IDENTIFIER '(' tableitems ')' VALUES valuesql {
        InsertSql ins($3, $5, $8);
        ins.display();
    }
    | INSERT INTO IDENTIFIER VALUES valuesql {
        vector<string> temp;
        InsertSql ins($3, temp, $5);
        ins.display();
    };
tableitems:
    IDENTIFIER ',' tableitems {
        $$.push_back($1);
        $$.insert($$.end(), $3.begin(), $3.end());
    }
    | IDENTIFIER {
        $$.push_back($1);
    };
valuesql:
    '(' valueitems ')' ',' valuesql {
        $$.push_back($2);
        $$.insert($$.end(), $5.begin(), $5.end());
    }
    | '(' valueitems ')' ';'
    {
        $$.push_back($2);
    };
valueitems:
    valueitem ',' valueitems {
        $$.push_back($1);
        $$.insert($$.end(), $3.begin(), $3.end());
    }
    | valueitem {
        $$.push_back($1);
    };
valueitem:
    INTEGER {$$ = $1;}
    | VALUEIT {$$ = $1;};

selectsql:
    SELECT attrsql FROM tables WHERE condsql ';' {
        $$.init($2, $4, $6);
        $$.display();
    }
    | SELECT attrsql FROM tables ';' {
        CondSql cond;
        $$.init($2, $4, cond);
        $$.display();
    };
attrsql:
    '*' {
        AttrItem item("*", "*");
        $$.push_back(item);
    }
    | attritem ',' attrsql {
        $$ = $3;
        $$.push_back($1);
    }
    | attritem {
        $$.push_back($1);
    };
attritem:
    IDENTIFIER {
        $$.init("", $1);
    }
    | IDENTIFIER '.' IDENTIFIER {
        $$.init($1, $3);
    };
tables:
    IDENTIFIER ',' tables {
        $$.push_back($1);
        $$.insert($$.end(), $3.begin(), $3.end());
    }
    | IDENTIFIER {
        $$.push_back($1);
    };
joinsql:
    KIND IOKIND JOIN IDENTIFIER {
        CondSql c;
        $$.init($1, $2, $4, c);
    }
    | KIND IOKIND JOIN IDENTIFIER ON condsql {
        $$.init($1, $2, $4, $6);
    }
    | IOKIND JOIN IDENTIFIER {
        CondSql c;
        $$.init("", $1, $3, c);
    }
    | IOKIND JOIN IDENTIFIER ON condsql {
        $$.init("", $1, $3, $5);
    }
    | KIND JOIN IDENTIFIER {
        CondSql c;
        $$.init($1, "", $3, c);
    }
    | KIND JOIN IDENTIFIER ON condsql {
        $$.init($1, "", $3, $5);
    };
condsql:
    conditem CONNOP condsql {
        $$ = $3;
        $$.conditions.push_back($1);
        $$.connops.push_back($2);
    }
    | conditem {
        $$.conditions.push_back($1);
    };
conditem:
    attritem IS NULLL {
        AttrItem attr2;
        Expression expre;
        expre.str = "NULLLL";
        $$.init("=", $1, attr2, expre);
    }
    | attritem IS CONNOP NULLL {
        AttrItem attr2;
        Expression expre;
        expre.str = "NULLLL";
        $$.init(">", $1, attr2, expre);
    }
    | attritem JUDGEOP expression {
        AttrItem attr2;
        $$.init($2, $1, attr2, $3);
    }
    | attritem JUDGEOP attritem exprop INTEGER {
        Expression expre;
        expre.numbers.push_back($5);
        expre.ops.push_back($4);
        expre.value = 0;
        $$.init($2, $1, $3, expre);
    }
    | attritem JUDGEOP attritem {
        Expression expre;
        $$.init($2, $1, $3, expre);
    };
expression:
    {}
    | VALUEIT {
        $$.str = $1;
    }
    | expression '+' expr {
        $$ = $1;
        $$.ops.push_back($2);
        $$.numbers.insert($$.numbers.end(), $3.numbers.begin(), $3.numbers.end());
        $$.ops.insert($$.ops.end(), $3.ops.begin(), $3.ops.end());
        $$.value = $1.value+$3.value;
    }
    | expression '-' expr {
        $$ = $1;
        $$.ops.push_back($2);
        $$.numbers.insert($$.numbers.end(), $3.numbers.begin(), $3.numbers.end());
        $$.ops.insert($$.ops.end(), $3.ops.begin(), $3.ops.end());
        $$.value = $1.value-$3.value;
    }
    | '-' expr {
        $$.ops.push_back($1);
        $$.numbers.insert($$.numbers.end(), $2.numbers.begin(), $2.numbers.end());
        $$.ops.insert($$.ops.end(), $2.ops.begin(), $2.ops.end());
        $$.value = 0-$2.value;
    }
    | INTEGER {
        $$.numbers.push_back($1);
        $$.transVal($1);
    }
    | expr;
expr:
    expr '*' INTEGER {
        $$ = $1;
        $$.ops.push_back($2);
        $$.numbers.push_back($3);
        $$.value = $1.value * atoi($3.c_str());
    }
    | expr '/' INTEGER {
        $$ = $1;
        $$.ops.push_back($2);
        $$.numbers.push_back($3);
        $$.value = $1.value / atoi($3.c_str());
    }
    | expr '*' '(' expression ')' {
        $$ = $1;
        $$.ops.push_back($2);
        $$.ops.push_back($3);
        $$.ops.insert($$.ops.end(), $4.ops.begin(), $4.ops.end());
        $$.numbers.insert($$.numbers.end(), $4.numbers.begin(), $4.numbers.end());
        $$.ops.push_back($5);
        $$.value = $1.value * $4.value;
    }
    | expr '/' '(' expression ')' {
        $$ = $1;
        $$.ops.push_back($2);
        $$.ops.push_back($3);
        $$.ops.insert($$.ops.end(), $4.ops.begin(), $4.ops.end());
        $$.numbers.insert($$.numbers.end(), $4.numbers.begin(), $4.numbers.end());
        $$.ops.push_back($5);
        $$.value = $1.value / $4.value;
    }
    | '(' expression ')' {
        $$.ops.push_back($1);
        $$.ops.insert($$.ops.end(), $2.ops.begin(), $2.ops.end());
        $$.numbers.insert($$.numbers.end(), $2.numbers.begin(), $2.numbers.end());
        $$.ops.push_back($3);
        $$.value = $2.value;
    }
    | INTEGER {
        $$.numbers.push_back($1);
        $$.transVal($1);
    };
exprop:
    '+' { $$ = $1; }
    | '-' { $$ = $1; }
    | '*' { $$ = $1; }
    | '/' { $$ = $1; };

deletesql:
    DELETE FROM IDENTIFIER WHERE condsql ';' {
        $$.init($3, $5);
        $$.display();
    }
    | DELETE FROM IDENTIFIER ';' {
        CondSql cond;
        $$.init($3, cond);
        $$.display();
    };

updatesql:
    UPDATE IDENTIFIER SET setsql WHERE condsql ';' {
        $$.init($2, $6, $4);
        $$.display();
    }
    | UPDATE IDENTIFIER SET setsql ';' {
        CondSql cond;
        $$.init($2, cond, $4);
        $$.display();
    };

setsql:
    conditem ',' setsql {
        $$ = $3;
        $$.push_back($1);
    }
    | conditem {
        $$.push_back($1);
    };

%%

void yyerror(const char *s)
{
    cerr<<s<<endl;
}