// Project: ATM Simulation
// Language: C++
// Description: Simulate basic ATM operations.

#include <iostream>
using namespace std;

int main() {
    double balance = 5000.0;
    double amount;
    int choice;

    do {
        cout << "\n--- ATM Machine ---\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Current balance: " << balance << " BDT\n";
        } else if (choice == 2) {
            cout << "Enter deposit amount: ";
            cin >> amount;

            if (amount > 0) {
                balance += amount;
                cout << "Deposit successful.\n";
            } else {
                cout << "Invalid amount.\n";
            }
        } else if (choice == 3) {
            cout << "Enter withdrawal amount: ";
            cin >> amount;

            if (amount <= 0) {
                cout << "Invalid amount.\n";
            } else if (amount > balance) {
                cout << "Insufficient balance.\n";
            } else {
                balance -= amount;
                cout << "Please collect your money.\n";
            }
        }

    } while (choice != 4);

    return 0;
}
