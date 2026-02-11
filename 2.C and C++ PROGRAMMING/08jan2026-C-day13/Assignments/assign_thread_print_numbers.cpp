/*
Purpose : Print numbers from 1 to 10 using threads by passing
          (a) a function and (b) a lambda expression.
Author  : Harshinie M
Date    : 08-01-2026
*/

#include <iostream>
#include <thread>

// Function to print numbers
void printNumbers()
{
    for (int i = 1; i <= 10; i++)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main()
{
    // Thread using function
    std::thread t1(printNumbers);

    // Thread using lambda
    std::thread t2([] {
        for (int i = 1; i <= 10; i++)
        {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    });

    t1.join();
    t2.join();

    return 0;
}
