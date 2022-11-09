# Write your MySQL query statement below

SELECT
    w1.id
from
    Weather w1,
    Weather w2
where
    -- w1.recordDate = w2.recordDate + 1
    DATEDIFF(w1.recordDate, w2.recordDate) = 1
    and w1.Temperature > w2.Temperature
;
