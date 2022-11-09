
select
    Department.name as Department,
    Employee.name as Employee,
    Employee.salary as Salary
from
    Employee join Department
    on Employee.departmentId = Department.id
where
    (Employee.departmentId, Employee.salary)
    in (
        select
            departmentId, MAX(salary)
        from
            Employee
        group by
            departmentId
    )
;
