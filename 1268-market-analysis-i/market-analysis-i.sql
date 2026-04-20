# Write your MySQL query statement below
WITH c1 as
(SELECT buyer_id,Count(*) as orders
from Orders 
where YEAR(order_date) = 2019
group by buyer_id )


SELECT user_id as `buyer_id`,join_date, coalesce(orders,0) as orders_in_2019
from Users as a
left join c1 as b on a.user_id = b.buyer_id
;