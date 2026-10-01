# Write your MySQL query statement below
SELECT "Low Salary" as category,
count(*) as accounts_count
from Accounts 
where income < 20000
UNION ALL
SELECT "Average Salary" as category,
count(*) as accounts_count
from Accounts 
where income >= 20000 AND income <= 50000
UNION ALL
SELECT "High Salary" as category,
count(*) as accounts_count
from Accounts 
where income > 50000
;