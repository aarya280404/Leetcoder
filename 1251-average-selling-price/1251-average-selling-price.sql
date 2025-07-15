# Write your MySQL query statement below

# wrong select p.product_id, ROUND(sum((p.price * u.units))/sum(u.units),2) as average_price from prices p, unitsSold u group by p.product_id

SELECT P.product_id,ifnull(ROUND((SUM(P.price * US.units * 1.00)/SUM(US.units * 1.00)),2),0) AS average_price
FROM Prices P
LEFT JOIN UnitsSold US
ON P.product_id=US.product_id AND (US.purchase_date BETWEEN P.start_date AND P.end_date)
GROUP BY P.product_id;