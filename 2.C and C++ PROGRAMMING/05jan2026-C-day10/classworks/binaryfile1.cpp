/*
Purpose : To demonstrate writing an object of a class into a
          binary file using ofstream in C++.
Question: Write a C++ program to store an Employee object in a
          binary file using write() function.
Author  : Harshinie M
Date    : 05/01/2026
*/

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Employee{
    int id;
    char name[40];
    double sal;

public:
    Employee(int num = 1001, const char *na = "Sample #1", double sa = 15000.05)
        : id(num), sal(sa) {
        strcpy(name, na);
    }

    void disp(){
        cout << "Output Num: " << id
             << "\tName: " << name
             << "\tSal: " << sal << endl;
    }
};

int main(){
    Employee emps = Employee(1101, "Karthik", 15000.45);

    ofstream fObj("myData.dat", ios::binary); // Open binary file

    fObj.write((char*)&emps, sizeof(emps));  // Write object to file

    emps.disp();                             // Display object data

    fObj.close();
    return 0;
}

