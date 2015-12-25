// database class
// author: dpatrickx

#ifndef DB_H
#define DB_H

#include "table.h"
#include "sql.h"
#include "../utils/PriQueue.h"
#include "map.h"

class DB {
private:
    table* getTable(string name) {
        return tbMap[name];
    }
public:
    string name;
    PriQueue<string> tbName;
    map<string, table*> tbMap;

    DB() {}

    DB(string n) {
        name = n;
    }

    void dropTb(string name) {
        if (tbMap.count(name) == 0) {
            printf("ERROR 1051 (42S02): Unknown table '%s'\n", name);
            return;
        }
        tbName.remove(name);
        tbMap.remove(name);
    }

    void createTB(TableCon c, string n) {
        if (tbMap.count(n)) {
            printf("ERROR 1050 (42S01): Table '%s' already exists\n", n);
            return;
        }
        Table table(c, n);
        tbName.insert(n);
        tbMap.insert(map<string, table*>::value_type(n, &table));
    }

    void showTBs() {
        cout<<"+--------------------+\n";
        cout<<"tables in "<<name<<endl;
        cout<<"+--------------------+\n";
        for (int i = 0; i < tbName.size(); i++)
            cout<<tbName[i]<<endl;
        cout<<"+--------------------+\n";
    }

    void insertTB(string name, vector<string> items, vector<vector<string> > values) {
        if (tbMap.count(name) == 0) {
            printf("ERROR 1051 (42S02): Unknown table '%s'\n", name);
            return;
        }
        table* tb = getTable(name);
        tb->insert(items, values);
    }

    void selectTB(vector<AttrItem> attrs, string name, JoinSql join, CondSql cond) {
        if (tbMap.count(name) == 0) {
            printf("ERROR 1051 (42S02): Unknown table '%s'\n", name);
            return;
        }
        table* tb = getTable(name);
        tb->select(attrs, join, cond);
    }

    void deleteTB(string name, CondSql cond) {
        if (tbMap.count(name) == 0) {
            printf("ERROR 1051 (42S02): Unknown table '%s'\n", name);
            return;
        }
        table* tb = getTable(name);
        tb->deleteItems(cond);
    }

    void update(string name, vector<CondItem> set, CondSql cond) {
        if (tbMap.count(name) == 0) {
            printf("ERROR 1051 (42S02): Unknown table '%s'\n", name);
            return;
        }
        table* tb = getTable(name);
        tb->update(set, cond);
    }
};

#endif