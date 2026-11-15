// Smart Banking Transaction System
#include <iostream>
#include <vector>
using namespace std;

class BankAccount {
private:
    double balance;
    vector<string> history;

public:
    BankAccount(double initial) : balance(initial) {}

    void deposit(double amount) {
        if (amount <= 0) return;
        balance += amount;
        history.push_back("Deposit: +" + to_string(amount));
    }

    void withdraw(double amount) {
        if (amount <= 0 || amount > balance) {
            cout << "Transaction declined.\n";
            return;
        }
        balance -= amount;
        history.push_back("Withdrawal: -" + to_string(amount));
    }

    void showBalance() const {
        cout << "Current Balance: " << balance << '\n';
    }

    void showHistory() const {
        for (const auto& item : history)
            cout << item << '\n';
    }
};

int main() {
    BankAccount account(5000);

    account.deposit(2000);
    account.withdraw(1500);
    account.showBalance();

    cout << "\nTransaction History:\n";
    account.showHistory();

    return 0;
}
