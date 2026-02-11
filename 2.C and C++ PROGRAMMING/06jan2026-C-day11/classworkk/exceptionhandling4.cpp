/*
Purpose : Demonstrate multiple catch blocks in C++ to handle different types of exceptions (int, double, unknown)
Author  : Harshinie M
Date    : 06/01/2026
*/

#include <iostream>
using namespace std;

int main(){
    cout << "Outer statement #1" << endl;

    try {
        cout << "Inner statement #1" << endl;

        throw 10;       // throw an int exception
        cout << "statement #2" << endl;

        throw 104.34;   // throw a double exception (this will never execute)
        cout << "statement #3" << endl;
    }
    catch(int x){
        cout << "Int type exception: " << x << endl;
    }
    catch(double x){
        cout << "Double type exception: " << x << endl;
    }
    catch(...){
        cout << "Caught unknown type" << endl;
    }

    cout << "Outer statement #4" << endl;
}

