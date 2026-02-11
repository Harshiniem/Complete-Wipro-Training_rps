/*
Purpose : Implement your wc program, which takes in file name as an
          argument and print number of lines, number of words and
          number of characters present in the file along with the file name.
Author  : Harshinie M
Date    : 05/01/2026
*/

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc, char *argv[]){
    ifstream fin(argv[1]);
    string line, word;
    int lines = 0, words = 0, chars = 0;

    while (getline(fin, line)){
        lines++;
        chars += line.length() + 1;

        stringstream ss(line);
        while (ss >> word)
            words++;
    }

    cout << lines << " " << words << " " << chars << " " << argv[1] << endl;

    fin.close();
    return 0;
}

