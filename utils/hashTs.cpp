#include "HashMap.h"
#include <iostream>
#include <string>
using namespace std;

string array[10];

int main() {
	array[0] = "id0";
	array[1] = "id1";
	array[2] = "id2";
	array[3] = "id3";
	array[4] = "id4";
	array[5] = "id4";
	array[6] = "id3";
	array[7] = "id2";
	array[8] = "id1";
	array[9] = "id0";
	HashMap map;
	for (int i = 0; i < 10; i++) {
		bool res = map.check(array[i]);
		cout<<"check "<<array[i]<<": "<<res<<endl;
		if (!res)
			map.insert(array[i]);
	}
}