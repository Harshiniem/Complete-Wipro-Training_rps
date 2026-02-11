/*
 * Purpose:
 * Write a C++ program to demonstrate the working of different types of
 * constructors and a destructor in a class.
 * The program should illustrate:
 * 1. Default Constructor
 * 2. Parameterized Constructor
 * 3. Copy Constructor
 * 4. Destructor call sequence
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

int main() {
    Test objOne;            // Calls Default Constructor
    Test objTwo = 100;      // Calls Parameterized Constructor
    Test objThree = objTwo; // Calls Copy Constructor
}

