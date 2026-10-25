// Advanced Inventory Management System
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Product {
    int id;
    string name;
    int quantity;
    double price;
};

int main() {
    vector<Product> products = {
        {101, "Laptop", 10, 65000},
        {102, "Keyboard", 25, 1200},
        {103, "Mouse", 40, 650},
        {104, "Monitor", 8, 15000}
    };

    sort(products.begin(), products.end(),
         [](const Product& a, const Product& b) {
             return a.quantity < b.quantity;
         });

    double totalValue = 0;

    cout << "=== INVENTORY MANAGEMENT SYSTEM ===\n\n";

    for (const auto& p : products) {
        cout << "ID: " << p.id
             << " | Product: " << p.name
             << " | Stock: " << p.quantity
             << " | Price: " << p.price << '\n';

        totalValue += p.quantity * p.price;
    }

    cout << "\nTotal Inventory Value: "
         << totalValue << '\n';

    return 0;
}
