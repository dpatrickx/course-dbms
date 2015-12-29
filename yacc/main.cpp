#include "main.h"
#include "yacc.tab.h"
#include "../db/sql.h"
#include "../db/table.h"
#include "../db/dbManager.h"

inline int writeInt(uint* bb, int a) {
    bb[0] = a;
    return 1;
}

inline int writeStr(char* bb, string tempStr) {
    int len = 0;
    for (int ii = 0;ii < tempStr.size();ii++) {
        *(bb) = tempStr[ii];
        bb++;
        len++;
    }
    *(bb) = '\0';
    bb++;
    len++;
    return len;
}

inline int readInt(uint* b) {
    int res = b[0];
    return res;
}

inline string readStr(char* bb) {
    int len = 0;
    while (1) {
        if (bb[len] == '\0') {
            len++;
            break;
        }
        len++;
    }
    char* tempCstar = new char[len];
    strncpy(tempCstar, bb, len);
    string res = tempCstar;
    return res;
}

void initTable(Table* table, string txtName) {
    cout<<"tb path is "<<txtName<<endl;
    int fileID;
    int index;
    int pageID = 0;
    FileManager* fm = new FileManager();
    BufPageManager* bpm = new BufPageManager(fm);
    BufType b;
    char* bb;
    string tempStr;
    int tempInt;

    fm->openFile(txtName.c_str(), fileID);
    b = bpm->getPage(fileID, pageID, index);
    bpm->access(index);
    // read begin
    // _fileID length slotNum bitSize typeNum pageNum nullPos freeNumPos freeMapPos
    table->_fileID = readInt(b); b++;
    table->length = readInt(b); b++;
    table->slotNum = readInt(b); b++;
    table->bitSize = readInt(b); b++;
    table->typeNum = readInt(b); b++;
    table->pageNum = readInt(b); b++;
    table->nullPos = readInt(b); b++;
    table->freeNumPos = readInt(b); b++;
    table->freeMapPos = readInt(b); b++;
    // tbName
    bb = (char*)(b);
    tempStr = readStr(bb);
    table->tbName = tempStr;
    bb += (tempStr.size()+1);
    // path
    tempStr = readStr(bb);
    table->path = tempStr;
    bb += (tempStr.size()+1);
    // priKey
    tempStr = readStr(bb);
    table->priKey = tempStr;
    bb += (tempStr.size()+1);
    // offset
    b = (uint*)(bb);
    int offsetSize = readInt(b);
    b++;
    for (int ii = 0; ii < offsetSize; ii++) {
        // read string
        bb = (char*)(b);
        tempStr = readStr(bb);
        bb += (tempStr.size()+1);
        // read int
        b = (uint*)(bb);
        tempInt = readInt(b);
        b++;
        table->offset.insert(pair<string, int>(tempStr, tempInt));
    }
    // sequence
    int sequSize = readInt(b);
    b++;
    bb = (char*)(b);
    for (int ii = 0; ii < sequSize; ii++) {
        tempStr = readStr(bb);
        bb += (tempStr.size()+1);
        table->sequence.push_back(tempStr);
    }
    // check
    b = (uint*)(bb);
    int checkSize = readInt(b);
    b++;
    bb = (char*)(b);
    for (int ii = 0; ii < checkSize; ii++) {
        tempStr = readStr(bb);
        bb += (tempStr.size()+1);
        b = (uint*)(bb);
        int tempSize = readInt(b);
        b++;
        bb = (char*)(b);
        vector<string> vec;
        for (int jj = 0; jj < tempSize; jj++) {
            string sss = readStr(bb);
            bb += (sss.size()+1);
            vec.push_back(sss);
        }
        table->check.insert(pair<string, vector<string> >(tempStr, vec));
    }
    // example
        // length
    b = (uint*)(bb);
    table->example.length = readInt(b);
    b++;
        // active
    tempInt = readInt(b);
    if (tempInt == 1)
        table->example.active = true;
    else
        table->example.active = false;
    b++;
        // tableName
    bb = (char*)(b);
    tempStr = readStr(bb);
    table->example.tableName = tempStr;
    bb += (tempStr.size()+1);
        // map<string, Type> attributes
    b = (uint*)(bb);
    tempInt = readInt(b);
    b++;
    bb = (char*)(b);
    for (int ii = 0; ii < tempInt; ii++) {
        tempStr = readStr(bb);
        bb += (tempStr.size()+1);
        b = (uint*)(bb);
        Type type;
        type.length = readInt(b); b++;
        type.type = readInt(b); b++;
        type.value = readInt(b); b++;
        type.number = readInt(b); b++;
        int notnull = readInt(b); b++;
        if (notnull == 1)
            type.notNull = true;
        else
            type.notNull = false;
        bb = (char*)b;
        string strStr = readStr(bb);
        bb += (strStr.size()+1);
        type.str = strStr;
        table->example.attributes.insert(pair<string, Type>(tempStr, type));
    }
    table->init();
}

