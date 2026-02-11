/*
 * Purpose : Find and replace a substring in a lengthy string. here substring and replacement substring can be of different length.
 * Author  : Harshinie M
 * Date    : 23/12/2025
 */
#include <stdio.h>
#include <string.h>

int main() {
    char s[100]="I love C", f[]="C", r[]="C language", out[150];
    int i=0,j=0,k;

    while(s[i]) {
        if(strncmp(&s[i], f, strlen(f))==0) {
            for(k=0;r[k];k++) out[j++]=r[k];
            i+=strlen(f);
        } else out[j++]=s[i++];
    }
    out[j]='\0';

    printf("%s", out);
}

