#ifndef ATTR_H
#define ATTR_H

#include <map>
#include <cstring>
using namespace std;

class Attr {
public:
	int length;
	map<string, int> attributes;
	map<string, int>::iterator iter;

	void addAttr(string name, int type) {
		
	}
};

#endif