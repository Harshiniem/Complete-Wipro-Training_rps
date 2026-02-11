#include <stdio.h>

int main() {
    int num = 101;
    int flag = 0;

    if(num <= 1) flag = 1;

    for(int i = 2; i*i <= num; i++) {
        if(num % i == 0) {
            flag = 1;
            break;
        }
    }

    if(flag)
        printf("%d is NOT prime\n", num);
    else
        printf("%d is prime\n", num);

    return 0;
}
