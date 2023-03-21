-- Error -- select customer_number from Orders order by order_number desc limit 1;

-- Error -- select customer_number from Orders order by count(*) desc group by customer_number limit 1;

select customer_number from Orders group by customer_number order by count(*) desc limit 1;