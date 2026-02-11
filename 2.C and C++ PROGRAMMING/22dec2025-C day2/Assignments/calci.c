/*
 *Purpose: Create a calculator using functions for each arithmetic operation
 *Author: Harshinie M
 *Date: 22/12/2025
 *
 */
#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int mul(int a, int b) {
    return a * b;
}

float div(int a, int b) {
    return (float)a / b;
}

int main() {
    int x = 10, y = 5;

    printf("Addition: %d\n", add(x, y));
    printf("Subtraction: %d\n", sub(x, y));
    printf("Multiplication: %d\n", mul(x, y));
    printf("Division: %.2f\n", div(x, y));

    return 0;
}

