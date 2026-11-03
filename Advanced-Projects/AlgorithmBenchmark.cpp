// Project: Algorithm Benchmark
// Language: C++
// Description: Compare bubble sort and selection sort performance.

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace chrono;

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    if (n <= 0 || n > 20000) {
        cout << "Enter a value between 1 and 20000.\n";
        return 0;
    }

    vector<int> data(n);

    for (int i = 0; i < n; i++) {
        data[i] = rand() % 100000;
    }

    vector<int> a = data;
    vector<int> b = data;

    auto start1 = high_resolution_clock::now();

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }

    auto end1 = high_resolution_clock::now();

    auto start2 = high_resolution_clock::now();

    for (int i = 0; i < n - 1; i++) {
        int smallest = i;

        for (int j = i + 1; j < n; j++) {
            if (b[j] < b[smallest]) {
                smallest = j;
            }
        }

        swap(b[i], b[smallest]);
    }

    auto end2 = high_resolution_clock::now();

    cout << "Bubble Sort: "
         << duration_cast<milliseconds>(end1 - start1).count()
         << " ms\n";

    cout << "Selection Sort: "
         << duration_cast<milliseconds>(end2 - start2).count()
         << " ms\n";

    return 0;
}
