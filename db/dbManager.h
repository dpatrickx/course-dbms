// manage all databases
// author: dpatrickx

#ifndef DBMANAGER_H
#define DBMANAGER_H

#include "../utils/PriQueue.h"
#include "../db/para.h"
#include "db.h"
#include <map>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

class DBManager {
private:
    DB* getDB(string name) {
        return dbMap[name];
    }
    DBManager(string r) {
        root = r;
        if (root[root.size()-1] != '/')
            root += "/";
        currDbName = "";
    }

public:
    static DBManager* _instance;
    static DBManager* instance(string r) {
        if (_instance == 0) {
            _instance = new DBManager(r);
        }
        return _instance;
    }
    PriQueue<string> dbName;
    map<string, DB*> dbMap;
    string currDbName;
    string root;        // root/dbname
    DB* currDb;

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
            printf("ERROR 1049 (42000): Unknown database %s\n", n.c_str());
    }

    void createDB(DB* d, string n) {
        if (dbMap.count(n)) {
            printf("ERROR 1007 (HY000): Can't create database '%s'; database exists\n", n.c_str());
            return;
        }
        mkdir(("./"+n+"/").c_str(), S_IRWXU);
        dbMap.insert(map<string, DB*>::value_type(n, d));
        dbName.insert(n);
    }

    void dropDB(string name) {
        if (dbMap.count(name) == 0) {
            printf("ERROR 1008 (HY000): Can't drop database '%s'; database doesn't exist\n", name.c_str());
            return;
        }
        dbName.remove(name);
        dbMap.erase(name);
        system(("rm -r "+name).c_str());
    }

    void dbWork(string n, int type) {
        DB* db;
        switch(type) {
            case CREATEDBSQL:
                db = new DB(n);
                createDB(db, n);
                break;
            case SHOWDBSQL:
                if (n == "")
                    showDBs();
                else {
                    db = getDB(n);
                    db->showTBs();
                }
                break;
            case DROPDBSQL:
                dropDB(n);
                break;
            case USEDBSQL:
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
            case SHOWTBSQL:
                currDb->showTBs();
                break;
            case DROPTBSQL:
                currDb->dropTB(n);
                break;
            case DESCTBSQL:
                currDb->descTB(n);
                break;
            default: break;
        }
    }

    void tbWork(const TableCon& c, string n) {
        if (currDbName == "") {
            printf("ERROR 1046 (3D000): No database selected\n");
            return;
        }
        currDb->createTB(c, n, currDbName);
    }

    void tbWork(string name, vector<string> t, vector<vector<string> > v) {
        if (currDbName == "") {
            printf("ERROR 1046 (3D000): No database selected\n");
            return;
        }
        currDb->insertTB(name, t, v);
    }

    void tbWork(vector<AttrItem> attrs, vector<string> t, CondSql cond, vector<string> opVec, vector<string> attrId, string gName) {
        if (currDbName == "") {
            printf("ERROR 1046 (3D000): No database selected\n");
            return;
        }
        currDb->selectTB(attrs, t, cond, opVec, attrId, gName);
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
        for (int i = 0; i < dbName.size(); i++)
            cout<<dbName[i]<<endl;
    }
};

#endif