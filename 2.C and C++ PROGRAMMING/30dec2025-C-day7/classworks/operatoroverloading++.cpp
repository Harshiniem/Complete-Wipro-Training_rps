/*
 * Purpose : Write a program to demonstrate operator overloading
 *           by overloading the prefix increment (++) operator
 *           using member function and returning object reference.
 *
 * Author  : Harshinie M
 * Date    : 30-12-2025
 */

#include <iostream>
using namespace std;

class Num{
    int data;   // Data member

public:
    // Constructor with default argument
    Num(int x = 0) : data(x) {}

    // Overloading prefix increment operator
    Num& operator++(){
        data++;          // Increment data
        return *this;    // Return current object
    }

    // Display function
    void disp(ostream &out){
        out << "data: " << data << endl;
    }
};

int main(){
    // Create object and initialize
    Num a = 10;

    // Prefix increment
    ++a;
    a.disp(cout);

    // Prefix increment again
    ++a;
    a.disp(cout);

    return 0;
}

