/*
Purpose : Implement your own cat program, which will take file name
          as an argument and print the contents of the file on the screen.
Author  : Harshinie M
Date    : 05/01/2026
*/

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]){
    ifstream fin(argv[1]);
    string line;

    while (getline(fin, line))
        cout << line << endl;

    fin.close();
    return 0;
}

