/*
 * Purpose : Write a program to demonstrate how the strtok() function
 *           is used to split a string into tokens using space as
 *           a delimiter.
 *
 * Author  : Harshinie M
 * Date    : 30-12-2025
 */

#include <stdio.h>
#include <string.h>

int main(){
    // Input string to be tokenized
    char str[] =
        "One way of using a class is by creating objects and using the member through that object";

    // First call to strtok(): pass string address and delimiter
    char *ptr = strtok(str, " ");

    // Loop until no more tokens are found
    while(ptr != NULL){
        // Print each token
        printf("%s\n", ptr);

        // Subsequent calls: pass NULL to continue tokenizing same string
        ptr = strtok(NULL, " ");
    }

    return 0;
}

