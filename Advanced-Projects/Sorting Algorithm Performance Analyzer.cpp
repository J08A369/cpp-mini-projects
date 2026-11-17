// Sorting Algorithm Performance Analyzer
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
using namespace std;
using namespace chrono;

int main() {
    vector<int> data(10000);

    mt19937 generator(42);
    for (int& x : data)
        x = generator() % 100000;

    vector<int> first = data;
    vector<int> second = data;

    auto start = steady_clock::now();
    sort(first.begin(), first.end());
    auto end = steady_clock::now();

    auto fastTime = duration_cast<microseconds>(
        end - start).count();

    start = steady_clock::now();
    stable_sort(second.begin(), second.end());
    end = steady_clock::now();

    auto stableTime = duration_cast<microseconds>(
        end - start).count();

    cout << "=== SORTING PERFORMANCE ===\n";
    cout << "Elements: " << data.size() << '\n';
    cout << "std::sort: " << fastTime << " microseconds\n";
    cout << "stable_sort: " << stableTime << " microseconds\n";

    return 0;
}
