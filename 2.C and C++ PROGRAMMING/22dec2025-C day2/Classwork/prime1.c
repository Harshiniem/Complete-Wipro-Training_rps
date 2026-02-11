/*
 *Purpose: Check if a number is prime.
 *Author: Harshinie M
 *Date: 22/12/2025
 *
 */
#include <stdio.h>

int isPrime(int num) {
    int flag = 1;
    for (int cnt = 2; cnt < num; cnt++) {
        if (num % cnt == 0) {
            flag = 0;
            break;
        }
    }
    return flag;
}

int main() {
    printf("Res: %d\n", isPrime(101)); // prime
    printf("Res: %d\n", isPrime(100)); // not prime
}

