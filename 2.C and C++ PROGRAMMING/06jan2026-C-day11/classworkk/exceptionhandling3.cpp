/*
Purpose : Demonstrate dynamic array creation using a function where each function handles its own exceptions so program continues even if some inputs are invalid
Author  : Harshinie M
Date    : 06/01/2026
*/

#include <iostream>
using namespace std;

// function declaration
void createArray(int);

int main(){
    createArray(10);      // create array of size 10
    createArray(20);      // create array of size 20
    createArray(-120);    // create array of size -120 (invalid)
    createArray(200);     // create array of size 200

    cout << "Executes normally even if exception occurs..." << endl;
}

// Function definition
void createArray(int size){
    try{
        if (size <= 0)
            throw size; // raise exception if size is invalid

        int *arr = new int[size]; // dynamically allocate array

        for (int cnt = 0; cnt < size; cnt++)
            arr[cnt] = 1001 + cnt; // fill array

        cout << "Array: ";
        for (int cnt = 0; cnt < size; cnt++)
            cout << arr[cnt] << " "; // print array
        cout << "\n************************************************\n";

        delete [] arr; // free memory
    }
    catch(int var){ // handle exception inside the function
        cout << "Caught int type Exception " << var << endl;
    }
}

