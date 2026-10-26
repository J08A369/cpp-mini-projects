// Project: File Word Search
// Language: C++
// Description: Search for a word in a text file.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string filename, target, line;
    int lineNumber = 0;
    bool found = false;

    cout << "Enter filename: ";
    cin >> filename;

    cout << "Enter word to search: ";
    cin >> target;

    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Could not open file.\n";
        return 0;
    }

    while (getline(file, line)) {
        lineNumber++;

        if (line.find(target) != string::npos) {
            cout << "Found on line " << lineNumber
                 << ": " << line << "\n";
            found = true;
        }
    }

    file.close();

    if (!found) {
        cout << "Word not found.\n";
    }

    return 0;
}
