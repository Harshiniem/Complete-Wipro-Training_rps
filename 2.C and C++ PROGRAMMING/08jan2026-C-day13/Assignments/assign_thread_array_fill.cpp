/*
Purpose : Create a C++ program to fill a global array of 100 elements using
          5 threads, where each thread fills exactly 20 elements.
Author  : Harshinie M
Date    : 08-01-2026
*/

#include <iostream>
#include <thread>

int arr[100];   // Global array of size 100

// Function to fill array elements
void fillArray(int startIndex, int count, int value)
{
    for (int i = startIndex; i < startIndex + count; i++)
    {
        arr[i] = value;
    }
}

int main()
{
    // Create 5 threads, each filling 20 elements
    std::thread t1(fillArray, 0, 20, 1);    // index 0–19
    std::thread t2(fillArray, 20, 20, 2);   // index 20–39
    std::thread t3(fillArray, 40, 20, 3);   // index 40–59
    std::thread t4(fillArray, 60, 20, 4);   // index 60–79
    std::thread t5(fillArray, 80, 20, 5);   // index 80–99

    // Wait for all threads to complete
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();

    // Print the array contents
    std::cout << "Array elements:\n";
    for (int i = 0; i < 100; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
