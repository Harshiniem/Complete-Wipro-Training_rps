/*
 * Purpose          : Implement the class Calendar with the given data and methods(functions) as given below.
	
		class Calendar{
			int day, month, Year;//private by default
		public:
			void setDate(int dd=1, mm=12, int yyyy=2025);
			bool valideDate();
			int dayOfWeek();
			int maxDays();
			bool isLeap();
			void printCalendar();			
		};

 * Author           : Harshinie M
 * Date             : 26/12/2025
 */
#include <iostream>
using namespace std;

class Num {
    int num;
public:
    Num(int n = 10) { num = n; }

    void dispNum() {
        cout << num << endl;
    }

    bool isEven() {
        return num % 2 == 0;
    }

    bool isPrime() {
        if (num <= 1) return false;
        for (int i = 2; i * i <= num; i++)
            if (num % i == 0) return false;
        return true;
    }
};

int main()
{
    Num n1;        // default value 10
    Num n2(7);     // custom value

    n1.dispNum();
    cout << "Even: " << n1.isEven() << endl;
    cout << "Prime: " << n1.isPrime() << endl;

    n2.dispNum();
    cout << "Even: " << n2.isEven() << endl;
    cout << "Prime: " << n2.isPrime() << endl;

    return 0;
}


