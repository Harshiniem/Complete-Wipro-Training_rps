/*
Purpose : To demonstrate the use of command-line arguments in C
          by displaying the argument count (argc) and argument
          vector (argv) passed to the program.
Question: Write a C program to display the count of command-line
          arguments and print each argument with its index.
Author  : Harshinie M
Date    : 05/01/2026
*/

#include <stdio.h>
 
int main(int argc, char *argv[]){

        printf("Count of args: %d\n", argc);

        printf("Argument List: \n");

        for(int cnt = 0; cnt < argc; cnt++)

                printf("\t\targv[%d]  ==> %s\n", cnt, argv[cnt]);
 
}
 
