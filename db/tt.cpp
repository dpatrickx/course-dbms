// create table table1 (id int not null, str varchar(10) not null, primary key(id));
string name = "table1";
TableCon con;
con.name.push_back("id");
con.name.push_back("str");
con.type.push_back("INT");
con.type.push_back("VARCHAR");
con.notNull.push_back(true);
con.notNull.push_back(true);
con.length.push_back(4);
con.length.push_back(10);
con.priKey = "id";
// insert into table1(attrInt, attrStr) values (9, "hello"), (10, "world");
vector<string> tableitems;
vector<vector<string> > valueSqls;
tableitems.push_back("id");
tableitems.push_back("str");
vector<string> temp;
temp.push_back("9");
temp.push_back("hello");
valueSqls.push_back(temp);
vector<string> temp1;
temp1.push_back("10");
temp1.push_back("world");
valueSqls.push_back(temp1);

// select str from table1 where str = 'hello';
vector<AttrItem> attrs;
vector<string> tables;
CondSql cond;

AttrItem item1("", "str");
AttrItem item2("", "");
Expression expr;
expr.str = "hello";
CondItem conditem("=", item1, item2, expr);

cond.conditions.push_back(conditem);
attrs.push_back(item1);
tables.push_back("table1");

// select str from table1 where str = 'hell';
vector<AttrItem> attrs;
vector<string> tables;
CondSql cond;

AttrItem item1("", "str");
AttrItem item2("", "");
Expression expr;
expr.str = "hell";
CondItem conditem("=", item1, item2, expr);

cond.conditions.push_back(conditem);
attrs.push_back(item1);
tables.push_back("table1");

// update table1 set str = 'hhh' where id = 10;
string tableName = "table1";
CondSql cond;
vector<CondItem> set;

AttrItem item1("", "id");
AttrItem item2("", "");
Expression expr;
expr.value = 10;
CondItem conditem("=", item1, item2, expr);

AttrItem item3("", "str");
Expression expr1;
expr1.str = "hhh";
Conditem condi("=", item3, item2, expr1);

cond.conditions.push_back(conditem);
set.push_back(condi);

// delete from table1 where id = 9;
string tableName = "table1";
CondSql cond;

AttrItem item1("", "id");
AttrItem item2("", "");
Expression expr;
expr.value = 9;
CondItem conditem("=", item1, item2, expr);

cond.conditions.push_back(conditem);
