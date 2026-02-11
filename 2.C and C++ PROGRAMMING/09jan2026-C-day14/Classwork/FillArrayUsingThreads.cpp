/*
 Purpose : Fill an array of 100 elements using 5 threads
 Question: Create a global array of 100 elements and use 5 threads where
           each thread fills 20 elements of the array.
 Author  : Harshinie M
 Date    : 09/01/2026
*/

#include <iostream>
#include <thread>
#include <vector>

using namespace std;

// Global array of 100 elements
int arr[100];

// Thread function to fill part of the array
void fillArray(int startIndex, int count)
{
    for (int i = startIndex; i < startIndex + count; i++)
    {
        arr[i] = 100 + i;   // Assigning value for identification
    }
}

int main()
{
    const int numThreads = 5;
    const int elementsPerThread = 20;

    vector<thread> threads;

    // Creating 5 threads
    for (int i = 0; i < numThreads; i++)
    {
        threads.emplace_back(
            fillArray,
            i * elementsPerThread,   // Starting index
            elementsPerThread        // Number of elements
        );
    }

    // Waiting for all threads to finish
    for (auto &t : threads)
    {
        t.join();
    }

    cout << "Array: ";

    // Displaying the array
    for (int i = 0; i < 100; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}
