// Project: Bank Transaction History
// Language: C++
// Description: Track deposits and withdrawals.

#include <iostream>
#include <vector>
using namespace std;

struct Transaction {
    string type;
    double amount;
    double balanceAfter;
};

int main() {
    vector<Transaction> history;
    double balance = 1000;
    int choice;

    do {
        cout << "\n--- Bank Transaction History ---\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. View History\n";
        cout << "4. Check Balance\n";
        cout << "5. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        if (choice == 1 || choice == 2) {
            double amount;

            cout << "Enter amount: ";
            cin >> amount;

            if (amount <= 0) {
                cout << "Invalid amount.\n";
            } else if (choice == 2 && amount > balance) {
                cout << "Insufficient balance.\n";
            } else {
                if (choice == 1) {
                    balance += amount;
                    history.push_back({"Deposit", amount, balance});
                } else {
                    balance -= amount;
                    history.push_back({"Withdrawal", amount, balance});
                }

                cout << "Transaction successful.\n";
            }
        } else if (choice == 3) {
            for (const Transaction &t : history) {
                cout << t.type << ": " << t.amount
                     << " BDT | Balance: "
                     << t.balanceAfter << " BDT\n";
            }

            if (history.empty()) {
                cout << "No transactions yet.\n";
            }
        } else if (choice == 4) {
            cout << "Current balance: " << balance << " BDT\n";
        }

    } while (choice != 5);

    return 0;
}
