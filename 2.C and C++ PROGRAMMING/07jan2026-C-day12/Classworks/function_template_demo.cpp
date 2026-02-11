/*
Purpose : Demonstrate function templates in C++ by passing arguments of
          different data types (int, char, float, double, and string)
          to the same function.
Author  : Harshinie M
Date    : 07/01/2026
*/

#include <iostream>     // Provides input-output stream objects like cout
using namespace std;    // Allows use of standard names without std:: prefix

// Template declaration
template <typename DT>  // DT is a placeholder for any data type
void fun(DT var)        // Function fun takes one argument of type DT
{
    cout << "var: " << var << endl;  // Prints the value of var
}

int main()
{
    fun(10);             // int argument passed
    fun('A');            // char argument passed
    fun(10.234f);        // float argument passed
    fun(10.234);         // double argument passed
    fun("C Style String"); // const char* (C-style string) passed

    return 0;            // Indicates successful program termination
}

