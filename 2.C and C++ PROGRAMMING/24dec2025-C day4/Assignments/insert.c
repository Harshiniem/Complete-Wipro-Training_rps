/*
Purpose: Insert element in dynamic array
Author: Harshinie M
Date: 24/12/2025
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, pos, val, i;
    int* arr;

    printf("Enter size: ");
    scanf("%d", &n);

    arr = (int*) malloc((n + 1) * sizeof(int));

    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter position and value: ");
    scanf("%d %d", &pos, &val);

    for (i = n; i >= pos; i--)
        arr[i] = arr[i - 1];

    arr[pos - 1] = val;

    for (i = 0; i <= n; i++)
        printf("%d ", arr[i]);

    free(arr);
    return 0;
}

