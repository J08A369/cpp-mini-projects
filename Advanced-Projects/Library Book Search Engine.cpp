// Library Book Search Engine
#include <iostream>
#include <vector>
using namespace std;

struct Book {
    string title;
    string author;
    bool available;
};

int main() {
    vector<Book> books = {
        {"Clean Code", "Robert Martin", true},
        {"The C++ Programming Language", "Bjarne Stroustrup", true},
        {"Effective C++", "Scott Meyers", false}
    };

    string keyword;
    cout << "Enter book title keyword: ";
    getline(cin, keyword);

    bool found = false;

    for (const auto& book : books) {
        if (book.title.find(keyword) != string::npos) {
            cout << "\nTitle: " << book.title
                 << "\nAuthor: " << book.author
                 << "\nStatus: "
                 << (book.available ? "Available" : "Borrowed")
                 << "\n";
            found = true;
        }
    }

    if (!found)
        cout << "No matching books found.\n";

    return 0;
}
