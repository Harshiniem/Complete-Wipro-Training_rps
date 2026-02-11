/*
 * Purpose: Using a loop implement the following?
		1 + 2 ^ 1 + 2 ^ 2 + 2 ^ 3 +... 2 ^ n 
		Where n is accepted from the user. Here n value cannot exceed 30 (validate using if). * Author: Harshinie M 
 * Date: 23/12/2025
 */
#include <stdio.h>
#include <math.h>

int main() {
    int n;
    long sum = 1;
    scanf("%d", &n);

    if(n > 30){
        printf("Invalid n");
        return 0;
    }

    for(int i=1;i<=n;i++)
        sum += pow(2, i);

    printf("Sum = %ld", sum);
    return 0;
}

