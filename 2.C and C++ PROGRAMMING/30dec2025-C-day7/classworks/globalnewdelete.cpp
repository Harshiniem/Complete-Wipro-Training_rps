/*
 * Purpose : Write a program to demonstrate overloading of global
 *           new and delete operators for dynamic memory allocation
 *           and deallocation.
 *
 * Author  : Harshinie M
 * Date    : 30-12-2025
 */

#include <iostream>
#include <cstdlib>  // For malloc and free
using namespace std;

// Overloading global 'new' operator
void* operator new(size_t size){
    cout << "Global operator new with size: " << size << endl;

    void *ptr = malloc(size);  // Allocate memory

    if (ptr == NULL){
        throw bad_alloc();      // Throw exception if allocation fails
    }

    return ptr;                 // Return allocated memory
}

// Overloading global 'delete' operator
void operator delete(void *ptr){
    cout << "Global operator delete" << endl;
    free(ptr);                  // Free allocated memory
}

// Test structure
struct Test{
    int data;

    // Constructor
    Test(int x = 0) : data(x){
        cout << "Test()" << endl;
    }

    // Destructor
    ~Test(){
        cout << "~Test()" << endl;
    }
};

int main(){
    // Dynamic allocation using overloaded global new
    Test *ptr = new Test();

    // Deallocation using overloaded global delete
    delete ptr;

    return 0;
}

