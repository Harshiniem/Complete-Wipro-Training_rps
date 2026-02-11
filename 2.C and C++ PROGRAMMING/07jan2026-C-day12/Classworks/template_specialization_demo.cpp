/*
Purpose : Demonstrate template specialization by defining a general
          template function and a specialized version for C-style strings.
Author  : Harshinie M
Date    : 07/01/2026
*/

#include <iostream>
using namespace std;

template <typename DT>
void fun(DT var)
{
    cout << "var: " << var << endl;
}

void fun(const char *cStr)
{
    cout << "C Style " << cStr << endl;
}

int main()
{
    fun(10);
    fun(234.345);
    fun("C Style String Here");

    return 0;
}

