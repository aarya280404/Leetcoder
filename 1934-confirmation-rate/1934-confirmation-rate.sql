# Write your MySQL query statement below
#select @cnt:= count(*) from confirmations where action='confirmed' group by user_id;
select s.user_id,ROUND(ifnull(avg(action='confirmed'),0),2) as confirmation_rate from signups s left join confirmations c on s.user_id = c.user_id group by s.user_id

