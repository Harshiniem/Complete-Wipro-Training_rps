/*
Purpose : Implement MyString class where memory is allocated dynamically and exceptions are used to handle incorrect sizes
Author  : Harshinie M
Date    : 06/01/2026
*/

#include <iostream>
#include <cstring>   // for strlen and strcpy
using namespace std;

// MyString class
class MyString {
private:
    char *str;   // pointer to store string dynamically
    int length;  // length of the string

public:
    // Constructor
    MyString(const char *s) {
        if (s == NULL || strlen(s) == 0)
            throw 0; // raise exception if string is empty or null

        length = strlen(s);
        str = new char[length + 1]; // +1 for null character '\0'
        strcpy(str, s);             // copy string
    }

    // Function to display string
    void display() {
        cout << "String: " << str << endl;
    }

    // Destructor
    ~MyString() {
        delete [] str; // free allocated memory
    }
};

int main() {
    try {
        MyString s1("Hello");
        s1.display();

        MyString s2("Dynamic Memory");
        s2.display();

        MyString s3("");   // invalid string → exception
        s3.display();
    }
    catch(int e) {
        cout << "Caught exception: Invalid string size" << endl;
    }

    cout << "Program executes normally even if exception occurs..." << endl;
}

