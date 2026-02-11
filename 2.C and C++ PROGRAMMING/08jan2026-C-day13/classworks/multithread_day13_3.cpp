/*
Purpose : Write a C++ program to demonstrate multithreading using std::thread
          with a lambda expression.
Author  : Harshinie M
Date    : 08-01-2026
*/

#include <iostream>
#include <thread>

int main()
{
    // Create a thread using a lambda expression
    std::thread t1([] {
        std::cout << "Inside lambda here" << std::endl;
    });

    // Code executed by the main thread
    std::cout << "In main()" << std::endl;

    // Wait for thread t1 to finish execution
    t1.join();

    return 0;
}
