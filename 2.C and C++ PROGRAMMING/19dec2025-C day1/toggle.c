#include <stdio.h>

int main() {
    int num = 10;
    int pos = 3;

    int result = num ^ (1 << pos); // toggle bit
    printf("After toggling %d bit on %d, num = %d\n", pos, num, result);

    return 0;
}
