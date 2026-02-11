/*
Purpose : Demonstrate diamond inheritance without virtual inheritance
          causing ambiguity and multiple base subobjects.
Author  : Harshinie M
Date    : 31/12/2025
*/

#include <iostream>
#include <string>
using namespace std;

class Person{
public:
    string name;
    Person(string n): name(n){}
};

class Student : public Person{
public:
    int rollNo;
    Student(string n,int r): Person(n), rollNo(r){}
};

class Employee : public Person{
public:
    int empId;
    Employee(string n,int e): Person(n), empId(e){}
};

class Intern : public Student, public Employee{
public:
    Intern(string n1,int r,string n2,int e)
        : Student(n1,r), Employee(n2,e){}
};

int main(){
    Intern obj("Jaya",101,"Jaya",5001);

    cout<<obj.Student::name<<endl;
    cout<<obj.Employee::name<<endl;

    cout<<"Size of Intern: "<<sizeof(obj)<<endl;
}

