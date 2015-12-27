#include "HashMap.h"
#include <iostream>
#include <string>
using namespace std;

string array[10];

int main() {
	HashMap map;
	map.insert("id0");
	cout<<map.check("id0")<<endl;
	map.remove("id0");
	cout<<map.check("id0")<<endl;
	map.insert("id0");
	map.insert("id1");
	cout<<map.check("id1")<<endl;
	map.remove("id1");
	cout<<map.check("id1")<<endl;
	map.insert("id1");
	map.insert("id2");
	cout<<map.check("id1")<<endl;
	map.remove("id1");
	cout<<map.check("id1")<<endl;
}