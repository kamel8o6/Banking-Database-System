INSERT INTO Customers VALUES (1, 'Ahmed Ali', '0101235678', 'ahmed@email.com');
INSERT INTO Customers VALUES (2, 'Sara Mohamed', '0119765432', 'sara@email.com');
INSERT INTO Customers VALUES (3, 'Omar Hassan', '0124567890', 'omar@email.com');

-- إدخال حسابات
INSERT INTO Accounts VALUES (101, 1, 5000.00, 'Savings');
INSERT INTO Accounts VALUES (102, 2, 3000.00, 'Current');
INSERT INTO Accounts VALUES (103, 3, 7000.00, 'Savings');

-- إدخال عمليات
INSERT INTO Transactions VALUES (1001, 101, 'Deposit', 2000.00, '2025-08-01');
INSERT INTO Transactions VALUES (1002, 101, 'Withdrawal', 500.00, '2025-08-05');
INSERT INTO Transactions VALUES (1003, 102, 'Deposit', 1500.00, '2025-08-02');
INSERT INTO Transactions VALUES (1004, 103, 'Withdrawal', 2000.00, '2025-08-03');
--إجمالي الرصيد لكل عميل