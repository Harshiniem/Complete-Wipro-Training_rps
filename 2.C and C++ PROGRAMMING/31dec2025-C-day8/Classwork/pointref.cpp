/*
Purpose : Demonstrate runtime polymorphism using
          base class pointer and reference.
Author  : Harshinie M
Date    : 31/12/2025
*/

#include <iostream>
using namespace std;

class Base{
public:
    virtual void funOne(){ cout<<"Base::funOne()"<<endl; }
    virtual void funTwo(){ cout<<"Base::funTwo()"<<endl; }
    virtual void funThree(){ cout<<"Base::funThree()"<<endl; }
};

class Derived : public Base{
public:
    void funOne(){ cout<<"Derived::funOne()"<<endl; }
    void funTwo(){ cout<<"Derived::funTwo()"<<endl; }
    void funThree(){ cout<<"Derived::funThree()"<<endl; }
};

void demoVirtFun(Base *bPtr){
    bPtr->funOne();
    bPtr->funTwo();
    bPtr->funThree();
}

void demoVirtFun(Base &bRef){
    bRef.funOne();
    bRef.funTwo();
    bRef.funThree();
}

int main(){
    Base bObj;
    Derived dObj;

    demoVirtFun(&bObj);
    demoVirtFun(dObj);
}

