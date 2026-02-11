/*
Purpose : Program to demonstrate runtime polymorphism using virtual functions
          and the importance of virtual destructor when deleting objects
          through a base class pointer passed to a function.
Author  : Harshinie M
Date    : 02-01-2026
*/

#include <iostream>
using namespace std;

class Base {
public:
    Base() {
        cout << "Base::Base() --> ctor" << endl;
    }

    virtual ~Base() {
        cout << "Base::~Base()--> dtor" << endl;
    }

    virtual void funOne() {
        cout << "Base::funOne()" << endl;
    }

    virtual void funTwo() {
        cout << "Base::funTwo()" << endl;
    }
};

class Derived : public Base {
public:
    Derived() {
        cout << "Derived::Derived() --> ctor" << endl;
    }

    ~Derived() {
        cout << "Derived::~Derived()--> dtor" << endl;
    }

    void funOne() {
        cout << "Derived::funOne()" << endl;
    }

    void funTwo() {
        cout << "Derived::funTwo()" << endl;
    }
};

void funCaller(Base *bptr) {
    bptr->funOne();
    bptr->funTwo();
    delete bptr;
    cout << "*********************************************\n";
}

int main() {
    funCaller(new Base());
    funCaller(new Derived());
    return 0;
}

