/*
 Purpose : Synchronize console output using mutex
 Question: Create 3 threads printing numbers from 1 to 10
           without interleaving output.
 Author  : Harshinie M
 Date    : 09/01/2026
*/

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex ioMutex;

void printSeries(int id)
{
    lock_guard<mutex> lock(ioMutex);

    cout << "Thread #" << id << ": ";
    for (int i = 1; i <= 10; i++)
        cout << i << " ";
    cout << endl;
}

int main()
{
    thread t1(printSeries, 1);
    thread t2(printSeries, 2);
    thread t3(printSeries, 3);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}
