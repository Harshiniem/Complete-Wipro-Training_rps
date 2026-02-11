/*
 *Purpose: Implement own version of strcpy().
 *Author: Harshinie M
 *Date: 22/12/2025
 *
 */
#include <stdio.h>

char *myStrCpy(char *dest, const char *src) {
    int cnt = 0;
    while(dest[cnt] = src[cnt])
        cnt++;
    return dest;
}

int main() {
    char str[25] = "Hello How0 I am fine";
    char strCopy[30];

    myStrCpy(strCopy, str);
    printf("Copied: %s\n", strCopy);
}

