#ifndef TYPE_H
#define TYPE_H

class Type {
public:
	int length;

	Type(int len) : length(len) {}
};

class Integer : public Type {
public:
	Integer(int len) : Type(len) {}
};

class Varchar : public Type {
public:
	Varchar(int len) : Type(len) {}
};

#endif