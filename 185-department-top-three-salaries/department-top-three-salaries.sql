# Write your MySQL query statement below
SELECT name2 as Department, name1 as Employee, salary as Salary 
from
(SELECT a.name as name1, b.name as name2,a.id as id1 ,a.salary,a.departmentId,b.id as id2, 
dense_rank() over(partition by a.departmentId order by a.salary desc) as rank1
from Employee as a
join Department as b on a.departmentId = b.id)t
where rank1 <= 3
;