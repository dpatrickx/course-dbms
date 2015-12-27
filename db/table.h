#ifndef TABLE_H
#define TABLE_H

#include "../bufmanager/BufPageManager.h"
#include "attr.h"
#include "para.h"
#include "auxSql.h"
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

// one table stored in one file
// the first page:
//      4 Bytes: a unsigned int - number of pages
//      n Bits: each bit reflect a page, 0-have space, 1-no space
// each page(8192 Bytes):
//      n*length data slot
//      4 byte: num of free slot bb[slotNum*length]
//      last n/8 Bytes - bit map for each data slot
// each item(length bytes):
//      null bitmap - 0: null, 1: not null

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
    map<string, int> offset;
    string priKey;

    // 1. write every Type
    // 2. write NullBitMap
    int _writeItem(int pageID, int rID, Attr attr) {
        int index;
        BufType b = bpm->getPage(_fileID, pageID, index);
        char* bb = (char*)b;
        bpm->markDirty(index);
        int pos = rID*length; // posth byte of the page
        // attr.writeAttr(b, pos);

        map<string, Type>::iterator s_it;
        for(s_it = attr.attributes.begin(); s_it != attr.attributes.end(); s_it++){
            s_it->second.write(b, pos+offset[s_it->first]);
        }
        // after write, pos is at the end of all values/ head of bitmap
        // change the null-bitmap according to notNull[]
        int rank = nullPos;
        int num = 0;
        for (s_it = attr.attributes.begin(); s_it != attr.attributes.end(); s_it++) {
            if (s_it->second.notNull)
                bb[pos+rank] |= (1<<(7-num));
            else
                bb[pos+rank] &= ~(1<<(7-num));
            num++;
            if (num == 8) {
                rank++;
                num = 0;
            }
        }
    }
