#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    bool isIssued;

    Book(int id, string title, string author) {
        this->id = id;
        this->title = title;
        this->author = author;
        this->isIssued = false;
    }
};

class Library {
private:
    vector<Book> books;

public:
    void addBook(int id, string title, string author) {
        books.emplace_back(id, title, author);
        cout << "Book added successfully!\n";
    }

    void searchByTitle(string title) {
        bool found = false;
        for (const auto& b : books) {
            if (b.title == title) {
                displayBook(b);
                found = true;
            }
        }
        if (!found) cout << "Book not found.\n";
    }

    void issueBook(int id) {
        for (auto& b : books) {
            if (b.id == id) {
                if (b.isIssued) {
                    cout << "Book is already issued.\n";
                } else {
                    b.isIssued = true;
                    cout << "Book issued successfully!\n";
                }
                return;
            }
        }
        cout << "Book ID not found.\n";
    }

    void returnBook(int id) {
        for (auto& b : books) {
            if (b.id == id) {
                b.isIssued = false;
                cout << "Book returned successfully!\n";
                return;
            }
        }
        cout << "Book ID not found.\n";
    }

    void displayBook(const Book& b) {
        cout << "[ID: " << b.id << "] Title: " << b.title 
             << " | Author: " << b.author 
             << " | Status: " << (b.isIssued ? "Issued" : "Available") << endl;
    }
};

int main() {
    Library myLibrary;
    
    // Sample Data
    myLibrary.addBook(101, "The C++ Programming Language", "Bjarne Stroustrup");
    myLibrary.addBook(102, "Clean Code", "Robert C. Martin");

    int choice, id;
    string title;

    while (true) {
        cout << "\n--- Library Management System ---\n";
        cout << "1. Search Book\n2. Issue Book\n3. Return Book\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter title: ";
                cin.ignore();
                getline(cin, title);
                myLibrary.searchByTitle(title);
                break;
            case 2:
                cout << "Enter Book ID to issue: ";
                cin >> id;
                myLibrary.issueBook(id);
                break;
            case 3:
                cout << "Enter Book ID to return: ";
                cin >> id;
                myLibrary.returnBook(id);
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
    return 0;
}