/*
 *Purpose: Write a program that concatenates two strings without using strcat.
 *Author: Harshinie M
 *Date: 22/12/2025
 *
 */
#include <stdio.h>

int main() {
    char str1[100] = "Hello";
    char str2[] = "World";
    int i = 0, j = 0;

    /* Move i to the end of str1 */
    while (str1[i] != '\0') {
        i++;
    }

    /* Copy str2 to the end of str1 */
    while (str2[j] != '\0') {
        str1[i] = str2[j];
        i++;
        j++;
    }

    str1[i] = '\0';   // null terminate

    printf("Concatenated String: %s", str1);
    return 0;
}

