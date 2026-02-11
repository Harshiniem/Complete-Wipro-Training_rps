#include <stdio.h>

int main(){

    int choice;
    do {
        printf("Enter the choice: 1 Edge / 2 Python / 3 Java / else quit\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("You have chosen Edge\n");
                break;
            case 2:
                printf("You have chosen Python\n");
                break;
            case 3:
                printf("You have chosen Java\n");
                break;
            default:
                printf("No such option Available\n");
                return 1;
        }
    } while(1);
}

