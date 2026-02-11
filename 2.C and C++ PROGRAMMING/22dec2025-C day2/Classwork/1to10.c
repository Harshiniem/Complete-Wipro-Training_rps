/*
 *Purpose: Use recursion to print numbers 1 to 10.
 *Author: Harshinie M
 *Date: 22/12/2025
 *
 */
#include <stdio.h>

void recur(int num) {
    if (num <= 10) {
        printf("%d  ", num);
        recur(num + 1);
    }
}

int main() {
    recur(1);
    printf("\n");
}

