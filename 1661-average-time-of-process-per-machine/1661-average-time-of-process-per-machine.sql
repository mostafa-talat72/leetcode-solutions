/* Write your T-SQL query statement below */
select a.machine_id , ROUND(avg(a.timestamp - a1.timestamp), 3) as processing_time
from Activity a
inner join Activity a1
on a.machine_id = a1.machine_id
where a.activity_type = 'end' 
and a1.activity_type = 'start'
group by a.machine_id;