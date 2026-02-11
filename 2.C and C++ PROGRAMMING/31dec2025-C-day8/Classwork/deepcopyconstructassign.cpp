/*
Purpose : Demonstrate deep copy using copy constructor
          and overloaded assignment operators.
Author  : Harshinie M
Date    : 31/12/2025
*/

#include <iostream>
#include <cstring>
using namespace std;

class MyString{
    char *str;
    int len;
public:
    MyString(const char *st=" "):len(strlen(st)+1){
        str = new char[len+1];
        strcpy(str, st);
    }

    MyString(const MyString& rhs):len(rhs.len){
        str = new char[len+1];
        strcpy(str, rhs.str);
    }

    MyString& operator=(const MyString& rhs){
        len = rhs.len;
        str = new char[len+1];
        strcpy(str, rhs.str);
        return *this;
    }

    ~MyString(){
        delete [] str;
    }

    friend ostream& operator<<(ostream &, const MyString&);
};

int main(){
    MyString one = "One string here is to initialize";
    MyString two = one;
    MyString three;
    three = two;

    cout<<"One: "<<one<<endl;
    cout<<"Two: "<<two<<endl;
    cout<<"Three: "<<three<<endl;
}

ostream& operator<<(ostream &out, const MyString& rhs){
    out<<"Len: "<<rhs.len<<"\tStr: "<<rhs.str;
    return out;
}

