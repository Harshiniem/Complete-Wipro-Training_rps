/*
 * Purpose: Character Arrays (2D Strings)
 * Author: Harshinie M
 * Date: 23/12/2025
 */
#include <stdio.h>

int main() {
    char names[][15] = {
        "Name One",
        "Name Two",
        "Name Three",
        "Name Four",
        "Name Five"
    };

    for(int i = 0; i < 5; i++) {
        printf("%s\n", names[i]);
    }
    return 0;
}

