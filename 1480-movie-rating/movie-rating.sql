# Write your MySQL query statement below
(SELECT Users.name as results
from MovieRating
join Users on MovieRating.user_id = Users.user_id
group by MovieRating.user_id
order by COUNT(*) desc,name asc
limit 1)
UNION ALL
(SELECT Movies.title as results
from MovieRating
join Movies on MovieRating.movie_id = Movies.movie_id
where DATE_FORMAT(created_at, '%Y-%m') = '2020-02'
group by MovieRating.movie_id
order by ROUND(AVG(rating),2) desc,title asc
limit 1)
;