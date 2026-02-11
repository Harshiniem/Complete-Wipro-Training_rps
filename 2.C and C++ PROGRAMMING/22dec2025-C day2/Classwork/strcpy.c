/*
 *Purpose: Copy a string into another array and print.
 *Author: Harshinie M
 *Date: 22/12/2025
 *
 */
#include <stdio.h>
#include <string.h>

int main() {
    char str[25] = "Hello How0 I am fine";
    char strCopy[30];

    printf("str: %s\tLen: %lu\tSize: %lu\n", str, strlen(str), sizeof(str));
    strcpy(strCopy, str);
    printf("Copied: %s\n", strCopy);
}

