/*
Purpose : Program to demonstrate runtime polymorphism using virtual functions
          and the importance of virtual destructor.
Author  : Harshinie M
Date    : 02-01-2026
*/
#include <iostream>
using namespace std;

class Base{
public:
	Base(){
		cout << "Base::Base() --> ctor" << endl;}
	virtual ~Base(){
		cout << "Base::~Base() --> dtor" << endl;}
	virtual void funone(){
		cout << "Base::funone()" << endl;}
	virtual void funtwo(){
		cout << "Base::funtwo()" << endl;}
};
class Derived:public Base{
public:
	Derived(){
		cout<<"Derived::Derived() --> ctor"<<endl;} 
	~Derived(){
		cout<<"Derived::~Derived()--> dtor"<<endl;} 
	void funOne(){
		cout<<"Derived::funOne()"<<endl;} 
	void funTwo(){
		cout<<"Derived::funTwo()"<<endl;} 
};
int main(){
	Base *bPtr = new Base();
	bPtr -> funone();
	bPtr -> funtwo();
	delete bPtr;
	cout << "*************************************************\n";
        bPtr = new Derived();
	bPtr->funone();
	bPtr->funtwo();
	delete bPtr;
}
