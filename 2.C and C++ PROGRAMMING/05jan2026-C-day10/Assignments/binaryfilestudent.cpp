/*
Purpose : Binary file based Student Record Management System
Author  : Harshinie M
Date    : 06-01-2026
*/

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Student
{
    int roll;
    char name[30];
    float marks;

public:
    void input()
    {
        cout << "Enter Roll No: ";
        cin >> roll;
        cin.ignore();
        cout << "Enter Name: ";
        cin.getline(name, 30);
        cout << "Enter Marks: ";
        cin >> marks;
    }

    void display()
    {
        cout << roll << "\t" << name << "\t" << marks << endl;
    }

    int getRoll()
    {
        return roll;
    }

    void setMarks(float m)
    {
        marks = m;
    }
};

void addStudent()
{
    Student s;
    ofstream fout("student.dat", ios::binary | ios::app);

    s.input();
    fout.write((char *)&s, sizeof(s));

    fout.close();
}

void displayAll()
{
    Student s;
    ifstream fin("student.dat", ios::binary);

    cout << "Roll\tName\tMarks\n";
    cout << "------------------------\n";

    while (fin.read((char *)&s, sizeof(s)))
    {
        s.display();
    }

    fin.close();
}

void updateMarks()
{
    fstream file("student.dat", ios::binary | ios::in | ios::out);
    Student s;
    int r;
    float newMarks;
    bool found = false;

    cout << "Enter roll number to update: ";
    cin >> r;

    while (file.read((char *)&s, sizeof(s)))
    {
        if (s.getRoll() == r)
        {
            cout << "Enter new marks: ";
            cin >> newMarks;

            s.setMarks(newMarks);

            file.seekp(-sizeof(s), ios::cur);
            file.write((char *)&s, sizeof(s));

            found = true;
            break;
        }
    }

    if (!found)
        cout << "Record not found!\n";

    file.close();
}

void deleteStudent()
{
    ifstream fin("student.dat", ios::binary);
    ofstream fout("temp.dat", ios::binary);

    Student s;
    int r;
    bool found = false;

    cout << "Enter roll number to delete: ";
    cin >> r;

    while (fin.read((char *)&s, sizeof(s)))
    {
        if (s.getRoll() != r)
        {
            fout.write((char *)&s, sizeof(s));
        }
        else
        {
            found = true;
        }
    }

    fin.close();
    fout.close();

    remove("student.dat");
    rename("temp.dat", "student.dat");

    if (found)
        cout << "Record deleted successfully\n";
    else
        cout << "Record not found\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n1. Add Student";
        cout << "\n2. Display All";
        cout << "\n3. Update Marks";
        cout << "\n4. Delete Student";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addStudent();
            break;
        case 2:
            displayAll();
            break;
        case 3:
            updateMarks();
            break;
        case 4:
            deleteStudent();
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 5);

    return 0;
}

