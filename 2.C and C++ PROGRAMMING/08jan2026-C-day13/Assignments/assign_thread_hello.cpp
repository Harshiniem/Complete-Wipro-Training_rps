/*
Purpose : Create a C++ program that creates a single thread and prints
          "Hello world from thread" and "Hello world from main".
Author  : Harshinie M
Date    : 08-01-2026
*/

#include <iostream>
#include <thread>

// Function executed by the thread
void helloThread()
{
    std::cout << "Hello world from thread" << std::endl;
}

int main()
{
    // Create a single thread
    std::thread t1(helloThread);

    // Code executed by main thread
    std::cout << "Hello world from main" << std::endl;

    // Wait for thread to finish
    t1.join();

    return 0;
}
