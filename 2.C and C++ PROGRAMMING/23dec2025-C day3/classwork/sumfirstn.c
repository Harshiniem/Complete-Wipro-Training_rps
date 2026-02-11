/*
 * Purpose: Sum of first n numbers, where n is accepted from user 
 * Author: Harshinie M
 * Date: 23/12/2025
 */
#include <stdio.h>

int main() {
    int n, sum=0;
    scanf("%d", &n);

    for(int i=1;i<=n;i++)
        sum += i;

    printf("Sum = %d", sum);
    return 0;
}