void initDB(DB* db, string dbPath) {
    int fileID;
    int index;
    FileManager* fm = new FileManager();
    BufPageManager* bpm = new BufPageManager(fm);
    BufType b;
    char* bb;
    string tempStr;
    int tempInt;
    string txtPath = dbPath;
    txtPath += "this.txt";
    cout<<"db path is "<<txtPath<<endl;
    fm->openFile(txtPath.c_str(), fileID);
    b = bpm->getPage(fileID, 0, index);
    bpm->access(index);

    bb = (char*)(b);
    tempStr = readStr(bb);
    bb += (tempStr.size()+1);
    db->dbName = tempStr;
    cout<<"dbName = "<<tempStr<<endl;
    b = (uint*)(bb);
    int tableSize = readInt(b);
    b++;
    bb = (char*)(b);
    for (int i = 0; i < tableSize; i++) {
        tempStr = readStr(bb);
        bb += (tempStr.size()+1);
        cout<<"table name is "<<tempStr<<endl;
        db->tbName.insert(tempStr);
    }
    // add table
    for (int i = 0; i < db->tbName.size(); i++) {
        string tablePath = dbPath;
        tablePath += db->tbName[i];
        tablePath += ".txt";
        Table* table = new Table();
        initTable(table, tablePath);
        db->tbMap.insert(map<string, Table*>::value_type(db->tbName[i], table));
    }
}

void initDBManager(string dbManPath) {
    DBManager* manager = DBManager::instance("./");
    DB db;
    int fileID;
    int index;
    FileManager* fm = new FileManager();
    BufPageManager* bpm = new BufPageManager(fm);
    BufType b;
    char* bb;
    string tempStr;
    int tempInt;

    fm->openFile(dbManPath.c_str(), fileID);
    b = bpm->getPage(fileID, 0, index);
    bpm->access(index);

    int size = readInt(b);
    b++;
    bb = (char*)(b);
    cout<<size<<"databases:\n";
    for (int i = 0; i < size; i++) {
        tempStr = readStr(bb);
        bb += (tempStr.size()+1);
        manager->dbName.insert(tempStr);
        cout<<tempStr<<endl;
    }
    cout<<"----------\n";
    // add databases
    for (int i = 0; i < manager->dbName.size(); i++) {
        string dbPath = "./mysql/";
        dbPath += manager->dbName[i];
        dbPath += "/";
        DB* db = new DB();
        initDB(db, dbPath);
        manager->dbMap.insert(map<string, DB*>::value_type(manager->dbName[i], db));
    }
}

