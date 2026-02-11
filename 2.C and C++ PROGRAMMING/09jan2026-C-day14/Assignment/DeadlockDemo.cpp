/*
 Purpose : Demonstrate deadlock scenario and its fix
 Question: Show deadlock using two mutexes and fix using std::lock
 Author  : Harshinie M
 Date    : 09/01/2026
*/

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex m1, m2;

void taskA()
{
    lock(m1, m2);
    lock_guard<mutex> lock1(m1, adopt_lock);
    lock_guard<mutex> lock2(m2, adopt_lock);
    cout << "Task A completed\n";
}

void taskB()
{
    lock(m1, m2);
    lock_guard<mutex> lock1(m1, adopt_lock);
    lock_guard<mutex> lock2(m2, adopt_lock);
    cout << "Task B completed\n";
}

int main()
{
    thread t1(taskA);
    thread t2(taskB);

    t1.join();
    t2.join();
    return 0;
}
