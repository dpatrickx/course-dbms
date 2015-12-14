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

%token<m_nInt> INTEGER
%token<m_sId>  IDENTIFIER INSERT INTO VALUES VALUESTMT
%token<m_sId>  KIND IO SELECT FROM WHERE EXPRESSION
%token<m_sId>  JUDEOP CONNOP UPDATE SET
%token<m_sId>  DELETE
%token<m_sId>  '+'  '-'  '*'  '/'  '%'  '='  '>'  '<'  '.'
%token<m_sId>  ','  ';'  '!'  '('  ')'  '['  ']'  '{'  '}' '?' '*'
%token<m_cOp>  OPERATOR
%type<m_sId>   sqllist insertsql selectsql deletesql updatesql
%type<m_sId>   selectident kind io
%type<m_valv>  valuesql 
%type<m_cons>  onstmt
%type<m_selv>  selectient
%type<m_joi>   joinsql
%type<m_coni>  conitem
%type<m_cons>  condsql

%start sqllist

%%
sqllist:
    {}
    | insertsql sqllist
    | selectsql sqllist
    | updatesql sqllist
    | deletesql sqllist;
insertsql:
    INSERT INTO IDENTIFIER VALUES valuesql
    {
        InsertSql ins($3, $5);
        ins.display();
    };
valuesql:
    VALUESTMT ',' valuesql
    {
        $$.push_back($1);
        $$.insert($$.end(), $3.begin(), $3.end());
    }
    |VALUESTMT ';'
    {
        $$.push_back($1);
    };

selectsql:
    SELECT selectient FROM joinsql WHERE condsql
    {
        SelectSql sel()
    };

selectient:
    '*'
    {
        SeleItem item("__","__");
        $$.push_back(item);
    }
    | IDENTIFIER '.' IDENTIFIER
    {
        SeleItem item($1, $3);
        $$.push_back(item);
    }
    | IDENTIFIER
    {
        SeleItem item("", $1);
        $$.push_back(item);
    }
    | IDENTIFIER ',' selectient
    {
        SeleItem item("", $1);
        $$.push_back(item);
        $$.insert($$.end(), $2.begin(), $2.end());
    }
    | IDENTIFIER '.' IDENTIFIER  ',' selectident
    {
        SeleItem item($1, $3);
        $$.push_back(item);
        $$.insert($$.end(), $4.begin(), $4.end());
    };
joinsql:
    IDENTIFIER kind io JOIN IDENTIFIER onstmt
    {
        $$ = JoinSql($1, $5, $2, $3, $6);
    };
onstmt:
    {
        $$ = CondSql()
    }
    | ON condsql
    {

    };
kind:
    {}
    | KIND
    {
        $$ = $1;
    };
io:
    {}
    | IO
    {
        $$ = $1;
    };

condsql:
    {}
    | conditem CONNOP condsql
    {
        $$.conditions.push_back($1);
        $$.conditions.insert($$.conditions.end(), $3.conditions.begin(), $3.conditions.end());
        $$.connops.push_back($2);
        $$.connops.insert($$.connops.end(), $3.connops.begin(), $3.connops.end());
    };

conditem:
    IDENTIFIER JUDEOP EXPRESSION
    {
        $$ = CondItem($2, "", $1, $3);
    }
    | IDENTIFIER '.' IDENTIFIER JUDEOP EXPRESSION
    {
        $$ = CondItem($2, $1, $3, $3);
    };

deletesql:
    DELETE FROM IDENTIFIER WHERE condsql
    {
        $$ = DeteleSql($3, $5);
    };

updateSql:
    UPDATE IDENTIFIER SET IDENTIFIER '=' EXPRESSION
    {
        CondSql c();
        $$ = UpdateSql($2, $4, $6, c);
    }
    | UPDATE IDENTIFIER SET IDENTIFIER '=' EXPRESSION WHERE condsql
    {
        $$ = UpdateSql($2, $4, $6, $8);
    };

%%

void yyerror(const char *s)
{
    cerr<<s<<endl;
}