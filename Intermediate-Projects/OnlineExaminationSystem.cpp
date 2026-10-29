// Project: Online Examination System
// Language: C++
// Description: MCQ exam with automatic result calculation.

#include <iostream>
using namespace std;

int main() {
    string questions[5] = {
        "Which language is used for system programming?",
        "What does CPU stand for?",
        "Which data structure uses FIFO?",
        "Which symbol ends a C++ statement?",
        "Which loop checks condition first?"
    };

    string options[5][4] = {
        {"Java", "C++", "HTML", "CSS"},
        {"Central Processing Unit", "Computer Personal Unit",
         "Central Program Utility", "Control Processing User"},
        {"Stack", "Queue", "Tree", "Graph"},
        {".", ",", ";", ":"},
        {"do-while", "while", "None", "Both A and B"}
    };

    char answers[5] = {'B', 'A', 'B', 'C', 'B'};
    char userAnswer;
    int score = 0;

    for (int i = 0; i < 5; i++) {
        cout << "\n" << i + 1 << ". " << questions[i] << "\n";

        for (int j = 0; j < 4; j++) {
            cout << char('A' + j) << ". " << options[i][j] << "\n";
        }

        cout << "Your answer: ";
        cin >> userAnswer;

        if (toupper(userAnswer) == answers[i]) {
            score++;
        }
    }

    cout << "\nFinal Score: " << score << "/5\n";
    cout << "Percentage: " << score * 20 << "%\n";

    return 0;
}
