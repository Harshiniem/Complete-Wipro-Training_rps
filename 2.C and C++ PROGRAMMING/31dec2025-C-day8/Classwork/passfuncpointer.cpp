/*
Purpose : Demonstrate passing function pointer to another function.
Author  : Harshinie M
Date    : 31/12/2025
*/

#include <stdio.h>

void fun();
void funCaller(void (*)());

int main(){
    funCaller(fun);
}

void fun(){
    printf("fun() called\n");
}

void funCaller(void (*fPtr)()){
    fPtr();
}

