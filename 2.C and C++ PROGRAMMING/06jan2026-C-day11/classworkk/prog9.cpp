/*
Purpose : Demonstrate stack unwinding with a wrapper (RAII) class where heap memory is safely released during exception handling
Author  : Harshinie M
Date    : 06/01/2026
*/

#include <iostream>
using namespace std;

struct Test{
    int data;
    Test(int x):data(x){
        cout << "Test(" << data << ")" << endl;
    }
    ~Test(){
        cout << "~Test()" << endl;
    }
};

class Pointer{   // Wrapper (RAII) class
    Test *ptr;
public:
    Pointer(int x): ptr(new Test(x)) {}
    ~Pointer(){
        delete ptr;
    }
};

void recur(int);

int main(){
    try{
        recur(1);
        cout << endl;
    }
    catch(int num){
        cout << "In main() Caught " << num << endl;
    }
    return 0;
}

void recur(int num){
    Pointer obj(num);   // stack-based wrapper object

    if(num <= 5){
        cout << num << " ";
        recur(num + 1);
        cout << num << " ";
    }

    throw num;   // exception is raised
}

