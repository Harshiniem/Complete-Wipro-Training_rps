/*
Purpose : Demonstrate join() and detach() using two threads and
          observe execution order when main() exits.
Author  : Harshinie M
Date    : 08-01-2026
*/

#include <iostream>
#include <thread>

void joinedThread()
{
    std::cout << "Hello world from joined thread" << std::endl;
}

void detachedThread()
{
    std::cout << "Hello world from detached thread" << std::endl;
}

int main()
{
    std::thread t1(joinedThread);
    std::thread t2(detachedThread);

    t2.detach();   // runs independently
    t1.join();     // main waits

    std::cout << "Hello world from main" << std::endl;

    return 0;
}
