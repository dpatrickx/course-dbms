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
	tbc->notNull = notNull;
	cout << "XXX" <<endl;
	Table* tb = new Table(*tbc, "test", "test");
	tb->example.display();
	cout << tb->example.length << endl;
	cout << endl;

	//test insert
	vector<string> v;
	v.push_back("9");
	v.push_back("ok");
	vector<vector<string> > vv;
	vv.push_back(v);
	for (int i = 0;i < 10; i++)
		tb->insert(n, vv);
	tb->showTB(1);

	// //test update
	string tableName = "test";
	CondSql cond;
	vector<CondItem> set;

	AttrItem item1("", "xuhan");
	AttrItem item2("", "");
	Expression expr;
	expr.value = 9;
	CondItem conditem("=", item1, item2, expr);

	AttrItem item3("", "bjs");
	Expression expr1;
	expr1.str = "hhh";
	CondItem condi("=", item3, item2, expr1);

	cond.conditions.push_back(conditem);
	set.push_back(condi);

	// cout << endl;
	tb->update(set, cond);
	tb->showTB(1);
	//cout << tb->conform(cond, 1, 0) << endl << endl;
	//cout << tb->conform(cond, 1, 1) << endl;
	//cout << tb->conform(cond, 1, 2) << endl;


	// //test select
	vector<AttrItem> attrs;
	vector<string> tables;
	CondSql cond1;

	AttrItem item11("", "bjs");
	AttrItem item22("", "");
	Expression expr11;
	expr11.str = "\'hhh\'";
	CondItem conditem1("=", item11, item22, expr11);

	cond1.conditions.push_back(conditem1);
	AttrItem item12("", "*");
	attrs.push_back(item12);
	tables.push_back("test");
	tb->select(attrs, cond1);
	//cout << tb->conform(cond1, 1, 0) << endl;
}