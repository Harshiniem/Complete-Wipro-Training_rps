/*
 * Purpose : Write a program to demonstrate the accessibility of
 *           private, protected, and public members of a base class
 *           in a derived class using public inheritance.
 *
 * Author  : Harshinie M
 * Date    : 30-12-2025
 */

#include <iostream>
using namespace std;

class Test{
    // Private member by default
    void funOne(){
        cout << "Test::funOne() --> Private" << endl;
    }

protected:
    // Protected member
    void funTwo(){
        cout << "Test::funTwo() --> Protected" << endl;
    }

public:
    // Public member
    void funThree(){
        cout << "Test::funThree() --> Public" << endl;
    }
};

// Derived class with public inheritance
class Derived : public Test{
public:
    void funFour(){
        // funOne();   // ❌ Not accessible (private member)

        funTwo();     // ✅ Accessible (protected member)
        funThree();   // ✅ Accessible (public member)
    }
};

int main(){
    Derived dObj;

    // Accessing public member using object
    dObj.funThree();

    // Accessing inherited members inside derived class function
    dObj.funFour();

    return 0;
}

