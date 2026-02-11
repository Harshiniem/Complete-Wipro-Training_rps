/*
Purpose : Write a C++ program to demonstrate creation of multiple threads
          and pausing their execution using sleep_for() from <chrono>.
Author  : Harshinie M
Date    : 08-01-2026
*/

#include <iostream>
#include <thread>
#include <chrono>

// Function executed by each thread
void fun()
{
    std::cout << "fun() called" << std::endl;

    // Pause the current thread for 1 second
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

int main()
{
    // Create multiple threads executing the same function
    std::thread t1(fun);
    std::thread t2(fun);
    std::thread t3(fun);
    std::thread t4(fun);
    std::thread t5(fun);

    // Wait for all threads to complete
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();

    return 0;
}
