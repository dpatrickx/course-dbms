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
		*(b+pos) = value;
		pos += 1;
	}
};

class Varchar : public Type {
public:
	string str;
	Varchar(int len) : Type(len) {}
	int write (uint* b, int& pos) {
		int length = str.length();
		int tempPos = pos;
		for (int i = 0; i < length; i+=4) {
			uint temp = 0;
			if (i+4 > length) {
				int tempLen = i+4;
				for (; i < length; i++) {
					temp <<= 8;
					temp |= a[i];
				}
				temp <<= 8*(tempLen-length);
			} else {
				for (int j = 0;j < 4;j++) {
					temp <<= 8;
					temp |= a[i+j];
				}
			}
			b[tempPos++] = temp;
		}
		pos += len;
	}
};

#endif