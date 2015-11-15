use test;

delimiter $$
drop procedure  if exists wk;
create procedure wk()
begin
declare i int;
declare str1 text;
declare str2 text;
declare str3 text;
set i = 1;
while i < 10000 do
	set str2 = concat('laozi jiushi xuhan de baba', i);
	set str3 = concat('xuhan de dad ', i);
	select name into str1 from xuhan where id = i;
	select str1;
	update xuhan set name = str2, con = str3 where name = str1;
	set i = i+1;
end while;
end $$

delimiter ;
call wk();