/*
Purpose : Write a C++ program to demonstrate multithreading using std::thread,
          where one thread prints '0' 100 times and the main thread prints
          'X' 100 times.
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

    // Main thread prints 'X' 100 times
    for (int cnt = 0; cnt < 100; cnt++)
    {
        std::cout << "X";
    }

    // Wait for thread t1 to finish
    t1.join();

    return 0;
}
