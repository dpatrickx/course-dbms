#include "main.h"
#include "yacc.tab.h"

int main()
{
    const char* sFile = "test.sql";
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
