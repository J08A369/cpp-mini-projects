// Rule-Based Job Matching Engine
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    string title;
    string requiredSkill;
    int score;
};

int main() {
    vector<Job> jobs = {
        {"C++ Developer", "cpp", 0},
        {"Web Developer", "html", 0},
        {"Data Analyst", "python", 0},
        {"Software Intern", "cpp", 0}
    };

    string skill;
    cout << "Enter your main skill: ";
    cin >> skill;

    for (auto& job : jobs)
        job.score = (job.requiredSkill == skill) ? 100 : 20;

    sort(jobs.begin(), jobs.end(),
         [](const Job& a, const Job& b) {
             return a.score > b.score;
         });

    cout << "\n=== JOB MATCH RESULTS ===\n";

    for (const auto& job : jobs)
        cout << job.title
             << " | Match Score: " << job.score << "%\n";

    return 0;
}
