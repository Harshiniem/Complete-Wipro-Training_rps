/*
 Purpose : Demonstrate usage of std::function with functions and lambda
 Question: Assign a normal function and a lambda expression to std::function
           and invoke them.
 Author  : Harshinie M
 Date    : 09/01/2026
*/

#include <iostream>
#include <functional>

using namespace std;

// Normal function: Addition
int Add(int x, int y)
{
    return x + y;
}

// Normal function: Subtraction
int Sub(int x, int y)
{
    return x - y;
}

int main()
{
    // std::function holding a normal function
    function<int(int, int)> fObj = Add;

    int res1 = fObj(100, 200);
    cout << "Result using normal function (Add): " << res1 << endl;

    // std::function holding a lambda expression
    function<int(int, int)> fObj2 = [](int x, int y) {
        return x + y;
    };

    int res2 = fObj2(10, 20);
    cout << "Result using lambda function: " << res2 << endl;

    return 0;
}
