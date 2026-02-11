/*
 *Purpose: Initialize partially and print all 100 elements.
 *Author: Harshinie M
 *Date: 22/12/2025
 *
 */
#include <stdio.h>

int main() {
    int arr[100] = {10, 20, 30}; // partial
    for (int cnt = 0; cnt < 100; cnt++)
        printf("%d  ", arr[cnt]);
    printf("\n");
}

