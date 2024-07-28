# Write your MySQL query statement below

SELECT e1.name 
FROM Employee AS e1
INNER JOIN Employee AS e2
ON e1.id = e2.managerId
GROUP BY e1.id, e1.name
HAVING COUNT(e2.managerId) >= 5;