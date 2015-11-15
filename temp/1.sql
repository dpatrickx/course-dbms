create database if not exists test;
use test;
drop table if exists xuhan;
create table xuhan(
	id int not null auto_increment,
	name text not null,
	con text not null,
	primary key(id));

delimiter $$
drop procedure  if exists wk;
create procedure wk()
begin
declare i int;
declare str1 text;
declare str2 text;
declare temp text;
set i = 1;
while i < 10000 do
	set str1 = concat('son', i);
	set str2 = concat('i am ', i);
	set str2 = concat(str2, ' son of xuhan');
	insert into xuhan (name, con) values (str1, str2);
	set i = i +1;
end while;
end $$

delimiter ;
call wk();