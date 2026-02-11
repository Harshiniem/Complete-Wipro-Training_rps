/*
 * Purpose          : Implement the class Num with the given data and methods as given below.
	
		class Num{
			int num;
		public:
			void setNum(int n = 10);
			void dispNum();
			bool isEven();
			bool isPrime();

 * Author           : Harshinie M
 * Date             : 26/12/2025
 */
#include <iostream>
using namespace std;

class Num {
    int num;
public:
    Num(int n=10) { num = n; }

    void dispNum() {
        cout << num << endl;
    }

    bool isEven() {
        return num % 2 == 0;
    }

    bool isPrime() {
        if(num <= 1) return false;
        for(int i=2; i*i<=num; i++)
            if(num%i==0) return false;
        return true;
    }
};

int main()
{
    Num n1;      // default 10
    Num n2(7);   // custom

    n1.dispNum();
    n2.dispNum();

    return 0;
}

