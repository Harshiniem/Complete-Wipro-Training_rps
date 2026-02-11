/*
Purpose : Binary file based Book Inventory System
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
    char title[40];
    float price;

public:
    void input()
    {
        cout << "Enter Book ID: ";
        cin >> bookId;
        cin.ignore();
        cout << "Enter Book Title: ";
        cin.getline(title, 40);
        cout << "Enter Price: ";
        cin >> price;
    }

    void display()
    {
        cout << bookId << "\t" << title << "\t" << price << endl;
    }
};

void addBook()
{
    Book b;
    ofstream fout("books.dat", ios::binary | ios::app);

    b.input();
    fout.write((char *)&b, sizeof(b));

    fout.close();
}

void listBooks()
{
    Book b;
    ifstream fin("books.dat", ios::binary);

    cout << "ID\tTitle\t\tPrice\n";
    cout << "-----------------------------\n";

    while (fin.read((char *)&b, sizeof(b)))
    {
        b.display();
    }

    fin.close();
}

int main()
{
    int choice;

    do
    {
        cout << "\n1. Add Book";
        cout << "\n2. List All Books";
        cout << "\n3. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addBook();
            break;
        case 2:
            listBooks();
            break;
        case 3:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 3);

    return 0;
}

