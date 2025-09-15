# Write your MySQL query statement below
select p.project_id,ROUND(avg(e.experience_years),2) as average_years from project p right join employee e on p.employee_id=e.employee_id group by project_id 
#select p.project_id, round(avg(e.experience_years),2) as average_years from employee e left join project p on e.employee_id=p.employee_id group by project_id