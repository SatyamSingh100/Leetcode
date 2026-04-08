# Write your MySQL query statement below
SELECT max(salary)  as SecondHighestSalary
from
(SELECT *,max(salary) over() as maxi
from Employee)t
where salary != maxi
;