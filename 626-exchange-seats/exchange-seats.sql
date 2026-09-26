# Write your MySQL query statement below
with cte1 as 
(SELECT *,
count(id) over() as total_count,
lead(student) over() as next_student,
lag(student) over() as prev_student,
row_number() over() as rank1
from Seat)

SELECT id, 
case 
    when rank1 = total_count AND rank1 % 2 = 1 then student
    when rank1 % 2 = 1 then next_student
    else prev_student
end as student
from cte1;    
