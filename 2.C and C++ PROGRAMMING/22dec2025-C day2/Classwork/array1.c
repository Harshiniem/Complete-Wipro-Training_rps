/*
 *Purpose: Fill array with 100 numbers, set non-primes to 0.
 *Author: Harshinie M
 *Date: 22/12/2025
 *
 */
#include <stdio.h>

int isPrime(int num) {
    int flag = 1;
    for (int cnt = 2; cnt < num; cnt++) {
        if (num % cnt == 0) {
            flag = 0;
            break;
        }
    }
    return flag;
}

int main() {
    int arr[100];
    printf("Enter the first Num: ");
    scanf("%d", &arr[0]);

    for (int cnt = 1; cnt < 100; cnt++)
        arr[cnt] = arr[0] + cnt;

    printf("Arr: ");
    for (int cnt = 0; cnt < 100; cnt++)
        printf("%d  ", arr[cnt]);
    printf("\n");

    for (int cnt = 0; cnt < 100; cnt++)
        if (isPrime(arr[cnt]) == 0)
            arr[cnt] = 0;

    printf("Arr: ");
    for (int cnt = 0; cnt < 100; cnt++)
        printf("%d  ", arr[cnt]);
    printf("\n");
}

