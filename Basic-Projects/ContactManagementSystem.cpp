// Project: Contact Management System
// Language: C++
// Description: Add, view, and search contacts.

#include <iostream>
#include <vector>
using namespace std;

struct Contact {
    string name;
    string phone;
};

int main() {
    vector<Contact> contacts;
    int choice;

    do {
        cout << "\n--- Contact Management ---\n";
        cout << "1. Add Contact\n";
        cout << "2. View Contacts\n";
        cout << "3. Search Contact\n";
        cout << "4. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        if (choice == 1) {
            Contact c;

            cout << "Enter name: ";
            cin >> ws;
            getline(cin, c.name);

            cout << "Enter phone: ";
            getline(cin, c.phone);

            contacts.push_back(c);
            cout << "Contact saved.\n";
        } else if (choice == 2) {
            for (const Contact &c : contacts) {
                cout << c.name << " - " << c.phone << "\n";
            }
        } else if (choice == 3) {
            string searchName;
            bool found = false;

            cout << "Enter name to search: ";
            cin >> ws;
            getline(cin, searchName);

            for (const Contact &c : contacts) {
                if (c.name == searchName) {
                    cout << c.name << " - " << c.phone << "\n";
                    found = true;
                }
            }

            if (!found) {
                cout << "Contact not found.\n";
            }
        }

    } while (choice != 4);

    return 0;
}
