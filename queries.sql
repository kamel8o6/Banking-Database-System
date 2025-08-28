SELECT c.Name, SUM(a.Balance) AS TotalBalance
FROM Customers c
JOIN Accounts a ON c.CustomerID = a.CustomerID
GROUP BY c.Name;
--كشف حساب لعميل
SELECT t.TransactionID, t.Type, t.Amount, t.Date
FROM Transactions t
JOIN Accounts a ON t.AccountID = a.AccountID
WHERE a.CustomerID = 1;

SELECT Type, SUM(Amount) AS Total
FROM Transactions
GROUP BY Type;

SELECT c.Name, SUM(a.Balance) AS TotalBalance
FROM Customers c
JOIN Accounts a ON c.CustomerID = a.CustomerID
GROUP BY c.Name
ORDER BY TotalBalance DESC;
