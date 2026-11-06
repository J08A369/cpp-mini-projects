// Project: Custom Dynamic Array
// Language: C++
// Description: Build a simple dynamic array without using vector.

#include <iostream>
using namespace std;

class DynamicArray {
private:
    int *data;
    int capacity;
    int length;

    void resize() {
        capacity *= 2;

        int *newData = new int[capacity];

        for (int i = 0; i < length; i++) {
            newData[i] = data[i];
        }

        delete[] data;
        data = newData;
    }

public:
    DynamicArray() {
        capacity = 2;
        length = 0;
        data = new int[capacity];
    }

    ~DynamicArray() {
        delete[] data;
    }

    void add(int value) {
        if (length == capacity) {
            resize();
        }

        data[length++] = value;
    }

    void display() const {
        for (int i = 0; i < length; i++) {
            cout << data[i] << " ";
        }

        cout << "\n";
    }

    int size() const {
        return length;
    }
};

int main() {
    DynamicArray numbers;
    int n, value;

    cout << "How many numbers? ";
    cin >> n;

    if (n < 0) {
        cout << "Invalid size.\n";
        return 0;
    }

    for (int i = 0; i < n; i++) {
        cout << "Enter number: ";
        cin >> value;
        numbers.add(value);
    }

    cout << "Array elements: ";
    numbers.display();

    cout << "Total elements: " << numbers.size() << "\n";

    return 0;
}
