#ifndef SQL_H
#define SQL_H

#include "table.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Sql{
public:
    virtual void work() {}
    virtual void display() {}
};

class CreateDbSql : public Sql {
public:
    string dbName;

    CreateDbSql() {}

    void init(string n) {
        dbName = n;
    }

    void work() {}

    void display() {
        cout<<"create database "<<dbName<<endl;
    }
};

class UseDbSql : public Sql {
public:
    string dbName;
    UseDbSql() {}
    UseDbSql(string d) {
        dbName = d;
    }

    void init(string d) {
        dbName = d;
    }
    void display() {
        cout<<"use database "<<dbName<<endl;
    }
};

class DropDbSql : public Sql {
public:
    string dbName;
    DropDbSql() {}
    DropDbSql(string d) {
        dbName = d;
    }

    void init(string d) {
        dbName = d;
    }
    void display() {
        cout<<"drop databaes "<<dbName<<endl;
    }
};

class ShowDbSql : public Sql {
public:
    string dbName;
    void init(string n) {
        dbName = n;
    }

    void display() {
        cout<<"show database "<<dbName<<endl;
    }
};

class CreateTbSql : public Sql {
public:
    TableCon content;
    string name;

    void work() {

    }

    CreateTbSql() {}
    CreateTbSql(string n, TableCon c) {
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
class ShowTbSql : public Sql {
public:
    string tbName;

    ShowTbSql() {}

    void init(string n) {
        tbName = n;
    }
    void display() {
        cout<<"show table "<<tbName<<endl;
    }
};
class DropTbSql : public Sql {
public:
    string tbName;

    DropTbSql() {}

    void init(string n) {
        tbName = n;
    }

    void display() {
        cout<<"drop table "<<tbName<<endl;
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
        cout<<"-------------------\n";
        cout<<"insert into table: "<<tableName<<endl;
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

// attr + 1 - 1
// 1 + 1 - 1
// -1
// 'sdfsdf'
class Expression {
public:
    vector<string> numbers;
    vector<string> ops;
    string str;

    Expression() {
        str = "";
    }
    Expression(vector<string> n, vector<string> o) {
        numbers = n;
        ops = o;
    }
    void init(vector<string> n, vector<string> o) {
        numbers = n;
        ops = o;
    }
    int isNull() {
        if (numbers.size()==0 and str=="")
            return 1;
        return 0;
    }
    void display() {
        if (numbers.size() == ops.size()) {
            for (int i = 0;i < numbers.size();i++)
                cout<<ops[i]<<' '<<numbers[i]<<' ';
        } else {
            for (int i = 0;i < numbers.size();i++) {
                cout<<numbers[i]<<' ';
                if (i < ops.size())
                    cout<<ops[i]<<' ';
            }
        }
        if (str != "")
            cout<<str;
    }
};
class AttrItem {
public:
    string tableName;
    string attrName;
    AttrItem() {
        tableName = "";
        attrName = "";
    }
    AttrItem(string s1, string s2) {
        tableName = s1;
        attrName = s2;
    }

    void init(string s1, string s2) {
        tableName = s1;
        attrName = s2;
    }

    int isNull() {
        if (tableName=="" && attrName=="")
            return 1;
        return 0;
    }

    void display() {
        if (tableName!="" && tableName!="*")
            cout<<tableName<<'.'<<attrName;
        else
            cout<<attrName;
    }
};
// attr1 >/</= attr2
// attr1 >/</= expression
class CondItem {
public:
    string judgeOp; // more/less/equl
    AttrItem attr1, attr2;
    Expression expression;
    CondItem() {}
    CondItem(string j, AttrItem a1, AttrItem a2, Expression e) {
        judgeOp = j;
        attr1 = a1;
        attr2 = a2;
        expression = e;
    }

    void init(string j, AttrItem a1, AttrItem a2, Expression e) {
        judgeOp = j;
        attr1 = a1;
        attr2 = a2;
        expression = e;
    }

    void display() {
        if (expression.isNull()) {
            attr1.display();
            cout<<" "<<judgeOp<<' ';
            attr2.display();
        } else {
            attr1.display();
            cout<<" "<<judgeOp<<' ';
            if (!attr2.isNull()) {
                attr2.display();
                cout<<' ';
            }
            expression.display();
        }
        cout<<endl;
    }
};
// (tb1.attr1 judeop tb2.attr2) or/and/not ...
class CondSql {
public:
    vector<CondItem> conditions;
    vector<string> connops;  // OR AND NOT

    CondSql() {}
    CondSql(vector<CondItem> cond, vector<string> conn) {
        conditions = cond;
        connops = conn;
    }

    void display() {
        if (conditions.size() > 0) {
            for (int i = 0; i < conditions.size(); i++) {
                conditions[i].display();
                if (i != conditions.size()-1)
                    cout<<connops[i]<<' ';
            }
        }
    }
};
// kind iokind join tb2 condition
class JoinSql : public Sql {
public:
    string kind;    // left/right/inner
    string iokind;  // inner/outer
    string tb2;
    CondSql condition; // on
    JoinSql() {
        kind = "";
        iokind = "";
    }
    JoinSql(string k, string i, string t, CondSql c) {
        kind = k;
        iokind = i;
        tb2 = t;
        condition = c;
    }

    int isNull() {
        if (kind=="" && iokind=="")
            return 1;
        return 0;
    }

    void init(string k, string i, string t, CondSql c) {
        kind = k;
        iokind = i;
        tb2 = t;
        condition = c;
    }

    void display() {
        cout<<kind<<' '<<iokind<<' '<<tb2<<' '<<"on"<<endl;
        condition.display();
    }
};
// select attrs from tb1 joinsql condsql
class SelectSql : public Sql {
public:
    vector<AttrItem> attrs;
    string tb1;
    JoinSql join;
    CondSql cond;

    SelectSql() {}
    SelectSql(vector<AttrItem> a, string t, JoinSql j, CondSql c) {
        attrs = a;
        tb1 = t;
        join = j;
        cond = c;
    }

    void init(vector<AttrItem> a, string t, JoinSql j, CondSql c) {
        attrs = a;
        tb1 = t;
        join = j;
        cond = c;
    }

    void display() {
        cout<<"-------------------\n";
        cout<<"attr size is "<<attrs.size()<<endl;
        for (int i = 0; i < attrs.size(); i++) {
            cout<<i<<": ";
            attrs[i].display();
            cout<<endl;
        }
        cout<<"from "<<tb1<<endl;
        join.display();
        cout<<"where\n";
        cond.display();
    }
};

class DeteleSql : public Sql {
public:
    string tableName;
    CondSql cond;
    DeteleSql() {}
    DeteleSql(string t, CondSql c) {
        tableName = t;
        cond = c;
    }

    void init(string n, CondSql c) {
        tableName = n;
        cond = c;
    }

    void display() {
        cout<<"-------------------\n";
        cout<<"delete from "<<tableName<<endl<<"where\n";
        cond.display();
    }
};

class UpdateSql : public Sql {
public:
    string tableName;
    CondSql cond;   // where clause
    vector<CondItem> set;

    UpdateSql() {}
    UpdateSql(string n, CondSql c, vector<CondItem> s) {
        tableName = n;
        cond = c;
        set = s;
    }

    void init(string n, CondSql c, vector<CondItem> s) {
        tableName = n;
        cond = c;
        set = s;
    }

    void display() {
        cout<<"-------------------\n";
        cout<<"update table "<<tableName<<endl;
        cout<<"set\n";
        for (int i = 0;i < set.size();i++)
            set[i].display();
        cout<<"where\n";
        cond.display();
    }
};
#endif
