/*
Purpose: Delete element from dynamic array
Author: Harshinie M
Date: 24/12/2025
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, pos, i;
    int* arr;

    printf("Enter size: ");
    scanf("%d", &n);

    arr = (int*) malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter position to delete: ");
    scanf("%d", &pos);

    for (i = pos - 1; i < n - 1; i++)
        arr[i] = arr[i + 1];

    printf("After deletion: ");
    for (i = 0; i < n - 1; i++)
        printf("%d ", arr[i]);

    free(arr);
    return 0;
}

