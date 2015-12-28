#ifndef SQL_H
#define SQL_H

#include "dbManager.h"
#include "auxSql.h"
#include "para.h"

class Sql{
public:
    int sqlType;
    Sql() {}
    // Sql() : manager(DBManager::instance("./")) {}
    // DBManager* const manager;
    // Sql& operator = (const Sql& s) {
    //     this->sqlType = s.sqlType;
    //     return *this;
    // }
    virtual void work() {}
};

class CreateDbSql : public Sql {
public:
    string dbName;

    CreateDbSql() {
        sqlType = CREATEDBSQL;
    }

    void work() {
        DBManager* manager = DBManager::instance("./");
        manager->dbWork(dbName, sqlType);
    }

    void init(string n) {
        dbName = n;
    }

    void display() {
        cout<<"SQL:  create database "<<dbName<<endl;
    }
};

class UseDbSql : public Sql {
public:
    string dbName;
    UseDbSql() {
        sqlType = USEDBSQL;
    }
    UseDbSql(string d) {
        dbName = d;
    }

    void work() {
        DBManager* manager = DBManager::instance("./");
        manager->dbWork(dbName, sqlType);
    }

    void init(string d) {
        dbName = d;
    }
    void display() {
        cout<<"SQL:  use database "<<dbName<<endl;
    }
};

class DropDbSql : public Sql {
public:
    string dbName;
    DropDbSql() {
        sqlType = DROPDBSQL;
    }
    DropDbSql(string d) {
        dbName = d;
    }

    void work() {
        DBManager* manager = DBManager::instance("./");
        manager->dbWork(dbName, sqlType);
    }

    void init(string d) {
        dbName = d;
    }
    void display() {
        cout<<"SQL:  drop databaes "<<dbName<<endl;
    }
};

class ShowDbSql : public Sql {
public:
    string dbName;

    ShowDbSql() {
        sqlType = SHOWDBSQL;
    }

    void init(string n) {
        dbName = n;
    }

    void work() {
        DBManager* manager = DBManager::instance("./");
        manager->dbWork(dbName, sqlType);
    }

    void display() {
        if (dbName != "")
            cout<<"SQL:  show database "<<dbName<<endl;
        else
            cout<<"SQL:  show databases\n";
    }
};

class CreateTbSql : public Sql {
public:
    TableCon content;
    string name;

    void work() {
        DBManager* manager = DBManager::instance("./");
        manager->tbWork(content, name);
    }

    CreateTbSql() {
        sqlType = CREATETBSQL;
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

class DescTbSql : public Sql {
public:
    string tbName;
    DescTbSql() {
        sqlType = DESCTBSQL;
    }

    void init(string n) {
        tbName = n;
    }

    void work() {
        DBManager* manager = DBManager::instance("./");
        manager->tbWork(tbName, sqlType);
    }

    void display() {
        cout<<"SQL:  desc table "<<tbName<<endl;
    }
};

class ShowTbSql : public Sql {
public:
    string tbName;
    ShowTbSql() {
        sqlType = SHOWTBSQL;
    }

    void work() {
        DBManager* manager = DBManager::instance("./");
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
        sqlType = DROPTBSQL;
    }

    void work() {
        DBManager* manager = DBManager::instance("./");
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
        sqlType = INSERTSQL;
    }
    InsertSql(string tab, vector<string> ite, vector<vector<string> > val) {
        valueSqls = val;
        tableitems = ite;
        tableName = tab;
    }

    void work() {
        DBManager* manager = DBManager::instance("./");
        manager->tbWork(tableName, tableitems, valueSqls);
    }

    void init(string tab, vector<string> ite, vector<vector<string> > val) {
        valueSqls = val;
        tableitems = ite;
        tableName = tab;
    }
    void display() {
        cout<<"\n==============================\n";
        cout<<"SQL:  insert into table: "<<tableName<<endl;
        cout<<"==============================\n";
        // cout<<"item size is "<<tableitems.size()<<endl;
        // for (int i = 0;i < tableitems.size();i++) {
        //     cout<<tableitems[i]<<endl;
        // }
        // cout<<"value size is "<<valueSqls.size()<<endl;
        // for (int i = 0;i < valueSqls.size();i++) {
        //     for (int j = 0;j < valueSqls[i].size();j++)
        //         cout<<valueSqls[i][j]<<' ';
        //     cout<<endl;
        // }
        // cout<<"-------------------\n";
    }

};


// select attrs from tables condsql
class SelectSql : public Sql {
public:
    vector<AttrItem> attrs;
    vector<string> tables;
    vector<string> opVec;
    vector<string> attrID;
    string groupName;
    CondSql cond;

    SelectSql() {
        sqlType = SELECTSQL;
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
        DBManager* manager = DBManager::instance("./");
        manager->tbWork(attrs, tables, cond, opVec, attrID, groupName);
    }

    void display() {
        cout<<"\n-------------------\n";
        cout<<"SQL:  select ";
        for (int i = 0; i < attrs.size(); i++) {
            attrs[i].display();
            cout<<' ';
        }
        for (int i = 0; i < opVec.size(); i++) {
            cout<<opVec[i]<<"("<<attrID[i]<<"), ";
        }
        cout<<"from ";
        for (int i = 0; i < tables.size(); i++)
            cout<<tables[i]<<' ';
        cout<<endl;
    }
};

class DeteleSql : public Sql {
public:
    string tableName;
    CondSql cond;
    DeteleSql() {
        sqlType = DELETESQL;
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
        DBManager* manager = DBManager::instance("./");
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
        sqlType = UPDATESQL;
    }
    UpdateSql(string n, CondSql c, vector<CondItem> s) {
        tableName = n;
        cond = c;
        set = s;
    }

    void work() {
        DBManager* manager = DBManager::instance("./");
        manager->tbWork(tableName, set, cond);
    }

    void init(string n, CondSql c, vector<CondItem> s) {
        tableName = n;
        cond = c;
        set = s;
    }

    void display() {
        cout<<"\n==============================\n";
        cout<<"SQL: update table "<<tableName<<endl;
        cout<<"set\n";
        for (int i = 0;i < set.size();i++) {
            set[i].display();
            cout<<' ';
        }
        cout<<"where\n";
        cond.display();
        cout<<"==============================\n";
    }
};
#endif
