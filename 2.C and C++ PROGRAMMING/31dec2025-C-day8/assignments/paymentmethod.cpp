/*
Purpose : Demonstrate abstraction and runtime polymorphism
          using payment methods.
Author  : Harshinie M
Date    : 31/12/2025
*/

#include <iostream>
using namespace std;

class PaymentMethod{
public:
    virtual void pay(double amount) = 0;
    virtual ~PaymentMethod(){}
};

class CreditCard : public PaymentMethod{
public:
    void pay(double amt){ cout<<"Paid "<<amt<<" using Credit Card"<<endl; }
};

class DebitCard : public PaymentMethod{
public:
    void pay(double amt){ cout<<"Paid "<<amt<<" using Debit Card"<<endl; }
};

class UPI : public PaymentMethod{
public:
    void pay(double amt){ cout<<"Paid "<<amt<<" using UPI"<<endl; }
};

int main(){
    PaymentMethod *ptr;
    CreditCard cc; DebitCard dc; UPI upi;

    ptr = &cc; ptr->pay(500);
    ptr = &dc; ptr->pay(1000);
    ptr = &upi; ptr->pay(300);
}

