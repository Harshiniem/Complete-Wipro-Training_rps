/*
Purpose: Find largest and smallest element
Author: Harshinie M
Date: 24/12/2025
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    int* arr;

    printf("Enter size: ");
    scanf("%d", &n);

    arr = (int*) malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
        arr[i] = rand() % 100;

    int min = arr[0], max = arr[0];

    for (i = 1; i < n; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }

    printf("Min = %d\nMax = %d\n", min, max);

    free(arr);
    return 0;
}

