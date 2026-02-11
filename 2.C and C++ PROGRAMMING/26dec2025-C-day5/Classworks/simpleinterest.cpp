/*
 * Purpose          : Simple Interest (default arguments)
 *                    Create a function simpleInterest() with:
 *                    - Principal
 *                    - Rate (default = 5%)
 *                    - Time (default = 1 year)
 * Author           : Harshinie M
 * Date             : 26/12/2025
 */
#include <iostream>
using namespace std;

double simpleInterest(double p, double r = 5, double t = 1) {
    return (p * r * t) / 100;
}

int main() {
    cout << simpleInterest(1000) << endl;
    cout << simpleInterest(1000, 7) << endl;
    cout << simpleInterest(1000, 7, 2) << endl;
    return 0;
}

