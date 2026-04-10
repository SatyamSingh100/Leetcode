# Write your MySQL query statement below
SELECT Department,Employee, Salary
from
(SELECT a.id as id1, a.name as Employee, a.salary as Salary, departmentID ,b.id as id2,b.name as Department,
rank() over(partition by b.id order by a.salary desc) as rank1
from Employee as a
join Department as b on a.departmentId = b.id)t
where rank1 =1
;