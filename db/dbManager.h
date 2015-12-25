// manage all databases
// author: dpatrickx

#ifndef DBMANAGER_H
#define DBMANAGER_H

#include "../utils/PriQueue.h"
#include "db.h"
#include <map>
#include <string>
#include <stdio.h>

class DBManager {
private:
    DB* getDB(string name) {
        return dbMap[name];
    }
public:
    PriQueue<string> dbName;
    map<string, DB*> dbMap;
    string currDbName;
    string root;        // root/dbname
    DB* currDb;

    DBManager(string r) {
        root = r;
        if (root[root.size()-1] != '/')
            root += "/";
        currDb = "";
    }

    void showDBs() {
        cout<<"+--------------------+\n";
        cout<<"| Database           |\n";
        cout<<"+--------------------+\n";
        for (int i = 0; i < dbName.size(); i++)
            cout<<dbName[i]<<endl;
        cout<<"+--------------------+\n";
    }

    void useDB(string n) {
        if (dbMap.count(n)) {
            currDbName = n;
            currDb = getDB(n);
        }
        else
            printf("ERROR 1049 (42000): Unknown database%s\n", n);
    }

    void createDB(DB* d, string n) {
        if (dbMap.count(n)) {
            printf("ERROR 1007 (HY000): Can't create database '%s'; database exists\n", n);
            return;
        }
        mkdir(("./"+n+"/").c_str(), S_IRWXU);
        dbMap.insert(map<string, DB*>::value_type(n, d));
        dbName.insert(n);
    }

    DB* dropDB(string name) {
        if (dbMap.count(n) == 0) {
            printf("ERROR 1008 (HY000): Can't drop database '%s'; database doesn't exist\n", name);
            return;
        }
        dbName.remove(name);
        dbMap.remove(name);
    }

    void dbWork(string n, int type) {
        switch(type) {
            case CREATEDB:
                DB* db = new DB(n)
                createDB(db, n);
                break;
            case SHOWDB:
                if (n == "")
                    showDBs();
                else
                    DB* db = getDB(n);
                    db->showTBs();
                break;
            case DROPDB:
                dropDB(n);
                break;
            case USEDB:
                useDB(n);
                break;
            default: break;

        }
    }

    void tbWork(string n, int type) {
        if (currDbName == "") {
            printf("ERROR 1046 (3D000): No database selected\n");
            return;
        }
        switch(type) {
            case SHOWTB:
                currDb->showTBs();
                break;
            case DROPTB:
                currDb->dropTb(string n);
                break;
            default: break;
        }
    }

    void tbWork(TableCon c, string n) {
        if (currDbName == "") {
            printf("ERROR 1046 (3D000): No database selected\n");
            return;
        }
        currDb->createTB(c, n);
    }

    void tbWork(vector<string> t, vector<vector<string> > v) {
        if (currDbName == "") {
            printf("ERROR 1046 (3D000): No database selected\n");
            return;
        }
        currDb->insertTB(t, v);
    }

    void tbWork(vector<AttrItem> attrs, string t, JoinSql join, CondSql cond) {
        if (currDbName == "") {
            printf("ERROR 1046 (3D000): No database selected\n");
            return;
        }
        currDb->selectDB(attrs, t, join, cond);
    }

    void tbWork(string name, CondSql cond) {
        if (currDbName == "") {
            printf("ERROR 1046 (3D000): No database selected\n");
            return;
        }
        currDb->deleteTB(name, cond);
    }

    void tbWork(string name, vector<CondItem> set, CondSql cond) {
        if (currDbName == "") {
            printf("ERROR 1046 (3D000): No database selected\n");
            return;
        }
        currDb->update(name, set, cond);
    }

    void display() {
        map<string, Table*> iter;
        for (iter = tables.begin();iter != tables.end();iter++)
            cout<<iter->first<<endl;
    }
};

#endif