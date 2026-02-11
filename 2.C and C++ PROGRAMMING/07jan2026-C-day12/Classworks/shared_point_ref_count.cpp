/*
Purpose : Demonstrate the working of shared_ptr in C++ and how reference
          counting changes when multiple shared_ptr objects share ownership.
Author  : Harshinie M
Date    : 07/01/2026
*/

#include <iostream>
#include <memory>
using namespace std;

class Test
{
    int data;

public:
    Test(int num = 0) : data(num) { cout << "Test()" << endl; }
    ~Test() { cout << "~Test()" << endl; }
    void disp() { cout << "Test::disp(): " << data << endl; }
};

int main()
{
    shared_ptr<Test> ptrOne(new Test(100));

    cout << "1. Use count/Reference Count: " << ptrOne.use_count() << endl;

    {
        shared_ptr<Test> ptrTwo = ptrOne;

        cout << "2. Use count/Reference Count: \t" << ptrOne.use_count() << endl;
        cout << "2. Use count/Reference Count: \t" << ptrTwo.use_count() << endl;
    }

    cout << "3. Use count/Reference Count: " << ptrOne.use_count() << endl;

    return 0;
}

