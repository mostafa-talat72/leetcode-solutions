/* Write your PL/SQL query statement below */
select e.name
from Employee e
inner join Employee m
on e.id = m.managerId
group by e.name,e.id
having count(m.managerId) >= 5;