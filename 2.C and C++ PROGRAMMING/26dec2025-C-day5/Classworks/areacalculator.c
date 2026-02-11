/*
 * Purpose          : Area Calculator(function overloading)
		Create overloaded functions named area() to calculate:
			Area of a square
			Area of a rectangle
			Area of a circle
  
 * Author           : Harshinie M
 * Date             : 26/12/2025
 */
#include <iostream>
using namespace std;

int area(int side) {
    return side * side;
}

int area(int l, int b) {
    return l * b;
}

double area(double r) {
    return 3.14159 * r * r;
}

int main() {
    cout << "Square: " << area(5) << endl;
    cout << "Rectangle: " << area(4, 6) << endl;
    cout << "Circle: " << area(3.5) << endl;
    return 0;
}

