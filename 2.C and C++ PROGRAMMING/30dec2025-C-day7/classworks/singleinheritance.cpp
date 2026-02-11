/*
 * Purpose : Write a program to demonstrate single inheritance in C++,
 *           where a derived class accesses public member functions
 *           of a base class.
 *
 * Author  : Harshinie M
 * Date    : 30-12-2025
 */

#include <iostream>
using namespace std;

// Base class
class Base{
public:
    // Member function of Base class
    void funOne(){
        cout << "Base::funOne()" << endl;
    }

    // Another member function of Base class
    void funTwo(){
        cout << "Base::funTwo()" << endl;
    }
};

// Derived class inherits from Base
class Derived : public Base{
public:
    // Member function of Derived class
    void funThree(){
        cout << "Derived::funThree()" << endl;
    }

    // Another member function of Derived class
    void funFour(){
        cout << "Derived::funFour()" << endl;
    }
};

int main(){
    // Create object of Derived class
    Derived dObj;

    // Access Base class functions using Derived object
    dObj.funOne();
    dObj.funTwo();

    // Access Derived class functions
    dObj.funThree();
    dObj.funFour();

    return 0;
}

