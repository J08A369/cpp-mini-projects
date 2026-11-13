// Project: Priority Task Scheduler
// Language: C++
// Description: Execute higher-priority tasks first.

#include <iostream>
#include <queue>
using namespace std;

struct Task {
    string name;
    int priority;
};

struct CompareTask {
    bool operator()(const Task &a, const Task &b) {
        return a.priority < b.priority;
    }
};

int main() {
    priority_queue<Task, vector<Task>, CompareTask> tasks;
    int choice;

    do {
        cout << "\n--- Task Scheduler ---\n";
        cout << "1. Add Task\n";
        cout << "2. Execute Next Task\n";
        cout << "3. View Next Task\n";
        cout << "4. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        if (choice == 1) {
            Task t;

            cout << "Task name: ";
            cin >> ws;
            getline(cin, t.name);

            cout << "Priority (higher number = higher priority): ";
            cin >> t.priority;

            tasks.push(t);
            cout << "Task added.\n";
        } else if (choice == 2) {
            if (tasks.empty()) {
                cout << "No pending tasks.\n";
            } else {
                cout << "Executing: " << tasks.top().name << "\n";
                tasks.pop();
            }
        } else if (choice == 3) {
            if (tasks.empty()) {
                cout << "No pending tasks.\n";
            } else {
                cout << "Next task: " << tasks.top().name << "\n";
            }
        }

    } while (choice != 4);

    return 0;
}
