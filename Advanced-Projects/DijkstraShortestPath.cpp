// Project: Dijkstra Shortest Path Finder
// Language: C++
// Description: Find shortest distances in a weighted graph.

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main() {
    int nodes, edges;

    cout << "Enter number of nodes and edges: ";
    cin >> nodes >> edges;

    if (nodes <= 0 || edges < 0) {
        cout << "Invalid graph size.\n";
        return 0;
    }

    vector<vector<pair<int, int>>> graph(nodes);

    cout << "Enter edges: source destination weight\n";

    for (int i = 0; i < edges; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        if (u < 0 || u >= nodes || v < 0 || v >= nodes || w < 0) {
            cout << "Invalid edge.\n";
            return 0;
        }

        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    int source;
    cout << "Enter source node (0 to " << nodes - 1 << "): ";
    cin >> source;

    if (source < 0 || source >= nodes) {
        cout << "Invalid source.\n";
        return 0;
    }

    vector<int> distance(nodes, INT_MAX);
    priority_queue<pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>> pq;

    distance[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int currentDistance = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (currentDistance != distance[u]) {
            continue;
        }

        for (auto edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (distance[u] <= INT_MAX - weight &&
                distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                pq.push({distance[v], v});
            }
        }
    }

    for (int i = 0; i < nodes; i++) {
        cout << "Distance to node " << i << ": ";

        if (distance[i] == INT_MAX) {
            cout << "Unreachable\n";
        } else {
            cout << distance[i] << "\n";
        }
    }

    return 0;
}
