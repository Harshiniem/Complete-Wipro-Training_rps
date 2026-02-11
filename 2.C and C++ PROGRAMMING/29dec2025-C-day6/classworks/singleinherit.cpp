/*
 * Purpose:
 * Write a C++ program to demonstrate single inheritance
 * with public inheritance. The program shows that public
 * member functions of a base class can be accessed using
 * a derived class object.
 *
 * Author: Harshinie M
 * Date  : 29-12-2025
 */

#include <iostream>
using namespace std;

class Base {
public:
    void funOne() {
        cout << "Base::funOne()" << endl;
    }

    void funTwo() {
        cout << "Base::funTwo()" << endl;
    }
};

// Derived class publicly inheriting Base
class Derived : public Base {};

int main() {
    Derived dObj;   // Derived class object
    dObj.funOne();  // Accessing Base class function
    dObj.funTwo();  // Accessing Base class function
}

