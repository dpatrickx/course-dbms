#include "main.h"
#include "yacc.tab.h"
#include "../db/sql.h"
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

void initTable(string txtName) {
    Table table;
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
    for (int i = 0; i < 9; i++) {
        cout<<readInt(b)<<endl;
        b++;
    }
    // tbName
    bb = (char*)(b);
    tempStr = readStr(bb);
    cout<<"tbName = ---"<<tempStr<<"---\n";
    bb += (tempStr.size()+1);
    // path
    tempStr = readStr(bb);
    cout<<"path = ---"<<tempStr<<"---\n";
    bb += (tempStr.size()+1);
    // priKey
    tempStr = readStr(bb);
    cout<<"priKey = ---"<<tempStr<<"---\n";
    bb += (tempStr.size()+1);
    // offset
    b = (uint*)(bb);
    int offsetSize = readInt(b);
    b++;
    for (int ii = 0; ii < offsetSize; ii++) {
        // read string
        bb = (char*)(b);
        tempStr = readStr(bb);
        cout<<ii<<": "<<tempStr<<"---";
        bb += (tempStr.size()+1);
        // read int
        b = (uint*)(bb);
        tempInt = readInt(b);
        b++;
        cout<<tempInt<<endl;
    }
    // sequence
    cout<<"sequence begin\n";
    int sequSize = readInt(b);
    b++;
    bb = (char*)(b);
    for (int ii = 0; ii < sequSize; ii++) {
        tempStr = readStr(bb);
        bb += (tempStr.size()+1);
        cout<<tempStr<<endl;
    }
    cout<<"sequence end\n";
    // check
    b = (uint*)(bb);
    int checkSize = readInt(b);
    b++;
    bb = (char*)(b);
    for (int ii = 0; ii < checkSize; ii++) {
        tempStr = readStr(bb);
        bb += (tempStr.size()+1);
        cout<<tempStr<<": ";
        b = (uint*)(bb);
        int tempSize = readInt(b);
        b++;
        bb = (char*)(b);
        for (int jj = 0; jj < tempSize; jj++) {
            tempStr = readStr(bb);
            bb += (tempStr.size()+1);
            cout<<tempStr<<", ";
        }
        cout<<endl;
    }
    // example
        // length
    b = (uint*)(bb);
    cout<<"example.length = "<<readInt(b)<<endl;
    b++;
        // active
    cout<<"example.active = "<<readInt(b)<<endl;
    b++;
        // tableName
    bb = (char*)(b);
    tempStr = readStr(bb);
    cout<<"example.tableName = "<<tempStr<<endl;
    bb += (tempStr.size()+1);
        // map<string, Type> attributes
    b = (uint*)(bb);
    tempInt = readInt(b);
    cout<<"example.attributes.length = "<<tempInt<<endl;
    b++;
    bb = (char*)(b);
    for (int ii = 0; ii < tempInt; ii++) {
        tempStr = readStr(bb);
        bb += (tempStr.size()+1);
        cout<<"attr"<<ii<<".name = "<<tempStr<<endl;
        b = (uint*)(bb);
        cout<<".length = "<<readInt(b);
        b++;
        cout<<".type = "<<readInt(b);
        b++;
        cout<<".value = "<<readInt(b);
        b++;
        cout<<".number = "<<readInt(b);
        b++;
        cout<<".notNull = "<<readInt(b);
        b++;
        bb = (char*)b;
        tempStr = readStr(bb);
        bb += (tempStr.size()+1);
        cout<<".str = "<<tempStr<<endl;
    }
}

void initDB(string dbPath) {
    DB db;
    int fileID;
    int index;
    FileManager* fm = new FileManager();
    BufPageManager* bpm = new BufPageManager(fm);
    BufType b;
    char* bb;
    string tempStr;
    int tempInt;

    fm->openFile(dbPath.c_str(), fileID);
    b = bpm->getPage(fileID, 0, index);
    bpm->access(index);

    bb = (char*)(b);
    tempStr = readStr(bb);
    bb += (tempStr.size()+1);
    cout<<"dbName = "<<tempStr<<endl;
    db.dbName = tempStr;
    b = (uint*)(bb);
    int tableSize = readInt(b);
    b++;
    bb = (char*)(b);
    for (int i = 0; i < tableSize; i++) {
        tempStr = readStr(bb);
        bb += (tempStr.size()+1);
        cout<<"table name is "<<tempStr<<endl;
    }
}

void initDBManager(string dbManPath) {}

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
    mkdir(("./mysql/"), S_IRWXU);
    FileManager* fm = new FileManager();
    BufPageManager* bpm = new BufPageManager(fm);
    BufType b;
    // write begin
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
        fileName += "this.txt";
        fm->createFile(fileName.c_str());
        fm->openFile(fileName.c_str(), fileID);
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
            cout<<txtName<<endl;
            fm->createFile(txtName.c_str());
            fm->openFile(txtName.c_str(), fileID);
            b = bpm->getPage(fileID, pageID, index);
            bpm->markDirty(index);
            // _fileID
            b += writeInt(b, table->_fileID);
            // length
            cout<<"length = "<<table->length<<endl;
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
    if (a == 0) {
        initTable("./mysql/test/customer.txt");
        return 0;
    } else if (a == 1) {
        initDB("./mysql/test/this.txt");
        return 0;
    } else if (a == 2) {
        initDBManager("./mysql/this.txt");
    }
    const char* sFile = "file.txt";
    FILE* fp = fopen(sFile, "r");
    if(fp == NULL)
    {
        printf("cannot open %s\n", sFile);
        return -1;
    }
    extern FILE* yyin;
    yyin = fp;
    printf("-----begin parsing %s\n", sFile);
    yyparse();
    puts("-----end parsing");
    fclose(fp);
    saveFile();
    return 0;
}

