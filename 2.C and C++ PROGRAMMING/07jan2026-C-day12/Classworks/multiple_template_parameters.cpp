/*
Purpose : Demonstrate function templates with multiple template parameters
          by passing arguments of different data types.
Author  : Harshinie M
Date    : 07/01/2026
*/

#include <iostream>
using namespace std;

template <typename DT, typename DU>
void fun(DT varOne, DU varTwo)
{
    cout << "varOne: " << varOne << "\tvarTwo: " << varTwo << endl;
}

int main()
{
    fun(10, 9273.35);
    fun('A', 10);
    fun(10.234f, "Hello");
    fun(10.234, 100);
    fun("C Style String", 123.34);

    return 0;
}

