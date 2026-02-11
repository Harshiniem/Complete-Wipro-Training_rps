/*
Purpose : Demonstrate dynamic array allocation using a function with exception handling in C++
Author  : Harshinie M
Date    : 06/01/2026
*/

#include <iostream>
using namespace std;

// dynamic array function declaration
void createArray(int);

int main(){
    try{
        createArray(10);     // create array of size 10
        createArray(20);     // create array of size 20
        createArray(-120);   // create array of size -120 (invalid)
        createArray(200);    // create array of size 200
    }
    catch(int var){ // handling the exception
        cout << "Caught int type Exception " << var << endl;
    }

    cout << "Executes normally even if exception occurs..." << endl;
}

// Function to create a dynamic array
void createArray(int size){
    if (size <= 0)
        throw size; // raising an exception if size is invalid

    int *arr = new int[size]; // dynamically allocate array

    for (int cnt = 0; cnt < size; cnt++)
        arr[cnt] = 1001 + cnt; // fill array with values

    cout << "Array: ";
    for (int cnt = 0; cnt < size; cnt++)
        cout << arr[cnt] << " ";
    cout << "\n************************************************\n";

    delete [] arr; // free memory
}

