/*
Purpose : Demonstrate exception handling using derived (invalid_argument) and base (exception) class catch blocks in C++
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

        throw invalid_argument("Message here"); // throw derived class exception

        cout << "statement #2" << endl;
    }
    catch(invalid_argument &e){   // derived class catch
        cout << "Derived: " << e.what() << endl;
    }
    catch(exception &e){          // base class catch
        cout << "Base class: " << e.what() << endl;
    }

    cout << "Outer statement #" << endl;
}

