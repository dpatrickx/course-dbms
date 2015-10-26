#ifndef DB_H
#define DB_H

#include "table.h"

class TableNode {
public:
	Table* table;
	Table* next;
	TableNode(Table* t = NULL) {
		next = NULL;
		table = t;
	}
};

class Db {
public:
	TableNode* tableHead;
	TableNode* tableTail;

	void addTable(Table* t) {
		tableTail->next = t;
		tableTail = t;
	}

	Db() {
		tableHead = NULL;
	}
};

#endif