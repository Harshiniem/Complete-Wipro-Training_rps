/*
 *Purpose: Implement your own strlen() function.
 *Author: Harshinie M
 *Date: 22/12/2025
 *
 */
#include <stdio.h>

int myStrLen(const char *str) {
    int cnt = 0;
    while (str[cnt] != 0)
        cnt++;
    return cnt;
}

int main() {
    char str[25] = "Hello How0 I am fine";
    printf("str: %s\tLen: %d\tSize: %lu\n", str, myStrLen(str), sizeof(str));
}

