/*
 *Purpose: Compare different strings.
 *Author: Harshinie M
 *Date: 22/12/2025
 *
 */
#include <stdio.h>
#include <string.h>

int main() {
    printf("Compare: %d\n", strcmp("Hello", "Hello"));  // same
    printf("Compare: %d\n", strcmp("Hello", "hello"));  // H != h
    printf("Compare: %d\n", strcmp("hello", "Hello"));  // h != H
}

