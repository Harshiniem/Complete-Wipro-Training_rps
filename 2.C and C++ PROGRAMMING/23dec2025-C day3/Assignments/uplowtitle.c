/*
 * Purpose : 2. Convert given string(short/lengthy) to 
		--> upper case		
			where all the characters are in upper case 
		--> lower case		
			where all the characters are in lower case 
		--> title case 
			where first character in each word is in upper case  
 * Author  : Harshinie M
 * Date    : 23/12/2025
 */
#include <stdio.h>
#include <ctype.h>

#include <stdio.h>
#include <ctype.h>

int main() {
    char str[100];
    int i;

    printf("Enter a string:\n");
    gets(str);

    /* Upper Case */
    printf("\nUpper Case:\n");
    for(i = 0; str[i]; i++)
        putchar(toupper(str[i]));

    /* Lower Case */
    printf("\n\nLower Case:\n");
    for(i = 0; str[i]; i++)
        putchar(tolower(str[i]));

    /* Title Case */
    printf("\n\nTitle Case:\n");
    str[0] = toupper(str[0]);
    for(i = 1; str[i]; i++) {
        if(str[i-1] == ' ')
            putchar(toupper(str[i]));
        else
            putchar(tolower(str[i]));
    }

    return 0;
}

