#ifndef DB_H
#define DB_H

#include "table.h"

class TableNode {
public:
	Table table;
	TableNode* next;
	TableNode(Table t = NULL) {
		next = NULL;
		table = t;
	}
};

class D {
public:
	TableNode* tableHead;
	TableNode* tableTail;

	void addTable(Table t) {
		tableTail->next = t;
		tableTail = t;
	}

	Db() {
		tableHead = NULL;
	}

	Table getTable(int fileID){
		TableNode* temp = tableHead;
		while(temp != NULL){
			if(temp->table._fileID == fileID){
				return temp;
			}
			temp = temp->next;
		}
		return NULL;
	}

	void setSQL(){}
};

#endif