/*
 Purpose : Demonstrate a simple thread pool implementation
 Question: Create a thread pool that executes submitted tasks using
           worker threads, mutex, and condition_variable.
 Author  : Harshinie M
 Date    : 09/01/2026
*/

#include <iostream>
#include <thread>
#include <vector>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <chrono>

using namespace std;

class SimpleThreadPool
{
    vector<thread> workers;              // Worker threads
    queue<function<void()>> tasks;        // Task queue

    mutex mLock;
    condition_variable cLock;
    bool stop = false;

public:
    // Constructor: creates worker threads
    SimpleThreadPool(unsigned int num)
    {
        for (unsigned int i = 0; i < num; ++i)
        {
            workers.emplace_back([this] {
                while (true)
                {
                    function<void()> task;

                    {
                        unique_lock<mutex> lock(mLock);

                        // Wait until task is available or pool is stopped
                        cLock.wait(lock, [this] {
                            return stop || !tasks.empty();
                        });

                        if (stop && tasks.empty())
                            return;

                        task = move(tasks.front());
                        tasks.pop();
                    }

                    // Execute task outside the lock
                    task();
                }
            });
        }
    }

    // Submit a task to the pool
    void submit(function<void()> task)
    {
        {
            lock_guard<mutex> lock(mLock);
            tasks.push(task);
        }
        cLock.notify_one();
    }

    // Destructor: stops threads and joins them
    ~SimpleThreadPool()
    {
        {
            lock_guard<mutex> lock(mLock);
            stop = true;
        }

        cLock.notify_all();

        for (auto &t : workers)
            t.join();
    }
};

int main()
{
    // Create thread pool with 3 worker threads
    SimpleThreadPool pool(3);

    // Submit 6 tasks
    for (int i = 0; i < 6; ++i)
    {
        pool.submit([i] {
            cout << "Task " << i + 1
                 << " executed by thread "
                 << this_thread::get_id() << endl;

            this_thread::sleep_for(chrono::seconds(1));
        });
    }

    return 0;
}
