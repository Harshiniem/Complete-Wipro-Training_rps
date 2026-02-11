/*
 Purpose : Demonstrate synchronization using mutex
 Question: Create 3 threads that add numbers from 1 to 1000 to a shared
           variable using mutex (lock_guard and unique_lock).
 Author  : Harshinie M
 Date    : 09/01/2026
*/

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

int sum = 0;
mutex mtx;

// Using lock_guard
void addWithLockGuard()
{
    for (int i = 1; i <= 1000; i++)
    {
        lock_guard<mutex> lock(mtx);
        sum += i;
    }
}

// Using unique_lock
void addWithUniqueLock()
{
    for (int i = 1; i <= 1000; i++)
    {
        unique_lock<mutex> lock(mtx);
        sum += i;
    }
}

int main()
{
    thread t1(addWithLockGuard);
    thread t2(addWithUniqueLock);
    thread t3(addWithLockGuard);

    t1.join();
    t2.join();
    t3.join();

    cout << "Final Sum = " << sum << endl;

    return 0;
}
