/*
Purpose : Demonstrate class template specialization by providing a
          specialized class definition for const char* data type.
Author  : Harshinie M
Date    : 07/01/2026
*/

#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
class Sample
{
    T data;

public:
    Sample(T arg = T()) : data(arg) {}
    void disp() { cout << "data: " << data << endl; }
};

template <>
class Sample<const char *>
{
    char *data;

public:
    Sample(const char *arg)
    {
        data = new char[strlen(arg) + 1];
        strcpy(data, arg);
    }

    void disp() { cout << "const char * --->  data: " << data << endl; }

    ~Sample() { delete[] data; }
};

int main()
{
    Sample<int> iObj(100);
    Sample<double> dObj(10.234);
    Sample<const char *> sObj("Some string here");

    iObj.disp();
    dObj.disp();
    sObj.disp();

    return 0;
}

