/*
 * Purpose:
 * Demonstrate static data member and static member function in C++.
 *
 * Author: Harshinie M
 * Date  : 29-12-2025
 */

#include <iostream>
using namespace std;

class Employee {
    static string compName; // static data member

public:
    static string company() { // static member function
        return compName;
    }
};

int main() {
    cout << "Employee::company() --> " << Employee::company() << endl;

    Employee obj1;
    cout << "obj1.company() --> " << obj1.company() << endl;
}

// Static data member definition
string Employee::compName = "Wipro Ltd";

