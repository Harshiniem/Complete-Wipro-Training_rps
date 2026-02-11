/*
Purpose : Program to demonstrate a Student Management System using
          inheritance, virtual functions, dynamic object creation,
          and runtime polymorphism.
Author  : Harshinie M
Date    : 02-01-2026
*/

#include <iostream>
#include <string>
using namespace std;

class Student {
protected:
    string name;
    int rollNo;

public:
    Student(string n, int r) : name(n), rollNo(r) {}

    virtual void calculateGrade() {
        cout << "Base Student grade calculation" << endl;
    }

    virtual ~Student() {}
};

class Undergraduate : public Student {
    int marks;

public:
    Undergraduate(string n, int r, int m)
        : Student(n, r), marks(m) {}

    void calculateGrade() {
        cout << "Undergraduate Student\n";
        cout << "Name: " << name << ", Roll No: " << rollNo << endl;

        if (marks >= 50)
            cout << "Final Grade: PASS\n";
        else
            cout << "Final Grade: FAIL\n";
    }
};

class Postgraduate : public Student {
    int marks;

public:
    Postgraduate(string n, int r, int m)
        : Student(n, r), marks(m) {}

    void calculateGrade() {
        cout << "Postgraduate Student\n";
        cout << "Name: " << name << ", Roll No: " << rollNo << endl;

        if (marks >= 60)
            cout << "Final Grade: PASS\n";
        else
            cout << "Final Grade: FAIL\n";
    }
};

class ResearchStudent : public Student {
    int publications;

public:
    ResearchStudent(string n, int r, int p)
        : Student(n, r), publications(p) {}

    void calculateGrade() {
        cout << "Research Student\n";
        cout << "Name: " << name << ", Roll No: " << rollNo << endl;

        if (publications >= 2)
            cout << "Final Grade: PASS\n";
        else
            cout << "Final Grade: FAIL\n";
    }
};

int main() {
    Student *sPtr;
    int choice;

    cout << "1. Undergraduate\n2. Postgraduate\n3. Research Student\n";
    cout << "Enter student type: ";
    cin >> choice;

    string name;
    int roll;

    cout << "Enter name: ";
    cin >> name;
    cout << "Enter roll number: ";
    cin >> roll;

    if (choice == 1) {
        int marks;
        cout << "Enter marks: ";
        cin >> marks;
        sPtr = new Undergraduate(name, roll, marks);
    }
    else if (choice == 2) {
        int marks;
        cout << "Enter marks: ";
        cin >> marks;
        sPtr = new Postgraduate(name, roll, marks);
    }
    else if (choice == 3) {
        int pubs;
        cout << "Enter number of publications: ";
        cin >> pubs;
        sPtr = new ResearchStudent(name, roll, pubs);
    }
    else {
        cout << "Invalid choice\n";
        return 0;
    }

    cout << "\n--- Grade Evaluation ---\n";
    sPtr->calculateGrade();

    delete sPtr;
    return 0;
}

