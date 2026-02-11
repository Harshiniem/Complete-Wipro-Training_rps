/*
 *Purpose: Create a string reverse function and test it with various inputs.
 *Author: Harshinie M
 *Date: 22/12/2025
 *
 */
#include <stdio.h>

void reverseString(char str[]) {
    int i = 0, j = 0;
    char temp;

    /* find length */
    while (str[j] != '\0') {
        j++;
    }
    j--;   // last character index

    /* swap characters */
    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;

        i++;
        j--;
    }
}

int main() {
    char str1[] = "hello";
    char str2[] = "Cprogram";
    char str3[] = "12345";

    reverseString(str1);
    reverseString(str2);
    reverseString(str3);

    printf("%s\n", str1);
    printf("%s\n", str2);
    printf("%s\n", str3);

    return 0;
}

