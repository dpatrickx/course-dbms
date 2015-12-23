#ifndef SQL_H
#define SQL_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Sql{
public:
    virtual void work() {}
    virtual void display() {}
};

class UseSql : public Sql {
public:
    string tbName;
    UseSql() {}
    UseSql(string d) {
        tbName = d;
    }

    void init(string d) {
        tbName = d;
    }
    void display() {
        cout<<"use database "<<tbName<<endl;
    }
};

class DropSql : public Sql {
public:
    string tbName;
    int type; // 0 - create immediately, 1 - judge if exists
    DropSql() {}
    DropSql(string d, int t = 0) {
        tbName = d;
        type = t;
    }

    void init(string d, int t = 0) {
        tbName = d;
        type = t;
    }
    void display() {
        if (type)
            cout<<"drop databaes if exists "<<tbName<<endl;
        else
            cout<<"drop databaes "<<tbName<<endl;
    }
};

class TableCon{
public:
    vector<string> name;
    vector<string> type;
    vector<bool>   notNull;
    string priKey;

    TableCon() {}

    void init(vector<string> n, vector<string> t, string p) {
        name = n;
        type = t;
        priKey = p;
    }

    void display() {
        cout<<"attr size is "<<name.size()<<endl;
        for (int i = 0; i < name.size(); i++) {
            cout<<i<<" :";
            cout<<name[i]<<' '<<type[i]<<' '<<notNull[i]<<endl;
        }
        cout<<"primary key is "<<priKey<<endl;
    }
};
class CreateSql : public Sql {
public:
    TableCon content;
    string name;

    CreateSql() {}
    CreateSql(string n, TableCon c) {
        // get attr
        content = c;
        name = n;
    }

    void init(string n, TableCon c) {
        // get attr
        content = c;
        name = n;
    }
    void display() {
        cout<<"-------------------\n";
        cout<<"table name is "<<name<<endl;
        content.display();
    }
};

class InsertSql : public Sql {
public:
    string tableName;
    vector<string> tableitems;
    vector<vector<string> > valueSqls;

    InsertSql() {}
    InsertSql(string tab, vector<string> ite, vector<vector<string> > val) {
        valueSqls = val;
        tableitems = ite;
        tableName = tab;
    }

    void init(string tab, vector<string> ite, vector<vector<string> > val) {
        valueSqls = val;
        tableitems = ite;
        tableName = tab;
    }
    void display() {
        cout<<"insert into table -- "<<tableName<<endl;
        cout<<"item size is "<<tableitems.size()<<endl;
        for (int i = 0;i < tableitems.size();i++) {
            cout<<tableitems[i]<<endl;
        }
        cout<<"value size is "<<valueSqls.size()<<endl;
        for (int i = 0;i < valueSqls.size();i++) {
            for (int j = 0;j < valueSqls[i].size();j++)
                cout<<valueSqls[i][j]<<' ';
            cout<<endl;
        }
    }

};

class SeleItem {
public:
    string tableName;
    string attrName;
    SeleItem() {}
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
    CondItem() {}
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

class JoinSql : public Sql {
public:
    string kind; // left/right/inner
    string iokind; // inner/outer
    string tableName1, tableName2;
    CondSql condition; // on
    JoinSql() {}
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

class DeteleSql : public Sql {
public:
    string tableName;
    CondSql cond;

    DeteleSql(string t, CondSql c) {
        tableName = t;
        cond = c;
    }
};

class UpdateSql : public Sql {
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
