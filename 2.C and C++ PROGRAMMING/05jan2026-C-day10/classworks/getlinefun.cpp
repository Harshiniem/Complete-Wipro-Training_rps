/*
Purpose : To demonstrate reading a file line by line using
          ifstream and getline() function.
Question: Write a C++ program to read the contents of a file
          line by line and display them on the screen.
Author  : Harshinie M
Date    : 05/01/2026
*/

#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream fobj("ioThree.cpp");   // Open file in read mode
    string str;

    while (getline(fobj, str))     // Reads line by line
        cout << str << endl;

    fobj.close();
    return 0;
}

