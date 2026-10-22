// Password Strength Analyzer
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string password;
    bool upper = false, lower = false;
    bool digit = false, symbol = false;

    cout << "Enter a sample password: ";
    cin >> password;

    for (unsigned char c : password) {
        if (isupper(c)) upper = true;
        else if (islower(c)) lower = true;
        else if (isdigit(c)) digit = true;
        else symbol = true;
    }

    int score = (password.size() >= 12)
              + upper + lower + digit + symbol;

    cout << "\n=== PASSWORD ANALYSIS ===\n";
    cout << "Length: " << password.size() << '\n';
    cout << "Uppercase: " << (upper ? "Yes" : "No") << '\n';
    cout << "Lowercase: " << (lower ? "Yes" : "No") << '\n';
    cout << "Number: " << (digit ? "Yes" : "No") << '\n';
    cout << "Symbol: " << (symbol ? "Yes" : "No") << '\n';
    cout << "Strength Score: " << score << "/5\n";

    return 0;
}
