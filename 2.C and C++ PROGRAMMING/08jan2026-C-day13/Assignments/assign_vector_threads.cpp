/*
Purpose : Create 5 threads using vector to store thread objects
          and synchronize them with main using join().
Author  : Harshinie M
Date    : 08-01-2026
*/

#include <iostream>
#include <thread>
#include <vector>

// Function executed by threads
void task(int id)
{
    std::cout << "Thread " << id << " running" << std::endl;
}

int main()
{
    std::vector<std::thread> threads;

    // Create 5 threads
    for (int i = 1; i <= 5; i++)
    {
        threads.emplace_back(task, i);
    }

    // Join all threads
    for (auto &t : threads)
    {
        t.join();
    }

    return 0;
}
