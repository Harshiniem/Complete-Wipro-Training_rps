/*
Purpose : Write a C++ program to demonstrate thread synchronization using
          std::mutex to safely update a shared global variable.
Author  : Harshinie M
Date    : 08-01-2026
*/

#include <iostream>
#include <thread>
#include <mutex>

int globVar = 0;      // Shared global variable
std::mutex mVar;     // Mutex to protect shared resource

// Function executed by threads
void Update()
{
    // Lock the mutex before accessing shared resource
    mVar.lock();

    for (int cnt = 0; cnt < 100000; cnt++)
        globVar++;

    // Unlock the mutex after work is done
    mVar.unlock();
}

int main()
{
    // Create two threads
    std::thread t1(Update);
    std::thread t2(Update);

    // Main thread also updates the shared variable
    mVar.lock();
    for (int cnt = 0; cnt < 100000; cnt++)
        globVar++;
    mVar.unlock();

    // Wait for child threads to complete
    t1.join();
    t2.join();

    // Print final value of global variable
    std::cout << "global var: " << globVar << std::endl;

    return 0;
}
