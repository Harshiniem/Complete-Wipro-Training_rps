/*
 * Purpose:
 * Write a C++ program to demonstrate passing an object to a function
 * using call by reference and to show that the copy constructor
 * is NOT invoked in this case.
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

// Function demonstrating call by reference
Test& fun(Test& arg) {
    return arg;
}

int main() {
    Test objTwo = 100; // Calls Parameterized Constructor
    fun(objTwo);      // No Copy Constructor call
}

