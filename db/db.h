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
    string name;
    PriQueue<string> tbName;
    map<string, Table*> tbMap;

    DB() {}

    DB(string n) {
        name = n;
    }

    void dropTB(string name) {
        if (tbMap.count(name) == 0) {
            printf("ERROR 1051 (42S02): Unknown table '%s'\n", name.c_str());
            return;
        }
        Table* tb = getTable(name);
        // tb->drop();
        system(("rm "+name+".txt").c_str());
        tbName.remove(name);
        tbMap.erase(name);
    }

    void createTB(TableCon c, string n) {
        if (tbMap.count(n)) {
            printf("ERROR 1050 (42S01): Table '%s' already exists\n", n.c_str());
            return;
        }
        Table table(c, n);
        tbName.insert(n);
        tbMap.insert(map<string, Table*>::value_type(n, &table));
    }

    void showTBs() {
        cout<<"+--------------------+\n";
        cout<<"tables in "<<name<<endl;
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
        cout<<"insertTB()\n";
        // tb->insert(t, v);
    }

    void selectTB(vector<AttrItem> attrs, vector<string> t, CondSql cond) {
        cout<<"selectTB()\n";
        // tb->select(attrs, t, cond);
    }

    void deleteTB(string name, CondSql cond) {
        if (tbMap.count(name) == 0) {
            printf("ERROR 1051 (42S02): Unknown table '%s'\n", name.c_str());
            return;
        }
        Table* tb = getTable(name);
        cout<<"deleteTB()\n";
        // tb->deleteItems(cond);
    }

    void update(string name, vector<CondItem> set, CondSql cond) {
        if (tbMap.count(name) == 0) {
            printf("ERROR 1051 (42S02): Unknown table '%s'\n", name.c_str());
            return;
        }
        Table* tb = getTable(name);
        cout<<"update()\n";
        // tb->update(set, cond);
    }
};

#endif