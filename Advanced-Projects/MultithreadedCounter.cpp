// Project: Multithreaded Counter
// Language: C++
// Description: Use multiple threads to update a shared counter.

#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
using namespace std;

long long counter = 0;
mutex counterMutex;

void countNumbers(int amount) {
    for (int i = 0; i < amount; i++) {
        lock_guard<mutex> lock(counterMutex);
        counter++;
    }
}

int main() {
    const int THREADS = 4;
    const int ITERATIONS = 100000;

    vector<thread> workers;

    for (int i = 0; i < THREADS; i++) {
        workers.push_back(thread(countNumbers, ITERATIONS));
    }

    for (thread &worker : workers) {
        worker.join();
    }

    cout << "Expected count: "
         << 1LL * THREADS * ITERATIONS << "\n";
    cout << "Actual count: " << counter << "\n";

    return 0;
}
