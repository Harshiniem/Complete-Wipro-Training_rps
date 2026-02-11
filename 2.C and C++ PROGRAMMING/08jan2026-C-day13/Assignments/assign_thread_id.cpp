/*
Purpose : Create 3 threads and print their thread IDs using
          std::this_thread::get_id().
Author  : Harshinie M
Date    : 08-01-2026
*/

#include <iostream>
#include <thread>

// Function to print thread ID
void printID()
{
    std::cout << "Thread ID: "
              << std::this_thread::get_id()
              << std::endl;
}

int main()
{
    std::thread t1(printID);
    std::thread t2(printID);
    std::thread t3(printID);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}
