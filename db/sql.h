#ifndef SQL_H
#define SQL_H

#include "dbManager.h"
#include "auxSql.h"

static DBManager* manager;

class Sql{
public:
    int sqlType;
    virtual void work();
};

class CreateDbSql : public Sql {
public:
    string dbName;

    CreateDbSql() {
        sqlType = CREATEDB;
    }

    void work() {
        manager->dbWork(dbName, sqlType);
    }

    void init(string n) {
        dbName = n;
    }

    void display() {
        cout<<"create database "<<dbName<<endl;
    }
};

class UseDbSql : public Sql {
public:
    string dbName;
    UseDbSql() {
        sqlType = USEDB;
    }
    UseDbSql(string d) {
        dbName = d;
    }

    void work() {
        manager->dbWork(dbName, sqlType);
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
    DropDbSql() {
        sqlType = DROPDB;
    }
    DropDbSql(string d) {
        dbName = d;
    }

    void work() {
        manager->dbWork(dbName, sqlType);
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

    ShowDbSql() {
        sqlType = SHOWDB;
    }

    void init(string n) {
        dbName = n;
    }

    void work() {
        manager->dbWork(dbName, sqlType);
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
        manager->tbWork(content, name);
    }

    CreateTbSql() {
        sqlType = CREATETB;
    }
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
    ShowTbSql() {
        sqlType = SHOWTB;
    }

    void work() {
        manager->tbWork("", sqlType);
    }

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

    DropTbSql() {
        sqlType = DROPTB;
    }

    void work() {
        manager->tbWork(tbName, sqlType);
    }

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

    InsertSql() {
        sqlType = INSERT;
    }
    InsertSql(string tab, vector<string> ite, vector<vector<string> > val) {
        valueSqls = val;
        tableitems = ite;
        tableName = tab;
    }

    void work() {
        manager->tbWork(tableName, tableitems, valueSqls);
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


// select attrs from tb1 joinsql condsql
class SelectSql : public Sql {
public:
    vector<AttrItem> attrs;
    vector<string> tables;
    CondSql cond;

    SelectSql() {

    }
    SelectSql(vector<AttrItem> a, vector<string> t, CondSql c) {
        attrs = a;
        tables = t;
        cond = c;
    }

    void init(vector<AttrItem> a, vector<string> t, CondSql c) {
        attrs = a;
        tables = t;
        cond = c;
    }

    void work() {
        manager->tbWork(attrs, tb1, join, cond);
    }

    void display() {
        cout<<"-------------------\n";
        cout<<"attr size is "<<attrs.size()<<endl;
        for (int i = 0; i < attrs.size(); i++) {
            cout<<i<<": ";
            attrs[i].display();
            cout<<endl;
        }
        cout<<"from\n";
        for (int i = 0; i < tables.size(); i++)
            cout<<tables[i]<<' ';
        cout<<endl;
        cout<<"where\n";
        cond.display();
    }
};

class DeteleSql : public Sql {
public:
    string tableName;
    CondSql cond;
    DeteleSql() {
        sqlType = DELETE;
    }
    DeteleSql(string t, CondSql c) {
        tableName = t;
        cond = c;
    }

    void init(string n, CondSql c) {
        tableName = n;
        cond = c;
    }

    void work() {
        manager->tbWork(tableName, cond);
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

    UpdateSql() {
        sqlType = UPDATE;
    }
    UpdateSql(string n, CondSql c, vector<CondItem> s) {
        tableName = n;
        cond = c;
        set = s;
    }

    void work() {
        manager->tbWork(tableName, set, cond);
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
