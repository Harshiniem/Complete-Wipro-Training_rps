/*
Purpose : Update your own cat program, which will take -n option and
          file name as arguments and print the contents of the file
          on the screen along with the line numbers.
Author  : Harshinie M
Date    : 05/01/2026
*/

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]){
    ifstream fin(argv[2]);
    string line;
    int lineNo = 1;

    while (getline(fin, line)){
        cout << lineNo << " " << line << endl;
        lineNo++;
    }

    fin.close();
    return 0;
}

