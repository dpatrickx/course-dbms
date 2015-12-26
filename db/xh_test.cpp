#include "type.h"
#include "table.h"
#include <iostream>

int main(){
	Varchar a("10", 100, 1);
	Integer b(1, 1, "10");
	Type* temp = new Type();
	temp = &a;
	cout << temp->getType() << endl;
	cout << ((Varchar*)temp)->length <<endl;
	temp = &b;
	cout << ((Integer*)temp)->getType() << endl;
}