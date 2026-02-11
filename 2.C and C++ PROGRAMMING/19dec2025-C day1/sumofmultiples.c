#include <stdio.h>

int main() {
    long sum = 0;
    for(long i = 1; i < 1000000; i++) {
        if(i % 5 == 0 || i % 7 == 0)
            sum += i;
    }
    printf("Sum = %ld\n", sum);

    return 0;
}

