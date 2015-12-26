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
	cout << endl;



	//test table
	vector<string> n;
	n.push_back("xuhan");
	n.push_back("bjs");
	vector<string> type;
	type.push_back("int");
	type.push_back("varchar");
	vector<string> len;
	len.push_back("4");
	len.push_back("4");
	vector<bool> notNull;
	notNull.push_back(1);
	notNull.push_back(1);
	TableCon* tbc = new TableCon();
	tbc->init(n, type, "xuhan");
	tbc->length = len;
	Table* tb = new Table(*tbc, "test");
	tb->example.display();
	cout << tb->example.length << endl;
	cout << endl;

	//test insert
	vector<string> v;
	v.push_back("9");
	v.push_back("ok");
	vector<vector<string> > vv;
	vv.push_back(v);
	tb->insert(n, vv);
	tb->showTB(1);

	//test update
	CondItem* set = new CondItem();
	AttrItem* item1 = new AttrItem();
	item->init("test", "xuhan");
	AttrItem* item2 = new AttrItem();
	set.init("=", *item1, *item2, )
}