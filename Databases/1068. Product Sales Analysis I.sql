# Write your MySQL query statement below
SELECT P.product_name, S.year, S.price 
FROM Sales S 
JOIN Product P ON S.product_id = P.product_id ORDER BY S.sale_id;
