/*
Purpose : Implement calculator using array of function pointers.
Author  : Harshinie M
Date    : 31/12/2025
*/

#include <stdio.h>

int Add(int,int);
int Sub(int,int);
int Mult(int,int);
int Divi(int,int);

typedef int (*FPTR)(int,int);

int calc(FPTR, int, int);

int main(){
    FPTR arr[] = {Add, Sub, Mult, Divi, NULL};

    for(int i=0; arr[i]!=NULL; i++)
        printf("Result: %d\n", calc(arr[i], 100, 20));
}

int Add(int x,int y){ return x+y; }
int Sub(int x,int y){ return x-y; }
int Mult(int x,int y){ return x*y; }
int Divi(int x,int y){ return x/y; }

int calc(FPTR fPtr, int x, int y){
    return fPtr(x,y);
}

