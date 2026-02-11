/*
Purpose : Program to demonstrate an Employee Payroll System using inheritance,
          virtual functions, dynamic object creation, and runtime polymorphism.
Author  : Harshinie M
Date    : 02-01-2026
*/

#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    int id;

public:
    Employee(string n, int i) : name(n), id(i) {}

    virtual void calculateSalary() {
        cout << "Base Employee salary calculation" << endl;
    }

    virtual ~Employee() {}
};

class FullTimeEmployee : public Employee {
    double basicPay;
    double allowances;

public:
    FullTimeEmployee(string n, int i, double b, double a)
        : Employee(n, i), basicPay(b), allowances(a) {}

    void calculateSalary() {
        double salary = basicPay + allowances;
        cout << "Full-Time Employee\n";
        cout << "ID: " << id << ", Name: " << name << endl;
        cout << "Salary: " << salary << endl;
    }
};

class PartTimeEmployee : public Employee {
    double hoursWorked;
    double payPerHour;

public:
    PartTimeEmployee(string n, int i, double h, double p)
        : Employee(n, i), hoursWorked(h), payPerHour(p) {}

    void calculateSalary() {
        double salary = hoursWorked * payPerHour;
        cout << "Part-Time Employee\n";
        cout << "ID: " << id << ", Name: " << name << endl;
        cout << "Salary: " << salary << endl;
    }
};

class ContractEmployee : public Employee {
    double contractAmount;

public:
    ContractEmployee(string n, int i, double c)
        : Employee(n, i), contractAmount(c) {}

    void calculateSalary() {
        cout << "Contract Employee\n";
        cout << "ID: " << id << ", Name: " << name << endl;
        cout << "Salary: " << contractAmount << endl;
    }
};

int main() {
    Employee *ePtr;
    int choice;

    cout << "1. Full-Time Employee\n2. Part-Time Employee\n3. Contract Employee\n";
    cout << "Enter employee type: ";
    cin >> choice;

    string name;
    int id;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter ID: ";
    cin >> id;

    if (choice == 1) {
        double basic, allowances;
        cout << "Enter basic pay: ";
        cin >> basic;
        cout << "Enter allowances: ";
        cin >> allowances;
        ePtr = new FullTimeEmployee(name, id, basic, allowances);
    }
    else if (choice == 2) {
        double hours, rate;
        cout << "Enter hours worked: ";
        cin >> hours;
        cout << "Enter pay per hour: ";
        cin >> rate;
        ePtr = new PartTimeEmployee(name, id, hours, rate);
    }
    else if (choice == 3) {
        double amount;
        cout << "Enter contract amount: ";
        cin >> amount;
        ePtr = new ContractEmployee(name, id, amount);
    }
    else {
        cout << "Invalid choice\n";
        return 0;
    }

    cout << "\n--- Salary Calculation ---\n";
    ePtr->calculateSalary();

    delete ePtr;
    return 0;
}

