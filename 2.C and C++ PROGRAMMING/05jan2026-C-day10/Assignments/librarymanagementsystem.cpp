/*
Purpose : Binary file based Library Management System
Author  : Harshinie M
Date    : 06-01-2026
*/

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Book
{
    int bookId;
    char bookName[40];
    char author[30];
    bool available;

public:
    void input()
    {
        cout << "Enter Book ID: ";
        cin >> bookId;
        cin.ignore();
        cout << "Enter Book Name: ";
        cin.getline(bookName, 40);
        cout << "Enter Author Name: ";
        cin.getline(author, 30);
        available = true; // new book is available
    }

    void display()
    {
        cout << bookId << "\t" << bookName << "\t"
             << author << "\t"
             << (available ? "Available" : "Issued") << endl;
    }

    int getBookId()
    {
        return bookId;
    }

    bool isAvailable()
    {
        return available;
    }

    void issue()
    {
        available = false;
    }

    void returnBook()
    {
        available = true;
    }
};

// Add book
void addBook()
{
    Book b;
    ofstream fout("library.dat", ios::binary | ios::app);

    b.input();
    fout.write((char *)&b, sizeof(b));

    fout.close();
}

// Display all books
void displayBooks()
{
    Book b;
    ifstream fin("library.dat", ios::binary);

    cout << "\nID\tBook Name\tAuthor\t\tStatus\n";
    cout << "----------------------------------------------\n";

    while (fin.read((char *)&b, sizeof(b)))
    {
        b.display();
    }

    fin.close();
}

// Issue book
void issueBook()
{
    fstream file("library.dat", ios::binary | ios::in | ios::out);
    Book b;
    int id;
    bool found = false;

    cout << "Enter Book ID to issue: ";
    cin >> id;

    while (file.read((char *)&b, sizeof(b)))
    {
        if (b.getBookId() == id)
        {
            if (b.isAvailable())
            {
                b.issue();
                file.seekp(-sizeof(b), ios::cur);
                file.write((char *)&b, sizeof(b));
                cout << "Book issued successfully\n";
            }
            else
            {
                cout << "Book already issued\n";
            }
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Book not found\n";

    file.close();
}

// Return book
void returnBook()
{
    fstream file("library.dat", ios::binary | ios::in | ios::out);
    Book b;
    int id;
    bool found = false;

    cout << "Enter Book ID to return: ";
    cin >> id;

    while (file.read((char *)&b, sizeof(b)))
    {
        if (b.getBookId() == id)
        {
            b.returnBook();
            file.seekp(-sizeof(b), ios::cur);
            file.write((char *)&b, sizeof(b));
            cout << "Book returned successfully\n";
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Book not found\n";

    file.close();
}

// Delete book
void deleteBook()
{
    ifstream fin("library.dat", ios::binary);
    ofstream fout("temp.dat", ios::binary);

    Book b;
    int id;
    bool found = false;

    cout << "Enter Book ID to delete: ";
    cin >> id;

    while (fin.read((char *)&b, sizeof(b)))
    {
        if (b.getBookId() != id)
            fout.write((char *)&b, sizeof(b));
        else
            found = true;
    }

    fin.close();
    fout.close();

    remove("library.dat");
    rename("temp.dat", "library.dat");

    if (found)
        cout << "Book deleted successfully\n";
    else
        cout << "Book not found\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n1. Add Book";
        cout << "\n2. Display Books";
        cout << "\n3. Issue Book";
        cout << "\n4. Return Book";
        cout << "\n5. Delete Book";
        cout << "\n6. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addBook();
            break;
        case 2:
            displayBooks();
            break;
        case 3:
            issueBook();
            break;
        case 4:
            returnBook();
            break;
        case 5:
            deleteBook();
            break;
        case 6:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 6);

    return 0;
}

