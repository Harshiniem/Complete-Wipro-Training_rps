/*
 *Purpose: Write a recursive function to calculate the nth number in the Fibonacci series
 *Author: Harshinie M
 *Date: 22/12/2025
 *
 */
#include <stdio.h>

int fibonacci(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n = 7;

    printf("Fibonacci number at position %d is %d", n, fibonacci(n));
    return 0;
}

