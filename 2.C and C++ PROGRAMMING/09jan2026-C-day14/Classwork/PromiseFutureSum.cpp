/*
 Purpose : Demonstrate inter-thread communication using promise and future
 Question: Create a thread that calculates the sum of numbers and sends
           the result to the main thread using promise and future.
 Author  : Harshinie M
 Date    : 09/01/2026
*/

#include <iostream>
#include <thread>
#include <chrono>
#include <future>

using namespace std;

// Thread function
void calculateSum(promise<int> prom)
{
    int sum = 0;

    for (int i = 1; i <= 10; i++)
    {
        this_thread::sleep_for(chrono::seconds(1));
        sum += i;
    }

    // Set the result in promise
    prom.set_value(sum);
}

int main()
{
    // Create promise object
    promise<int> pObj;

    // Get future from promise
    future<int> fObj = pObj.get_future();

    // Create thread and transfer ownership of promise
    thread t1(calculateSum, move(pObj));

    // Wait for result from future
    int result = fObj.get();

    cout << "Result : " << result << endl;

    // Wait for thread to finish
    t1.join();

    return 0;
}
