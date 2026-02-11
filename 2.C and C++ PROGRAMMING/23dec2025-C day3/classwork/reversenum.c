/*
 * Purpose : Reverse a number. Where number is accepted from the user.
 * Author  : Harshinie M
 * Date    : 23/12/2025
 */
#include <stdio.h>

int main() {
    int n, rev=0;
    scanf("%d", &n);

    while(n != 0){
        rev = rev * 10 + (n % 10);
        n /= 10;
    }

    printf("Reverse = %d", rev);
    return 0;
}

