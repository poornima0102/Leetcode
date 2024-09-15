# Write your MySQL query statement below
select eU.unique_id,e.name from Employees as e
left join EmployeeUNI as eU on e.id=eU.id

-- select eU.unique_id,e.name from EmployeeUNI as eU
-- Right join Employees as e on e.id=eU.id