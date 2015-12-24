#ifndef TYPE_H
#define TYPE_H

#include <cstring>
using namespace std;

enum TYPE{INT, CHAR, NUL};

class Type {
public:
	int length;

	Type(int len) : length(len) {}
	virtual int write(uint*, int&) = 0;
	virtual int getType() = 0;
};

class Null : public Type {
public:
	Null() : Type(0) {
	}
	virtual int write (uint* b, int& pos) {
		// pos - nth byte of page b
	    pos += length;
	}
	virtual int getType(){
		return NUL;
	}
};

class Varchar : public Type {
public:
	string str;
	Varchar(string value, int len) : Type(len) {
		str = value;
	}
	virtual int write (uint* b, int& pos) {
		// pos - nth byte of page b
	    char* bb = (char*) b;
	    bb += pos;
	    for (int i = 0;i < len;i++) {
	        *(bb+i) = str[i];
	    }
	    pos += length;
	}
	virtual int getType(){
		return CHAR;
	}
};

class Integer : public Varchar {
public:
	Integer (string value, int len) : Varchar(value, len) {}
	virtual int write(uint* b, int& pos) {
		char* bb = (char*) b;
	    bb += pos;
	    for (int i = 0;i < len;i++) {
	        *(bb+i) = str[i];
	    }
	    pos += length;
	}
	virtual int getType(){
		return INT;
	}
};

#endif