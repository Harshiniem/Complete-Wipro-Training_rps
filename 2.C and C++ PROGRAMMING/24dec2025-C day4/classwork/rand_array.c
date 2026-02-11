/*
Purpose: Create dynamic array and fill using rand()
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

    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}

