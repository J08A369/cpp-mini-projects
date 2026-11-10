// Project: Memory Allocation Simulator
// Language: C++
// Description: Simulate first-fit memory allocation.

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int blockCount, processCount;

    cout << "Enter number of memory blocks: ";
    cin >> blockCount;

    if (blockCount <= 0) {
        cout << "Invalid number of blocks.\n";
        return 0;
    }

    vector<int> blocks(blockCount);

    cout << "Enter block sizes:\n";
    for (int i = 0; i < blockCount; i++) {
        cin >> blocks[i];
    }

    cout << "Enter number of processes: ";
    cin >> processCount;

    if (processCount < 0) {
        cout << "Invalid number of processes.\n";
        return 0;
    }

    vector<int> processes(processCount);

    cout << "Enter process sizes:\n";
    for (int i = 0; i < processCount; i++) {
        cin >> processes[i];
    }

    for (int i = 0; i < processCount; i++) {
        bool allocated = false;

        for (int j = 0; j < blockCount; j++) {
            if (blocks[j] >= processes[i]) {
                cout << "Process " << i + 1
                     << " allocated to block " << j + 1 << "\n";

                blocks[j] -= processes[i];
                allocated = true;
                break;
            }
        }

        if (!allocated) {
            cout << "Process " << i + 1
                 << " could not be allocated.\n";
        }
    }

    cout << "\nRemaining block sizes:\n";
    for (int i = 0; i < blockCount; i++) {
        cout << "Block " << i + 1 << ": " << blocks[i] << "\n";
    }

    return 0;
}
