#ifndef SQL_H
#define SQL_H

#include "attr.h"
#include "para.h"
#include "table.h"
#include "../fileio/FileManager.h"

class Receiver {
public:
	FileManager* fm;
	string sentence;
	if (it is a CreateSql) {
		fm->createFile
		CreateSql sql(sentence);
	}
	Receiver(string c, FileManager* fm) : sentence(c), fm(fm) {}
};

virtual class Sql{
public:
	virtual void work() {}
};

class CreateSql : Sql {
public:
	void work() {
		Table table();
	}

	CreateSql(string sen, int file) {
		// get attr
		work();
	}
};
#endif