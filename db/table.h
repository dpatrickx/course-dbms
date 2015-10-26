#ifndef TABLE_H
#define TABLE_H

#include "../utils/MyHashMap.h"
#include "../utils/MyBitMap.h"
#include "../fileio/FileManager.h"
#include "../fileio/BufPageManager.h"
using namespace std;

class Table {
private:
	int _fileID;
	int _pageID;
public:
	int insert(int fileID, int pageID, dict content) {
		// find a empty slot in bit map
		// 
		// 
	}

	int remove(int fileID, int pageID, dict content) {
		// select item by rid
		// remove and mark 0 in bit map
	}

	int update(int fileID, int pageID, dict content) {

	}

	dict select(int fileID, int pageID, dict content) {

	}

	ItemManager() {
	}
};

#endif