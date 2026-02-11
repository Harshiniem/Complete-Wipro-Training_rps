/*
Purpose : Demonstrate the use of tellp() to show the position of the
          file write pointer while writing data into a file.
Author  : Harshinie M
Date    : 05/01/2026
*/

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream fout("dataTest.txt");

    cout << "Initial position: " << fout.tellp() << endl;

    fout << "Hello";
    cout << "After writing 'Hello': " << fout.tellp() << endl;

    fout << " World";
    cout << "After writing ' World': " << fout.tellp() << endl;

    fout.close();
    return 0;
}

