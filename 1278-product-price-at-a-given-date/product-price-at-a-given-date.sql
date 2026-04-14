# Write your MySQL query statement below
WITH t1 as
(SELECT * ,
row_number() over(partition by product_id order by change_date desc) as rank1
from Products
where change_date <= '2019-08-16')

, t2 as
(SELECT distinct product_id as p2,
10 as price
from Products
)

-- SELECT product_id,
-- max(price) as price
-- from
-- (SELECT product_id , new_price as price
-- from t1
-- where rank1 =1
-- UNION ALL 
-- SELECT * from t2)t
-- group by product_id



SELECT p2 as `product_id`,price_n as `price`
from(SELECT *,
case 
    when new_price IS NULL then 10
    else new_price
end price_n,
case 
    when rank1 IS NULL then 1
    else rank1
end rank2      
from 
(SELECT * from t1
right join t2 on t1.product_id = t2.p2
order by change_date desc)t)tt
where rank2 = 1
;