/*
 * Purpose:
 * Demonstrate Singleton design pattern in C++ using static member
 * to ensure only one object is created.
 *
 * Author: Harshinie M
 * Date  : 29-12-2025
 */

#include <iostream>
using namespace std;

class Singleton {
private: 
    static Singleton *ptr2Obj;

    // Private constructors
    Singleton() {
        cout << "Object created..." << endl;
    }
    Singleton(int x) {
        cout << "Object created...with " << x << endl;
    }
    Singleton(const Singleton &);

public: 
    // Static method to get single instance
    static Singleton& getSingleton() {
        if (ptr2Obj == nullptr)
            ptr2Obj = new Singleton();
        return *ptr2Obj;
    }        

    void disp() {
        cout << "Singleton::disp()" << endl;
    }
};

// Initialize static member
Singleton* Singleton::ptr2Obj = nullptr;

int main() {
    // Singleton objOne; // Error: constructor is private

    Singleton &refObj = Singleton::getSingleton();
    refObj.disp();
}

