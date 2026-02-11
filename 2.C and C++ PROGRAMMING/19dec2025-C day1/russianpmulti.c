#include <stdio.h>

int main() {
    int a = 13, b = 24;
    int result = 0;
    int x = a, y = b;

    printf("First\tSecond\tResult\n");
    while(x > 0) {
        printf("%d\t%d\t%d\n", x, y, result);
        if(x % 2 != 0)
            result += y;
        x /= 2;
        y *= 2;
    }
    printf("Multiplication Result = %d\n", result);

    return 0;
}
