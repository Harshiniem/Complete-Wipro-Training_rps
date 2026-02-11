/*
 * Purpose : Count of digits in a number. Where number is accepted from the user.
 * Author  : Harshinie M
 * Date    : 23/12/2025
 */
#include <stdio.h>

int main() {
    int n, count=0;
    scanf("%d", &n);

    while(n != 0){
        count++;
        n /= 10;
    }

    printf("Digits = %d", count);
    return 0;
}

