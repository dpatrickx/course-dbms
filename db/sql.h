#ifndef SQL_H
#define SQL_H

#include "attr.h"
#include "para.h"
#include "table.h"

class Receiver {
public:
	string sentence;
	if (it is a CreateSql) {
		CreateSql sql(sentence);
	}
	Receiver(string c) : sentence(c) {}
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

	CreateSql(string sen) {
		// get attr
		work();
	}
};
#endif