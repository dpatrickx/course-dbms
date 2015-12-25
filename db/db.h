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
    PriQueue<string> tbName;
    map<string, table*> tbMap;

    DB() {}

    void createTb(TableCon c, string n) {
        if (tbMap.count(n)) {
            printf("ERROR 1050 (42S01): Table '%s' already exists\n", n);
            return;
        }
        Table table(c, n);
        tbName.insert(n);
        tbMap.insert(map<string, table*>::value_type(n, &table));
    }

    void dropTable(string n) {}


};

#endif