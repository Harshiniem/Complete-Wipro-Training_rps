/*
 *Purpose: Recursion printing numbers forward and backward.
 *Author: Harshinie M
 *Date: 22/12/2025
 *
 */
#include <stdio.h>

void funOne(int num) {
    if (num <= 5) {
        printf("%d  ", num);
        funOne(num + 1);
        printf("%d  ", num);
    }
}

int main() {
    funOne(1);
    printf("\n");
}

