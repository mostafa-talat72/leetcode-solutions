/* Write your PL/SQL query statement below */
select w.id
from Weather w
inner join Weather w1
on w.recordDate = w1.recordDate + 1
where w.temperature > w1.temperature;