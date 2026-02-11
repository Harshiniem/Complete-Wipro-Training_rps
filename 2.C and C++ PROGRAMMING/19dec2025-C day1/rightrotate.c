#include <stdio.h>

int main() {
    unsigned char num = 10; // 00001010
    int pos = 2;

    unsigned char result = (num >> pos) | (num << (8 - pos));
    printf("Right Rotate result = %d\n", result);

    return 0;
}
