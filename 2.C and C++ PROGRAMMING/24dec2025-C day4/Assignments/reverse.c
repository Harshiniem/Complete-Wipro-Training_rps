/*
Purpose: Reverse dynamic array
Author: Harshinie M
Date: 24/12/2025
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, temp;
    int* arr;

    printf("Enter size: ");
    scanf("%d", &n);

    arr = (int*) malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for (i = 0; i < n / 2; i++) {
        temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }

    printf("Reversed: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    free(arr);
    return 0;
}

