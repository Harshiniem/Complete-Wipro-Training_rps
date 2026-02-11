/*
Purpose : Demonstrate virtual inheritance to solve
          the diamond inheritance problem.
Author  : Harshinie M
Date    : 31/12/2025
*/

#include <iostream>
using namespace std;

class Base{
public:
    void funOne(){ cout<<"Base::funOne()"<<endl; }
};

class BaseOne : virtual public Base{};
class BaseTwo : virtual public Base{};

class Derived : public BaseOne, public BaseTwo{};

int main(){
    Derived d;
    d.funOne();
}

