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
	map<string, Type> attributes;
	string tableName;	// the name of the table which attr belongs to
	bool active;

	void addAttr(Type type, string name) {
		attributes.insert(pair<string, Type>(name, type));
	}
	// void definition(string name, int off){
	// 	attrName.insert(pair<string, int>(name, off));
	// }
	bool writeAttr(uint* b, int& pos){
		map<string, Type>::iterator s_it;
		bool flag = 0;
		for(s_it = attributes.begin(); s_it != attributes.end(); i++){
			s_it->second.write(b, pos);
			flag = 1;
		}
		return flag;
	}
	Type getAttr(string target){
		// map<string, Type>::iterator s_it;
		// s_it = attributes.find(target);
		// if(s_it == attrName.end())
		// 	return NULL;
		Type targetOff = attributes[target];
		return targetOff;
	}

	void display() {
		// display all the attributes
		map<string, Type>::iterator s_it;
		for(s_it = attributes.begin(); s_it != attributes.end(); i++){
			s_it->second.dispay(b, pos);
		}
	}

	void remove(){
		active = 0;
	}

	Attr(string sen) {
		sentence = "sen";
		tableName = "table";
		active = 1;
	}
};

#endif