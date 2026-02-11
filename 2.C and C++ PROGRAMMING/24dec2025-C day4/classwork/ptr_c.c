/*
Purpose: Demonstrate pointers of different data types in C
Author: Harshinie M
Date: 24/12/2025
*/

#include <stdio.h>

int main() {
    int a = 10;
    float b = 5.5;
    double c = 20.25;

    int* iPtr = &a;
    float* fPtr = &b;
    double* dPtr = &c;

    iPtr = (int*) dPtr;   // ✅ Allowed in C

    printf("iPtr: %p\n", iPtr);
    printf("fPtr: %p\n", fPtr);
    printf("dPtr: %p\n", dPtr);

    return 0;
}

