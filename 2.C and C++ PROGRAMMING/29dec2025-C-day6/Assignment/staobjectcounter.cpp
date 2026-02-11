/*
 * Purpose : Count number of objects created
 * Author  : Harshinie M
 * Date    : 29/12/2025
 */
#include <iostream>
using namespace std;

class Counter {
	static int count;
public:
	Counter(){
		count++;
	}
	static void showcount(){
		cout << "Total objects created: " << count << endl;
	}
};
int Counter::count = 0;

int main(){
	Counter c1;
	Counter c2;
	Counter c3;

	Counter::showcount();

	return 0;
}
