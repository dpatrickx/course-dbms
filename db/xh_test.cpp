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
	n.push_back("test2_xuhan");
	n.push_back("bjs");
	n.push_back("dhy");
	vector<string> type;
	type.push_back("int");
	type.push_back("varchar");
	type.push_back("int");
	vector<string> len;
	len.push_back("4");
	len.push_back("4");
	len.push_back("4");
	vector<bool> notNull;
	notNull.push_back(0);
	notNull.push_back(1);
	notNull.push_back(0);
	TableCon* tbc = new TableCon();
	tbc->init(n, type, "test2_xuhan");
	tbc->length = len;
	tbc->notNull = notNull;
	tbc->checkAttrs.push_back("bjs");
	vector<string> val;
	val.push_back("\'F\'");
	val.push_back("\'M\'");
	tbc->checkVal.push_back(val);
	Table* tb = new Table(*tbc, "test", "test");
	Table* tb2 = new Table(*tbc, "test2", "test");
	//tb->example.display();
	cout << tb->example.length << endl;
	cout << endl;

	//test insert
	vector<string> v;
	v.push_back("10");
	v.push_back("\'F\'");
	v.push_back("10");
	vector<string> ab;
	ab.push_back("8");
	ab.push_back("\'F\'");
	ab.push_back("2");
	vector<string> abc;
	abc.push_back("7");
	abc.push_back("\'M\'");
	abc.push_back("3");
	vector<vector<string> > vv;
	vv.push_back(v);
	vv.push_back(ab);
	vv.push_back(abc);
	vector<string> l;
	// for (int i = 0;i < 10; i++)
		tb->insert(n, vv);
		tb2->insert(n, vv);
	tb->showTB(1);


	vector<Table*> tt;
	tt.push_back(tb2);

	// //test update
	string tableName = "test";
	CondSql cond;
	vector<CondItem> set;

	AttrItem item1("", "test2_xuhan");
	AttrItem item2("", "");
	Expression expr;
	expr.value = 10;
	CondItem conditem("=", item1, item2, expr);

	AttrItem item3("", "test2_xuhan");
	Expression expr1;
	//expr1.value = 8;
	AttrItem item4("", "dhy");
	CondItem condi("=", item3, item4, expr1);

	cond.conditions.push_back(conditem);
	set.push_back(condi);

	cout << endl;
	tb->update(set, cond, tt);
	tb->showTB(1);
	//cout << tb->conform(cond, 1, 0) << endl << endl;
	//cout << tb->conform(cond, 1, 1) << endl;
	//cout << tb->conform(cond, 1, 2) << endl;


	// //test select
	vector<AttrItem> attrs;
	vector<string> tables;
	CondSql cond1;

	AttrItem item11("", "test2_xuhan");
	AttrItem item22("test2", "test2_xuhan");
	Expression expr11;
	//expr11.str = "\'%a%b%\'";
	CondItem conditem1("=", item11, item22, expr11);

	cond1.conditions.push_back(conditem1);
	AttrItem item12("test2", "dhy");
	AttrItem item13("", "test2_xuhan");
	attrs.push_back(item12);
	attrs.push_back(item13);
	tables.push_back("test");
	vector<string> op;
	// op.push_back("sum");
	// op.push_back("avg");
	// op.push_back("max");
	// op.push_back("min");
	vector<string> attrID;
	// attrID.push_back("xuhan");
	// attrID.push_back("xuhan");
	// attrID.push_back("xuhan");
	// attrID.push_back("xuhan");
	tb->select(attrs, cond1, op, attrID, "", tt);
	//cout << tb->conform(cond1, 1, 0) << endl;
}