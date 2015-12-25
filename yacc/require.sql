-- databaser sql
create database test;	-- yes CreateDbSql
drop database test;		-- yes DropDbSql
use database test;		-- yes UseDbSql
USE orderDB;
show database test;		-- yes ShowDbSql
-- table sql
drop table publisher;		-- yes DropTbSql
CREATE TABLE publisher (    -- yes CreateTbSql
  id int(10) NOT NULL,
  name varchar(100) NOT NULL,
  state varchar(2),
  PRIMARY KEY  (id)
);
CREATE TABLE book (
  id int(10) NOT NULL,
  title varchar(100) NOT NULL,
  authors varchar(200),
  publisher_id int(10) NOT NULL,
  copies int(10),
  pages int(10),
  PRIMARY KEY  (id)
);
show table publisher;		-- yes ShowTbSql
-- insert sql
INSERT INTO book(item1, item2) values     -- yes InsertSql
 (200001,'Marias Diary (Plus S.)','Mark P. O. Morford',100082,5991,2530),
 (200002,'Standing in the Shadows','Richard Bruce Wright',101787,2900,1860),
 (200003,'Children of the Thunder','Carlo DEste',102928,3447,2154),
 (200004,'The Great Gilly Hopkins','Gina Bari Kolata',101339,39,2809),
 (200005,'Meine Juden--eure Juden','E. J. W. Barber',103089,206,2771),
 (200006,'You Can Draw a Kangaroo','Amy Tan',101850,5296,2092);
insert into test2(id, class) values(5, 'str5');

-- select sql, expression only support int, maybe worthy to try support string add
select * from table1;   -- yes SelectSql
select * from table1 where id = 3 and class = 'hello';
select attr1, attr2 from table1 where id = 3 and class = 'hello';
select tb1.attr1, tb2.attr2 from tb1, tb2 where tb1.attr1 = tb2.attr1 and tb1.attr2 < tb2.attr2;
select * from table1 where attr is null;
select * from table1 where attr is not null;

-- delete sql
delete from test2 where id>3 and class>'str4';
delete from test2 where id=2 and class<'str6';
delete from test2 where id=1+1+1 and class<'str6';
delete from test2 where id=-1+1 and class<'str6';
delete from test2 where id=id+1 and class<'str6';

-- update sql
update test2 set id = 1 + 1;	-- set all id to 1
update test2 set id = id + 1;
update test2 set id = 2 * 3 where id1 = 1;
update test2 set id = 3+4*5 where id1 > 3;

