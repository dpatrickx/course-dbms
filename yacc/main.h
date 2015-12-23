#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include "../db/sql.h"
using namespace std;

struct Type
{
    string m_sId;
    int m_nInt;
    char m_cOp;
    vector<string> m_strv;
    vector<vector<string> > m_vecv;
    CondSql m_cons;
    CondItem m_coni;
    vector<SeleItem> m_selv;
    SeleItem m_sel;
    JoinSql m_joi;
    UseSql m_use;
    DropSql m_drop;
    CreateSql m_cre;
    InsertSql m_ins;
    TableCon m_con;
    Sql m_sql;
};

#define YYSTYPE Type

#endif