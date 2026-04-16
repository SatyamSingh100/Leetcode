# Write your MySQL query statement below
WITH c1 as
(SELECT *,
row_number() over(partition by student_id,subject  order by subject,exam_date) as first,
row_number() over(partition by student_id,subject  order by subject,exam_date desc) as last
from Scores)

,c2 as
(SELECT student_id, subject, score, exam_date 
from c1
where first = 1
UNION
SELECT student_id, subject, score, exam_date
from c1 
where last = 1)


SELECT a.student_id, a.subject , a.score as first_score, b.score as latest_score 
from c1 as a
join c1 as b on a.first = b.last
where (a.first = 1 AND a.student_id = b.student_id AND a.subject = b.subject AND a.exam_date < b.exam_date AND a.score < b.score)
;