/*
 *Purpose: Multiple functions calling each other.
 *Author: Harshinie M
 *Date: 22/12/2025
 *
 */
#include <stdio.h>

void fun();
void funOne();
void funTwo();
void funThree();

int main() {
    printf("1. in main()...\n");
    fun();
    printf("2. in main()...\n");
}

void fun() {
    printf("1. Inside fun()...\n");
    funOne();
    printf("2. Inside fun()...\n");
}

void funOne() {
    printf("1. Inside funOne()...\n");
    funTwo();
    printf("2. Inside funOne()...\n");
}

void funTwo() {
    printf("1. Inside funTwo()...\n");
    funThree();
    printf("2. Inside funTwo()...\n");
}

void funThree() {
    printf("Inside funThree()...\n");
}

