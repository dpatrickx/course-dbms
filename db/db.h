#ifndef DB_H
#define DB_H

#include "table.h"
#include "map.h"
#include "../utils/PriQueue.h"

class TableNode {
public:
	Table table;
	TableNode* next;
	TableNode(Table t = NULL) {
		next = NULL;
		table = t;
	}
};


class DB {
public:
	PriQueue<string> tableNameQue;
	map<string, Table*> tables;
	string name;

	void addTable(Table* t, string n) {
		databases.insert(map<string, DB*>::value_type(n, t));
		tableNameQue.insert(n);
	}

	void display() {
		map<string, Table*> iter;
		for (iter = tables.begin();iter != tables.end();iter++)
			cout<<iter->first<<endl;
	}

	Table* getTable(string name) {
		return tables[name];
	}

	Table* removeTable(string name) {
		tableNameQue.remove(name);
		tables.remove(name);
	}

	DB(string n) {
		name = n;
	}

};

#endif