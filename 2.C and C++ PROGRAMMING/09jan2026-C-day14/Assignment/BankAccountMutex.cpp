/*
 Purpose : Demonstrate mutex inside a class
 Question: Simulate bank account deposit and withdrawal using threads
           and protect shared balance using mutex.
 Author  : Harshinie M
 Date    : 09/01/2026
*/

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

class BankAccount
{
    int balance;
    mutex mtx;

public:
    BankAccount() : balance(0) {}

    void deposit(int amount)
    {
        lock_guard<mutex> lock(mtx);
        balance += amount;
    }

    void withdraw(int amount)
    {
        lock_guard<mutex> lock(mtx);
        balance -= amount;
    }

    int getBalance()
    {
        return balance;
    }
};

int main()
{
    BankAccount account;

    thread t1(&BankAccount::deposit, &account, 1000);
    thread t2(&BankAccount::withdraw, &account, 500);
    thread t3(&BankAccount::deposit, &account, 200);

    t1.join();
    t2.join();
    t3.join();

    cout << "Final Balance = " << account.getBalance() << endl;

    return 0;
}
