/*
 Purpose : Demonstrate readers-writers synchronization
 Question: Allow multiple readers but only one writer at a time.
 Author  : Harshinie M
 Date    : 09/01/2026
*/

#include <iostream>
#include <thread>
#include <mutex>
#include <shared_mutex>

using namespace std;

shared_mutex rwMutex;
int resource = 0;

void reader(int id)
{
    shared_lock<shared_mutex> lock(rwMutex);
    cout << "Reader " << id << " reads value " << resource << endl;
}

void writer(int id)
{
    unique_lock<shared_mutex> lock(rwMutex);
    resource += 10;
    cout << "Writer " << id << " writes value " << resource << endl;
}

int main()
{
    thread r1(reader, 1);
    thread r2(reader, 2);
    thread r3(reader, 3);
    thread w1(writer, 1);
    thread w2(writer, 2);

    r1.join(); r2.join(); r3.join();
    w1.join(); w2.join();

    return 0;
}
