/*
Purpose : Implement a generic class DynArray that can store elements of
          any data type and supports default constructor, parameterized
          constructors, destructor, and display operation.
Author  : Harshinie M
Date    : 07/01/2026
*/

#include <iostream>
using namespace std;

template <typename T>
class DynArray
{
    T *arr;
    int size;

public:
    DynArray() : arr(nullptr), size(0) {}

    DynArray(int s) : size(s)
    {
        arr = new T[size];
    }

    DynArray(int s, T value) : size(s)
    {
        arr = new T[size];
        for (int i = 0; i < size; i++)
            arr[i] = value;
    }

    void display()
    {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    ~DynArray()
    {
        delete[] arr;
    }
};

int main()
{
    DynArray<int> a1(5, 10);
    DynArray<double> a2(3, 2.5);

    a1.display();
    a2.display();

    return 0;
}

