/*
Purpose : Demonstrate throwing and catching standard C++ exception (invalid_argument) using exception base class
Author  : Harshinie M
Date    : 06/01/2026
*/

#include <iostream>
#include <cstdlib>
#include <exception>
using namespace std;

int main(){

    cout << "Outer statement #1" << endl;

    try {
        cout << "Inner statement #1" << endl;

        throw invalid_argument("Message here"); // throw standard exception

        cout << "statement #2" << endl;
    }
    catch(exception &e){ // catch base class reference
        cout << e.what() << endl;
    }

    cout << "Outer statement #" << endl;
}

