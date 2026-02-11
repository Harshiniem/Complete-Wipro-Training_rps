/*
 Purpose : Fill an array of 100 elements using 5 threads
 Question: Create a vector of 100 elements and use 5 threads where
           each thread fills 20 elements of the vector.
 Author  : Harshinie M
 Date    : 09/01/2026
*/

#include <iostream>
#include <thread>
#include <vector>

using namespace std;

// Thread function
void fillArray(vector<int> &arr, int startIndex, int count)
{
    for (int i = startIndex; i < startIndex + count; i++)
    {
        arr[i] = 100 + i;   // Assign values for verification
    }
}

int main()
{
    // Vector (dynamic array managed by STL)
    vector<int> vArr(100);

    const int numThreads = 5;
    const int elementsPerThread = 20;

    vector<thread> threads;

    // Creating threads
    for (int i = 0; i < numThreads; i++)
    {
        threads.emplace_back(
            fillArray,
            ref(vArr),               // Pass vector by reference
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

    // Display vector contents
    for (int i : vArr)
    {
        cout << i << " ";
    }

    cout << endl;

    return 0;
}
