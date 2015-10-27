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
		pageNum = 32;
		for (int i = 31;i >= 0;i--)
			BufType b = bpm->allocPage(_fileID, i, index, false);
		b[0] = 31;
		b[1] = 0;
		bpm->markDirty(index);
	}

	int writeItem(Vector<Type> vec) {
		int index;
		BufType b = bpm->allocPage(_fileID, 0, index, false);
		access(index);
		// find a available page on the first page's bitmap
		// allocate 32 pages at each time, so the pageNum must be 32n
		int num = pageNum/32;
		int empthPage = 1;
		for (int i = 1; i <= num; i++) {
			int temp = b[i];
			if (b == -1) {
				empthPage += 32;
				continue;
			}
			for (int j = 31; j >= 0; j--) {
				if (!(temp>>j & 1)) {
					empthPage += (31-j);
					goto writeFlag1;
				}
			}
		}
	writeFlag1:
		// find a available slot on the page's bitmap
		BufType b = bpm->allocPage(_fileID, empthPage, index, true);
		markDirty(index);
		int empthRid = 0;;
		for (int i = 2048-bitSize; i < bitSize; i++) {
			int temp = b[i];
			if (b == -1) {
				empthRid += 32;
				continue;
			}
			for (int j = 31; j >= 0; j--) {
				if (!(temp>>j & 1)) {
					empthRid += (31-j);
					goto writeFlag2;
				}
			}
		}
	writeFlag1:
		// writeItem
		_writeItem(empthPage, empthRid, vec);
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