#ifndef TABLE_H
#define TABLE_H

#include "../bufmanager/BufPageManager.h"
#include "attr.h"
#include <iostream>
#include <vector>
using namespace std;

enum {REMOVE, UPDATE, SHOW}

// one table stored in one file
// the first page:
//      4 Bytes: a unsigned int - number of pages
//      n Bits: each bit reflect a page, 0-have space, 1-no space
// each page(8192 Bytes):
//      n*length data slot
//      last n/8 Bytes - bit map for each data slot

class TableCon{
public:
    vector<string> name;
    vector<string> type;
    vector<string> length;
    vector<bool>   notNull;
    string priKey;

    TableCon() {}

    void init(vector<string> n, vector<string> t, string p) {
        name = n;
        type = t;
        priKey = p;
    }

    void display() {
        cout<<"attr size is "<<name.size()<<endl;
        for (int i = 0; i < name.size(); i++) {
            cout<<i<<" :";
            cout<<name[i]<<' '<<type[i]<<' '<<notNull[i]<<endl;
        }
        cout<<"primary key is "<<priKey<<endl;
    }
};

class Table {
private:
    int _fileID;
    int length;     // length of item / byte
    int slotNum;    // number of data slot
    int bitSize;    // number of bitmap bits in the end of page
    int typeNum;
    uint pageNum;   // first 4 bytes of first page of the file
    BufPageManager* bpm;
    FileManager* fm;
    Attr example;
    map<string, int> offset;

    int _writeItem(int pageID, int rID, Attr attribute) {
        int index;
        BufType b = bpm->getPage(_fileID, pageID, index);
        bpm->markDirty(index);
        int pos = rID*length; // posth byte of the page
        attribute.writeAttr(b, pos);
    }
public:
    string name;
    //vector<Attr> attrs;

    int _writeItem(int pageID, int rID, Attr attribute) {
        int index;
        BufType b = bpm->getPage(_fileID, pageID, index);
        bpm->markDirty(index);
        int pos = rID*length; // posth byte of the page
        attribute.writeAttr(b, pos);
    }

    Table(TableCon c, string n) {
        // set name
        name = n;
        // set _fileid
        fm = new FileManager();
        fm->createFile((n+".txt").c_str());
        fm->openFile((n+".txt").c_str(), _fileID);
        // set bmp
        bpm = new BufPageManager(fm);
        // set example, offset
        Attr ex;
        ex.tableName = n;
        int len = 0;
        for (int i = 0; i < c.name.size(); i++) {
            string tempType = c.type[i];
            offset.insert(pair<string, int>(c.name[i], len));
            if (tempType == "int") {
                len += 4;
                Integer type(4, c.notNull[i], c.length[i]);
                ex.attributes.insert(pair<string, Type>(c.name[i], type));
            } else if (tempType == "varchar") {
                int tempLen = atoi(c.length[i].c_str());
                len += tempLen;
                Varchar type(tempLen, c.notNull[i]);
                ex.attributes.insert(pair<string, Type>(c.name[i], type));
            } else if (tempType == "bool") {
                len += 1;
                Bool type(1, c.notNull[i]);
                ex.attributes.insert(pair<string, Type>(c.name[i], type));
            }
        }
        ex.length = len;
        example = ex;
        // set typeNum
        typeNum = c.name.size();
        // set length
        length = ex.len;
        length += (c.name.size()/8+1);
        // set slotNum, bitSize
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
        BufType b = bpm->getPage(_fileID, 0, index);
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
        BufType b = bpm->getPage(_fileID, emptyPage, index);
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
                        BufType c = bpm->getPage(_fileID, 0, index);
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
        attribute.pageID = emptyPage;
        attribute.rID = emptyRid;
        _writeItem(emptyPage, emptyRid, attribute);
        //attrs.push_back(attribute);
        // update the bit map
        return 1;
    }

    int removeItem(int pageID, int rID) {
        // only put the slot bit to be 0
        int index;
        BufType b = bpm->getPage(_fileID, pageID, index);
        bpm->markDirty(index);

        int pos = slotNum*length;
        pos += (rID/32);
        int temp = b[pos];
        pos %= 32;
        temp &= (~(1<<(31-pos)));
        //bitmap

        // vector<Attr>::iterator it;
        // for(it = attrs.begin(); it != attrs.end(); it++){
        //     if(it->pageID == pageID && it->rID == rID){
        //         it->remove();
        //     }
        // }
    }

    int searchItem(string name, char* equal) {
        for(int i = 0; i < 32; i++){
            int index;
            BufType b = bpm->getPage(_fileID, i, index);
            for(int j = 0; j < slotNum; j++){
                char* bb = (char*)b + j*length;
                bb += offset[name];
                int len = example.getAttr(name).length;
                int type = example.getAttr(name).getType();
                if(type == INT){
                    uint* bbb = (uint*)bb;
                    if((*bbb) == (*(int*)equal)){

                    }
                }
                else if(type == CHAR){

                }
                else if(type == NUL){

                }
            }
        }
    }

    int updateItem(int pageID, int rID, Attr attribute) {
        // the slot must be written before, only need to rewrite the item
        _writeItem(pageID, rID, attribute);
    }

    BufType getItem(int pageID, int rID) {
        int index;
        BufType b = bpm->getPage(_fileID, pageID, index);
        bpm->access(index);
        return b+(length*rID);
    }

    void display() {
        cout<<name<<endl;
    }
};

#endif