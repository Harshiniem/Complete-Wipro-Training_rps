/*
 * Purpose          : Implement the class BankAccount with the given data and methods as given below.
		Data:
	    	Account number
			Account holder name
			Balance
        Provide functions to:
			setAccount --> Initial value of number, name and balance, 
        	Deposit money
        	Withdraw money
        	Display balance
 * Author           : Harshinie M
 * Date             : 26/12/2025
 */
#include <iostream>
#include <cstring>   // for strcpy
using namespace std;

class BankAccount {
    int accNo;
    double balance;
    char name[30];

public:
    BankAccount(int a, const char n[], double b) {
        accNo = a;
        balance = b;
        strcpy(name, n);
    }

    void deposit(double amt) {
        balance += amt;
    }

    void withdraw(double amt) {
        if (amt <= balance)
            balance -= amt;
    }

    void display() {
        cout << accNo << " " << name
             << " Balance: " << balance << endl;
    }
};

int main()
{
    BankAccount b1(101, "Harshinie", 5000);

    b1.display();
    b1.deposit(1000);
    b1.withdraw(500);
    b1.display();

    return 0;
}

