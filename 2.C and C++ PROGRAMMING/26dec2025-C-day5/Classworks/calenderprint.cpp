/*
 * Purpose          : 4. Calendar Printer
		Create a function printCalendar() with:
			Day(default = 1)
			Month (default = 12)
			Year (default = 2025                                                                                        * Author           : Harshinie M 
 * Date             : 26/12/2025
 */
#include <iostream>
using namespace std;

void printCalendar(int day = 1, int month = 12, int year = 2025) {
    cout << "Date: " << day << "/" << month << "/" << year << endl;
}

int main() {
    printCalendar();
    printCalendar(26);
    printCalendar(26, 12);
    printCalendar(26, 12, 2025);
    return 0;
}

