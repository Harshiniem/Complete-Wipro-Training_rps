/*
Purpose : To demonstrate reading an object of a class from a
          binary file using ifstream in C++.
Question: Write a C++ program to read an Employee object from a
          binary file and display its contents.
Author  : Harshinie M
Date    : 05/01/2026
*/

#include <iostream>
#include <cstring>
#include <fstream>
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
    Employee emps;        // Object with default values

    emps.disp();          // Display default values

    ifstream fObj("myData.dat", ios::binary); // Open binary file

    if (fObj){
        fObj.read((char*)&emps, sizeof(emps)); // Read object from file
        emps.disp();                            // Display read values
    }

    fObj.close();
    return 0;
}

