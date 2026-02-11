#include <stdio.h>

int main() {
    int num = 10;  // number
    int pos = 3;   // bit position

    int res = num & (1 << pos);
    if(res)
        printf("%d bit on %d is ON\n", pos, num);
    else
        printf("%d bit on %d is OFF\n", pos, num);

    return 0;
}
