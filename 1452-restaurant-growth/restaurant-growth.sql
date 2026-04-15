# Write your MySQL query statement below
WITH c1 as
(SELECT *,
sum(amount) as sum1
from Customer
group by visited_on
order by visited_on)

SELECT visited_on, total_sum as `amount`,
ROUND((total_sum*100.0/(7*100.0)),2) as average_amount
from
(SELECT *,
SUM(sum1) over(order by visited_on rows between 6 preceding and current row) as total_sum,
lag(sum1,6) over() as is_Valid
from c1)t
where is_Valid IS NOT NULL
;