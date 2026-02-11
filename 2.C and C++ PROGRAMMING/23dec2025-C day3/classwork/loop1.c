/*
 * Purpose : Print the following patterns: 
	Where n is accepted from the user for number of lines
	
	 	 
	1. 	
		*
		* *
		* * *
		* * * *
	2. 	
		1
		1 2
		1 2 3
		1 2 3 4
	3. 	
		* * * *
		* * *
		* *
		*
 
 * Author  : Harshinie M
 * Date    : 23/12/2025
 */
#include <stdio.h>

#include <stdio.h>

int main() {
    int n;

    printf("Enter number of lines: ");
    scanf("%d", &n);

    /* Pattern 1 */
    printf("\nPattern 1:\n");
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++)
            printf("* ");
        printf("\n");
    }

    /* Pattern 2 */
    printf("\nPattern 2:\n");
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++)
            printf("%d ", j);
        printf("\n");
    }

    /* Pattern 3 */
    printf("\nPattern 3:\n");
    for(int i = n; i >= 1; i--) {
        for(int j = 1; j <= i; j++)
            printf("* ");
        printf("\n");
    }

    return 0;
}

