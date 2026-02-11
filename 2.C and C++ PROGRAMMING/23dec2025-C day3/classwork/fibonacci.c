/*
 * Purpose: Print first n numbers in fibonacci series, where n is accepted from user 
 * Author: Harshinie M
 * Date: 23/12/2025
 */
#include <stdio.h>

int main() {
    int n, a=0, b=1, c;
    scanf("%d", &n);

    for(int i=1;i<=n;i++){
        printf("%d ", a);
        c = a + b;
        a = b;
        b = c;
    }
    return 0;
}

