/*
 * Purpose : Write a program to demonstrate returning the current
 *           object using the this pointer and perform method chaining.
 *
 * Author  : Harshinie M
 * Date    : 30-12-2025
 */

#include <iostream>
using namespace std;

class Test{
public:
    // Function returns reference to current object
    Test& funOne(){
        cout << "in funOne " << this << endl;
        return *this;   // return current object
    }

    // Another member function
    void funTwo(){
        cout << "in funTwo" << endl;
    }
};

int main(){
    // Create object of Test class
    Test objOne;

    // Method chaining using returned object
    objOne.funOne().funTwo();

    return 0;
}

