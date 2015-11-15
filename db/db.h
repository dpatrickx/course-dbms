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


	void addTable(Table* t) {
		TableNode* temp = TableNode(t);
		if (tableHead == NULL)
			tableHead = tableTail = temp;
		else {
			tableTail->next = temp;
			tableTail = temp;
		}
	}

	void display() {
		cout<<name<<endl;
		TableNode* temp = tableHead;
		while (1) {
			if (temp != NULL)
				cout<<temp->table->name<<endl;
			if (temp == tableTail)
				break;
			temp = temp->next;
		}
	}

	DB(string n) {
		name = n;
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