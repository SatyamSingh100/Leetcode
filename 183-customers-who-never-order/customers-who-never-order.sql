# Write your MySQL query statement below
SELECT a.name as `Customers`
from Customers as a
LEFT join Orders as b on a.id = b.customerId
where b.id IS NULL
;