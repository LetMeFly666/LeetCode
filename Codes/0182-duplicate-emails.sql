# Write your MySQL query statement below

-- # 方法一
-- select
--     distinct p1.Email as Email
-- from
--     Person p1,
--     Person p2
-- where
--     p1.Email = p2.Email
--     and p1.id != p2.id


-- # 方法二
-- select 
--     Email
-- from (
--     select
--         Email, count(Email) as cnt
--     from
--         Person
--     group by
--         Email
-- ) as temp  # 必须写as xx
-- where
--     cnt > 1


# 方法三
select
    Email
from
    Person
group by
    Email
having
    count(Email) > 1
