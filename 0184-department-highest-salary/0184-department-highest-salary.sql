# Write your MySQL query statement below
select d.name as Department,e.name as Employee,e.salary as Salary
from Employee e
join Department d
on e.departmentId=d.id 
WHERE e.salary = (
    SELECT MAX(e2.salary)
    FROM Employee e2
    WHERE e2.departmentId = e.departmentId
);

