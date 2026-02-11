/*
 * Purpose:
 * Demonstrate object copying in a class using an array in C++.
 *
 * Author: Harshinie M
 * Date  : 29-12-2025
 */

#include <iostream>
using namespace std;

class MyArray { // abstraction
    int arr[100]; // array
    int size;     // integer

public:
    MyArray();
    MyArray(int data);
    void printArray();
};

int main() {
    MyArray objTwo(100);       // parameterized constructor
    MyArray objThree = objTwo; // object copying

    objTwo.printArray();
    objThree.printArray();
}

MyArray::MyArray() {
    size = 100;
    for (int cnt = 0; cnt < size; cnt++)
        arr[cnt] = 0;
}

MyArray::MyArray(int data) {
    size = 100;
    for (int cnt = 0; cnt < size; cnt++)
        arr[cnt] = data + cnt;
}

void MyArray::printArray() {
    cout << "Size: " << size << "\tarray:" << endl;
    for (int cnt = 0; cnt < size; cnt++)
        cout << arr[cnt] << "  ";
    cout << endl;
}

