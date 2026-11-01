// Project: Student Attendance Tracker
// Language: C++
// Description: Record attendance and calculate attendance percentage.

#include <iostream>
using namespace std;

int main() {
    int students, days;

    cout << "Enter number of students: ";
    cin >> students;

    cout << "Enter number of class days: ";
    cin >> days;

    if (students <= 0 || days <= 0) {
        cout << "Invalid input.\n";
        return 0;
    }

    for (int i = 1; i <= students; i++) {
        string name;
        int present = 0;
        char status;

        cout << "\nStudent " << i << " name: ";
        cin >> ws;
        getline(cin, name);

        for (int j = 1; j <= days; j++) {
            cout << "Day " << j << " (P/A): ";
            cin >> status;

            if (status == 'P' || status == 'p') {
                present++;
            } else if (status != 'A' && status != 'a') {
                cout << "Invalid status; counted as absent.\n";
            }
        }

        double percentage = present * 100.0 / days;

        cout << "Student: " << name << "\n";
        cout << "Present: " << present << "/" << days << "\n";
        cout << "Attendance: " << percentage << "%\n";
    }

    return 0;
}
