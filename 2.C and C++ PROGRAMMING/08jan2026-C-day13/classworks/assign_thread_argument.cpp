/*
Purpose : Write a C++ program to demonstrate passing arguments to a thread
          function using std::thread.
Author  : Harshinie M
Date    : 08-01-2026
*/

#include <iostream>
#include <thread>

// Function executed by the new thread
void funOne(int arg)
{
    std::cout << "New Thread: " << arg << std::endl;
}

int main()
{
    // Create a thread and pass argument to the function
    std::thread t1(funOne, 100);

    // Code executed by main thread
    std::cout << "Main Thread:" << std::endl;

    // Wait for thread to complete
    t1.join();

    return 0;
}
