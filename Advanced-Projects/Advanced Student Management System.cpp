// Advanced Student Management System
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Student {
    int id;
    string name;
    double gpa;
};

int main() {
    vector<Student> students = {
        {101, "Rahim", 3.85},
        {102, "Karim", 3.65},
        {103, "Nadia", 3.95}
    };

    sort(students.begin(), students.end(),
         [](const Student& a, const Student& b) {
             return a.gpa > b.gpa;
         });

    cout << "=== STUDENT MANAGEMENT SYSTEM ===\n";

    for (const auto& s : students) {
        cout << "ID: " << s.id
             << " | Name: " << s.name
             << " | GPA: " << s.gpa << '\n';
    }

    return 0;
}
