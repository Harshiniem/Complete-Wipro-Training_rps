/*
 Purpose : Fill an array of 100 elements using 5 threads
 Question: Create a local static array of 100 elements inside main()
           and use 5 threads where each thread fills 20 elements.
 Author  : Harshinie M
 Date    : 09/01/2026
*/

#include <iostream>
#include <thread>
#include <vector>

using namespace std;

// Thread function
void fillArray(int* arr, int startIndex, int count)
{
    for (int i = startIndex; i < startIndex + count; i++)
    {
        arr[i] = 100 + i;   // Assign values for identification
    }
}

int main()
{
    // Local static array (shared across threads)
    static int arr[100];

    const int numThreads = 5;
    const int elementsPerThread = 20;

    vector<thread> threads;

    // Creating threads
    for (int i = 0; i < numThreads; i++)
    {
        threads.emplace_back(
            fillArray,
            arr,                     // Pointer to static array
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

    // Display array contents
    for (int i = 0; i < 100; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}
