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

class Varchar : public Type {
public:
	string str;
	Varchar(string value, int len) : Type(len) {
		str = value;
	}
	int write (uint* b, int& pos) {
		// pos - nth byte of page b
	    char* bb = (char*) b;
	    bb += pos;
	    for (int i = 0;i < len;i++) {
	        *(bb+i) = str[i];
	    }
	    pos += length;
	}
};

class Integer : public Varchar {
public:
	Integer (string value, int len) : Varchar(value, len) {}
};

#endif