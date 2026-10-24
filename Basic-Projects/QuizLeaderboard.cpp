// Project: Quiz Leaderboard
// Language: C++
// Description: Store player scores and rank them.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Player {
    string name;
    int score;
};

int main() {
    vector<Player> players;
    int n;

    cout << "Number of players: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        Player p;

        cout << "Player name: ";
        cin >> ws;
        getline(cin, p.name);

        cout << "Score: ";
        cin >> p.score;

        players.push_back(p);
    }

    sort(players.begin(), players.end(),
         [](const Player &a, const Player &b) {
             return a.score > b.score;
         });

    cout << "\n--- Leaderboard ---\n";

    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << players[i].name
             << " - " << players[i].score << "\n";
    }

    return 0;
}
