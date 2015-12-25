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
valueitem   ({yin}({other_operator}|{nondigit}|{digit})*+{yin})
blank_chars ([ \f\r\t\v]+)
comment     ("--"[^\r\n]*{newline})
SIMPLE_OPERATOR     ("+"|"-"|"*"|"/"|"%"|"."|","|";"|"!"|"("|")"|"["|"]"|"{"|"}"|"?"|":")
other_operator      (" "|"("|")"|","|"."|":"|"-")
EXPRESSION  ([{SIMPLE_OPERATOR}A-Za-z]+)
yin         ("\'"|"\"")
%%
">"                                 {   yylval.m_sId = ">";         return JUDGEOP;     }
"<"                                 {   yylval.m_sId = "<";         return JUDGEOP;     }
"="                                 {   yylval.m_sId = "=";         return JUDGEOP;     }
"INNER"|"inner"                     {   yylval.m_sId = "inner";     return IOKIND;      }
"OUTER"|"outer"                     {   yylval.m_sId = "outer";     return IOKIND;      }
"AND"|"and"                         {   yylval.m_sId = "and";       return CONNOP;      }
"OR"|"or"                           {   yylval.m_sId = "or";        return CONNOP;      }
"NOT"|"not"                         {   yylval.m_sId = "not";       return CONNOP;      }
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
"LEFT"|"left"                       {   yylval.m_sId = "left";      return KIND;        }
"RIGHT"|"right"                     {   yylval.m_sId = "right";     return KIND;        }
"DELETE"|"delete"                   {   yylval.m_sId = "delete";    return DELETE;      }
"SET"|"set"                         {   yylval.m_sId = "set";       return SET;         }
"UPDATE"|"update"                   {   yylval.m_sId = "update";    return UPDATE;      }
"CREATE"|"create"                   {   yylval.m_sId = "create";    return CREATE;      }
"PRIMARY"|"primary"                 {   yylval.m_sId = "primary";   return PRIMARY;     }
"KEY"|"key"                         {   yylval.m_sId = "key";       return KEY;         }
"NOT NULL"|"not null"               {   yylval.m_sId = "not null";  return NOTNULL;     }
"DATABASE"|"database"               {   yylval.m_sId = "database";  return DATABASE;    }
"SHOW"|"show"                       {   yylval.m_sId = "show";      return SHOW;        }
"INT"|"int"                         {   yylval.m_sId = "int";       return TYPE;        }
"VARCHAR"|"varchar"                 {   yylval.m_sId = "varchar";   return TYPE;        }
"BOOL"|"bool"                       {   yylval.m_sId = "bool";      return TYPE;        }
{yin}           {
            yylval.m_sId = yytext;
            return YIN;
}
{valueitem}     {
            yylval.m_sId = yytext;
            return VALUEIT;
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