/*
Purpose : Program to overload prefix and postfix ++ operators
Author  : Harshinie M
Date    : 30-12-2025
*/

#include <iostream>
using namespace std;

class Num
{
    int value;

public:
    // Constructor
    Num(int v = 0) { value = v; }

    // Prefix ++
    Num& operator++()
    {
        value++;      // increment first
        return *this; // return object
    }

    // Postfix ++
    Num operator++(int)
    {
        Num temp = *this; // save current value
        value++;          // increment
        return temp;      // return old value
    }

    void show() { cout << value << endl; }
};

int main()
{
    Num n1(5);

    cout << "Original value: ";
    n1.show();

    cout << "After Prefix ++: ";
    ++n1;       // calls prefix
    n1.show();

    cout << "After Postfix ++: ";
    n1++;       // calls postfix
    n1.show();

    return 0;
}

