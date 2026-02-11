/*
 *Purpose: Develop a function that converts temperature between Celsius and Fahrenheit
 *Author: Harshinie M
 *Date: 22/12/2025
 *
 */
#include <stdio.h>

float celsiusToFahrenheit(float c) {
    return (c * 9 / 5) + 32;
}

float fahrenheitToCelsius(float f) {
    return (f - 32) * 5 / 9;
}

int main() {
    float c = 25, f = 77;

    printf("Celsius to Fahrenheit: %.2f\n", celsiusToFahrenheit(c));
    printf("Fahrenheit to Celsius: %.2f\n", fahrenheitToCelsius(f));

    return 0;
}

