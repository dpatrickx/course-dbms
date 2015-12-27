#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include "../db/sql.h"
using namespace std;

struct YaccType
{
    string m_sId;
    int m_nInt;
    char m_cOp;
    vector<string> m_strv;
    vector<vector<string> > m_vecv;

    UseDbSql m_usedb;
    ShowDbSql m_showdb;
    CreateDbSql m_credb;
    DropDbSql m_dropdb;

    CreateTbSql m_cretb;
    DropTbSql m_droptb;
    ShowTbSql m_showtb;

    TableCon m_con;
    InsertSql m_ins;

    SelectSql m_sel;
    JoinSql m_join;
    CondSql m_cond;
    vector<AttrItem> m_attr;
    Expression m_expr;
    AttrItem m_sitem;
    CondItem m_citem;

    DescTbSql m_desc;

    DeteleSql m_dele;

    UpdateSql m_upda;
    vector<CondItem> m_set;

    Sql m_sql;
};

#define YYSTYPE YaccType
#define YYINITDEPTH 5000
#define YYIAXDEPTH 6000

#endif