public:
    string tbName;
    string path;    // path/name.txt
    Attr example;
    int nullPos;     // offset of null bitmap in each item
    int freeNumPos;  // freeMapPos - 4
    int freeMapPos;  // offset of free bitmap in each page

    Table(const TableCon& c, string n, string root) {
        // set priKey
        priKey = c.priKey;
        // set name
        path = root;
        tbName = n;
        // set _fileid
        fm = new FileManager();
        fm->createFile((root+"/"+n+".txt").c_str());
        fm->openFile((root+"/"+n+".txt").c_str(), _fileID);
        // set bmp
        bpm = new BufPageManager(fm);
        // set example, offset
        Attr ex;
        ex.tableName = n;
        int len = 0;
        for (int i = 0; i < c.name.size(); i++) {
            string tempType = c.type[i];
            if (tempType == "int")
                len += 4;
            else if (tempType == "varchar") {
                int tempLen = atoi(c.length[i].c_str());
                len += tempLen;
            } else if (tempType == "bool") {
                len += 1;
            }
        }
        ex.length = len;
        // set length, nullPos
        length = len;
        nullPos = len;
        length += (c.name.size()/8+1);
        for (int i = c.name.size()-1; i >= 0; i--) {
            string tempType = c.type[i];
            if (tempType == "int") {
                len -= 4;
                Integer type(4, c.notNull[i], c.length[i]);
                ex.attributes.insert(pair<string, Integer>(c.name[i], type));
            } else if (tempType == "varchar") {
                int tempLen = atoi(c.length[i].c_str());
                len -= tempLen;
                Varchar type("xuhan", tempLen, c.notNull[i]);
                ex.attributes.insert(pair<string, Varchar>(c.name[i], type));
            } else if (tempType == "bool") {
                len -= 1;
                Bool type(1, c.notNull[i]);
                ex.attributes.insert(pair<string, Type>(c.name[i], type));
            }
            offset.insert(pair<string, int>(c.name[i], len));
        }
        example = ex;
        // set typeNum
        typeNum = c.name.size();
        // set slotNum, bitSize, position
        slotNum = 8188/length;
        int bitNum = (8188-slotNum*length)*8;
        if (bitNum < slotNum) {
            int delta = (slotNum-bitNum)/(8*length+1)+1;
            slotNum -= delta;
            bitNum += delta*8*length;
        }
        bitSize = bitNum/8;
        freeNumPos = slotNum*length;
        freeMapPos = freeNumPos + 4;
        // init first page
        int index;
        pageNum = 32;
        BufType b;
        for (int i = 32;i >= 0;i--) {
            b = bpm->allocPage(_fileID, i, index, false);
            // set array b to 0, b[2048]
            memset(b, 0, 2048*sizeof(uint));
            char* bb = (char*)b;
            int* bbb = (int*) (bb+freeNumPos);
            bbb[0] = slotNum;
        }
        b[0] = 32;
        b[1] = 0;   // 32 pages
        bpm->markDirty(index);
    }

    // describe talbe
    void desc() {
        cout<<"+-------------+-------------+------+-----+\n";
        cout<<"| Field       | Type        | Null | Key |\n";
        cout<<"+-------------+-------------+------+-----+\n";
        map<string, Type>::iterator it;
        for (it = example.attributes.begin(); it != example.attributes.end(); it++) {
            cout<<"| "<<it->first<<" | ";
            switch((it->second).getType()) {
                case INTE:
                    cout<<"INT("<<(it->second).number<<") |";
                    break;
                case STRING:
                    cout<<"VARCHAR("<<(it->second).length<<") |";
                    break;
                default: break;
            }
            if ((it->second).notNull)
                cout<<" NO  |";
            else
                cout<<" YES |";
            if (priKey == (it->first))
                cout<<" PRI |\n";
            else
                cout<<"     |\n";
        }
        cout<<"+-------------+-------------+------+-----+\n";
    }

    void showTB(int pageID){
        int index;
        BufType b = bpm->getPage(_fileID, pageID, index);
        char* bb = (char*)b;
        for (int i = 0; i < 40; i++) {
            for (int j = 7; j>= 0; j--)
                cout<<((bb[i]>>j)&1)<<'-';
            cout<<endl;
        }
        cout << endl;
    }

    // write Item:
    // 1. find an available page
    // 2. find an available slot, set pageBitMap to 1, check if page is full
    // 3. _writeItem
    int writeItem(Attr attribute) {
        // get the first page -- page0
        map<string, Type>::iterator s_it;
        int index;
        BufType b = bpm->getPage(_fileID, 0, index);
        char* bb = (char*)(b+1);
        bpm->access(index);
        // find a available page on the first page's bitmap
        // allocate 32 pages at each time, so the pageNum must be 32n
        int num = -1;
        int oldNum = 0;
        int emptyPage = 1;
        // emptyPageTH page is available
        for (int i = 0; i < pageNum; i++) {
            if (i%8 == 0)
                num++;
            char temp = bb[num];
            int tempInt = (int)temp;
            if (tempInt == -1) {
                i += 7;
                continue;
            }
            if (((temp>>(7-(i%8)))&1) == 0) {
                emptyPage = i+1;
                break;
            }

        }
        // find a available slot on the page's bitmap
        b = bpm->getPage(_fileID, emptyPage, index);
        bpm->markDirty(index);
        bb = (char*) b;
        // get number of free slots
        int* tempB = (int*) (bb+freeNumPos);
        int freeNum = tempB[0];
        cout<<"freeNum = "<<freeNum<<endl;
        int emptyRid = 0;
        num = -1;
        for (int i = 0; i < slotNum; i++) {
            if (i%8 == 0)
                num++;
            char temp = bb[num+freeMapPos];
            int tempInt = (int)temp;
            if (tempInt == -1) {
                i += 7;
                continue;
            }
            if (((temp>>(7-(i%8)))&1) == 0) {
                emptyRid = i;
                // put the empty slot bit to be 1
                bb[num+freeMapPos] |= (1<<(7-(i%8)));
                freeNum--;
                tempB[0] = freeNum;
                // check if the page is full
                if (freeNum == 0) {
                    BufType c = bpm->getPage(_fileID, 0, index);
                    char* cc = (char*)(c+1);
                    bpm->markDirty(index);
                    emptyPage--;
                    int pagePos = emptyPage/8;
                    int tempt = emptyPage%8;
                    cc[pagePos] |= (1<<(7-tempt));
                }
                break;
            }
        }
        cout<<"emptyPage = "<<emptyPage<<endl;
        cout<<"emptyRid = "<<emptyRid<<endl;
        // writeItem
        _writeItem(emptyPage, emptyRid, attribute);
        return 1;
    }

    // remove Item:
    // 1. put pageBitMap to 0
    int removeItem(int pageID, int rID) {
        // only put the slot bit to be 0
        int index;
        BufType b = bpm->getPage(_fileID, pageID, index);
        bpm->markDirty(index);

        int pos = slotNum*length;
        pos += (rID/32);
        pos %= 32;
        b[pos] &= (~(1<<(31-pos)));
    }

    // update Item:
    // 1. _writeItem
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
        cout<<tbName<<endl;
    }

    void insert(vector<string> items, vector<vector<string> > value){
        if(items.size() == 0){
            for(int i = 0; i < value.size(); i++){
                Attr* writeItems = new Attr();
                map<string, int>::iterator it = offset.begin();
                for(int j = 0; j < value[i].size(); j++){
                    string itemName = it->first;
                    Type* exam = new Type();
                    exam = example.getAttr(itemName);
                    int type = exam->getType();
                    if(type == INTE){
                        int val = atoi(value[i][j].c_str());
                        ((Integer*)exam)->value = val;
                        writeItems->addAttr(*exam, itemName);
                    }
                    else if(type == STRING){
                        string val = value[i][j];
                        ((Varchar*)exam)->str = val;
                        writeItems->addAttr(*exam, itemName);
                    }
                    it++;
                }
                writeItem(*writeItems);
            }
        }
        else{
            for(int i = 0; i < value.size(); i++){
                Attr* writeItems = new Attr();
                for(map<string, int>::iterator it = offset.begin(); it != offset.end(); it++){
                    string itemName = it->first;
                    bool exist = 0;
                    for(int j = 0; j < items.size(); j++){
                        if(items[j] == itemName){
                            Type* exam = new Type();
                            exam = example.getAttr(itemName);
                            int type = exam->getType();
                            if(type == INTE){
                                int val = atoi(value[i][j].c_str());
                                ((Integer*)exam)->value = val;
                                writeItems->addAttr(*exam, itemName);
                            }
                            else if(type == STRING){
                                string val = value[i][j];
                                ((Varchar*)exam)->str = val;
                                writeItems->addAttr(*exam, itemName);
                            }
                            exist = 1;
                            break;
                        }
                    }
                    if(!exist){
                        Type* null = new Null();
                        writeItems->addAttr(*null, itemName);
                    }
                }
                writeItem(*writeItems);
            }
        }
    }

    void select(vector<AttrItem> attrs/*, JoinSql join*/, CondSql cond){
        for(int i = 0; i < pageNum; i++){
            int index;
            BufType bt = bpm->getPage(_fileID, i, index);
            char* bbt = (char*) bt;
            int j = 0;
            for(j = 0; j < slotNum; j++){
                int pos = freeMapPos;
                pos += (j/8);
                int temp = j%8;
                if (((bbt[pos]>>temp)&1)){
                    if(conform(cond, i, j)){
                        int index;
                        BufType b = bpm->getPage(_fileID, i, index);
                        char* bb = (char*)b;
                        bb += j*length;
                        for(int k = 0; k < attrs.size(); k++){
                            Type* temp = new Type();
                            temp = example.getAttr(attrs[k].attrName);
                            int off = offset[attrs[k].attrName];
                            int type = temp->getType();
                            if(type == INTE){
                                cout << "select " << attrs[k].attrName << ": " << *((uint*)(bb+off)) << endl;
                            }
                            else if(type == STRING){
                                int len = temp->length;
                                char c[len];
                                strncpy(c, bb+off, len);
                                cout << "select " << attrs[k].attrName << ": " << c << endl;
                            }
                        }
                    }
                }
            }
        }
    }

    void deleteItems(CondSql cond){
        for(int i = 0; i < pageNum; i++){
            for(int j = 0; j < slotNum; j++){
                if(conform(cond, i, j)){
                    int index;
                    BufType b = bpm->getPage(_fileID, i, index);
                    bpm->markDirty(index);
                    removeItem(i, j);
                }
            }
        }
    }

    void update(vector<CondItem> set, CondSql cond) {
        for(int i = 0; i < pageNum; i++){
            for(int j = 0; j < slotNum; j++){
                if(conform(cond, i, j)){
                    Attr* waitUpdate = new Attr();
                    int index;
                    BufType b = bpm->getPage(_fileID, i, index);
                    bpm->markDirty(index);
                    char* bb = (char*)b + j*length;
                    for(map<string, int>::iterator it = offset.begin(); it != offset.end(); it++){
                        string itemName = it->first;
                        Type* temp = new Type();
                        temp = example.getAttr(itemName);
                        int type = temp->getType();
                        if(type == INTE){
                            int val = *((uint*)(bb + offset[itemName]));
                            ((Integer*)temp)->value = val;
                            waitUpdate->addAttr(*temp, itemName);
                        }
                        else if(type == STRING){
                            char v[100];
                            strncpy(v, bb + offset[itemName], temp->length);
                            string val(v);
                            ((Varchar*)temp)->str = val;
                            waitUpdate->addAttr(*temp, itemName);
                        }
                    }
                    for(int k = 0; k < set.size(); k++){
                        Type* temp = new Type();
                        temp = example.getAttr(set[k].attr1.attrName);
                        int type = temp->getType();
                        if(set[k].attr2.isNull()){
                            if(type == INTE){
                                ((Integer*)temp)->value = set[k].expression.value;
                            }
                            else if(type == STRING){
                                ((Varchar*)temp)->str = set[k].expression.str;
                            }
                        }
                        else if(set[k].expression.isNull()){
                            if(type == INTE){
                                ((Integer*)temp)->value = ((Integer*)(waitUpdate->getAttr(set[k].attr2.attrName)))->value;
                            }
                            else if(type == STRING){
                                ((Varchar*)temp)->str = ((Varchar*)(waitUpdate->getAttr(set[k].attr2.attrName)))->str;
                            }
                        }
                        else{
                            int a2 = ((Integer*)waitUpdate->getAttr(set[k].attr2.attrName))->value;
                            if(set[k].expression.ops[0] == "+"){
                                a2 += atoi(set[k].expression.numbers[0].c_str());
                            }
                            else if(set[k].expression.ops[0] == "-"){
                                a2 -= atoi(set[k].expression.numbers[0].c_str());
                            }
                            else if(set[k].expression.ops[0] == "*"){
                                a2 *= atoi(set[k].expression.numbers[0].c_str());
                            }
                            else if(set[k].expression.ops[0] == "/"){
                                a2 /= atoi(set[k].expression.numbers[0].c_str());
                            }
                            ((Integer*)temp)->value = a2;
                        }
                        waitUpdate->attributes[set[k].attr1.attrName] = *temp;
                    }
                    updateItem(i, j, *waitUpdate);
                }
            }
        }
    }

    bool conform(CondSql cond, int pageID, int rID){ // build a attr according to pageID & rID
        if(cond.conditions.size() == 0)
            return 1;
        Attr* test = new Attr();
        int index;
        BufType b = bpm->getPage(_fileID, pageID, index);
        bpm->access(index);
        char* bb = (char*)b + rID*length;
        for(map<string, int>::iterator it = offset.begin(); it != offset.end(); it++){
            string itemName = it->first;
            Type* temp = new Type();
            temp = example.getAttr(itemName);
            int type = temp->getType();
            if(type == INTE){
                int val = *((uint*)(bb + offset[itemName]));
                ((Integer*)temp)->value = val;
                test->addAttr(*temp, itemName);
            }
            else if(type == STRING){
                char v[100];
                strncpy(v, bb + offset[itemName], temp->length);
                string val(v);
                ((Varchar*)temp)->str = val;
                test->addAttr(*temp, itemName);
            }
        }
        bool ret = 1;
        for(int i = 0; i < cond.conditions.size(); i++){
            CondItem item = cond.conditions[i];
            if(item.judgeOp == "="){
                int type = test->getAttr(item.attr1.attrName)->getType();
                if(type == INTE){
                    if(item.expression.isNull()){
                        if(((Integer*)test->getAttr(item.attr1.attrName))->value != 
                            ((Integer*)test->getAttr(item.attr2.attrName))->value){
                            ret = 0;
                            //cout << "A" <<endl;
                            break;
                        }
                    }
                    else if(item.attr2.isNull()){
                        if(((Integer*)test->getAttr(item.attr1.attrName))->value != 
                            item.expression.value){
                            ret = 0;
                            //cout << "B" <<endl;
                            break;
                        } 
                    }
                    else{
                        int a2 = ((Integer*)test->getAttr(item.attr2.attrName))->value;
                        if(item.expression.ops[0] == "+"){
                            a2 += atoi(item.expression.numbers[0].c_str());
                        }
                        else if(item.expression.ops[0] == "-"){
                            a2 -= atoi(item.expression.numbers[0].c_str());
                        }
                        else if(item.expression.ops[0] == "*"){
                            a2 *= atoi(item.expression.numbers[0].c_str());
                        }
                        else if(item.expression.ops[0] == "/"){
                            a2 /= atoi(item.expression.numbers[0].c_str());
                        }
                        if(((Integer*)test->getAttr(item.attr1.attrName))->value != 
                            a2){
                            ret = 0;
                            //cout << "C" <<endl;
                            break;
                        } 
                    }
                }
                else if(type == STRING){
                    if(item.expression.isNull()){
                        if(((Varchar*)test->getAttr(item.attr1.attrName))->str != 
                            ((Varchar*)test->getAttr(item.attr2.attrName))->str){
                            ret = 0;
                            //cout << "D" <<endl;
                            break;
                        }
                    }
                    else{
                        string compare = "\'" + ((Varchar*)test->getAttr(item.attr1.attrName))->str + "\'";
                        if(compare != item.expression.str){
                            ret = 0;
                            //cout << "E" <<endl;
                            break;
                        }
                    }
                }
            }
            else{
                int type = test->getAttr(item.attr1.attrName)->getType();
                if(type == INTE){
                    if(item.expression.isNull()){ // attr1 </<=/>/>=attr2
                        if(item.judgeOp == "<"){
                            if(((Integer*)test->getAttr(item.attr1.attrName))->value >= 
                                ((Integer*)test->getAttr(item.attr2.attrName))->value){
                                ret = 0;
                            //cout << "F" <<endl;
                                break;
                            }
                        }
                        else if(item.judgeOp == "<="){
                            if(((Integer*)test->getAttr(item.attr1.attrName))->value > 
                                ((Integer*)test->getAttr(item.attr2.attrName))->value){
                                ret = 0;
                            //cout << "G" <<endl;
                                break;
                            }
                        }
                        else if(item.judgeOp == ">="){
                            if(((Integer*)test->getAttr(item.attr1.attrName))->value < 
                                ((Integer*)test->getAttr(item.attr2.attrName))->value){
                                ret = 0;
                            //cout << "H" <<endl;
                                break;
                            }
                        }
                        else if(item.judgeOp == ">"){
                            if(((Integer*)test->getAttr(item.attr1.attrName))->value <= 
                                ((Integer*)test->getAttr(item.attr2.attrName))->value){
                                ret = 0;
                            //cout << "I" <<endl;
                                break;
                            }
                        }
                    }
                    else if(item.attr2.isNull()){ //attr1 </>/<=/>= expression
                        if(item.judgeOp == "<"){
                            if(((Integer*)test->getAttr(item.attr1.attrName))->value >= 
                                item.expression.value){
                                ret = 0;
                            //cout << "J" <<endl;
                                break;
                            }
                        }
                        else if(item.judgeOp == "<="){
                            if(((Integer*)test->getAttr(item.attr1.attrName))->value > 
                                item.expression.value){
                                ret = 0;
                            //cout << "K" <<endl;
                                break;
                            }
                        }
                        else if(item.judgeOp == ">="){
                            if(((Integer*)test->getAttr(item.attr1.attrName))->value < 
                                item.expression.value){
                                ret = 0;
                            //cout << "L" <<endl;
                                break;
                            }
                        }
                        else if(item.judgeOp == ">"){
                            if(((Integer*)test->getAttr(item.attr1.attrName))->value <= 
                                item.expression.value){
                                ret = 0;
                            //cout << "M" <<endl;
                                break;
                            }
                        }
                    }
                    else{ // attr1 </<=/>/>= attr2 +/-/*// number
                        int a2 = ((Integer*)test->getAttr(item.attr2.attrName))->value;
                        if(item.expression.ops[0] == "+"){
                            a2 += atoi(item.expression.numbers[0].c_str());
                        }
                        else if(item.expression.ops[0] == "-"){
                            a2 -= atoi(item.expression.numbers[0].c_str());
                        }
                        else if(item.expression.ops[0] == "*"){
                            a2 *= atoi(item.expression.numbers[0].c_str());
                        }
                        else if(item.expression.ops[0] == "/"){
                            a2 /= atoi(item.expression.numbers[0].c_str());
                        }
                        if(item.judgeOp == "<"){
                            if(((Integer*)test->getAttr(item.attr1.attrName))->value >=
                                a2){
                                ret = 0;
                            //cout << "N" <<endl;
                                break;
                            }
                        }
                        else if(item.judgeOp == "<="){
                            if(((Integer*)test->getAttr(item.attr1.attrName))->value >
                                a2){
                                ret = 0;
                            //cout << "O" <<endl;
                                break;
                            }
                        }
                        else if(item.judgeOp == ">="){
                            if(((Integer*)test->getAttr(item.attr1.attrName))->value <
                                a2){
                                ret = 0;
                            //cout << "P" <<endl;
                                break;
                            }
                        }
                        else if(item.judgeOp == ">"){
                            if(((Integer*)test->getAttr(item.attr1.attrName))->value <=
                                a2){
                                ret = 0;
                            //cout << "Q" <<endl;
                                break;
                            }
                        }
                    }
                }
                else{ret = 0;cout << "Condition Fault" << endl;}
            }
        }
        return ret;
    }
};

#endif