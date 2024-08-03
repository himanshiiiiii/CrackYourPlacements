# Write your MySQL query statement below


SELECT query_name,  ROUND(AVG(rating/position),2) as quality, 
ROUND((SUM(IF(rating < 3, 1, 0)) / COUNT(*)) * 100, 2) as poor_query_percentage
FROM Queries 
where query_name IS NOT NULL
GROUP BY query_name;