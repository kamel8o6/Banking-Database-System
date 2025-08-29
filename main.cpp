#include <iostream>
#include <vector>
#include <string>
using namespace std;

// هيكل العميل
struct Customer {
    int id;
    string name;
    string phone;
    string email;
};

// هيكل الحساب
struct Account {
    int accountId;
    int customerId;
    double balance;
    string type; // Savings / Current
};

// هيكل العملية
struct Transaction {
    int transactionId;
    int accountId;
    string type; // Deposit / Withdrawal
    double amount;
    string date;
};

// بيانات تجريبية
vector<Customer> customers = {
    {1, "Ahmed Ali", "01012345678", "ahmed@email.com"},
    {2, "Sara Mohamed", "01198765432", "sara@email.com"}
};

vector<Account> accounts = {
    {101, 1, 5000.0, "Savings"},
    {102, 2, 3000.0, "Current"}
};

vector<Transaction> transactions;

// دوال مساعدة
void showBalance(int customerId) {
    for (auto &acc : accounts) {
        if (acc.customerId == customerId) {
            cout << "Account ID: " << acc.accountId
                 << " | Balance: " << acc.balance << endl;
        }
    }
}

void deposit(int accountId, double amount, string date) {
    for (auto &acc : accounts) {
        if (acc.accountId == accountId) {
            acc.balance += amount;
            transactions.push_back({(int)transactions.size() + 1001, accountId, "Deposit", amount, date});
            cout << "Deposit successful! New Balance: " << acc.balance << endl;
            return;
        }
    }
    cout << "Account not found!" << endl;
}

void withdraw(int accountId, double amount, string date) {
    for (auto &acc : accounts) {
        if (acc.accountId == accountId) {
            if (acc.balance >= amount) {
                acc.balance -= amount;
                transactions.push_back({(int)transactions.size() + 1001, accountId, "Withdrawal", amount, date});
                cout << "Withdrawal successful! New Balance: " << acc.balance << endl;
            } else {
                cout << "Insufficient balance!" << endl;
            }
            return;
        }
    }
    cout << "Account not found!" << endl;
}

void showTransactions(int customerId) {
    for (auto &acc : accounts) {
        if (acc.customerId == customerId) {
            cout << "Transactions for Account " << acc.accountId << ":\n";
            for (auto &t : transactions) {
                if (t.accountId == acc.accountId) {
                    cout << t.type << " | Amount: " << t.amount
                         << " | Date: " << t.date << endl;
                }
            }
        }
    }
}

int main() {
    int choice;
    do {
        cout << "\n===== Banking System Menu =====\n";
        cout << "1. Show Customer Balance\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Show Transactions\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int customerId;
            cout << "Enter Customer ID: ";
            cin >> customerId;
            showBalance(customerId);
        } else if (choice == 2) {
            int accountId;
            double amount;
            string date;
            cout << "Enter Account ID: ";
            cin >> accountId;
            cout << "Enter Amount: ";
            cin >> amount;
            cout << "Enter Date (YYYY-MM-DD): ";
            cin >> date;
            deposit(accountId, amount, date);
        } else if (choice == 3) {
            int accountId;
            double amount;
            string date;
            cout << "Enter Account ID: ";
            cin >> accountId;
            cout << "Enter Amount: ";
            cin >> amount;
            cout << "Enter Date (YYYY-MM-DD): ";
            cin >> date;
            withdraw(accountId, amount, date);
        } else if (choice == 4) {
            int customerId;
            cout << "Enter Customer ID: ";
            cin >> customerId;
            showTransactions(customerId);
        }

    } while (choice != 0);

    cout << "Exiting program..." << endl;
    return 0;
}
