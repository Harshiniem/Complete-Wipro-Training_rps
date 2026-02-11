/*
Purpose : Write a C++ program to demonstrate multithreading using std::thread,
          where one thread continuously prints '0' and the main thread
          continuously prints 'X'.
Author  : Harshinie M
Date    : 08-01-2026
*/

#include <iostream>
#include <thread>

// Function that will run in a separate thread
void funOne()
{
    while (1)
    {
        std::cout << "0";
    }
}

int main()
{
    // Create a thread object and start funOne()
    std::thread t1(funOne);

    // Main thread prints 'X'
    while (1)
    {
        std::cout << "X";
    }

    // Good practice (never reached due to infinite loop)
    t1.join();

    return 0;
}
