/*
 * Purpose : Write a program to demonstrate how a static local variable
 *           inside a function retains its value across multiple
 *           function calls.
 *
 * Author  : Harshinie M
 * Date    : 30-12-2025
 */

#include <iostream>
using namespace std;

// Function declaration
int fun();

int main(){
    // Calling fun() multiple times
    cout << "fun() " << fun() << endl;
    cout << "fun() " << fun() << endl;
    cout << "fun() " << fun() << endl;
    cout << "fun() " << fun() << endl;

    return 0;
}

// Function definition
int fun(){
    // Static local variable
    // Initialized only once and value is retained between function calls
    static int var = 10;

    // Return current value and then increment
    return var++;
}

