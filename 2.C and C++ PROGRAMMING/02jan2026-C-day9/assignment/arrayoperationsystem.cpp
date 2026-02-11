/*
Purpose : Program to demonstrate an Array Operations System using inheritance,
          virtual functions, and runtime polymorphism to handle different
          data types (int, float, string).
Author  : Harshinie M
Date    : 02-01-2026
*/

#include <iostream>
#include <string>
using namespace std;

class ArrayBase {
public:
    virtual void insert() = 0;   // pure virtual function
    virtual void display() = 0;  // pure virtual function
    virtual ~ArrayBase() {}
};

class IntegerArray : public ArrayBase {
    int arr[10];
    int n;

public:
    void insert() {
        cout << "Enter number of integers: ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
    }

    void display() {
        cout << "Integer Array: ";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

class FloatArray : public ArrayBase {
    float arr[10];
    int n;

public:
    void insert() {
        cout << "Enter number of floats: ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
    }

    void display() {
        cout << "Float Array: ";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

class StringArray : public ArrayBase {
    string arr[10];
    int n;

public:
    void insert() {
        cout << "Enter number of strings: ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
    }

    void display() {
        cout << "String Array: ";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    ArrayBase *aPtr;
    int choice;

    cout << "1. Integer Array\n2. Float Array\n3. String Array\n";
    cout << "Enter array type: ";
    cin >> choice;

    if (choice == 1) {
        aPtr = new IntegerArray();
    }
    else if (choice == 2) {
        aPtr = new FloatArray();
    }
    else if (choice == 3) {
        aPtr = new StringArray();
    }
    else {
        cout << "Invalid choice\n";
        return 0;
    }

    aPtr->insert();
    aPtr->display();

    delete aPtr;
    return 0;
}

