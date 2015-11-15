#ifndef SQL_H
#define SQL_H

#include "attr.h"
#include "para.h"
#include "table.h"
#include "../fileio/FileManager.h"

virtual class Sql{
public:
	virtual void work() {}
};

class CreateSql : public Sql {
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