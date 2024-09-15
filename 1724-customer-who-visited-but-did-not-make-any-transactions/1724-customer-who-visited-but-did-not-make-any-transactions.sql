# Write your MySQL query statement below

-- select visits.customer_id, count(visits.visit_id)as count_no_trans
--  from visits
--  where 
--  visit_id not in (select visit_id from transactions)
--  group by customer_id

SELECT 
    V.customer_id, 
    COUNT(V.visit_id) AS count_no_trans
FROM 
    Visits V
LEFT JOIN 
    Transactions T
ON 
    V.visit_id = T.visit_id
WHERE 
    T.transaction_id IS NULL
GROUP BY 
    V.customer_id;