#ifndef TABLE_H
#define TABLE_H

#include "../bufmanager/BufPageManager.h"
#include "attr.h"
#include <iostream>
#include <vector>
using namespace std;

// one table stored in one file
// the first page:
//      4 Bytes: a unsigned int - number of pages
//      n Bits: each bit reflect a page, 0-have space, 1-no space
// each page(8192 Bytes):
//      n*length data slot
//      last n/8 Bytes - bit map for each data slot

class Table {
private:
    int _fileID;
    int length;     // length of item
    int slotNum;    // number of data slot
    int bitSize;    // number of bitmap bytes in the end of page
    uint pageNum;   // first 4 bytes of first page of the file
    BufPageManager* bpm;

    int _writeItem(int pageID, int rID, Attr attribute) {
        int index;
        BufType b = bpm->getPage(_fileID, pageID, index);
        bpm->markDirty(index);
        int pos = rID*length; // posth byte of the page
        attribute.writeAttr(b, pos);
    }
public:
    string name;
    vector<Attr> attrs;

    int _writeItem(int pageID, int rID, Attr attribute) {
        int index;
        BufType b = bpm->getPage(_fileID, pageID, index);
        bpm->markDirty(index);
        int pos = rID*length; // posth byte of the page
        attribute.writeAttr(b, pos);
    }

    Table(Attr a, int file, BufPageManager* b, string n) {
        name = n;
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
        b[1] = 0;   // 32 pages
        bpm->markDirty(index);
    }

    int writeItem(Attr attribute) {
        // get the first page -- page0
        int index;
        BufType b = bpm->getPage(_fileID, 0, index, false);
        bpm->access(index);
        // find a available page on the first page's bitmap
        // allocate 32 pages at each time, so the pageNum must be 32n
        int num = pageNum/32;
        int emptyPage = 1;
        // emptyPageTH page is available
        for (int i = 1; i <= num; i++) {
            int temp = b[i];
            if (temp == -1) {
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
        bpm->markDirty(index);
        int emptyRid = 0;
        int add = length*slotNum;
        for (int i = 0; i < bitSize; i++) {
            int temp = b[i+add];
            if (b == -1) {
                empthRid += 32;
                continue;
            }
            for (int j = 31; j >= 0; j--) {
                if (!(temp>>j & 1)) {
                    empthRid += (31-j);
                    // put the empty slot bit to be 1
                    b[i+add] |= (1<<j);
                    // check if the page is full
                    if (temp==-1 && i==bitSize-1) {
                        // this page is full, put bit on first page to 1
                        BufType c = bpm->getPage(_fileID, 0, index, false);
                        bpm->access(index);
                        int pagePos = emptyPage/32;
                        pagePos++;
                        int tempt = emptyPage%32;
                        c[pagePos] |= (1<<(31-tempt));
                    }
                    goto writeFlag2;
                }
            }
        }
    writeFlag2:
        // writeItem
        _writeItem(emptyPage, emptyRid, attribute);
        // update the bit map
        return 1;
    }

    int removeItem(int pageID, int rID) {
        // only put the slot bit to be 0
        int index;
        BufType b = bpm->getPage(_fileID, pageID, index, false);
        bpm->markDirty(index);

        int pos = slotNum*length;
        pos += (rID/32);
        int temp = b[pos];
        pos %= 32;
        temp &= (~(1<<(31-pos)));
    }

    int updateItem(int pageID, int rID, Attr attribute) {
        // the slot must be written before, only need to rewrite the item
        _writeItem(pageID, rID, attribute);
    }

    BufType getItem(int pageID, int rID) {
        int index;
        BufType b = bpm->getPage(_fileID, i, index, false);
        bpm->access(index);
        return b+(length*rID);
    }

    void display() {
        cout<<name<<endl;
    }
};

#endif