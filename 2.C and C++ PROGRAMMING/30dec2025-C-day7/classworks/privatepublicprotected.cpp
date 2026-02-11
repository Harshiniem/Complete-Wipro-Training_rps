/*
 * Purpose : Write a program to demonstrate how private, protected,
 *           and public members of a base class are accessed in
 *           a derived class using public inheritance.
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

// Derived class using public inheritance
class Derived : public Test{
public:
    void funFour(){
        // funOne();  // ❌ Not accessible (private member)

        funTwo();    // ✅ Accessible (protected member)
        funThree();  // ✅ Accessible (public member)
    }
};

int main(){
    // Create object of Derived class
    Derived dObj;

    // Public member can be accessed using object
    dObj.funThree();

    // Function of Derived class accessing inherited members
    dObj.funFour();

    return 0;
}

