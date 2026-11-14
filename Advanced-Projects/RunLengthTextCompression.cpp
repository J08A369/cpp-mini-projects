// Project: Run-Length Text Compression
// Language: C++
// Description: Compress repeated characters in a string.

#include <iostream>
using namespace std;

int main() {
    string text;

    cout << "Enter text without spaces: ";
    cin >> text;

    if (text.empty()) {
        cout << "No text entered.\n";
        return 0;
    }

    string compressed = "";
    int count = 1;

    for (int i = 1; i <= (int)text.length(); i++) {
        if (i < (int)text.length() && text[i] == text[i - 1]) {
            count++;
        } else {
            compressed += text[i - 1];
            compressed += to_string(count);
            count = 1;
        }
    }

    cout << "Original text: " << text << "\n";
    cout << "Compressed text: " << compressed << "\n";

    return 0;
}
