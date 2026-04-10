# Write your MySQL query statement below
SELECT distinct num as ConsecutiveNums
from
(SELECT *,
LEAD(num) over() as next1,
LEAD(num,2) over() as next2
from Logs)t
where next1 = num AND next2 = next1
;