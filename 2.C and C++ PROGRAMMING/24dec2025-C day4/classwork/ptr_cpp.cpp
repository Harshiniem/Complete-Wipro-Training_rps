/*
Purpose: Demonstrate pointers of different data types in C++
Author: Harshinie M
Date: 24/12/2025
*/

#include <iostream>
using namespace std;

int main() {
    int a = 10;
    float b = 5.5;
    double c = 20.25;

    int* iPtr = &a;
    float* fPtr = &b;
    double* dPtr = &c;

    // iPtr = dPtr;   // ❌ ERROR in C++ (type safety)

    // Type casting
    iPtr = static_cast<int*>( (void*) dPtr );

    cout << "iPtr: " << iPtr << endl;
    cout << "fPtr: " << fPtr << endl;
    cout << "dPtr: " << dPtr << endl;

    return 0;
}

