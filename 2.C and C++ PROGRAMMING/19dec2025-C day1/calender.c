#include <stdio.h>

int main() {
    int startDay = 1; // 0=Sun,1=Mon...
    int days = 30;

    printf("Su Mo Tu We Th Fr Sa\n");
    for(int i=0; i<startDay; i++)
        printf("   ");

    for(int day=1; day<=days; day++) {
        printf("%2d ", day);
        if((day + startDay) % 7 == 0)
            printf("\n");
    }
    printf("\n");

    return 0;
}

