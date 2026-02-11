/*
 * Purpose : Write a program to demonstrate operator overloading
 *           entirely using friend functions for arithmetic operators
 *           (+, -) and the insertion operator (<<).
 *
 * Author  : Harshinie M
 * Date    : 30-12-2025
 */

#include <iostream>
using namespace std;

class Num{
    int data;   // Data member

public:
    // Constructor with default value
    Num(int x = 0) : data(x) {}

    // Friend functions for operator overloading
    friend Num operator+(const Num&, const Num&);
    friend Num operator-(const Num&, const Num&);
    friend ostream& operator<<(ostream &, const Num &);
};

// Overload '+' operator using friend function
Num operator+(const Num& lhs, const Num& rhs){
    Num temp(lhs.data + rhs.data);
    return temp;
}

// Overload '-' operator using friend function
Num operator-(const Num& lhs, const Num& rhs){
    Num temp(lhs.data - rhs.data);
    return temp;
}

// Overload '<<' operator using friend function
ostream& operator<<(ostream &out, const Num &obj){
    out << "data: " << obj.data;
    return out;  // Allows chaining
}

int main(){
    Num a = 100, b = 20;

    // Display initial objects
    cout << a << "   " << b << endl;

    // Perform arithmetic using overloaded operators
    Num c = a + b;
    Num d = c + a - b;

    // Display results
    cout << c << "   " << d << endl;

    return 0;
}

