# Write your MySQL query statement below

# FirstTry：理解错了，不是managerId为空就说明不是manager。managerId是这个人的经理
-- select 
--     distinct(staff.name) as Employee
-- from
--     Employee staff,
--     Employee manager
-- where
--     staff.managerId is Null
--     and manager.managerId is not Null
--     and staff.salary > manager.salary;

# SecondTry：方法一 where
-- select
--     staff.name as Employee
-- from
--     Employee staff,
--     Employee manager
-- where
--     staff.managerId = manager.id
--     and staff.salary > manager.salary

# ThirdTry：方法二 join
select
    staff.name as Employee
from
    Employee staff
join
    Employee manager
on
    staff.managerId = manager.id
    and staff.salary > manager.salary