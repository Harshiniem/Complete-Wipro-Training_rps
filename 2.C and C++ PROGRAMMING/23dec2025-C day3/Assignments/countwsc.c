/*
 * Purpose : char str[] = "Have a lengthy string here"
		Count the number of words, characters and spaces. * Author  : Harshinie M 
 * Date    : 23/12/2025
 */
#include <stdio.h>

int main() {
    char s[] = "Have a lengthy string here";
    int i, w=1, sp=0;

    for(i=0; s[i]; i++)
        if(s[i]==' ') sp++;

    printf("Chars=%d Words=%d Spaces=%d", i, sp+1, sp);
}

