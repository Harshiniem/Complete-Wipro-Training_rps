/*
 Purpose : Demonstrate thread synchronization using condition_variable
 Question: Create a thread that waits for a notification using
           condition_variable and proceeds only after receiving it.
 Author  : Harshinie M
 Date    : 09/01/2026
*/

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <condition_variable>

using namespace std;

// Mutex and condition variable
mutex mVar;
condition_variable cVar;

// Shared condition flag
bool ready = false;

// Thread function
void funOne()
{
    unique_lock<mutex> lock(mVar);

    // Wait until 'ready' becomes true
    cVar.wait(lock, [] { return ready; });

    cout << "Received Notification.. Proceeding now " << ready << endl;
}

int main()
{
    // Create thread
    thread t1(funOne);

    // Simulate some work in main thread
    this_thread::sleep_for(chrono::seconds(2));

    {
        // Lock mutex and update condition
        lock_guard<mutex> lock(mVar);
        ready = true;
    }

    // Notify waiting thread
    cVar.notify_one();

    // Wait for thread to finish
    t1.join();

    return 0;
}
