#include <stdio.h>

int main() {
    int num = 23;

    if(num % 100 >= 11 && num % 100 <= 13)
        printf("%dth\n", num);
    else if(num % 10 == 1)
        printf("%dst\n", num);
    else if(num % 10 == 2)
        printf("%dnd\n", num);
    else if(num % 10 == 3)
        printf("%drd\n", num);
    else
        printf("%dth\n", num);

    return 0;
}
