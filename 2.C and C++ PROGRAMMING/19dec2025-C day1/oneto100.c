#include <stdio.h>

int main() {
    int cnt;

    // For loop
    for(cnt=1; cnt<=100; cnt++)
        printf("%d ", cnt);
    printf("\n");

    // While loop
    cnt = 1;
    while(cnt <= 100) {
        printf("%d ", cnt);
        cnt++;
    }
    printf("\n");

    // Do-While loop
    cnt = 1;
    do {
        printf("%d ", cnt);
        cnt++;
    } while(cnt <= 100);
    printf("\n");

    return 0;
}

