/*
Purpose : Demonstrate unwinding of stack during exception handling
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

void recur(int);   // function declaration

int main(){
    try{
        recur(1);
    }
    catch(int num){
        cout << "In main() Caught " << num << endl;
    }
}

//  function definition (THIS WAS MISSING / NOT FOUND)
void recur(int num){
    Test obj(num);   // stack-based object

    if(num <= 5){
        cout << num << " ";
        recur(num + 1);
        cout << num << " ";
    }

    throw num;
}


