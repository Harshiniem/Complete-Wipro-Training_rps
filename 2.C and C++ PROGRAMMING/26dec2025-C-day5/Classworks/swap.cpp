/*
 * Purpose          : swap 2 values 
		void swap(int *, int *);
		void swap(int &, int &);
 * Author           : Harshinie M
 * Date             : 26/12/2025
 */
#include <iostream>
using namespace std;

// Call by Address
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Call by Reference
void swapRef(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

int main() {
    int x = 10, y = 20;
    swap(&x, &y);
    cout << x << " " << y << endl;

    swapRef(x, y);
    cout << x << " " << y << endl;
    return 0;
}

