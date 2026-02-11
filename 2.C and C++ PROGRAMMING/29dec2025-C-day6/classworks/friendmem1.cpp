/*
 * Purpose:
 * Write a C++ program to demonstrate the use of a friend function
 * to access private members of a class. The program shows that
 * the main() function can access a class’s private constructor
 * and private member functions when declared as a friend.
 *
 * Author: Harshinie M
 * Date  : 29-12-2025
 */

#include <iostream>
using namespace std;

class Test { // All members of a class are private by default
    int data;

    // Private constructor with default argument
    Test(int x = 10) : data(x) {
        cout << "constructor called" << endl;
    }

    // Private member function
    void disp() {
        cout << "Data: " << data << endl;
    }

    // Granting access to main()
    friend int main();
};

int main() {
    Test obj = 100; // Accessing private constructor
    obj.disp();     // Accessing private member function
}

