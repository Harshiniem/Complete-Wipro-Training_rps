/*
Purpose : Program to overload operator new for a class
Author  : Harshinie M
Date    : 30-12-2025
*/

#include <iostream>
#include <cstdlib>
using namespace std;

class Test
{
    int data;

public:
    Test(int x = 0) : data(x) {}

    // Overload operator new
    void* operator new(size_t size)
    {
        cout << "Allocating " << size << " bytes\n";
        void *ptr = malloc(size);
        if (!ptr)
            throw bad_alloc();
        return ptr;
    }

    // Overload operator delete
    void operator delete(void *ptr)
    {
        cout << "Deleting memory\n";
        free(ptr);
    }

    void show()
    {
        cout << "Data = " << data << endl;
    }
};

int main()
{
    Test *t1 = new Test(10);
    t1->show();

    delete t1;

    return 0;
}

