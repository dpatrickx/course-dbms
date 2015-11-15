use test;

delimiter $$
drop procedure  if exists wk;
create procedure wk()
begin
declare i int;
declare temp int;
declare str1 text;
declare str2 text;
set i = 1;
while i < 100000 do
	set temp = i*i;
	set str1 = concat('dad', temp);
	set str2 = concat('i am ', temp);
	set str2 = concat(str2, ' dad of xuhan, xuhan is my son');
	update xuhan set name = str1, con = str2 where id = i;
	set i = i +1;
end while;
end $$

delimiter ;
call wk();