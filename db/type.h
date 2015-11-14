#ifndef TYPE_H
#define TYPE_H

#include <cstring>
using namespace std;

class Type {
public:
	int length;

	Type(int len) : length(len) {}
	virtual int write(uint*, int&) = 0;
};

class Integer : public Type {
public:
	int value;
	Integer(int c) : Type(1) {
		value = c;
	}
	int write (uint* b, int& pos) {
		// pos - nth byte of page b
	    uint* bb = (uint*)((char*)b + pos);
	    (*bb) = value;
	    pos += 4;
	}
};

class Varchar : public Type {
public:
	string str;
	Varchar(int len) : Type(len) {}
	int write (uint* b, int& pos) {
		// pos - nth byte of page b
	    char* bb = (char*) b;
	    bb += pos;
	    for (int i = 0;i < len;i++) {
	        *(bb+i) = str[i];
	    }
	    pos += len;
	}
};

#endif