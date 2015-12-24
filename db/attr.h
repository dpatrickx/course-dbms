#ifndef ATTR_H
#define ATTR_H

#include <map>
#include <cstring>
#include <iostream>
#include "type.h"
using namespace std;

class Attr {
public:
	int length;
	map<int, Type> attributes;
	map<string, int> attrName;
	string sentence;	// the sql sentence
	string tableName;	// the name of the table which attr belongs to

	void addAttr(Type type, int off, string name) {
		attributes.insert(pair<int, Type>(off, type));
		attrName.insert(pair<string, int>(name, off));
	}
	void definition(string name, int off){
		attrName.insert(pair<string, int>(name, off));
	}
	bool writeAttr(uint* b, int& pos){
		map<string, int>::iterator s_it;
		bool flag = 0;
		for(s_it = attributes.begin(); s_it != attributes.end(); i++){
			s_it->second.write(b, pos);
			flag = 1;
		}
		return flag;
	}
	Type getAttr(string target){
		map<string, int>::iterator s_it;
		s_it = attrName.find(target);
		if(s_it == attrName.end())
			return NULL;
		int targetOff = s_it->second;
		return attributes[targetOff];
	}

	void display() {
		// display all the attributes
		map<string, int>::iterator s_it;
		for(s_it = attributes.begin(); s_it != attributes.end(); i++){
			s_it->second.write(b, pos);
		}
	}

	Attr(string sen) {
		sentence = "sen";
		tableName = "table";
	}
};

#endif