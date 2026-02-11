/*
 *Purpose: Implement your own version of the strlen function
 *Author: Harshinie M
 *Date: 22/12/2025
 *
 */
#include <stdio.h>

int myStrLen(const char str[]) {
    int len = 0;

    while (str[len] != '\0') {
        len++;
    }

    return len;
}

int main() {
    char str[] = "Wipro";

    printf("Length of string: %d", myStrLen(str));
    return 0;
}

