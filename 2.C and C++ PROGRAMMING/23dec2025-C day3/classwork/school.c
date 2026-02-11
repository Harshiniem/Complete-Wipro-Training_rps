/*
 * Purpose:  take name an age from the user.
	say if the age is 5+ --> elemetary school
					11+ --> middle school
					14+ --> High School 
					16+ ==> Pre-University
					18+ --> Under graduation..
					
					21+ --> Adult.
					
	For accepting a name(strings in C):

			char name[25];
			printf("Enter a name");
			scanf("%s", name);
		 
 * Author: Harshinie M
 * Date: 23/12/2025
 */
#include <stdio.h>

int main() {
    char name[25];
    int age;

    scanf("%s %d", name, &age);

    if(age >= 21) printf("Adult");
    else if(age >= 18) printf("Under Graduation");
    else if(age >= 16) printf("Pre-University");
    else if(age >= 14) printf("High School");
    else if(age >= 11) printf("Middle School");
    else if(age >= 5) printf("Elementary School");
    else printf("Too young");

    return 0;
}

