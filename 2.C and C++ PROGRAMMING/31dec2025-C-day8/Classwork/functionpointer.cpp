/*
Purpose : Demonstrate calling a function using function pointer.
Author  : Harshinie M
Date    : 31/12/2025
*/

#include <stdio.h>

void fun();

int main(){
    void (*funPtr)();
    funPtr = fun;
    funPtr();
}

void fun(){
    printf("fun() called\n");
}

