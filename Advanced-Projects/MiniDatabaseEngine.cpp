// Project: Mini Database Engine
// Language: C++
// Description: Store and search simple records in memory.

#include <iostream>
#include <vector>
using namespace std;

struct Record {
    int id;
    string name;
    string department;
};

int main() {
    vector<Record> database;
    int choice;

    do {
        cout << "\n--- Mini Database ---\n";
        cout << "1. Insert Record\n";
        cout << "2. View All Records\n";
        cout << "3. Search by ID\n";
        cout << "4. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        if (choice == 1) {
            Record r;
            bool duplicate = false;

            cout << "Enter ID: ";
            cin >> r.id;

            for (const Record &item : database) {
                if (item.id == r.id) {
                    duplicate = true;
                    break;
                }
            }

            if (duplicate) {
                cout << "ID already exists.\n";
            } else {
                cout << "Enter name: ";
                cin >> ws;
                getline(cin, r.name);

                cout << "Enter department: ";
                getline(cin, r.department);

                database.push_back(r);
                cout << "Record inserted.\n";
            }
        } else if (choice == 2) {
            for (const Record &r : database) {
                cout << r.id << " | " << r.name
                     << " | " << r.department << "\n";
            }
        } else if (choice == 3) {
            int searchID;
            bool found = false;

            cout << "Enter ID: ";
            cin >> searchID;

            for (const Record &r : database) {
                if (r.id == searchID) {
                    cout << r.id << " | " << r.name
                         << " | " << r.department << "\n";
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Record not found.\n";
            }
        }

    } while (choice != 4);

    return 0;
}
