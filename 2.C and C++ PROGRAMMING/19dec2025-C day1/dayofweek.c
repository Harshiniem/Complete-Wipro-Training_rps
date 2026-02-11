#include <stdio.h>

int main() {

    int d = 19;
    int m = 12;
    int year = 2025;

    int y = year % 100;   // last two digits
    int c = 6;            // century code for 2000s
    int m_code = 5;       // December code

    int sum = d + m_code + y + (y / 4) + c;
    int day = sum % 7;

    if(day == 0) printf("Sunday\n");
    else if(day == 1) printf("Monday\n");
    else if(day == 2) printf("Tuesday\n");
    else if(day == 3) printf("Wednesday\n");
    else if(day == 4) printf("Thursday\n");
    else if(day == 5) printf("Friday\n");
    else if(day == 6) printf("Saturday\n");

    return 0;
}

