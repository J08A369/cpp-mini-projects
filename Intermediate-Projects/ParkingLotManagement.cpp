// Project: Parking Lot Management System
// Language: C++
// Description: Track parking slots and calculate parking fees.

#include <iostream>
using namespace std;

int main() {
    const int SLOTS = 8;
    bool occupied[SLOTS] = {false};
    int choice, slot, hours;

    do {
        cout << "\n--- Parking Lot ---\n";
        cout << "1. View Slots\n";
        cout << "2. Park Vehicle\n";
        cout << "3. Remove Vehicle\n";
        cout << "4. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        if (choice == 1) {
            for (int i = 0; i < SLOTS; i++) {
                cout << "Slot " << i + 1 << ": "
                     << (occupied[i] ? "Occupied" : "Available") << "\n";
            }
        } else if (choice == 2) {
            cout << "Enter slot number (1-8): ";
            cin >> slot;

            if (slot < 1 || slot > SLOTS) {
                cout << "Invalid slot.\n";
            } else if (occupied[slot - 1]) {
                cout << "Slot is occupied.\n";
            } else {
                occupied[slot - 1] = true;
                cout << "Vehicle parked successfully.\n";
            }
        } else if (choice == 3) {
            cout << "Enter slot number (1-8): ";
            cin >> slot;

            if (slot < 1 || slot > SLOTS) {
                cout << "Invalid slot.\n";
            } else if (!occupied[slot - 1]) {
                cout << "Slot is already empty.\n";
            } else {
                cout << "Parking hours: ";
                cin >> hours;

                if (hours <= 0) {
                    cout << "Invalid hours.\n";
                } else {
                    cout << "Parking fee: " << hours * 50 << " BDT\n";
                    occupied[slot - 1] = false;
                }
            }
        }

    } while (choice != 4);

    return 0;
}
