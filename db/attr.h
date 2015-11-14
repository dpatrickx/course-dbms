#ifndef ATTR_H
#define ATTR_H

#include <map>
#include <cstring>
#include "type.h"
using namespace std;

class Attr {
public:
	int length;
	map<int, Type> attributes;
	map<string, int> attrName;

	void addAttr(Type type, int off) {
		attributes.insert(pair<int, Type>(off, type));
	}
	void definition(string name, int off){
		attrName.insert(pair<string, int>(name, off));
	}
	bool writeAttr(string target){
		map<string, int>::iterator s_it;
		s_it = attrName.find(target);
		if(s_it == attrName.end())
			return 0;
		int targetOff = s_it->second;
		attributes[targetOff].write();
		return 1;
	}
	Type getAttr(string target){
		map<string, int>::iterator s_it;
		s_it = attrName.find(target);
		if(s_it == attrName.end())
			return NULL;
		int targetOff = s_it->second;
		return attributes[targetOff];
	}
};

#endif