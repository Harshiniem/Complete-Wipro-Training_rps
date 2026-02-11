/*
 * Purpose : Generate unique employee IDs
 * Author  : Harshinie M
 * Date    : 29/12/2025
 */

#include <iostream>
#include <string>
using namespace std;

class Employee {
    int id;
    string name;

    static int nextID;   // class member

public:
    Employee(string n) {
        name = n;
        id = nextID++;   // assign and increment
    }

    void display() const {
        cout << "ID: " << id << ", Name: " << name << endl;
    }
};

// Definition of static member
int Employee::nextID = 1001;

int main() {
    Employee e1("Arun");
    Employee e2("Divya");
    Employee e3("Kiran");

    e1.display();
    e2.display();
    e3.display();

    return 0;
}

