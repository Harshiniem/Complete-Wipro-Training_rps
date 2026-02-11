/*
 * Purpose : Write a program to demonstrate the order of execution of
 *           constructors and destructors in multiple inheritance.
 *
 * Author  : Harshinie M
 * Date    : 30-12-2025
 */

#include <iostream>
using namespace std;

// Base class A
struct A{
    A(){
        cout << "A()" << endl;
    }
    ~A(){
        cout << "~A()" << endl;
    }
};

// Base class B
struct B{
    B(){
        cout << "B()" << endl;
    }
    ~B(){
        cout << "~B()" << endl;
    }
};

// Base class C
struct C{
    C(){
        cout << "C()" << endl;
    }
    ~C(){
        cout << "~C()" << endl;
    }
};

// Derived class D inherits from A, B, and C
struct D : A, B, C{
    // Constructor
    D() : B(), C(), A(){
        cout << "D()" << endl;
    }

    // Destructor
    ~D(){
        cout << "~D()" << endl;
    }
};

int main(){
    // Creating object of derived class D
    D dObj;

    // Destructors will be called automatically
    return 0;
}

