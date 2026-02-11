/*
 * Purpose: 2. Simple Interest Calcalulator by accepting principal, rate and duration--> (P * R * T ) / 100	--> Interest.
	Amount = Principal + Interest. 

 * Author: Harshinie M
 * Date: 23/12/2025
 */
#include <stdio.h>

int main() {
    float P, R, T, SI, amount;
    scanf("%f %f %f", &P, &R, &T);

    SI = (P * R * T) / 100;
    amount = P + SI;

    printf("Interest = %.2f\nAmount = %.2f", SI, amount);
    return 0;
}

