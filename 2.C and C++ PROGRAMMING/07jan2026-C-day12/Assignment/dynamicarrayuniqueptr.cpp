/*
Purpose : Create a dynamic array using unique_ptr instead of raw pointers
          inside createArray(size), initialize values, print elements,
          and ensure automatic cleanup.
Author  : Harshinie M
Date    : 07/01/2026
*/

#include <iostream>
#include <memory>
using namespace std;

unique_ptr<int[]> createArray(int size)
{
    unique_ptr<int[]> arr = make_unique<int[]>(size);

    for (int i = 0; i < size; i++)
        arr[i] = (i + 1) * 10;

    return arr;
}

int main()
{
    int size = 5;

    unique_ptr<int[]> myArray = createArray(size);

    for (int i = 0; i < size; i++)
        cout << myArray[i] << " ";

    cout << endl;

    return 0;
}

