// Project: Hotel Booking Management System
// Language: C++
// Description: Manage room bookings and calculate charges.

#include <iostream>
using namespace std;

int main() {
    const int ROOMS = 5;
    bool booked[ROOMS] = {false};
    int choice, room, nights;

    do {
        cout << "\n--- Hotel Booking System ---\n";
        cout << "1. View Rooms\n";
        cout << "2. Book Room\n";
        cout << "3. Checkout\n";
        cout << "4. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        if (choice == 1) {
            for (int i = 0; i < ROOMS; i++) {
                cout << "Room " << i + 1 << ": "
                     << (booked[i] ? "Occupied" : "Available") << "\n";
            }
        } else if (choice == 2) {
            cout << "Enter room number (1-5): ";
            cin >> room;

            if (room < 1 || room > ROOMS) {
                cout << "Invalid room number.\n";
            } else if (booked[room - 1]) {
                cout << "Room is already occupied.\n";
            } else {
                booked[room - 1] = true;
                cout << "Enter number of nights: ";
                cin >> nights;

                if (nights <= 0) {
                    booked[room - 1] = false;
                    cout << "Invalid number of nights.\n";
                } else {
                    cout << "Booking confirmed.\n";
                    cout << "Total cost: " << nights * 2000 << " BDT\n";
                }
            }
        } else if (choice == 3) {
            cout << "Enter room number (1-5): ";
            cin >> room;

            if (room < 1 || room > ROOMS) {
                cout << "Invalid room number.\n";
            } else if (!booked[room - 1]) {
                cout << "Room is not occupied.\n";
            } else {
                booked[room - 1] = false;
                cout << "Checkout completed.\n";
            }
        }

    } while (choice != 4);

    return 0;
}
