#include "main.h"
#include "yacc.tab.h"
#include "../db/sql.h"
#include "../db/dbManager.h"

int main()
{
    const char* sFile = "file.txt";
    FILE* fp = fopen(sFile, "r");
    if(fp == NULL)
    {
        printf("cannot open %s\n", sFile);
        return -1;
    }
    extern FILE* yyin;
    yyin = fp;
    printf("-----begin parsing %s\n", sFile);
    yyparse();
    puts("-----end parsing");
    fclose(fp);
    return 0;
}
