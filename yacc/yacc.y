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
%token<m_sId>  DATABASE SHOW
%token<m_sId>  IDENTIFIER INSERT INTO VALUES YIN VALUEIT
%token<m_sId>  CREATE TABLE PRIMARY KEY TYPE NOTNULL
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
%type<m_strv>  tableitems valueitems
%type<m_vecv>  valuesql
%type<m_sel>   selectsql
%type<m_join>  joinsql
%type<m_cond>  condsql
%type<m_attr>  attrsql
%type<m_sitem> attritem
%type<m_citem> conditem
%type<m_expr>  expression
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
    SHOW DATABASE IDENTIFIER ';' {
        $$.init($3);
        $$.display();
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
    SHOW TABLE IDENTIFIER ';' {
        $$.init($3);
        $$.display();
    };
createtbsql:
    CREATE TABLE IDENTIFIER '(' tablecon ';' {
        $$.init($3, $5);
        $$.display();
    };
tablecon:
    IDENTIFIER TYPE '(' INTEGER ')' NOTNULL ',' tablecon {
        $$.length.push_back($4);
        $$.name.push_back($1);
        $$.type.push_back($2);
        $$.notNull.push_back(true);
        $$.length.insert($$.length.end(), $8.length.begin(), $8.length.end());
        $$.name.insert($$.name.end(), $8.name.begin(), $8.name.end());
        $$.type.insert($$.type.end(), $8.type.begin(), $8.type.end());
        $$.notNull.insert($$.notNull.end(), $8.notNull.begin(), $8.notNull.end());
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
    | IDENTIFIER TYPE NOTNULL ',' tablecon {
        $$.length.push_back("0");
        $$.name.push_back($1);
        $$.type.push_back($2);
        $$.notNull.push_back(true);
        $$.length.insert($$.length.end(), $5.length.begin(), $5.length.end());
        $$.name.insert($$.name.end(), $5.name.begin(), $5.name.end());
        $$.type.insert($$.type.end(), $5.type.begin(), $5.type.end());
        $$.notNull.insert($$.notNull.end(), $5.notNull.begin(), $5.notNull.end());
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
    | IDENTIFIER TYPE '(' INTEGER ')' NOTNULL ')' {
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
    | IDENTIFIER TYPE NOTNULL ')' {
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
    SELECT attrsql FROM IDENTIFIER joinsql WHERE condsql ';' {
        $$.init($2, $4, $5, $7);
        $$.display();
    }
    | SELECT attrsql FROM IDENTIFIER joinsql ';' {
        CondSql cond;
        $$.init($2, $4, $5, cond);
        $$.display();
    }
    | SELECT attrsql FROM IDENTIFIER WHERE condsql ';' {
        JoinSql join;
        $$.init($2, $4, join, $6);
        $$.display();
    }
    | SELECT attrsql FROM IDENTIFIER ';' {
        CondSql cond;
        JoinSql join;
        $$.init($2, $4, join, cond);
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
    attritem JUDGEOP attritem expression {
        $$.init($2, $1, $3, $4);
    }
    | attritem JUDGEOP expression {
        AttrItem attr2;
        $$.init($2, $1, attr2, $3);
    };
expression:
    {}
    | VALUEIT {
        $$.str = $1;
    }
    | expression exprop expression {
        $$ = $1;
        $$.ops.push_back($2);
        $$.numbers.insert($$.numbers.end(), $3.numbers.begin(), $3.numbers.end());
        $$.ops.insert($$.ops.end(), $3.ops.begin(), $3.ops.end());
    }
    | exprop expression {
        $$.ops.push_back($1);
        $$.numbers.insert($$.numbers.end(), $2.numbers.begin(), $2.numbers.end());
        $$.ops.insert($$.ops.end(), $2.ops.begin(), $2.ops.end());
    }
    | INTEGER {
        $$.numbers.push_back($1);
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