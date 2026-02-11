/*
 * Purpose :  Read the longest string from a collection of  strings
 * Author  : Harshinie M
 * Date    : 23/12/2025
 */
#include <stdio.h>
#include <string.h>

int main() {
    char s[5][50] = {"C", "Programming", "Language", "Is", "Easy"};
    int i, max = 0;

    for(i = 1; i < 5; i++)
        if(strlen(s[i]) > strlen(s[max]))
            max = i;

    printf("Longest string: %s", s[max]);
}

