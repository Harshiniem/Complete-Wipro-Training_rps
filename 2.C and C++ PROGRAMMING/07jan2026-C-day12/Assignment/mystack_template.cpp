/*
Purpose : Design a generic stack using class templates with operations
          push, pop, top, and isEmpty.
Author  : Harshinie M
Date    : 07/01/2026
*/

#include <iostream>
using namespace std;

template <typename T>
class MyStack
{
    T *arr;
    int topIndex, capacity;

public:
    MyStack(int cap = 5) : capacity(cap), topIndex(-1)
    {
        arr = new T[capacity];
    }

    void push(T value)
    {
        if (topIndex < capacity - 1)
            arr[++topIndex] = value;
    }

    void pop()
    {
        if (topIndex >= 0)
            topIndex--;
    }

    T top()
    {
        return arr[topIndex];
    }

    bool isEmpty()
    {
        return topIndex == -1;
    }

    ~MyStack()
    {
        delete[] arr;
    }
};

int main()
{
    MyStack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);

    while (!s.isEmpty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}

