#ifndef TABLE_H
#define TABLE_H

#include "../fileio/FileManager.h"
#include "sql.h"
using namespace std;

class Table {
private:
	int _fileID;	// one table - one file
	int _pageID;
	int length;		// length of item
	Attr attr;
public:
	Table() {}
	Table(Attr a) {
		attr = a;
		
	}
};

#endif