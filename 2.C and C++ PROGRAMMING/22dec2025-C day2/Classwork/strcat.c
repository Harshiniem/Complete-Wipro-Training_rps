/*
 *Purpose: Concatenate two strings.
 *Author: Harshinie M
 *Date: 22/12/2025
 *
 */
#include <stdio.h>
#include <string.h>

int main() {
    char str[25] = "Hello How I am fine";
    char strCopy[30] = "Hai, ";

    printf("str: %s\tLen: %lu\tSize: %lu\n", str, strlen(str), sizeof(str));
    strcat(strCopy, str);
    printf("Concatenated: %s\n", strCopy);
}

