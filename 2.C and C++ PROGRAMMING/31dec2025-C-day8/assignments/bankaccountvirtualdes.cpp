/*
Purpose : Demonstrate virtual destructor to ensure
          proper object destruction in inheritance.
Author  : Harshinie M
Date    : 31/12/2025
*/

#include <iostream>
using namespace std;

class Account{
public:
    virtual void calculateInterest() = 0;
    virtual ~Account(){ cout<<"Account Destructor"<<endl; }
};

class SavingsAccount : public Account{
public:
    void calculateInterest(){ cout<<"Savings Interest Calculated"<<endl; }
    ~SavingsAccount(){ cout<<"SavingsAccount Destructor"<<endl; }
};

int main(){
    Account *ptr = new SavingsAccount();
    ptr->calculateInterest();
    delete ptr;
}

