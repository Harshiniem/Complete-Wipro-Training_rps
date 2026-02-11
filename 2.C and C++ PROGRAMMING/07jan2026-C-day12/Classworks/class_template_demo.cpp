/*
Purpose : Demonstrate class templates in C++ by creating objects of the
          same class with different data types.
Author  : Harshinie M
Date    : 07/01/2026
*/

#include <iostream>
using namespace std;

template <typename T>
class Sample
{
    T data;

public:
    Sample(T arg = T()) : data(arg) {}
    void disp() { cout << "data: " << data << endl; }
};

int main()
{
    Sample<int> iObj(100);
    Sample<double> dObj(10.234);
    Sample<string> sObj(string("Some string here"));

    iObj.disp();
    dObj.disp();
    sObj.disp();

    return 0;
}

