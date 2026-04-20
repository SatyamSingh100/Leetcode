# Write your MySQL query statement below
WITH c1 as
(SELECT *
from(SELECT *,
row_number() over(partition by customer_id order by order_date) as rank1
from Delivery as d)t
where rank1 = 1)

SELECT
ROUND((SELECT count(*) from c1 where order_date = customer_pref_delivery_date)*100.0/((SELECT count(*) from c1)), 2)
as immediate_percentage;