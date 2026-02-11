#include <stdio.h>

int main() {
    int a = 5, b = 2;
    float x = 5.0, y = 2.0;

    printf("Addition: %d + %d = %d\n", a, b, a+b);
    printf("Subtraction: %d - %d = %d\n", a, b, a-b);
    printf("Multiplication: %d * %d = %d\n", a, b, a*b);
    printf("Integer division: %d / %d = %d\n", a, b, a/b);
    printf("Float division: %.2f / %.2f = %.2f\n", x, y, x/y);

    return 0;
}
