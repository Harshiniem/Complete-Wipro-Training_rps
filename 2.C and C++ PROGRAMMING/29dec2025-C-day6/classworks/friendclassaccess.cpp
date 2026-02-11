/*
 * Purpose:
 * Write a C++ program to demonstrate the use of a friend class
 * to access private members (private constructor and private
 * member function) of another class.
 *
 * Author: Harshinie M
 * Date  : 29-12-2025
 */

#include <iostream>
using namespace std;

class Test { // All members of a class are private by default
    int data;

    // Private constructor
    Test(int x = 10) : data(x) {
        cout << "constructor called" << endl;
    }

    // Private member function
    void disp() {
        cout << "Data: " << data << endl;
    }

    // Declaring friend class
    friend class UsingTest;
};

class UsingTest {
    Test obj;

public:
    // Constructor accessing Test's private constructor
    UsingTest(int x = 100) : obj(Test(x)) {}

    // Member function accessing Test's private function
    void print() {
        obj.disp();
    }
};

int main() {
    UsingTest obj = 100;
    obj.print();
}

