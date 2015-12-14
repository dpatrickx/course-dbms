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
    vector<string> m_valv;
    CondSql m_cons;
    CondItem m_coni;
    vector<SeleItem> m_selv;
    SeleItem m_sel;
    JoinSql m_joi;
};

#define YYSTYPE Type

#endif