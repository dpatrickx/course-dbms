#ifndef TYPE_H
#define TYPE_H

#include "para.h"
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

class Type {
public:
	int length;		// bytes
	bool notNull;

	Type(int l, bool n) {
		length = l;
		notNull = n;
	}
	Type(){}
	virtual int write(uint*, int&) {}
	virtual int getType() {}
	virtual void display() {}
};

class Null : public Type {
public:
	Null() : Type(0, 0) {
	}
	virtual int write (uint* b, int& pos) {
		// pos - nth byte of page b
	    pos += length;
	}
	virtual int getType(){
		return NUL;
	}
	virtual void display(){
		printf("NULL\n");
	}
};

class Varchar : public Type {
public:
	string str;
	Varchar(string value, int len, bool n) : Type(len, n) {
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
	virtual int getType(){
		return STRING;
	}
	virtual void display(){
		printf("%s\n", str.c_str());
	}
};

class Integer : public Type {
public:
	int value;
	int number;
	Integer (int value, bool n, string len) : Type(4, n) {
		number = atoi(len.c_str());
	}
	int write(uint* b, int& pos) {
		char* bb = (char*) b;
	    bb += pos;
	    uint* bbb = (uint*) bb;
	    *(bbb) = value;
	    pos += length;
	}
	virtual int getType(){
		return INTEGER;
	}
	virtual void display(){
		printf("%d\n", value);
	}
};

class Bool : public Type {
public:
	bool value;
	void write(uint* b, int& pos) {}
	virtual int getType(){
		return BOOL;
	}
};

#endif