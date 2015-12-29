#ifndef TABLE_H
#define TABLE_H

#include "../bufmanager/BufPageManager.h"
#include "../utils/HashMap.h"
#include "./stx/btree.h"
#include "attr.h"
#include "para.h"
#include "auxSql.h"
#include <iostream>
#include <string.h>
#include <vector>
#include <sstream>
#include <regex>
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
public:
    int _fileID;
    int length;     // length of item / byte
    int slotNum;    // number of data slot
    int bitSize;    // number of bitmap bits in the end of page
    int typeNum;
    uint pageNum;   // first 4 bytes of first page of the file
    int nullPos;     // offset of null bitmap in each item
    int freeNumPos;  // freeMapPos - 4
    int freeMapPos;  // offset of free bitmap in each page

    string tbName;
    string path;    // path/tbName.txt
    string priKey;

    map<string, int> offset;
    vector<string> sequence;
    map<string, vector<string> > check;
    Attr example;

    HashMap hashMap;
    BufPageManager* bpm;
    FileManager* fm;

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
        for (int i = 0; i < sequence.size(); i++) {
            Type* type = attr.getAttr(sequence[i]);
            if (type->type == NUL)
                bb[pos+rank] &= ~(1<<(7-num));
            else
                bb[pos+rank] |= (1<<(7-num));
            num++;
            if (num == 8) {
                rank++;
                num = 0;
            }
        }
    }

    Table() {}

    void init() {
        // hashmap bpm fm
        int off = offset[priKey];
        int index;
        fm = new FileManager();
        fm->openFile((path+"/"+tbName+".txt").c_str(), _fileID);
        bpm = new BufPageManager(fm);
        if (priKey == "")
            return;
        BufType b = bpm->getPage(_fileID, 0, index);
        bpm->access(index);
        int pageNum = b[0];
        for (int i = 1; i <= pageNum; i++) {
            BufType ab = bpm->getPage(_fileID, i, index);
            bpm->access(index);
            char* abb = (char*)(ab);
            int* bbb = (int*) (abb+freeNumPos);
            int freeNum = bbb[0];
            if (freeNum == slotNum)
                continue;
            abb += freeMapPos;
            for (int j = 0; j < slotNum; j++) {
                if (j>0 && j%8==0)
                    abb++;
                int temp = abb[0];
                temp >>= (7-(j%8));
                temp &= 1;
                if (temp == 1) {
                    char* ba = (char*)(ab);
                    ba += j*length;
                    ba += off;
                    uint* zz = (uint*)(ba);
                    uint aa = zz[0];
                    stringstream ss;
                    ss << aa;
                    string a;
                    ss >> a;
                    hashMap.insert(a);
                }
            }
        }
    }

    stx::btree<int, pair<int, int> >* btr;

    Table(const TableCon& c, string n, string root) {
        btr = new stx::btree<int, pair<int, int> >();
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
        //set check
        for(int i = 0; i < c.checkAttrs.size(); i++){
            check.insert(pair<string, vector<string> >(c.checkAttrs[i], c.checkVal[i]));
            cout << "check: " << c.checkAttrs[i] << endl;
        }
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
                len += (tempLen + 1);
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
                len -= (tempLen + 1);
                Varchar type("xuhan", tempLen + 1, c.notNull[i]);
                ex.attributes.insert(pair<string, Varchar>(c.name[i], type));
            } else if (tempType == "bool") {
                len -= 1;
                Bool type(1, c.notNull[i]);
                ex.attributes.insert(pair<string, Type>(c.name[i], type));
            }
            offset.insert(pair<string, int>(c.name[i], len));
            sequence.insert(sequence.begin(), c.name[i]);
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
        char* bb;
        int* bbb;
        for (int i = pageNum;i >= 0;i--) {
            b = bpm->allocPage(_fileID, i, index, false);
            bpm->markDirty(index);
            // set array b to 0, b[2048]
            memset(b, 0, 2048*sizeof(uint));
            bb = (char*)b;
            bbb = (int*) (bb+freeNumPos);
            bbb[0] = slotNum;
        }
        b[0] = pageNum;
        bb = (char*)(b+1);
        int numRank = -1;
        for (int i = 0; i < pageNum; i++) {
            if (i%8 == 0)
                numRank++;
            int tempp = i%8;
            bb[1+numRank] &= (~(1<<(7-tempp)));
        }
        bpm->markDirty(index);
    }

    void saveFile() {
        bpm->close();
        fm->closeFile(_fileID);
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
                    cout<<"VARCHAR("<<(it->second).length - 1<<") |";
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
        bpm->access(index);
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
        int emptyPage = -1;
        // emptyPageTH page is available
        for (int i = 0; i < pageNum; i++) {
            if (i%8 == 0)
                num++;
            char temp = bb[num];
            if (((temp>>(7-(i%8)))&1) == 0) {
                emptyPage = i+1;
                break;
            }
        }
        if (emptyPage == -1) {
            // add pages
            for (int i = 1; i <= pageNum; i++) {
                b = bpm->allocPage(_fileID, pageNum+i, index, false);
                // set array b to 0, b[2048]
                memset(b, 0, 2048*sizeof(uint));
                bb = (char*)b;
                int* bbb = (int*) (bb+freeNumPos);
                bbb[0] = slotNum;
            }
            b = bpm->getPage(_fileID, 0, index);
            bb = (char*)(b+1);
            int numRank = pageNum/8;
            int cha = pageNum%8;
            for (int i = 0; i < pageNum; i++) {
                if ((i+cha)%8 == 0)
                    numRank++;
                int tempp = ((i+cha))%8;
                bb[numRank] &= (~(1<<(7-tempp)));
            }
            // add pages
            emptyPage = pageNum+1;
            pageNum += pageNum;
            b[0] = pageNum;
        }
        // find a available slot on the page's bitmap
        b = bpm->getPage(_fileID, emptyPage, index);
        bpm->markDirty(index);
        bb = (char*) b;
        // get number of free slots
        int* tempB = (int*) (bb+freeNumPos);
        int freeNum = tempB[0];
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
                    int eee = emptyPage - 1;
                    int pagePos = eee/8;
                    int tempt = eee%8;
                    cc[pagePos] |= (1<<(7-tempt));
                }
                break;
            }
        }
        // writeItem
        //bt->insert(attribute.attributes["xuhan"].value, pair<int, int>(emptyPage, emptyRid));
        _writeItem(emptyPage, emptyRid, attribute);
        return 1;
    }

    // remove Item:
    // 1. put pageBitMap to 0
    int removeItem(int pageID, int rID) {
        // only put the slot bit to be 0
        int index;
        BufType b = bpm->getPage(_fileID, pageID, index);
        char* bb = (char*)b;
        bpm->markDirty(index);
        int pos = freeMapPos;
        pos += (rID/8);
        rID %= 8;
        bb[pos] &= (~(1<<(7-rID)));
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

    void insert(vector<string> items, vector<vector<string> > value, vector<Table*> tb){
        if(items.size() == 0){
            for(int i = 0; i < value.size(); i++){//every item
                Attr* writeItems = new Attr();
                //map<string, int>::iterator it = offset.begin();
                bool conti = 1;
                for(int j = 0; j < value[i].size(); j++){//every type
                    //check
                    conti = 1;
                    string itemName = sequence[j];
                    map<string, vector<string> >::iterator c_it;
                    c_it = check.find(itemName);
                    if(c_it == check.end()){
                        conti = 0;
                    }
                    else{
                        for(int ss = 0; ss < c_it->second.size(); ss++){
                            if(value[i][j] == c_it->second[ss]){
                                conti = 0;
                                break;
                            }
                        }
                    }
                    if(conti){
                        cout << "Check error" << endl;
                        break;
                    }
                    //hash
                    if(itemName == priKey){
                        bool res = hashMap.check(value[i][j]);
                        if(!res){
                            hashMap.insert(value[i][j]);
                        }
                        else{
                            conti = 1;
                            cout << "Primary Key Conflict!" << endl;
                            break;
                        }
                    }
                    //restriction

                    int found;
                    if((found = itemName.find("_")) != string::npos){
                        string s = itemName;
                        string delim = "_";
                        vector<string> retu;
                        size_t last = 0;
                        size_t index = s.find_first_of(delim,last);
                        if (index!=std::string::npos)
                        {
                            retu.push_back(s.substr(last,index-last));
                            last=index+1;
                            index=s.find_first_of(delim,last);
                        }
                        if (index-last>0)
                        {
                            retu.push_back(s.substr(last,index-last));
                        }
                        int nn = 0;
                        for(nn = 0; nn < tb.size(); nn++){
                            if(retu[0] == tb[nn]->tbName){
                                break;
                            }
                        }
                        if(nn != tb.size()){
                            if(!tb[nn]->hashMap.check(value[i][j])){
                                conti = 1;
                                break;
                            }
                        }
                    }

                    //write
                    Type* exam = new Type();
                    exam = example.getAttr(itemName);
                    int type = exam->getType();
                    if(type == INTE){
                        bool isnull = 0;
                        for(int k = 0; k < value[i][j].size(); k++){
                            if(value[i][j][k] < '0' || value[i][j][k] > '9'){
                                if(value[i][j] == "null"){
                                    if(exam->notNull){
                                        cout << "INPUT ERROR" << endl;
                                        conti = 1;
                                        break;
                                    }
                                    else{
                                        Type* null = new Null();
                                        writeItems->addAttr(*null, itemName);
                                        isnull = 1;
                                        break;
                                    }
                                }
                                else{
                                    cout << "INPUT ERROR" << endl;
                                    conti = 1;
                                    break;
                                }
                            }
                        }
                        if(conti){
                            break;
                        }
                        if(isnull){
                            continue;
                        }
                        int val = atoi(value[i][j].c_str());
                        ((Integer*)exam)->value = val;
                        writeItems->addAttr(*exam, itemName);
                    }
                    else if(type == STRING){
                        if(value[i][j][0] != '\'' || value[i][j][value[i][j].size()-1] != '\'' || value[i][j] == "null"){
                            if(value[i][j] == "null"){
                                if(exam->notNull){
                                    cout << "INPUT ERROR" << endl;
                                    conti = 1;
                                }
                                else{
                                    Type* null = new Null();
                                    writeItems->addAttr(*null, itemName);
                                    continue;
                                }
                            }
                            else{
                                cout << "INPUT ERROR" << endl;
                                conti = 1;
                            }
                        }
                        if(conti){
                            break;
                        }
                        string val = value[i][j];
                        ((Varchar*)exam)->str = val;
                        writeItems->addAttr(*exam, itemName);
                    }
                    //it++;
                }
                if(conti){
                    continue;
                }
                writeItem(*writeItems);
            }
        }
        else{
            for(int i = 0; i < value.size(); i++){
                Attr* writeItems = new Attr();
                bool conti = 0;
                for(map<string, int>::iterator it = offset.begin(); it != offset.end(); it++){
                    string itemName = it->first;
                    bool exist = 0;
                    for(int j = 0; j < items.size(); j++){
                        if(items[j] == itemName){
                            //check
                            conti = 1;
                            map<string, vector<string> >::iterator c_it;
                            c_it = check.find(itemName);
                            if(c_it == check.end()){
                                conti = 0;
                            }
                            else{
                                for(int ss = 0; ss < c_it->second.size(); ss++){
                                    if(value[i][j] == c_it->second[ss]){
                                        conti = 0;
                                        break;
                                    }
                                }
                            }
                            if(conti){
                                cout << "Check error" << endl;
                                break;
                            }
                            //hash
                            if(itemName == priKey){
                                bool res = hashMap.check(value[i][j]);
                                if(!res){
                                    hashMap.insert(value[i][j]);
                                }
                                else{
                                    conti = 1;
                                    cout << "Primary Key Conflict!" << endl;
                                    break;
                                }
                            }
                            //write
                            Type* exam = new Type();
                            exam = example.getAttr(itemName);
                            int type = exam->getType();
                            if(type == INTE){
                                bool isnull = 0;
                                for(int k = 0; k < value[i][j].size(); k++){
                                    if(value[i][j][k] < '0' || value[i][j][k] > '9'){
                                        if(value[i][j] == "null"){
                                            if(exam->notNull){
                                                cout << "INPUT ERROR" << endl;
                                                conti = 1;
                                                break;
                                            }
                                            else{
                                                Type* null = new Null();
                                                writeItems->addAttr(*null, itemName);
                                                isnull = 1;
                                                break;
                                            }
                                        }
                                        else{
                                            cout << "INPUT ERROR" << endl;
                                            conti = 1;
                                            break;
                                        }
                                    }
                                }
                                if(conti){
                                    break;
                                }
                                if(isnull){
                                    exist = 1;
                                    break;
                                }
                                int val = atoi(value[i][j].c_str());
                                ((Integer*)exam)->value = val;
                                writeItems->addAttr(*exam, itemName);
                            }
                            else if(type == STRING){
                                if(value[i][j][0] != '\'' || value[i][j][value[i][j].size()-1] != '\'' || value[i][j] == "null"){
                                    if(value[i][j] == "null"){
                                        if(exam->notNull){
                                            cout << "INPUT ERROR" << endl;
                                            conti = 1;
                                            break;
                                        }
                                        else{
                                            Type* null = new Null();
                                            writeItems->addAttr(*null, itemName);
                                            break;
                                        }
                                    }
                                    else{
                                        cout << "INPUT ERROR" << endl;
                                        conti = 1;
                                        break;
                                    }
                                }
                                string val = value[i][j];
                                ((Varchar*)exam)->str = val;
                                writeItems->addAttr(*exam, itemName);
                            }
                            exist = 1;
                            break;
                        }
                        if(conti){
                            break;
                        }
                    }
                    if(conti){
                        break;
                    }
                    if(!exist){
                        Type* null = new Null();
                        writeItems->addAttr(*null, itemName);
                    }
                }
                if(conti){
                    continue;
                }
                writeItem(*writeItems);
            }
        }
    }

    void operation(int op, string attrID, CondSql cond, string group){
        if(group == ""){
            int sum = 0;
            int avg = 0;
            int mx = 0;
            int mn = 2147483647;
            int num = 0;
            for(int i = 1; i <= pageNum; i++){
                int index;
                BufType b = bpm->getPage(_fileID, i, index);
                bpm->access(index);
                char* bb = (char*) b;
                int j = 0;
                for(j = 0; j < slotNum; j++){
                    int pos = freeMapPos;
                    pos += (j/8);
                    int temp = j%8; 
                    if (((bb[pos]>>(7-temp))&1)){
                        if(conform(cond, i, j, vector<Table*>())){
                            int temp = *((uint*)(bb + j*length + offset[attrID]));
                            num++;
                            sum += temp;
                            if(temp > mx)
                                mx = temp;
                            if(temp < mn)
                                mn = temp;
                        }
                    }
                }
            }
            avg = sum/num;
            if(op == 1)
                cout << "SUM(" << attrID << "): " << sum << endl;
            else if(op == 2)
                cout << "AVG(" << attrID << "): " << avg << endl;
            else if(op == 3)
                cout << "MAX(" << attrID << "): " << mx << endl;
            else if(op == 4)
                cout << "MIN(" << attrID << "): " << mn << endl;
            else if(op == 5)
                cout << "COUNT(" << attrID << "): " << num << endl;
        }
        else{
            map<string, int> g;
            map<string, int> num;
            Type* t = example.getAttr(group);
            int type = t->getType();
            for(int i = 1; i <= pageNum; i++){
                int index;
                BufType b = bpm->getPage(_fileID, i, index);
                bpm->access(index);
                char* bb = (char*) b;
                int j = 0;
                for(j = 0; j < slotNum; j++){
                    int pos = freeMapPos;
                    pos += (j/8);
                    int temp = j%8; 
                    if (((bb[pos]>>(7-temp))&1)){
                        if(conform(cond, i, j, vector<Table*>())){
                            string tmp;
                            if(type == INTE){
                                stringstream ss;
                                ss<<*((uint*)(bb + j*length + offset[group]));
                                ss>>tmp;
                            }
                            else if(type == STRING){
                                char tp[t->length+10];
                                strncpy(tp, (bb + j*length + offset[group]), t->length);
                                string tpp(tp);
                                tmp = tpp;
                            }
                            map<string, int>::iterator o_it;
                            o_it = g.find(tmp);
                            if(o_it == g.end()){
                                if(op != 4 && op != 2)
                                    g[tmp] = 0;
                                else if(op == 2){
                                    num[tmp] = 0;
                                }
                                else
                                    g[tmp] = 2147483647;
                            }
                            int temp = *((uint*)(bb + j*length + offset[attrID]));
                            if(op == 1)
                                g[tmp] += temp;
                            else if(op == 2){
                                num[tmp]++;
                                g[tmp] += temp;
                            }
                            else if(op == 3){
                                if(temp > g[tmp])
                                    g[tmp] = temp;
                            }
                            else if(op == 4){
                                if(temp < g[tmp])
                                    g[tmp] = temp;
                            }
                        }
                    }
                }
            }
            for(map<string, int>::iterator it = g.begin(); it != g.end(); it++){
                if(op == 1)
                    cout << it->first << ": " << "SUM(" << attrID << "): " << it->second << endl;
                else if(op == 2)
                    cout << it->first << ": " << "AVG(" << attrID << "): " << (it->second/num[it->first]) << endl;
                else if(op == 3)
                    cout << it->first << ": " << "MAX(" << attrID << "): " << it->second << endl;
                else if(op == 4)
                    cout << it->first << ": " << "MIN(" << attrID << "): " << it->second << endl;
                else if(op == 5)
                    cout << it->first << ": " << "COUNT(" << attrID << "): " << num[it->first] << endl;
            }
        }
    }

    map<string, vector<int> > pID;
    map<string, vector<int> > rankID;
    void select(vector<AttrItem> attrs, CondSql cond, vector<string> op, vector<string> attrID, string groupName, vector<Table*> tb){
        if(op.size() != 0){
            cout<<"+------------------------------+\n";
            for(int i = 0; i < op.size(); i++){
                if(op[i] == "sum"){
                    operation(1, attrID[i], cond, groupName);
                }
                else if(op[i] == "max"){
                    operation(3, attrID[i], cond, groupName);
                }
                else if(op[i] == "avg"){
                    operation(2, attrID[i], cond, groupName);
                }
                else if(op[i] == "min"){
                    operation(4, attrID[i], cond, groupName);
                }
                else if(op[i] == "count"){
                    operation(5, attrID[i], cond, groupName);
                }
            }
            return;
        }
        for(int i = 1; i <= pageNum; i++){
            int index;
            BufType bt = bpm->getPage(_fileID, i, index);
            bpm->access(index);
            char* bbt = (char*) bt;
            int j = 0;
            for(j = 0; j < slotNum; j++){
                int pos = freeMapPos;
                pos += (j/8);
                int temp = j%8;
                if (((bbt[pos]>>(7-temp))&1)){
                    pID.erase(pID.begin(),pID.end());
                    rankID.erase(rankID.begin(),rankID.end());
                    if(conform(cond, i, j, tb)){
                        show(attrs, i, j, tb);
                        cout<<"-------------------------\n";
                    }
                }
            }
        }
        // bt->print(cout);
    }

    void show(vector<AttrItem> attrs, int i, int j, vector<Table*> tb){ // i->pageID, j->rID
        int index;
        BufType b = bpm->getPage(_fileID, i, index);
        bpm->access(index);
        char* bb = (char*)b;
        bb += j*length;
        for(int k = 0; k < attrs.size(); k++){ //select * from
            if(attrs[k].attrName == "*"){
                for(int m = 0; m < sequence.size(); m++){
                    Type* temp = new Type();
                    temp = example.getAttr(sequence[m]);
                    int off = offset[sequence[m]];
                    int type = temp->getType();
                    if(type == INTE){
                        if(*((uint*)(bb+off)) != 0)
                            cout << sequence[m] << ": " << *((uint*)(bb+off)) << endl;
                        else{
                            int poss = nullPos;
                            poss += (m/8);
                            int tmp = m%8;
                            if(((bb[poss]>>(7-tmp))&1)){
                                cout << sequence[m] << ": " << 0 << endl;
                            }
                            else{
                                cout << sequence[m] << ": " << "null" << endl;
                            }
                        }
                    }
                    else if(type == STRING){
                        int len = temp->length;
                        char c[len+10];
                        strncpy(c, bb+off, len);
                        if((bb+off)[0] != '\0')
                            cout << sequence[m] << ": " << c << endl;
                        else{
                            int poss = nullPos;
                            poss += (m/8);
                            int tmp = m%8;
                            if(((bb[poss]>>(7-tmp))&1)){
                                cout << sequence[m] << ": " << "" << endl;
                            }
                            else{
                                cout << sequence[m] << ": " << "null" << endl;
                            }
                        }
                    }
                }
                break;
            }
            // not select * from
            if(attrs[k].tableName!="" && attrs[k].tableName!=tbName){
                int nn;
                for(nn = 0; nn < tb.size(); nn++){
                    if(attrs[k].tableName == tb[nn]->tbName){
                        break;
                    }
                }
                AttrItem attrTrans("", attrs[k].attrName);
                vector<AttrItem> attrss;
                attrss.push_back(attrTrans);
                for(int ii = 0; ii < pID[tb[nn]->tbName].size(); ii++){
                    // cout << "*** " << tb[nn]->tbName << " ***" << endl;
                    tb[nn]->show(attrss, pID[tb[nn]->tbName][ii], rankID[tb[nn]->tbName][ii], vector<Table*>());
                }
            }
            else{
                Type* temp = new Type();
                temp = example.getAttr(attrs[k].attrName);
                int off = offset[attrs[k].attrName];
                int type = temp->getType();
                int m;
                cout<<"*** "<<tbName<<" ***\n";
                for(int sk = 0; sk < sequence.size(); sk++){
                    if(attrs[k].attrName == sequence[sk]){
                        m = sk;
                        break;
                    }
                }
                if(type == INTE){
                    if(*((uint*)(bb+off)) != 0)
                        cout << sequence[m] << ": " << *((uint*)(bb+off)) << endl;
                    else{
                        int poss = nullPos;
                        poss += (m/8);
                        int tmp = m%8;
                        if(((bb[poss]>>(7-tmp))&1)){
                            cout << sequence[m] << ": " << 0 << endl;
                        }
                        else{
                            cout << sequence[m] << ": " << "null" << endl;
                        }
                    }
                }
                else if(type == STRING){
                    int len = temp->length;
                    char c[len+10];
                    strncpy(c, bb+off, len);
                    if(strcmp(c, "") != 0)
                        cout << sequence[m] << ": " << c << endl;
                    else{
                        int poss = nullPos;
                        poss += (m/8);
                        int tmp = m%8;
                        if(((bb[poss]>>(7-tmp))&1)){
                            cout << sequence[m] << ": " << "" << endl;
                        }
                        else{
                            cout << sequence[m] << ": " << "null" << endl;
                        }
                    }
                }
            }
        }
    }

    void deleteItems(CondSql cond){
        for(int i = 1; i <= pageNum; i++) {
            int index;
            BufType bt = bpm->getPage(_fileID, i, index);
            bpm->access(index);
            char* bbt = (char*) bt;
            int j = 0;
            for(j = 0; j < slotNum; j++) {
                int pos = freeMapPos;
                pos += (j/8);
                int temp = j%8;
                if (((bbt[pos]>>(7-temp))&1)) {
                    if(conform(cond, i, j, vector<Table*>())){
                        int index;
                        BufType b = bpm->getPage(_fileID, i, index);
                        char* bb = (char*)(b);
                        bb += j*length;
                        bb += offset[priKey];
                        uint* bbb = (uint*)(bb);
                        stringstream ss;
                        int aaa = bbb[0];
                        ss << aaa;
                        string ttt;
                        ss >> ttt;
                        hashMap.remove(ttt);
                        bpm->markDirty(index);
                        removeItem(i, j);
                    }
                }
            }
        }
    }

    bool isCheck(string name, string content){
        map<string, vector<string> >::iterator c_it;
        c_it = check.find(name);
        if(c_it != check.end()){
            for(int ss = 0; ss < c_it->second.size(); ss++){
                if(content == c_it->second[ss]){
                    return 1;
                }
            }
        }
        else{
            return 1;
        }
        return 0;
    }

    void update(vector<CondItem> set, CondSql cond, vector<Table*> tb) {
        for(int k = 0; k < set.size(); k++){
            int found;
            if((found = set[k].attr1.attrName.find("_")) != string::npos){
                string s = set[k].attr1.attrName;
                string delim = "_";
                vector<string> retu;
                size_t last = 0;  
                size_t index = s.find_first_of(delim,last);  
                if (index!=std::string::npos)  
                {  
                    retu.push_back(s.substr(last,index-last));
                    last=index+1;  
                    index=s.find_first_of(delim,last);  
                } 
                else {
                    break;
                } 
                if (index-last>0)  
                {  
                    retu.push_back(s.substr(last,index-last));  
                }
                else {
                    break;
                }
                int nn = 0;
                for(nn = 0; nn < tb.size(); nn++){
                    if(retu[0] == tb[nn]->tbName){
                        break;
                    }
                }
                if(retu[1] != tb[nn]->priKey){
                    break;
                }
                if(nn != tb.size()){
                    int type = example.getAttr(s)->getType();
                    if(set[k].attr2.isNull()){
                        if(type == INTE){
                            stringstream ss;
                            ss<<set[k].expression.value;
                            string sk;
                            ss>>sk;
                            if(!tb[nn]->hashMap.check(sk)){
                                cout << "Against " << tb[nn]->tbName << " Key Restriction" << endl;
                                return;
                            }
                        }
                        else if(type == STRING){
                            string sk;
                            sk = set[k].expression.str;
                            if(!tb[nn]->hashMap.check(sk)){
                                cout << "Against " << tb[nn]->tbName << " Key Restriction" << endl;
                                return;
                            }
                        }
                    }
                }
            }
        }
        for(int i = 1; i <= pageNum; i++){
            int index;
            BufType bt = bpm->getPage(_fileID, i, index);
            bpm->access(index);
            char* bbt = (char*) bt;
            int j = 0;
            for(j = 0; j < slotNum; j++){
                int pos = freeMapPos;
                pos += (j/8);
                int temp = j%8;
                if (((bbt[pos]>>(7-temp))&1)){
                    if(conform(cond, i, j, vector<Table*>())){
                        Attr* waitUpdate = new Attr();
                        int index;
                        BufType b = bpm->getPage(_fileID, i, index);
                        bpm->markDirty(index);
                        char* bb = (char*)b + j*length;
                        for(map<string, int>::iterator it = offset.begin(); it != offset.end(); it++){ // get a new item
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
                                char v[temp->length+10];
                                strncpy(v, bb + offset[itemName], temp->length);
                                string val(v);
                                ((Varchar*)temp)->str = "\'" + val + '\'';
                                waitUpdate->addAttr(*temp, itemName);
                            }
                        }
                        bool cont = 1;
                        for(int k = 0; k < set.size(); k++){
                            Type* temp = new Type();
                            temp = example.getAttr(set[k].attr1.attrName);
                            int type = temp->getType();
                            if(set[k].attr1.attrName == priKey){
                                if(type == INTE){
                                    if(set[k].attr2.isNull()){
                                        stringstream ss;
                                        ss<<set[k].expression.value;
                                        string sk;
                                        ss>>sk;
                                        if(hashMap.check(sk)){
                                            cout << "Update Primary Key Error1" << endl;
                                            return;
                                        }
                                    }
                                    else if(set[k].expression.isNull()){
                                        stringstream sss;
                                        sss<<((Integer*)(waitUpdate->getAttr(set[k].attr2.attrName)))->value;
                                        string sk;
                                        sss>>sk;
                                        if(hashMap.check(sk)){
                                            cout << "Update Primary Key Error2" << endl;
                                            cont = 0;
                                            break;
                                        }
                                    }
                                }
                            }
                            if(set[k].attr2.isNull()){
                                if(set[k].expression.str == "null"){
                                    if(temp->notNull){
                                        cout << "Update NULL Error" << endl;
                                        cont = 0;
                                        break;
                                    }
                                    else{
                                        if(type == INTE){
                                            ((uint*)bb)[offset[set[k].attr1.attrName]] = 0;
                                        }
                                        else if(type == STRING){
                                            bb[offset[set[k].attr1.attrName]] = '\0';
                                        }
                                        temp = new Null();
                                    }
                                }
                                else{
                                    if(type == INTE){
                                        stringstream sss;
                                        sss<<set[k].expression.value;
                                        string content;
                                        sss>>content;
                                        if(set[k].expression.str != ""){
                                            cont = 0;
                                            cout << "Update Input Error" << endl;
                                            break;
                                        }
                                        if(isCheck(set[k].attr1.attrName, content) == 0){
                                            cont = 0;
                                            cout << "Update Check Error" << endl;
                                            break;
                                        }
                                        ((Integer*)temp)->value = set[k].expression.value;
                                    }
                                    else if(type == STRING){
                                        if(set[k].expression.value != 0){
                                            cont = 0;
                                            cout << "Update Input Error" << endl;
                                            break;
                                        }
                                        if(isCheck(set[k].attr1.attrName, set[k].expression.str) == 0){
                                            cont = 0;
                                            cout << "Update Check Error" << endl;
                                            break;
                                        }
                                        ((Varchar*)temp)->str = set[k].expression.str;
                                    }
                                }
                            }
                            else if(set[k].expression.isNull()){
                                if(type == INTE){
                                    stringstream sss;
                                    sss<<((Integer*)(waitUpdate->getAttr(set[k].attr2.attrName)))->value;
                                    string content;
                                    sss>>content;
                                    if(isCheck(set[k].attr1.attrName, content) == 0){
                                        cont = 0;
                                        cout << "Update Check Error" << endl;
                                        break;
                                    }
                                    ((Integer*)temp)->value = ((Integer*)(waitUpdate->getAttr(set[k].attr2.attrName)))->value;
                                }
                                else if(type == STRING){
                                    if(isCheck(set[k].attr1.attrName, ((Varchar*)(waitUpdate->getAttr(set[k].attr2.attrName)))->str) == 0){
                                        cont = 0;
                                        cout << "Update Check Error" << endl;
                                        break;
                                    }
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
                                stringstream sss;
                                sss<<a2;
                                string content;
                                sss>>content;
                                if(isCheck(set[k].attr1.attrName, content) == 0){
                                    cont = 0;
                                    cout << "Update Check Error" << endl;
                                    break;
                                }
                                ((Integer*)temp)->value = a2;
                            }
                            waitUpdate->attributes[set[k].attr1.attrName] = *temp;
                        }
                        if(cont == 0){
                            continue;
                        }
                        updateItem(i, j, *waitUpdate);
                    }
                    // else{
                    //     cout << "Such Item Not Found" << endl;
                    // }
                }
            }
        }
    }

    bool conform(CondSql cond, int pageID, int rID, vector<Table*> tb){ // build a attr according to pageID & rID
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
                char v[temp->length+10];
                strncpy(v, bb + offset[itemName], temp->length);
                string val(v);
                ((Varchar*)temp)->str = val;
                test->addAttr(*temp, itemName);
            }
        }
        bool ret = 1;
        for(int i = 0; i < cond.conditions.size(); i++){
            CondItem item = cond.conditions[i];
            if(item.attr1.tableName != "" && item.attr1.tableName != tbName){
                int nn = 0;
                for(nn = 0; nn < tb.size(); nn++){
                    if(item.attr1.tableName == tb[nn]->tbName)
                        break;
                }
                AttrItem attri1("", item.attr1.attrName);
                CondItem condi(item.judgeOp, attri1, item.attr2, item.expression);
                CondSql condTrans;
                condTrans.conditions.push_back(condi);
                bool secondTb = 0;
                map<string, vector<int> >::iterator p_it;
                p_it = pID.find(tb[nn]->tbName);
                if(p_it == pID.end()){
                    for(int ii = 0; ii < tb[nn]->pageNum; ii++){
                        int index;
                        BufType bt = tb[nn]->bpm->getPage(tb[nn]->_fileID, ii, index);
                        tb[nn]->bpm->access(index);
                        char* bbt = (char*) bt;
                        int jj = 0;
                        for(jj = 0; jj < tb[nn]->slotNum; jj++){
                            int pos = tb[nn]->freeMapPos;
                            pos += (jj/8);
                            int temp = jj%8;
                            if (((bbt[pos]>>(7-temp))&1)){
                                if(tb[nn]->conform(condTrans, ii, jj, tb)){
                                    pID[tb[nn]->tbName].push_back(ii);
                                    rankID[tb[nn]->tbName].push_back(jj);
                                    secondTb = 1;
                                }
                            }
                        }
                    }
                }
                else{
                    for(int iii = 0; iii < pID[tb[nn]->tbName].size(); iii++){
                        int ii = pID[tb[nn]->tbName][iii];
                        int jj = rankID[tb[nn]->tbName][iii];
                        if(tb[nn]->conform(condTrans, ii, jj, tb)){
                            secondTb = 1;
                        }
                        else{
                            vector<int>::iterator v_it = pID[tb[nn]->tbName].begin() + iii;
                            pID[tb[nn]->tbName].erase(v_it);
                            v_it = rankID[tb[nn]->tbName].begin() + iii;
                            rankID[tb[nn]->tbName].erase(v_it);
                        }
                    }
                }
                if(secondTb == 0){
                    ret = 0;
                    break;
                }
                continue;
            }
            if(item.judgeOp == "="){ // case = 
                int type = test->getAttr(item.attr1.attrName)->getType();
                if(type == INTE){
                    if(item.expression.isNull()){
                        if(item.attr2.tableName != ""){
                            int nn = 0;
                            for(nn = 0; nn < tb.size(); nn++){
                                if(item.attr2.tableName == tb[nn]->tbName){
                                    break;
                                }
                            }
                            AttrItem attri1("", item.attr2.attrName);
                            AttrItem attri2("", "");
                            Expression expr;
                            expr.value = ((Integer*)test->getAttr(item.attr1.attrName))->value;
                            CondItem condi("=", attri1, attri2, expr);
                            CondSql condTrans;
                            condTrans.conditions.push_back(condi);
                            bool secondTb = 0;
                            map<string, vector<int> >::iterator p_it;
                            p_it = pID.find(tb[nn]->tbName);
                            if(p_it == pID.end()){
                                for(int ii = 0; ii < tb[nn]->pageNum; ii++){
                                    int index;
                                    BufType bt = tb[nn]->bpm->getPage(tb[nn]->_fileID, ii, index);
                                    tb[nn]->bpm->access(index);
                                    char* bbt = (char*) bt;
                                    int jj = 0;
                                    for(jj = 0; jj < tb[nn]->slotNum; jj++){
                                        int pos = tb[nn]->freeMapPos;
                                        pos += (jj/8);
                                        int temp = jj%8;
                                        if (((bbt[pos]>>(7-temp))&1)){
                                            if(tb[nn]->conform(condTrans, ii, jj, vector<Table*>())){
                                                pID[tb[nn]->tbName].push_back(ii);
                                                rankID[tb[nn]->tbName].push_back(jj);
                                                secondTb = 1;
                                            }
                                        }
                                    }
                                }
                            }
                            else{
                                for(int iii = 0; iii < pID[tb[nn]->tbName].size(); iii++){
                                    int ii = pID[tb[nn]->tbName][iii];
                                    int jj = rankID[tb[nn]->tbName][iii];
                                    if(tb[nn]->conform(condTrans, ii, jj, vector<Table*>())){
                                        secondTb = 1;
                                    }
                                    else{
                                        vector<int>::iterator v_it = pID[tb[nn]->tbName].begin() + iii;
                                        pID[tb[nn]->tbName].erase(v_it);
                                        v_it = rankID[tb[nn]->tbName].begin() + iii;
                                        rankID[tb[nn]->tbName].erase(v_it);
                                    }
                                }
                            }
                            if(secondTb == 0){
                                ret = 0;
                                break;
                            }
                        }
                        else{
                            if(((Integer*)test->getAttr(item.attr1.attrName))->value != 
                                ((Integer*)test->getAttr(item.attr2.attrName))->value){
                                ret = 0;
                                // cout << "A" <<endl;
                                break;
                            }
                        }
                    }
                    else if(item.attr2.isNull()){
                        if(item.expression.str == "null"){
                            int poss = nullPos;
                            int m;
                            for(int sk = 0; sk < sequence.size(); sk++){
                                if(item.attr1.attrName == sequence[sk]){
                                    m = sk;
                                    break;
                                }
                            }
                            poss += (m/8);
                            int tmp = m%8;
                            if(((bb[poss]>>(7-tmp))&1)){
                                ret = 0;
                                break;
                            }
                        }
                        else if(((Integer*)test->getAttr(item.attr1.attrName))->value != 
                            item.expression.value){
                            ret = 0;
                            // cout << "B" <<endl;
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
                            // cout << "C" <<endl;
                            break;
                        } 
                    }
                }
                else if(type == STRING){
                    if(item.expression.isNull()){
                        if(item.attr2.tableName != ""){
                            int nn = 0;
                            for(nn = 0; nn < tb.size(); nn++){
                                if(item.attr2.tableName == tb[nn]->tbName){
                                    break;
                                }
                            }
                            AttrItem attri1("", item.attr2.attrName);
                            AttrItem attri2("", "");
                            Expression expr;
                            expr.str = "\'" + ((Varchar*)test->getAttr(item.attr1.attrName))->str + "\'";
                            CondItem condi("=", attri1, attri2, expr);
                            CondSql condTrans;
                            condTrans.conditions.push_back(condi);
                            bool secondTb = 0;
                            map<string, vector<int> >::iterator p_it;
                            p_it = pID.find(tb[nn]->tbName);
                            if(p_it == pID.end()){
                                for(int ii = 0; ii < tb[nn]->pageNum; ii++){
                                    int index;
                                    BufType bt = tb[nn]->bpm->getPage(tb[nn]->_fileID, ii, index);
                                    tb[nn]->bpm->access(index);
                                    char* bbt = (char*) bt;
                                    int jj = 0;
                                    for(jj = 0; jj < tb[nn]->slotNum; jj++){
                                        int pos = tb[nn]->freeMapPos;
                                        pos += (jj/8);
                                        int temp = jj%8;
                                        if (((bbt[pos]>>(7-temp))&1)){
                                            if(tb[nn]->conform(condTrans, ii, jj, vector<Table*>())){
                                                pID[tb[nn]->tbName].push_back(ii);
                                                rankID[tb[nn]->tbName].push_back(jj);
                                                secondTb = 1;
                                            }
                                        }
                                    }
                                }
                            }
                            else{
                                for(int iii = 0; iii < pID[tb[nn]->tbName].size(); iii++){
                                    int ii = pID[tb[nn]->tbName][iii];
                                    int jj = rankID[tb[nn]->tbName][iii];
                                    if(tb[nn]->conform(condTrans, ii, jj, vector<Table*>())){
                                        secondTb = 1;
                                    }
                                    else{
                                        vector<int>::iterator v_it = pID[tb[nn]->tbName].begin() + iii;
                                        pID[tb[nn]->tbName].erase(v_it);
                                        v_it = rankID[tb[nn]->tbName].begin() + iii;
                                        rankID[tb[nn]->tbName].erase(v_it);
                                    }
                                }
                            }
                            if(secondTb == 0){
                                ret = 0;
                                break;
                            }
                        }
                        else{
                            if(((Varchar*)test->getAttr(item.attr1.attrName))->str != 
                                ((Varchar*)test->getAttr(item.attr2.attrName))->str){
                                ret = 0;
                                // cout << "D" <<endl;
                                break;
                            }
                        }
                    }
                    else{
                        if(item.expression.str == "null"){
                            int poss = nullPos;
                            int m;
                            for(int sk = 0; sk < sequence.size(); sk++){
                                if(item.attr1.attrName == sequence[sk]){
                                    m = sk;
                                    break;
                                }
                            }
                            poss += (m/8);
                            int tmp = m%8;
                            if(((bb[poss]>>(7-tmp))&1)){
                                ret = 0;
                                break;
                            }
                        }
                        else if(item.expression.str.find("%") != string::npos || item.expression.str.find("_") != string::npos){
                            string c = item.expression.str;
                            string delim = "%";
                            vector<string> retu;
                            size_t last = 0;
                            size_t index = c.find_first_of(delim,last);
                            while (index!=std::string::npos)
                            {
                                retu.push_back(c.substr(last,index-last));
                                last=index+1;
                                index=c.find_first_of(delim,last);
                            }
                            if (index-last>0)
                            {
                                retu.push_back(c.substr(last,index-last));
                            }
                            string s = retu[0];
                            for(int i = 1; i < retu.size(); i++){
                                s += (".*" + retu[i]);
                            }
                            int found = s.find("_", 0);
                            while(found != std::string::npos){
                                s[found] = '.';
                                found = s.find("_", found+1);
                            }
                            regex pattern(s);
                            string compare = "\'" + ((Varchar*)test->getAttr(item.attr1.attrName))->str + "\'";
                            if(!regex_match(compare, pattern)){
                                ret = 0;
                                break;
                            }
                        }
                        else{
                            string compare = "\'" + ((Varchar*)test->getAttr(item.attr1.attrName))->str + "\'";
                            if(compare != item.expression.str){
                                ret = 0;
                                // cout << "E" <<endl;
                                break;
                            }
                        }
                    }
                }
            }
            else{ //case < > <= >= (only int)
                int type = test->getAttr(item.attr1.attrName)->getType();
                if(type == INTE){
                    if(item.expression.isNull()){ // attr1 </<=/>/>=attr2
                        if(item.judgeOp == "<"){
                            if(((Integer*)test->getAttr(item.attr1.attrName))->value >= 
                                ((Integer*)test->getAttr(item.attr2.attrName))->value){
                                ret = 0;
                            // cout << "F" <<endl;
                                break;
                            }
                        }
                        else if(item.judgeOp == "<="){
                            if(((Integer*)test->getAttr(item.attr1.attrName))->value > 
                                ((Integer*)test->getAttr(item.attr2.attrName))->value){
                                ret = 0;
                            // cout << "G" <<endl;
                                break;
                            }
                        }
                        else if(item.judgeOp == ">="){
                            if(((Integer*)test->getAttr(item.attr1.attrName))->value < 
                                ((Integer*)test->getAttr(item.attr2.attrName))->value){
                                ret = 0;
                            // cout << "H" <<endl;
                                break;
                            }
                        }
                        else if(item.judgeOp == ">"){
                            if(((Integer*)test->getAttr(item.attr1.attrName))->value <= 
                                ((Integer*)test->getAttr(item.attr2.attrName))->value){
                                ret = 0;
                            // cout << "I" <<endl;
                                break;
                            }
                        }
                    }
                    else if(item.attr2.isNull()){ //attr1 </>/<=/>= expression
                        if(item.judgeOp == "<"){
                            if(((Integer*)test->getAttr(item.attr1.attrName))->value >= 
                                item.expression.value){
                                ret = 0;
                            // cout << "J" <<endl;
                                break;
                            }
                        }
                        else if(item.judgeOp == "<="){
                            if(((Integer*)test->getAttr(item.attr1.attrName))->value > 
                                item.expression.value){
                                ret = 0;
                            // cout << "K" <<endl;
                                break;
                            }
                        }
                        else if(item.judgeOp == ">="){
                            if(((Integer*)test->getAttr(item.attr1.attrName))->value < 
                                item.expression.value){
                                ret = 0;
                            // cout << "L" <<endl;
                                break;
                            }
                        }
                        else if(item.judgeOp == ">"){
                            if(((Integer*)test->getAttr(item.attr1.attrName))->value <= 
                                item.expression.value){
                                ret = 0;
                            // cout << "M" <<endl;
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
                            // cout << "N" <<endl;
                                break;
                            }
                        }
                        else if(item.judgeOp == "<="){
                            if(((Integer*)test->getAttr(item.attr1.attrName))->value >
                                a2){
                                ret = 0;
                            // cout << "O" <<endl;
                                break;
                            }
                        }
                        else if(item.judgeOp == ">="){
                            if(((Integer*)test->getAttr(item.attr1.attrName))->value <
                                a2){
                                ret = 0;
                            // cout << "P" <<endl;
                                break;
                            }
                        }
                        else if(item.judgeOp == ">"){
                            if(((Integer*)test->getAttr(item.attr1.attrName))->value <=
                                a2){
                                ret = 0;
                            // cout << "Q" <<endl;
                                break;
                            }
                        }
                    }
                }
                else{ret = 0;cout << "Condition Fault" << endl;}
            }
        }
        delete test;
        return ret;
    }
};

#endif