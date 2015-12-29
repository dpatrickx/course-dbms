// database class
// author: dpatrickx

#ifndef DB_H
#define DB_H

#include "table.h"
#include "auxSql.h"
#include "../utils/PriQueue.h"
#include <map>
#include <stdlib.h>

class DB {
private:
    Table* getTable(string name) {
        return tbMap[name];
    }
public:
    string dbName;
    PriQueue<string> tbName;
    map<string, Table*> tbMap;

    DB() {}

    DB(string n) {
        dbName = n;
    }

    void saveFile() {
        for (int i = 0; i < tbName.size(); i++) {
            Table* tb = getTable(tbName[i]);
            tb->saveFile();
        }
    }

    void dropTB(string name) {
        if (tbMap.count(name) == 0) {
            printf("ERROR 1051 (42S02): Unknown table '%s'\n", name.c_str());
            return;
        }
        Table* tb = getTable(name);
        // tb->drop();
        delete tb;
        system(("rm "+dbName+"/"+name+".txt").c_str());
        tbName.remove(name);
        tbMap.erase(name);
    }

    void createTB(const TableCon& c, string n, string path) {
        if (tbMap.count(n)) {
            printf("ERROR 1050 (42S01): Table '%s' already exists\n", n.c_str());
            return;
        }
        Table* table = new Table(c, n, path);
        tbName.insert(n);
        tbMap.insert(map<string, Table*>::value_type(n, table));
    }

    void showTBs() {
        cout<<"+--------------------+\n";
        cout<<"tables in "<<dbName<<endl;
        cout<<"+--------------------+\n";
        for (int i = 0; i < tbName.size(); i++)
            cout<<tbName[i]<<endl;
        cout<<"+--------------------+\n";
    }

    void insertTB(string name, vector<string> t, vector<vector<string> > v) {
        if (tbMap.count(name) == 0) {
            printf("ERROR 1051 (42S02): Unknown table '%s'\n", name.c_str());
            return;
        }
        Table* tb = getTable(name);
        tb->insert(t, v);
    }

    void selectTB(vector<AttrItem> attrs, vector<string> t, CondSql cond, vector<string> opVec, vector<string> attrId, string gName) {
        vector<Table*> vec;
        Table* tb = getTable(t[0]);
        map<string, Table*>::iterator it;
        for (it = tbMap.begin(); it != tbMap.end(); it++) {
            vec.push_back(it->second);
        }
        tb->select(attrs, cond, opVec, attrId, gName, vec);
    }

    void descTB(string name) {
        if (tbMap.count(name) == 0) {
            printf("ERROR 1051 (42S02): Unknown table '%s'\n", name.c_str());
            return;
        }
        Table* tb = getTable(name);
        tb->desc();
    }

    void deleteTB(string name, CondSql cond) {
        if (tbMap.count(name) == 0) {
            printf("ERROR 1051 (42S02): Unknown table '%s'\n", name.c_str());
            return;
        }
        Table* tb = getTable(name);
        tb->deleteItems(cond);
    }

    void update(string name, vector<CondItem> set, CondSql cond) {
        if (tbMap.count(name) == 0) {
            printf("ERROR 1051 (42S02): Unknown table '%s'\n", name.c_str());
            return;
        }
        Table* tb = getTable(name);
        tb->update(set, cond);
    }
};

#endif