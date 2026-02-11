/*
 *Purpose: Initialize 5x3 2D array partially.
 *Author: Harshinie M
 *Date: 22/12/2025
 *
 */
#include <stdio.h>

int main() {
    int arr[][3] = {{10}, {20}, {30}, {40}, {50}};
    int row = 5, col = 3;

    for (int rCnt = 0; rCnt < row; rCnt++) {
        for (int cCnt = 0; cCnt < col; cCnt++)
            printf("%d  ", arr[rCnt][cCnt]);
        printf("\n");
    }
}

