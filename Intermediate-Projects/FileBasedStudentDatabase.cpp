// Project: File-Based Student Database
// Language: C++
// Description: Save student records to a file and display them.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    int choice;

    do {
        cout << "\n--- Student Database ---\n";
        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        if (choice == 1) {
            int id;
            string name;
            double gpa;

            cout << "Student ID: ";
            cin >> id;

            cout << "Student name: ";
            cin >> ws;
            getline(cin, name);

            cout << "GPA: ";
            cin >> gpa;

            if (gpa < 0 || gpa > 4.0) {
                cout << "Invalid GPA. Use a value from 0 to 4.\n";
                continue;
            }

            ofstream file("students.txt", ios::app);

            if (!file.is_open()) {
                cout << "Could not open file.\n";
                continue;
            }

            file << id << "|" << name << "|" << gpa << "\n";
            file.close();

            cout << "Student saved successfully.\n";
        } else if (choice == 2) {
            ifstream file("students.txt");
            string line;

            if (!file.is_open()) {
                cout << "No student records found yet.\n";
                continue;
            }

            cout << "\n--- Saved Students ---\n";

            while (getline(file, line)) {
                cout << line << "\n";
            }

            file.close();
        }

    } while (choice != 3);

    return 0;
}
