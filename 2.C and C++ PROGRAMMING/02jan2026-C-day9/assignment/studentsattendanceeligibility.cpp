/*
Purpose : Program to demonstrate runtime polymorphism using inheritance
          by checking attendance eligibility of different students.
Author  : Harshinie M
Date    : 02-01-2026
*/

#include <iostream>
#include <string>
using namespace std;

class StdAttendance {
protected:
    string name;
    int attendance;

public:
    StdAttendance(string n, int a) : name(n), attendance(a) {}

    string getName() {
        return name;
    }

    virtual bool checkEligibility() = 0;
    virtual ~StdAttendance() {}
};

class ArtsStudent : public StdAttendance {
public:
    ArtsStudent(string n, int a) : StdAttendance(n, a) {}

    bool checkEligibility() {
        return attendance >= 65;
    }
};

class ScienceStudent : public StdAttendance {
public:
    ScienceStudent(string n, int a) : StdAttendance(n, a) {}

    bool checkEligibility() {
        return attendance >= 70;
    }
};

class EngineeringStudent : public StdAttendance {
public:
    EngineeringStudent(string n, int a) : StdAttendance(n, a) {}

    bool checkEligibility() {
        return attendance >= 75;
    }
};

int main() {

    StdAttendance *sArr[] = {
        new ArtsStudent("Smitha", 68),
        new ScienceStudent("Rahul", 72),
        new EngineeringStudent("Sachin", 78),
        new ArtsStudent("Balu", 64),
        new ScienceStudent("Sharma", 72),
        new EngineeringStudent("Rathore", 79),
        NULL
    };

    for (int cnt = 0; sArr[cnt] != NULL; cnt++) {
        cout << sArr[cnt]->getName() << " is ";
        if (sArr[cnt]->checkEligibility())
            cout << "Eligible" << endl;
        else
            cout << "Not Eligible" << endl;
    }

    for (int cnt = 0; sArr[cnt] != NULL; cnt++) {
        delete sArr[cnt];
    }

    return 0;
}

