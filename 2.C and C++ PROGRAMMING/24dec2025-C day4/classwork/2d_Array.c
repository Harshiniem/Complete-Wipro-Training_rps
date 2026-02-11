/*
Purpose: 2D dynamic array
Author: Harshinie M
Date: 24/12/2025
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int r, c, i, j;
    int** arr;

    printf("Enter rows and cols: ");
    scanf("%d %d", &r, &c);

    arr = (int**) malloc(r * sizeof(int*));

    for (i = 0; i < r; i++)
        arr[i] = (int*) malloc(c * sizeof(int));

    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            arr[i][j] = i + j;

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }

    return 0;
}

