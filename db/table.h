#ifndef TABLE_H
#define TABLE_H

#include "../bufmanager/BufPageManager.h"
#include "type.h"
#include <vector>
using namespace std;

// one table stored in one file
// the first page:
//		4 Bytes: a unsigned int - number of pages
//		n Bits: each bit reflect a page, 0-have space, 1-no space
// each page(8192 Bytes):
//		n*length data slot
//		last n/8 Bytes - bit map for each data slot

class Table {
private:
	int _fileID;
	int length;		// length of item
	int slotNum;	// number of data slot
	int bitSize;	// number of bitmap bytes in the end of page
	uint pageNum;	// first 4 bytes of first page of the file
	Attr attr;		// attributes
	BufPageManager* bpm;

	int _writeItem(int pageID, int rID, Vector<Type> vec) {
		int index;
		BufType b = bpm->getPage(_fileID, pageID, index);
		bpm->markDirty(index);
		int pos = 0;
		for (int i = 0;i < vec.size(); i++)
			vec[i].write(b, pos);
	}
public:
	Table(Attr a, int file, BufPageManager* b) {
		attr = a;
		bpm = b;
		// a data slot's length
		length = a.length;
		_fileID = file;
		// slotNum - number of slot
		// bitNum - number of bitmap bits; bitSize - number of bitmap bytes
		slotNum = 8192/length;
		int bitNum = (8192-initNum*length)*8;
		if (bitNum < slotNum) {
			int delta = (slotNum-bitNum)/(8*length)+1;
			slotNum -= delta;
			bitNum += delta*8;
		}
		bitSize = bitNum/8;

		// init first page
		int index;
		pageNum = 10;
		for (int i = 9;i >= 0;i--)
			BufType b = bpm->allocPage(_fileID, i, index, false);
		b[0] = 10;
		b[1] = 0;
		bpm->markDirty(index);
	}

	int writeItem() {
		
		// find a available page on the first page's bitmap
		// find a available slot on the page's bitmap
		// writeItem
		// update the bit map
		return 1;
	}

	int removeItem() {

	}

	int updateItem() {

	}

	int getItem() {

	}
};

#endif