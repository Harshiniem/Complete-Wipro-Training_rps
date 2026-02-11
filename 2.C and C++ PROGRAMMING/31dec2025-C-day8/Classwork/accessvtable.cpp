/*
Purpose : Demonstrate internal working of virtual functions
          by manually accessing the virtual table.
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

using FPTR = void (*)();

void demoFun(Base *bPtr){
    long *vPtr = (long *)(bPtr);
    FPTR *vTable = ((FPTR *)*vPtr);
    vTable[0]();
    vTable[1]();
    vTable[2]();
}

int main(){
    Base bObj;
    demoFun(&bObj);
}

