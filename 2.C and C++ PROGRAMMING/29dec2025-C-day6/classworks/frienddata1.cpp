/*
 * Purpose:
 * Write a C++ program to demonstrate the use of a friend function
 * to access private data members of a class.
 * The program shows how a non-member function can access
 * private members when declared as a friend.
 *
 * Author: Harshinie M
 * Date  : 29-12-2025
 */

#include <iostream>
using namespace std;

class Box {
    int length; // private data member

public:
    // Parameterized constructor with default value
    Box(int len = 10) : length(len) {}

    // Friend function declaration
    friend void showLength(Box &b);
};

// Friend function definition
void showLength(Box &b) {
    cout << "Length : " << b.length << endl;
}

int main() {
    Box gift;        // Object created using default argument
    showLength(gift); // Friend function accessing private data
}

