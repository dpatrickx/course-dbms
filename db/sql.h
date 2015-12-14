#ifndef SQL_H
#define SQL_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Sql{
public:
    virtual void work() {}
};

class CreateSql : public Sql {
public:
    void work() {
        //Table table();
    }

    CreateSql(string sen, int file) {
        // get attr
        work();
    }
};

class InsertSql : public Sql {
public:
    string tableName;
    vector<string> valueSqls;

    InsertSql(string tab, vector<string> val) {
        valueSqls = val;
        tableName = tab;
    }

    void display() {
        cout<<"insert into table -- "<<tableName<<endl;
        cout<<"size -- "<<valueSqls.size()<<endl;
        for (int i = 0;i < valueSqls.size();i++)
            cout<<valueSqls[i]<<endl;
    }

};

class SeleItem {
public:
    string tableName;
    string attrName;

    SeleItem(string s1, string s2) {
        tableName = s1;
        attrName = s2;
    }
};

class CondItem {
public:
    string judeop; // more/less/equl
    string tableName;
    string attrName;
    string expression;

    CondItem(string j, string t, string a, string e) {
        judeop = j;
        tableName = t;
        attrName = a;
        expression = e;
    }
};

class CondSql {
public:
    vector<CondItem> conditions;
    vector<string> connops;  // OR AND NOT

    CondSql() {}
    CondSql(vector<CondItem> cond, vector<string> conn) {
        conditions = cond;
        connops = conn;
    }
};

class JoinSql : public sql {
public:
    string kind; // left/right/inner
    string iokind; // inner/outer
    string tableName1, tableName2;
    CondSql condition; // on
    JoinSql(string n1, string n2, string k, string iok, CondSql con) {
        kind = k;
        iokind = iok;
        tableName1 = n1;
        tableName2 = n2;
        condition = con;
    }
};

class SelectSql : public Sql {
public:
    vector<SeleItem> selVec;
    JoinSql join;
    CondSql cond;

    SelectSql(vector<SeleItem> s, JoinSql j, CondSql c) {
        join = j;
        cond = c;
        selVec = s;
    }
};

class DeteleSql : public sql {
public:
    string tableName;
    CondSql cond;

    DeteleSql(string t, CondSql c) {
        tableName = t;
        cond = c;
    }
};

class UpdateSql : public sql {
public:
    string tableName;
    //vector<string> attrs;
    string attr;
    string expression;
    //vector<string> exprs;
    CondSql cond;

    UpdateSql(string t, string a, string e, CondSql c) {
        tableName = t;
        attr = a;
        expression = e;
        cond = c;
    }
};
#endif