void saveFile() {
    DBManager* manager = DBManager::instance("./");
    manager->saveFile();
    // save database classes
    int fileID;
    int index;
    int pageID = 0;
    string tempStr;
    int tempInt;
    char* bb;
    mkdir(("mysql/"), S_IRWXU);
    FileManager* fm = new FileManager();
    BufPageManager* bpm = new BufPageManager(fm);
    BufType b;
    // write database manager
    fm->createFile("./mysql/this.txt");
    fm->openFile("./mysql/this.txt", fileID);
    b = bpm->getPage(fileID, 0, index);
    bpm->markDirty(index);
    b += writeInt(b, manager->dbName.size());
    bb = (char*)(b);
    for (int i = 0; i < manager->dbName.size(); i++)
        bb += writeStr(bb, manager->dbName[i]);
    bpm->close();
    fm->closeFile(fileID);
    // write back
    map<string, DB*>::iterator it;
    map<string, Table*>::iterator its;
    string fileName = "./mysql/";
    for (it = manager->dbMap.begin(); it != manager->dbMap.end(); it++) {
        DB* db = it->second;
        fileName = "./mysql/";
        fileName += db->dbName;
        fileName += "/";
        mkdir((fileName.c_str()), S_IRWXU);
        // write this database
        string dbFilePath = fileName;
        dbFilePath += "this.txt";
        fm->createFile(dbFilePath.c_str());
        fm->openFile(dbFilePath.c_str(), fileID);
        b = bpm->getPage(fileID, 0, index);
        bpm->markDirty(index);
        // write begin
        bb = (char*)(b);
        bb += writeStr(bb, db->dbName);
        b = (uint*)(bb);
        b += writeInt(b, db->tbName.size());
        bb = (char*)(b);
        for (int q = 0; q < db->tbName.size(); q++) {
            bb += writeStr(bb, db->tbName[q]);
        }
        // write back
        bpm->close();
        fm->closeFile(fileID);
        for (its = db->tbMap.begin(); its != db->tbMap.end(); its++) {
            // write a Table class
            Table* table = its->second;
            string txtName = fileName;
            txtName += table->tbName;
            txtName += ".txt";
            fm->createFile(txtName.c_str());
            fm->openFile(txtName.c_str(), fileID);
            b = bpm->getPage(fileID, pageID, index);
            bpm->markDirty(index);
            // _fileID
            b += writeInt(b, table->_fileID);
            // length
            b += writeInt(b, table->length);
            // slotNum
            b += writeInt(b, table->slotNum);
            // bitSize
            b += writeInt(b, table->bitSize);
            // typeNum
            b += writeInt(b, table->typeNum);
            // pageNum
            b += writeInt(b, table->pageNum);
            // nullPos
            b += writeInt(b, table->nullPos);
            // freeNumPos
            b += writeInt(b, table->freeNumPos);
            // freeMapPos
            b += writeInt(b, table->freeMapPos);
            // tbName
            bb = (char*)(b);
            bb += writeStr(bb, table->tbName);
            // path
            bb += writeStr(bb, table->path);
            // priKey
            bb += writeStr(bb, table->priKey);
            // map<string, int> offset;
            b = (uint*)(bb);
            b += writeInt(b, table->offset.size());
            map<string, int>::iterator siit;
            for (siit = table->offset.begin(); siit != table->offset.end(); siit++) {
                bb = (char*)(b);
                bb += writeStr(bb, siit->first);
                b = (uint*)(bb);
                b += writeInt(b, siit->second);
            }
            // sequence
            b += writeInt(b, table->sequence.size());
            bb = (char*)(b);
            for (int ii = 0; ii < table->sequence.size(); ii++)
                bb += writeStr(bb, table->sequence[ii]);
            // map<string, vector<string> > check
            b = (uint*)(bb);
            b += writeInt(b, table->check.size());
            bb = (char*)(b);
            map<string, vector<string> >::iterator svsit;
            for (svsit = table->check.begin(); svsit != table->check.end(); svsit++) {
                bb += writeStr(bb, svsit->first);
                b = (uint*)(bb);
                b += writeInt(b, svsit->second.size());
                bb = (char*)(b);
                for (int ii = 0; ii < svsit->second.size(); ii++)
                    bb += writeStr(bb, svsit->second[ii]);
            }
            // example
                // length
            b = (uint*)(bb);
            b += writeInt(b, table->example.length);
                // active
            if (table->example.active)
                b += writeInt(b, 1);
            else
                b += writeInt(b, 0);
                // tableName
            bb = (char*)(b);
            bb += writeStr(bb, table->example.tableName);
                // map<string, Type> attributes
            b = (uint*)(bb);
            b += writeInt(b, table->example.attributes.size());
            bb = (char*)(b);
            map<string, Type>::iterator stit;
            for (stit = table->example.attributes.begin(); stit != table->example.attributes.end(); stit++) {
                bb += writeStr(bb, stit->first);
                // length type value number notNull str
                b = (uint*)(bb);
                b += writeInt(b, stit->second.length);
                b += writeInt(b, stit->second.type);
                b += writeInt(b, stit->second.value);
                b += writeInt(b, stit->second.number);
                if (stit->second.notNull)
                    b += writeInt(b, 1);
                else
                    b += writeInt(b, 0);
                bb = (char*)(b);
                bb += writeStr(bb, stit->second.str);
            }
            // write back
            bpm->close();
            fm->closeFile(fileID);
        }
    }
}

int main()
{
    int a;
    cin>>a;
    if (a == 0)
        initDBManager("./mysql/this.txt");
    else {
        system("rm -r mysql");
        system("rm -r test");
    }
    const char* sFile = "file.txt";
    FILE* fp = fopen(sFile, "r");
    if(fp == NULL) {
        printf("cannot open %s\n", sFile);
        return -1;
    }
    extern FILE* yyin;
    yyin = fp;
    printf("-----begin parsing %s\n", sFile);
    yyparse();
    puts("-----end parsing");
    fclose(fp);
    if (a != 0)
        saveFile();
    return 0;
}

