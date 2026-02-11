/*
 * Purpose : Write a program to demonstrate class-specific
 *           overloading of new and delete operators for dynamic
 *           memory allocation and deallocation.
 *
 * Author  : Harshinie M
 * Date    : 30-12-2025
 */

#include <iostream>
#include <cstdlib>  // For malloc and free
using namespace std;

class Test{
    int data;   // Data member

public:
    // Constructor
    Test(int x = 0) : data(x) {}

    // Overloaded class-specific new operator
    void* operator new(size_t size){
        cout << "Test::operator new size: " << size << endl;

        void *ptr = malloc(size);   // Allocate memory
        if (ptr == NULL)
            throw bad_alloc();      // Throw exception if allocation fails
        return ptr;
    }

    // Overloaded class-specific delete operator
    void operator delete(void *ptr){
        cout << "Test::operator delete" << endl;
        free(ptr);                  // Deallocate memory
    }
};

int main(){
    // Dynamic allocation using class-specific new
    Test *ptr = new Test(100);

    // Deallocation using class-specific delete
    delete ptr;

    return 0;
}

