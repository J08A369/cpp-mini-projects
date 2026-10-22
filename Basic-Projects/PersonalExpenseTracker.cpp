// Project: Personal Expense Tracker
// Language: C++
// Description: Record expenses and calculate total spending.

#include <iostream>
#include <vector>
using namespace std;

struct Expense {
    string category;
    double amount;
};

int main() {
    vector<Expense> expenses;
    int choice;

    do {
        cout << "\n--- Expense Tracker ---\n";
        cout << "1. Add Expense\n";
        cout << "2. View Expenses\n";
        cout << "3. Show Total\n";
        cout << "4. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        if (choice == 1) {
            Expense e;

            cout << "Category: ";
            cin >> ws;
            getline(cin, e.category);

            cout << "Amount (BDT): ";
            cin >> e.amount;

            if (e.amount < 0) {
                cout << "Amount cannot be negative.\n";
            } else {
                expenses.push_back(e);
                cout << "Expense recorded.\n";
            }
        } else if (choice == 2) {
            for (const Expense &e : expenses) {
                cout << e.category << ": " << e.amount << " BDT\n";
            }
        } else if (choice == 3) {
            double total = 0;

            for (const Expense &e : expenses) {
                total += e.amount;
            }

            cout << "Total expenses: " << total << " BDT\n";
        }

    } while (choice != 4);

    return 0;
}
