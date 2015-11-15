#ifndef PARSE_HPP
#define PARSE_HPP

#include "sql.h"
#include "db.h"
#include "../utils/PriQueue.h"
#include "attr.h"
#include <string>
#include <map>
#include <vector>

inline char convToLowerA(char chConv) {
    return (chConv >= 'A' && chConv <= 'Z')? (chConv | 0x20) : chConv;
}

inline void convStrToLowerA(string& str) {
    for (int i = 0;i <= str.length();i++)
        str[i] = convToLowerA(str[i]);
}

inline int startWith(string a, string tar) {
	return (a.substr(0, tar.length()) == tar);
}


class Parse {
public:
	FileManager* fm;
	string sentence;
	string rootPath;
	DB* currDB;
	PriQueue<string> dbNameQue;
	map<string, DB*> databases;

	Parse(string sen, FileManager* fm) : fm(fm) {
		sentence = convStrToLowerA(sen);
		rootPath = "../data/";
		curDbName = "";
	}

	void work() {
		if (startWith(sentence, "create database ")) {
			string name = sentence.erase(0, 16);
			dbNameQue.insert(name);
			// create dir
			status = mkdir(rootPath+name, S_IRWXU|S_IRWXG|S_IRWXG|S_IXOTH);
			// create DB & add into map
			DB* tempDB = new DB(name);
			databases.insert(map<string, DB*>::value_type(name, tempDB));
		}

		if (startWith(sentence, "use database ")) {
			curDbName = sentence.erase(0, 13);
			currDB = databases[name];
		}

		if (startWith(sentence, "drop database ")) {
			string name = sentence.erase(0, 14);
			dbNameQue.remove(name);
			if (curDbName == name)
				curDbName = "";
			// delete dir and files
			// do not know how to do
		}

		if (startWith(startWith, "show database ")) {
			string name = sentence.erase(0, 14);
			DB* tempDB = databases[name];
			tempDB.display();
		}

		if (startWith(sentence, "create table ")) {
			string sen = sentence.erase(0, 13);
			// create file
			int fileID;
			fm->createFile(rootPath+curDbName+'/'+name);
			fm->openFile(rootPath+curDbName, fileID);
			// pass sentence to a attr class
			Attr attr = new Attr(sen);
			// create table
			Table* t = new Table(attr, fileID, fm, attr.tableName);
			currDB.addTable(t, attr.tableName);
			// create index file
		}

		if (startWith(sentence, "drop table ")) {
			string name = sentence.erase(0, 11);
			Table* table = currDB->getTable(name);
			currDB->removeTable(name);
			// delete data file
			// delete relevent index files
			// remove from DB
			delete table;
		}

		if (startWith(sentence, "show table ")) {
			string name = sentence.erase(0, 11);
			Table* table = currDB->getTable(name);
			table->attr.display();
		}
	}
;
#endif
