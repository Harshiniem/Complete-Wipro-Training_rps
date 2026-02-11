/*
Purpose : Demonstrate ambiguity resolution in multiple inheritance
          when base classes contain functions with the same name.
Author  : Harshinie M
Date    : 31/12/2025
*/

#include <iostream>
using namespace std;

class BaseOne{
public:
    void funOne(){ cout<<"BaseOne::funOne()"<<endl; }
    void funTwo(){ cout<<"BaseOne::funTwo()"<<endl; }
};

class BaseTwo{
public:
    void funOne(){ cout<<"BaseTwo::funOne()"<<endl; }
    void funTwo(){ cout<<"BaseTwo::funTwo()"<<endl; }
};

class Derived : public BaseOne, public BaseTwo { };

int main(){
    Derived dObj;
    dObj.BaseOne::funOne();
    dObj.BaseTwo::funTwo();
}

