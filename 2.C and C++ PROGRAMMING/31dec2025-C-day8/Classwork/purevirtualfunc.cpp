/*
Purpose : Demonstrate abstract base class using
          pure virtual function.
Author  : Harshinie M
Date    : 31/12/2025
*/

#include <iostream>
using namespace std;

class Base{
public:
    virtual void disp() = 0;
};

class Derived : public Base{
public:
    void disp(){ cout<<"Derived::disp()"<<endl; }
};

int main(){
    Base *bPtr;
    Derived dObj;

    bPtr = &dObj;
    bPtr->disp();
}

