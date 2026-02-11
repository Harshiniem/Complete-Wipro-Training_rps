/*
Purpose : Demonstrate runtime polymorphism using virtual functions
          with base class pointer.
Author  : Harshinie M
Date    : 31/12/2025
*/

#include <iostream>
using namespace std;

class Base{
public:
    virtual void disp(){ cout<<"Base::disp()"<<endl; }
};

class Derived : public Base{
public:
    void disp(){ cout<<"Derived::disp()"<<endl; }
};

int main(){
    Base *bPtr;
    Base bObj;
    Derived dObj;

    bPtr = &bObj;
    bPtr->disp();

    bPtr = &dObj;
    bPtr->disp();
}

