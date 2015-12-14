/*  lexer file
    author: dpatrickx*/

%{
    #include "main.h"
    #include "yacc.tab.h"
    extern "C"
    {
        int yywrap(void);
        int yylex(void);
    }
%}

%x COMMENT
nondigit    ([_A-Za-z])
newline     (\r|\n|\r\n)
digit       ([0-9])
integer     ({digit}+)
identifier  ({nondigit}({nondigit}|{digit})*)
blank_chars ([ \f\r\t\v]+)
comment     ("//"[^\r\n]*{newline})
valueStmt   ("("[^\(\)]*")")
SIMPLE_OPERATOR     ("+"|"-"|"*"|"/"|"%"|"="|"<"|">"|"."|","|";"|"!"|"("|")"|"["|"]"|"{"|"}"|"?"|":")
EXPRESSION  ([{SIMPLE_OPERATOR}A-Za-z]+)
%%
"INSERT"|"insert"                   {   yylval.m_sId = yytext;  return INSERT;         }
"INTO"|"into"                       {   yylval.m_sId = yytext;  return INTO;           }
"VALUES"|"values"                   {   yylval.m_sId = yytext;  return VALUES;         }
"SELECT"|"select"                   {   yylval.m_sId = yytext;  return SELECT;         }
"FROM"|"from"                       {   yylval.m_sId = yytext;  return FROM;           }
"WHERE"|"where"                     {   yylval.m_sId = yytext;  return WHERE;          }
"LEFT"|"left"|"RIGHT"|"right"       {   yylval.m_sId = yytext;  return KIND;           }
"INNER"|"inner"|"OUTER"|"outer"     {   yylval.m_sId = yytext;  return IO;             }
"AND"|"and"                         {   yylval.m_sId = "and";   return CONNOP;         }
"OR"|"or"                           {   yylval.m_sId = "or";    return CONNOP;         }
"NOT"|"not"                         {   yylval.m_sId = "not";   return CONNOP;         }
">"                                 {   yylval.m_sId = "more";  return JUDEOP;         }
"<"                                 {   yylval.m_sId = "less";  return JUDEOP;         }
"="                                 {   yylval.m_sId = "equl";  return JUDEOP;         }
"delete"|"DELETE"                   {   yylval.m_sId = yytext;  return DELETE;         }
"set"|"SET"                         {   yylval.m_sId = yytext;  return SET;            }
"update"|"UPDATE"                   {   yylval.m_sId = yytext;  return UPDATE;         }
{SIMPLE_OPERATOR} {
            yylval.m_sId = yytext;
            return (int)yytext[0];
        }
{EXPRESSION}    {
            yylval.m_sId = yytext;
            return EXPRESSION;
        }
{identifier}    {
            yylval.m_sId = yytext;
            return IDENTIFIER;
        }
{valueStmt}     {
            yylval.m_sId = yytext;
            return VALUESTMT;
        }
{integer}       {
            yylval.m_nInt = atoi(yytext);
            return INTEGER;
        }
{blank_chars}   {}
{newline}       {}
{comment}       {}

.       {
            yylval.m_cOp=yytext[0];
            return OPERATOR;
        }

%%
int yywrap(void)
{
    puts("-----the file is end");
    return 1;
}