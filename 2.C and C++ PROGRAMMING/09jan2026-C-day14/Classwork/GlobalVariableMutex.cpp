/*
 Purpose : Demonstrate synchronization using mutex
 Question: Create multiple threads to update a global variable safely
           using mutex to avoid race condition.
 Author  : Harshinie M
 Date    : 09/01/2026
*/

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

// Global variable shared among threads
int globVar = 0;

// Mutex for synchronization
mutex mVar;

// Thread function
void Update()
{
    // Acquire lock on mutex
    unique_lock<mutex> lock(mVar);

    for (int cnt = 0; cnt < 100000; cnt++)
        globVar++;

    // Explicitly release lock
    lock.unlock();
}

int main()
{
    // Create three threads
    thread t1(Update);
    thread t2(Update);
    thread t3(Update);

    // Wait for threads to finish
    t1.join();
    t2.join();
    t3.join();

    // Display final value
    cout << "global var: " << globVar << endl;

    return 0;
}
