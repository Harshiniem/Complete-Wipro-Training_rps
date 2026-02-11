/*
 * Purpose :  Accept a lenthy string as a string. Split each word and store them as separate string in a 2 D array.
		(Converting 1 D to 2 D array) 

 * Author  : Harshinie M
 * Date    : 23/12/2025
 */
#include <stdio.h>

int main() {
    char str[] = "C programming is easy";
    char words[10][20];
    int i = 0, r = 0, c = 0;

    while(str[i]) {
        if(str[i] == ' ') {
            words[r][c] = '\0';
            r++; c = 0;
        } else {
            words[r][c++] = str[i];
        }
        i++;
    }
    words[r][c] = '\0';

    for(i = 0; i <= r; i++)
        printf("%s\n", words[i]);
}

