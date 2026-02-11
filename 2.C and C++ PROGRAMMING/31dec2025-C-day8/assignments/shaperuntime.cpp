/*
Purpose : Demonstrate runtime polymorphism using
          base class pointer with shapes.
Author  : Harshinie M
Date    : 31/12/2025
*/

#include <iostream>
using namespace std;

class Shape{
public:
    virtual void draw(){ cout<<"Drawing Shape"<<endl; }
    virtual ~Shape(){}
};

class Circle : public Shape{
public:
    void draw(){ cout<<"Drawing Circle"<<endl; }
};

class Rectangle : public Shape{
public:
    void draw(){ cout<<"Drawing Rectangle"<<endl; }
};

class Triangle : public Shape{
public:
    void draw(){ cout<<"Drawing Triangle"<<endl; }
};

int main(){
    Shape *ptr;
    Circle c; Rectangle r; Triangle t;

    ptr = &c; ptr->draw();
    ptr = &r; ptr->draw();
    ptr = &t; ptr->draw();
}

