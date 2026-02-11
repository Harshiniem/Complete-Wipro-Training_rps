/*
Purpose : Demonstrate overloading of assignment operator
          for primitive data and object assignment.
Author  : Harshinie M
Date    : 31/12/2025
*/

#include <iostream>
using namespace std;

class Test{
    int data;
public:
    Test(int x=0): data(x){}
    Test& operator=(int);
    Test& operator=(const Test&);
    friend ostream& operator<<(ostream &, const Test&);
};

int main(){
    Test obj;
    obj = 100;

    Test objOne;
    objOne = obj;

    cout<<"Obj: "<<obj<<"\t\tObjOne: "<<objOne<<endl;
}

Test& Test::operator=(int arg){
    data = arg;
    return *this;
}

Test& Test::operator=(const Test& rhs){
    data = rhs.data;
    return *this;
}

ostream& operator<<(ostream &out, const Test& arg){
    out<<"data: "<<arg.data;
    return out;
}

