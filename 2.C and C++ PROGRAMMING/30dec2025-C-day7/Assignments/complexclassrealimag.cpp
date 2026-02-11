/*
Purpose : Program to overload +, - and << operators for Complex class
Author  : Harshinie M
Date    : 30-12-2025
*/

#include <iostream>
using namespace std;

class Complex
{
    int real, imag;

public:
    // Constructor
    Complex(int r = 0, int i = 0)
    {
        real = r;
        imag = i;
    }

    // Overload + operator
    Complex operator+(Complex c)
    {
        Complex temp;
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        return temp;
    }

    // Overload - operator
    Complex operator-(Complex c)
    {
        Complex temp;
        temp.real = real - c.real;
        temp.imag = imag - c.imag;
        return temp;
    }

    // Overload << operator (friend)
    friend ostream& operator<<(ostream &out, Complex &c);
};

// Definition of << operator
ostream& operator<<(ostream &out, Complex &c)
{
    out << c.real << " + " << c.imag << "i";
    return out;
}

int main()
{
    Complex c1(4, 5), c2(2, 3);

    Complex c3 = c1 + c2;
    Complex c4 = c1 - c2;

    cout << "Addition: " << c3 << endl;
    cout << "Subtraction: " << c4 << endl;

    return 0;
}

