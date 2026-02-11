/*
Purpose : Implement DynArray class where memory is allocated dynamically and exceptions are used to handle incorrect sizes
Author  : Harshinie M
Date    : 06/01/2026
*/

#include <iostream>
using namespace std;

// DynArray class
class DynArray {
private:
    int *arr;   // pointer to store array dynamically
    int size;   // size of the array

public:
    // Constructor
    DynArray(int s) {
        if (s <= 0)
            throw s; // raise exception if size is invalid
        size = s;
        arr = new int[size]; // allocate memory dynamically

        // Fill array with values starting from 1001
        for (int i = 0; i < size; i++)
            arr[i] = 1001 + i;
    }

    // Function to display array
    void display() {
        cout << "Array: ";
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    // Destructor to free memory
    ~DynArray() {
        delete [] arr;
    }
};

int main() {
    try {
        DynArray a1(5);     // valid size
        a1.display();

        DynArray a2(10);    // valid size
        a2.display();

        DynArray a3(-3);    // invalid size → will throw exception
        a3.display();
    }
    catch(int e) {          // handle exception
        cout << "Caught int type Exception: " << e << endl;
    }

    cout << "Program executes normally even if exception occurs..." << endl;
}

