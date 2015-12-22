use test;
drop table if exists test1;
drop table if exists test2;
create table if not exists test1(
	id int not null auto_increment,
	name text not null,
	primary key(id));

create table if not exists test2(
	id int not null,
	id1 int not null auto_increment,
		class text not null,
	primary key(id1));

-- insert sql
insert into test1(name) values('str1');
insert into test1(name) values('str2');
insert into test1(name) values('str3');
insert into test1(name) values('str4');
insert into test1(name) values('str5');
insert into test2(id, class) values(5, 'str5');
insert into test2(id, class) values(4, 'str4');
insert into test2(id, class) values(3, 'str3');
insert into test2(id, class) values(2, 'str2');
insert into test2(id, class) values(1, 'str1');
	-- insert into test2 values (...) -- taken as into test2(attr1, attr2, ...)

-- select sql, expression only support int, maybe worthy to try support string add
select * from test2 where id>3 and class>'str4';
select * from test2 where id=1+1 and class<'str6';
select * from test2 where id=1+1+1 and class<'str6';

select * from test1 inner join test2;	-- 5*5
select * from test1 inner join test2 on test1.id = test2.id1;	-- 5
select * from test1 inner join test2 on test1.id = test2.id;	-- 5
select * from test1 right outer join test2 on test1.id = test2.id;	-- test1
select * from test1 left outer join test2 on test1.id = test2.id;	-- test2
select * from test1 right join test2 on test1.id = test2.id;		-- test1
select * from test1 left join test2 on test1.id = test2.id;			-- test2
select * from test1 inner join test2 on test1.id = test2.id where test1.name = 'str1';
select * from test1 right outer join test2 on test1.id = test2.id where test1.name = 'str1';
select * from test1 left outer join test2 on test1.id = test2.id where test1.name = 'str1';
select * from test1 right join test2 on test1.id = test2.id where test1.name = 'str1';
select * from test1 left join test2 on test1.id = test2.id where test1.name = 'str1';

-- delete sql
delete from test2 where id>3 and class>'str4';
delete from test2 where id=1+1 and class<'str6';
delete from test2 where id=1+1+1 and class<'str6';

-- update sql
update test2 set id = 1;	-- set all id to 1
update test2 set id = id + 1;
update test2 set id = 1001 where id1 = 1;
update test2 set id = 1001 where id1 > 3;

