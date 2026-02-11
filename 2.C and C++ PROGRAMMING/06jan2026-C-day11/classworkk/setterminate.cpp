/*
Purpose : Demonstrate the use of set_terminate() and custom terminate handler when an exception is not caught
Author  : Harshinie M
Date    : 06/01/2026
*/

#include <iostream>
#include <cstdlib>    // for exit()
#include <exception>  // for set_terminate()
using namespace std;

// Custom terminate handler function
void funOne(){
    cout << "void funOne() called..." << endl;
    exit(1); // quits the program before abort() is called
}

int main(){
    set_terminate(funOne); // register custom terminate handler

    cout << "Outer statement #1" << endl;

    try {
        cout << "Inner statement #1" << endl;

        // throw 10;
        cout << "statement #2" << endl;

        // throw 104.34;
        cout << "statement #3" << endl;

        throw 104.34f; // float exception (no matching catch)

        cout << "statement #4" << endl;
    }
    catch(int x){
        cout << "Int type exception: " << x << endl;
    }
    catch(double x){
        cout << "Double type exception: " << x << endl;
    }

    cout << "Outer statement #5" << endl;
}

