/*
 *Purpose: Print numbers 1–25 in 5x5 matrix.
 *Author: Harshinie M
 *Date: 22/12/2025
 *
 */
#include <stdio.h>

int main() {
    int cntOne, cntTwo, num = 1;
    for (cntOne = 0; cntOne < 5; cntOne++) {
        for (cntTwo = 0; cntTwo < 5; cntTwo++)
            printf("%d ", num++);
        printf("\n");
    }
}

