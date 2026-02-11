/*
Purpose : Program to overload +, - and << operators for Time class
Author  : Harshinie M
Date    : 30-12-2025
*/

#include <iostream>
using namespace std;

class Time
{
    int hrs, min;

public:
    // Constructor
    Time(int h = 0, int m = 0)
    {
        hrs = h;
        min = m;
    }

    // Overload + operator
    Time operator+(Time t)
    {
        Time temp;
        temp.min = min + t.min;
        temp.hrs = hrs + t.hrs + (temp.min / 60);
        temp.min = temp.min % 60;
        return temp;
    }

    // Overload - operator
    Time operator-(Time t)
    {
        Time temp;
        int total1 = hrs * 60 + min;
        int total2 = t.hrs * 60 + t.min;
        int diff = total1 - total2;

        temp.hrs = diff / 60;
        temp.min = diff % 60;
        return temp;
    }

    // Overload << operator
    friend ostream& operator<<(ostream &out, Time &t);
};

// Definition of << operator
ostream& operator<<(ostream &out, Time &t)
{
    out << t.hrs << ":" << t.min;
    return out;
}

int main()
{
    Time t1(2, 45), t2(1, 30);

    Time t3 = t1 + t2;
    Time t4 = t1 - t2;

    cout << "Addition: " << t3 << endl;
    cout << "Subtraction: " << t4 << endl;

    return 0;
}

