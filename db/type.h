#ifndef TYPE_H
#define TYPE_H

#include "para.h"
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;

class Type {
public:
	int length;		// bytes
	bool notNull;
	int type;
	int value;
	string str;
	int number;

	Type(int l, bool n, int t) {
		length = l;
		notNull = n;
		type = t;
	}
	Type() {}
	virtual void write(uint* b, int pos) {
		if(type == INTE){
			char* bb = (char*) b;
		    bb += pos;
		    uint* bbb = (uint*) bb;
		    *(bbb) = value;
		}
		else if(type == STRING){
			char* bb = (char*) b;
		    bb += pos;
		    for (int i = 1;i < str.size()-1;i++) {
		        *(bb+i-1) = str[i];
		    }
		    if(str.size()-2 <= length){
		    	*(bb+str.size()-2) = '\0';
		    }
		}
		else if(type == NUL){}
	}
	virtual int getType() {return type;}
	virtual void display() {
		if(type == INTE){
			printf("%d\n", value);
		}
		else if(type == STRING){
			printf("%s\n", str.c_str());
		}
		else if(type == NUL){
			printf("NULL\n");
		}
	}
};

class Null : public Type {
public:
	Null() : Type(0, 0, NUL) {
		str = "";
		value = 0;
	}
	virtual void write (uint* b, int pos) {
		// pos - nth byte of page b
	}
	virtual int getType(){
		return type;
	}
	virtual void display(){
		printf("NULL\n");
	}
};

class Varchar : public Type {
public:
	Varchar(string value, int len, bool n) : Type(len, n, STRING) {
		str = value;
		number = 0;
	}
	virtual void write (uint* b, int pos) {
		// pos - nth byte of page b
	    char* bb = (char*) b;
	    bb += pos;
	    for (int i = 0;i < length;i++) {
	        *(bb+i) = str[i];
	    }
	}
	virtual int getType(){
		return type;
	}
	virtual void display(){
		printf("%s\n", str.c_str());
	}
};

class Integer : public Type {
public:
	Integer (int value, bool n, string len) : Type(4, n, INTE) {
		this->value = value;
		number = atoi(len.c_str());
	}
	virtual void write(uint* b, int pos) {
		char* bb = (char*) b;
	    bb += pos;
	    uint* bbb = (uint*) bb;
	    *(bbb) = value;
	}
	virtual int getType(){
		return type;
	}
	virtual void display(){
		printf("%d\n", value);
	}
};

class Bool : public Type {
public:
	bool value1;
	Bool(bool val, bool n) : Type(1, n, BOOL){
		value1 = val;
	}
	virtual void write(uint* b, int pos) {}
	virtual int getType(){
		return BOOL;
	}
};

#endif