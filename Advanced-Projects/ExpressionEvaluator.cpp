// Project: Arithmetic Expression Evaluator
// Language: C++
// Description: Evaluate a basic expression with two numbers.

#include <iostream>
using namespace std;

int main() {
    double a, b;
    char op;

    cout << "Enter an expression (example: 12 + 5): ";
    cin >> a >> op >> b;

    switch (op) {
        case '+':
            cout << "Result: " << a + b << "\n";
            break;

        case '-':
            cout << "Result: " << a - b << "\n";
            break;

        case '*':
            cout << "Result: " << a * b << "\n";
            break;

        case '/':
            if (b == 0) {
                cout << "Error: Division by zero.\n";
            } else {
                cout << "Result: " << a / b << "\n";
            }
            break;

        default:
            cout << "Unsupported operator.\n";
    }

    return 0;
}
