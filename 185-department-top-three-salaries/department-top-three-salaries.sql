select Department,Employee,Salary as Salary
from(select d.name as Department,e.name as Employee,salary,
dense_rank() over(partition by d.name order by salary desc) as rrr
from employee as e
join department as d on e.departmentId=d.id)t
where rrr<=3
;
