/*
Purpose : Write a C++ program to demonstrate creation of a thread using
          a function object (functor).
Author  : Harshinie M
Date    : 08-01-2026
*/

#include <iostream>
#include <thread>

// Class with function call operator (functor)
class Test
{
public:
    void operator()()
    {
        std::cout << "Thread from Test" << std::endl;
    }
};

int main()
{
    // Create an object of Test class
    Test obj;

    // Create a thread using function object
    std::thread t1(obj);

    // Main thread execution
    std::cout << "Thread from main()" << std::endl;

    // Wait for thread t1 to complete
    t1.join();

    return 0;
}
