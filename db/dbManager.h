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

    void work(TableCon c, string n) {
        if (currDbName == "") {
            printf("ERROR 1046 (3D000): No database selected\n");
            return;
        }
        currDb->createTb(c, n);
    }
    void work(int type) {
        if (currDbName == "") {
            printf("ERROR 1046 (3D000): No database selected\n");
            return;
        }
        switch(type) {
            case 0: currDb->work(); break;
            default: break;
        }
    }

    void display() {
        map<string, Table*> iter;
        for (iter = tables.begin();iter != tables.end();iter++)
            cout<<iter->first<<endl;
    }
};

#endif