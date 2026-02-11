/*
Purpose : To demonstrate reading a file word by word using
          ifstream and the extraction (>>) operator.
Question: Write a C++ program to read the contents of a file
          word by word and display them on the screen.
Author  : Harshinie M
Date    : 05/01/2026
*/

#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream fobj("ioThree.cpp");   // Open file in read mode
    string str;

    while (fobj >> str)            // Reads word by word
        cout << str << " ";

    fobj.close();
    return 0;
}

