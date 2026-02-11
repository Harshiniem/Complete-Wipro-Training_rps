/*
 * Purpose : Write a program to demonstrate operator overloading
 *           by overloading both prefix (++) and postfix (++)
 *           increment operators and show their behavior.
 *
 * Author  : Harshinie M
 * Date    : 30-12-2025
 */

#include <iostream>
using namespace std;

class Num{
    int data;   // Data member

public:
    // Constructor with default value
    Num(int x = 0) : data(x) {}

    // Prefix increment operator overloading
    Num& operator++(){
        cout << "Pre-fix" << endl;
        data++;              // Increment first
        return *this;        // Return modified object
    }

    // Postfix increment operator overloading
    Num operator++(int){
        cout << "Post-fix" << endl;

        // Store current state before increment
        Num temp(*this);

        data++;              // Increment after storing
        return temp;         // Return old value
    }

    // Display function
    void disp(ostream &out){
        out << "data: " << data << endl;
    }
};

int main(){
    Num a = 10;

    // Prefix increment
    ++a;
    a.disp(cout);

    // Postfix increment
    a++;
    a.disp(cout);

    return 0;
}

