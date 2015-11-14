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
		int pos = rID*length; // posth byte of the page
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
		// bitNum - number of bitmap bits
		// bitSize - bitNum/8
		slotNum = 8192/length;
		int bitNum = (8192-slotNum*length)*8;
		if (bitNum < slotNum) {
			int delta = (slotNum-bitNum)/(8*length+1)+1;
			slotNum -= delta;
			bitNum += delta*8*length;
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
		// get the first page -- page0
		int index;
		BufType b = bpm->getPage(_fileID, 0, index, false);
		access(index);
		// find a available page on the first page's bitmap
		// allocate 32 pages at each time, so the pageNum must be 32n
		int num = pageNum/32;
		int emptyPage = 1;
		for (int i = 1; i <= num; i++) {
			int temp = b[i];
			if (b == -1) {
				emptyPage += 32;
				continue;
			}
			for (int j = 31; j >= 0; j--) {
				if (!(temp>>j & 1)) {
					emptyPage += (31-j);
					goto writeFlag1;
				}
			}
		}
	writeFlag1:
		// find a available slot on the page's bitmap
		BufType b = bpm->getPage(_fileID, emptyPage, index, true);
		markDirty(index);
		int emptyRid = 0;;
		for (int i = 2048-bitSize; i < bitSize; i++) {
			int temp = b[i];
			if (b == -1) {
				empthRid += 32;
				continue;
			}
			for (int j = 31; j >= 0; j--) {
				if (!(temp>>j & 1)) {
					empthRid += (31-j);
					// put the empty slot bit to be 1
					temp |= (1<<j);
					goto writeFlag2;
				}
			}
		}
	writeFlag2:
		// writeItem
		_writeItem(emptyPage, emptyRid, vec);
		// update the bit map
		return 1;
	}

	int removeItem(int pageID, int rID) {
		// only put the slot bit to be 0
		int index;
		BufType b = bpm->getPage(_fileID, i, index, false);
		markDirty(index);

		int pos = 2048 - bitSize;
		pos += (rID/32);
		int temp = b[pos];
		pos %= 32;
		temp &= (~(1<<(31-pos)));
	}

	int updateItem(int pageID, int rID, Vector<Type> vec) {
		_writeItem(pageID, rID, vec);
		// remember to mark the bit to be 1
	}

	BufType getItem(int pageID, int rID) {
		int index;
		BufType b = bpm->getPage(_fileID, i, index, false);
		access(index);
		return b+(length*rID);
	}
};

#endif