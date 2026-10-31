// Project: Railway Reservation System
// Language: C++
// Description: Book and cancel train seats.

#include <iostream>
using namespace std;

int main() {
    const int TOTAL_SEATS = 10;
    bool booked[TOTAL_SEATS] = {false};
    int choice, seat;

    do {
        cout << "\n--- Railway Reservation System ---\n";
        cout << "1. View Seats\n";
        cout << "2. Book Seat\n";
        cout << "3. Cancel Booking\n";
        cout << "4. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        if (choice == 1) {
            for (int i = 0; i < TOTAL_SEATS; i++) {
                cout << "Seat " << i + 1 << ": "
                     << (booked[i] ? "Booked" : "Available") << "\n";
            }
        } else if (choice == 2) {
            cout << "Enter seat number (1-10): ";
            cin >> seat;

            if (seat < 1 || seat > TOTAL_SEATS) {
                cout << "Invalid seat number.\n";
            } else if (booked[seat - 1]) {
                cout << "Seat already booked.\n";
            } else {
                booked[seat - 1] = true;
                cout << "Seat booked successfully.\n";
            }
        } else if (choice == 3) {
            cout << "Enter seat number (1-10): ";
            cin >> seat;

            if (seat < 1 || seat > TOTAL_SEATS) {
                cout << "Invalid seat number.\n";
            } else if (!booked[seat - 1]) {
                cout << "This seat is not booked.\n";
            } else {
                booked[seat - 1] = false;
                cout << "Booking cancelled.\n";
            }
        }

    } while (choice != 4);

    return 0;
}
