/*
 * Purpose : Write a program to demonstrate operator overloading
 *           for arithmetic operators (+ and -) as member functions
 *           and overloading the insertion operator (<<) using
 *           a friend function.
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

    // Overload '+' operator as member function
    Num operator+(const Num& rhs){
        Num temp(data + rhs.data);  // Add data members
        return temp;
    }

    // Overload '-' operator as member function
    Num operator-(const Num& rhs){
        Num temp(data - rhs.data);  // Subtract data members
        return temp;
    }

    // Friend function to overload '<<' operator
    friend ostream& operator<<(ostream &out, const Num &obj);
};

// Overloading '<<' operator using friend function
ostream& operator<<(ostream &out, const Num &obj){
    out << "data: " << obj.data;
    return out;  // Allow chaining
}

int main(){
    // Create objects
    Num a = 100, b = 20;

    // Display using overloaded '<<'
    cout << a << "   " << b << endl;

    // Perform arithmetic using overloaded operators
    Num c = a + b;
    Num d = c + a - b;

    // Display results using overloaded '<<'
    cout << c << "   " << d << endl;

    return 0;
}

