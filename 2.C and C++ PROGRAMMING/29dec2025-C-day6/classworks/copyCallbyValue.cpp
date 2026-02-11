/*
 * Purpose:
 * Write a C++ program to demonstrate the invocation of the copy constructor
 * when an object is passed to a function using call by value.
 * The program also shows the order of constructor and destructor calls.
 *
 * Author: Harshinie M
 * Date  : 29-12-2025
 */

#include <iostream>
using namespace std;

class Test {
public:
    // Default Constructor
    Test() {
        cout << "Test() --> Default Ctor" << endl;
    }

    // Parameterized Constructor
    Test(int) {
        cout << "Test(int) --> Parameterized Ctor" << endl;
    }

    // Copy Constructor
    Test(const Test &) {
        cout << "Test(const Test&) --> Copy Ctor" << endl;
    }

    // Destructor
    ~Test() {
        cout << "~Test() --> Destructor" << endl;
    }
};

// Function demonstrating call by value
Test fun(Test arg) {
    return arg;
}

int main() {
    Test objTwo = 100; // Calls Parameterized Constructor
    fun(objTwo);      // Copy Constructor is invoked
}

