# Write your MySQL query statement below
WITH c1 as
(SELECT requester_id  as id1,
count(*) as cnt1
from RequestAccepted as f
group by requester_id)

, c2 as
(SELECT accepter_id as id1,
count(*) as cnt1
from RequestAccepted as f
group by accepter_id)


,c3 AS 
(SELECT id1,Sum(cnt1) as cnt
from
(SELECT *
from c1
union all 
SELECT * from c2)t
group by id1)

SELECT id1 as id, cnt as num
from c3
order by cnt desc limit 1
;