/*
 * Purpose : Write a program to demonstrate runtime polymorphism
 *           using virtual functions and base class pointers.
 *
 * Author  : Harshinie M
 * Date    : 30-12-2025
 */

#include <iostream>
using namespace std;

// Base class
class Base{
public:
    // Virtual function
    virtual void funOne(){
        cout << "Base::funOne()" << endl;
    }
};

// Derived class
class Derived : public Base{
public:
    // Overridden function
    void funOne(){
        cout << "Derived::funOne()" << endl;
    }
};

int main(){
    // Base class pointer and objects
    Base *ptr, bObj;
    Derived dObj;

    // Base pointer pointing to Base object
    ptr = &bObj;
    ptr->funOne();   // Calls Base::funOne()

    // Base pointer pointing to Derived object
    ptr = &dObj;
    ptr->funOne();   // Calls Derived::funOne() (runtime binding)

    return 0;
}

