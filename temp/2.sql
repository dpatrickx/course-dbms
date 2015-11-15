use test;

delimiter $$
drop procedure  if exists wk;
create procedure wk()
begin
declare i int;
declare str1 text;
declare str2 text;
set i = 1;
while i < 100000 do
	set str1 = concat('dad', i);
	set str2 = concat('i am ', i);
	set str2 = concat(str2, ' dad of xuhan');
	update xuhan set name = str1, con = str2 where id  = i;
	set i = i +1;
end while;
end $$

delimiter ;
call wk();