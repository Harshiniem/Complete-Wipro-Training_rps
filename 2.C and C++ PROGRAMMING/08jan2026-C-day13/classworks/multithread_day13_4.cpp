/*
Purpose : Write a C++ program to demonstrate the use of detach() in multithreading,
          where a thread prints '0' 100 times and runs independently from main(),
          while the main thread prints 'X' 100 times.
Author  : Harshinie M
Date    : 08-01-2026
*/

#include <iostream>
#include <thread>

// Function that will run in a separate thread
void funOne()
{
    for (int cnt = 0; cnt < 100; cnt++)
    {
        std::cout << "0";
    }
}

int main()
{
    // Create a thread object and start funOne()
    std::thread t1(funOne);

    // Detach the thread (runs independently)
    t1.detach();

    // Main thread prints 'X' 100 times
    for (int cnt = 0; cnt < 100; cnt++)
    {
        std::cout << "X";
    }

    return 0;
}
