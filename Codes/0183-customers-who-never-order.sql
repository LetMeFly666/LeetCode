-- # Error
-- select
--     c.Name as Customers
-- from
--     Customers c,
--     Orders o
-- where
--     c.id not in o.id

select
    Customers.Name as Customers
from
    Customers
where
    Customers.id not in (
        select
            CustomerId
        from
            Orders
    )
