/*
 * Purpose : Write a program to demonstrate the use of the
 *           this pointer to differentiate between data members
 *           and function parameters having the same name.
 *
 * Author  : Harshinie M
 * Date    : 30-12-2025
 */

#include <iostream>
using namespace std;

class Test{
    int data;   // Data member of the class

public:
    // Function with parameter name same as data member
    void funOne(int data){
        // 'this->data' refers to the data member
        // 'data' refers to the function parameter
        this->data = data;
        cout << "funOne Data: " << data << endl;
    }

    // Function to display the stored data
    void funTwo(){
        cout << "funTwo Data: " << data << endl;
    }
};

int main(){
    // Create object of Test class
    Test obj;

    // Assign value using funOne()
    obj.funOne(10);

    // Display value using funTwo()
    obj.funTwo();

    return 0;
}

