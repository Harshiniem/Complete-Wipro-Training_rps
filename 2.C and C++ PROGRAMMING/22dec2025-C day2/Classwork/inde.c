/*
 *Purpose: Call multiple functions independently.
 *Author: Harshinie M
 *Date: 22/12/2025
 *
 */
#include <stdio.h>

void fun() { printf("Inside fun()...\n"); }
void funOne() { printf("Inside funOne()...\n"); }
void funTwo() { printf("Inside funTwo()...\n"); }
void funThree() { printf("Inside funThree()...\n"); }

int main() {
    printf("1. in main()...\n");
    fun();
    funOne();
    funThree();
    printf("2. in main()...\n");
}

