create database BankingSystem
-- جدول العملاء
CREATE TABLE Customers (
    CustomerID INT PRIMARY KEY,
    Name VARCHAR(50),
    Phone VARCHAR(20),
    Email VARCHAR(50)
);

-- جدول الحسابات
CREATE TABLE Accounts (
    AccountID INT PRIMARY KEY,
    CustomerID INT,
    Balance DECIMAL(10,2),
    AccountType VARCHAR(20),
    FOREIGN KEY (CustomerID) REFERENCES Customers(CustomerID)
);

-- جدول العمليات
CREATE TABLE Transactions (
    TransactionID INT PRIMARY KEY,
    AccountID INT,
    Type VARCHAR(20), -- Deposit / Withdrawal
    Amount DECIMAL(10,2),
    Date DATE,
    FOREIGN KEY (AccountID) REFERENCES Accounts(AccountID)
);
-- إدخال عملاء