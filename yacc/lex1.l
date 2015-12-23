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
comment     ("--"[^\r\n]*{newline})
SIMPLE_OPERATOR     ("+"|"-"|"*"|"/"|"%"|"="|"<"|">"|"."|","|";"|"!"|"("|")"|"["|"]"|"{"|"}"|"?"|":")
other_operator      (" "|"("|")"|",")
EXPRESSION  ([{SIMPLE_OPERATOR}A-Za-z]+)
yin         ("\'"|"\"")
%%
"USE"|"use"                         {   yylval.m_sId = "use";       return USE;         }
"DROP"|"drop"                       {   yylval.m_sId = "drop";      return DROP;        }
"TABLE"|"table"                     {   yylval.m_sId = "table";     return TABLE;       }
"IF"|"if"                           {   yylval.m_sId = "if";        return IF;          }
"EXISTS"|"exists"                   {   yylval.m_sId = "exists";    return EXISTS;      }
"JOIN"|"join"                       {   yylval.m_sId = "join";      return JOIN;        }
"ON"|"on"                           {   yylval.m_sId = "on";        return ON;          }
"INSERT"|"insert"                   {   yylval.m_sId = "insert";    return INSERT;      }
"INTO"|"into"                       {   yylval.m_sId = "into";      return INTO;        }
"VALUES"|"values"                   {   yylval.m_sId = "values";    return VALUES;      }
"SELECT"|"select"                   {   yylval.m_sId = "select";    return SELECT;      }
"FROM"|"from"                       {   yylval.m_sId = "from";      return FROM;        }
"WHERE"|"where"                     {   yylval.m_sId = "where";     return WHERE;       }
"LEFT"|"left"|"RIGHT"|"right"       {   yylval.m_sId = yytext;      return KIND;        }
"INNER"|"inner"|"OUTER"|"outer"     {   yylval.m_sId = yytext;      return IO;          }
"AND"|"and"                         {   yylval.m_sId = "and";       return CONNOP;      }
"OR"|"or"                           {   yylval.m_sId = "or";        return CONNOP;      }
"NOT"|"not"                         {   yylval.m_sId = "not";       return CONNOP;      }
"DELETE"|"delete"                   {   yylval.m_sId = "delete";    return DELETE;      }
"SET"|"set"                         {   yylval.m_sId = "set";       return SET;         }
"UPDATE"|"update"                   {   yylval.m_sId = "update";    return UPDATE;      }
{yin}           {
            yylval.m_sId = yytext;
            return YIN;
}
{identifier}    {
            yylval.m_sId = yytext;
            return IDENTIFIER;
        }
{SIMPLE_OPERATOR}    {
            yylval.m_sId = yytext;
            return (int)yytext[0];
        }
{EXPRESSION}    {
            yylval.m_sId = yytext;
            return EXPRESSION;
        }
{integer}       {
            yylval.m_sId = yytext;
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