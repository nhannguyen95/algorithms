-- Left join
SELECT Name AS Customers
FROM Customers LEFT JOIN Orders
ON Customers.Id = Orders.CustomerId
WHERE CustomerId IS NULL;

-- Subquery
SELECT Name AS Customers
FROM Customers
WHERE Id NOT IN
(
    SELECT DISTINCT CustomerId
    FROM Orders
);
