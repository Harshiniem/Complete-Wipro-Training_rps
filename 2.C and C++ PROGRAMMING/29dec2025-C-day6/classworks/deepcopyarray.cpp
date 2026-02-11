/*
 * Purpose:
 * Demonstrate deep copy using copy constructor
 * to avoid dangling pointer issues in C++.
 *
 * Author: Harshinie M
 * Date  : 29-12-2025
 */

#include <iostream>
using namespace std;

// Code demonstrates deep copy to avoid dangling pointer
class MyArray {
    int *arr;
    int size;

public:
    MyArray();
    MyArray(int data);
    MyArray(const MyArray&);
    void printArray();

    ~MyArray() {
        if (size) {
            delete[] arr;
        }
        size = 0;
    }
};

int main() {
    MyArray objTwo(100); // parameterized constructor
    objTwo.printArray();

    {
        MyArray objThree = objTwo; // copy constructor (deep copy)
        objThree.printArray();
    } // objThree destroyed here

    objTwo.printArray(); // safe access, no dangling pointer
}

MyArray::MyArray(const MyArray& rhs) {
    size = rhs.size;
    arr = new int[size]; // separate memory allocation
    for (int cnt = 0; cnt < size; cnt++)
        arr[cnt] = rhs.arr[cnt];
}

MyArray::MyArray() : size(10) {
    arr = new int[size];
    for (int cnt = 0; cnt < size; cnt++)
        arr[cnt] = 0;
}

MyArray::MyArray(int sz) : size(sz) {
    int data = 101;
    arr = new int[size];
    for (int cnt = 0; cnt < size; cnt++)
        arr[cnt] = data + cnt;
}

void MyArray::printArray() {
    cout << "Size: " << size << "\tarray:" << endl;
    for (int cnt = 0; cnt < size; cnt++)
        cout << arr[cnt] << "  ";
    cout << endl;
}

