/*
 * Purpose: largest of 3 numbers, where numbers are accepted by the user.
 * Author: Harshinie M
 * Date: 23/12/2025
 */
#include <stdio.h>

int main() {
    int a,b,c;
    scanf("%d %d %d", &a, &b, &c);

    if(a > b && a > c) printf("%d", a);
    else if(b > c) printf("%d", b);
    else printf("%d", c);

    return 0;
}

