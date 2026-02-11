/*
 * Purpose:  Swapping  2 numbers using temporary variable.

 * Author: Harshinie M
 * Date: 23/12/2025
 */
#include <stdio.h>

int main() {
    int a, b, temp;
    scanf("%d %d", &a, &b);

    temp = a;
    a = b;
    b = temp;

    printf("a=%d b=%d", a, b);
    return 0;
}

