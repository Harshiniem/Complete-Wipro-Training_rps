/*
 * Purpose : Write a program to demonstrate operator overloading
 *           for arithmetic operators (+ and -) using member functions.
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

    // Overload '+' operator
    Num operator+(const Num& rhs){
        Num temp(data + rhs.data);  // Add data members
        return temp;                // Return new object
    }

    // Overload '-' operator
    Num operator-(const Num& rhs){
        Num temp(data - rhs.data);  // Subtract data members
        return temp;                // Return new object
    }

    // Display function
    void disp(ostream &out){
        out << "data: " << data << endl;
    }
};

int main(){
    // Create objects
    Num a = 100, b = 20;

    // Display initial values
    a.disp(cout);
    b.disp(cout);

    // Use overloaded '+' operator
    Num c = a + b;

    // Use combination of '+' and '-' operators
    Num d = c + a - b;

    // Display results
    c.disp(cout);
    d.disp(cout);

    return 0;
}

