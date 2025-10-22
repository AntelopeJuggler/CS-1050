/******************************************************************************
Simone Marta - smvnb
CS 1050
Prelab 4
9/15/2025

Description: Part 1 lists ten numbers, starting from one, where each successive number is the previous one times three.
Part 2 gives a selection of three riddles the user can choose from. The user is given three chances to get one correct.
Part 3 takes an inputted integer, adds 50 if it is even, or subtracts 25 if it's odd.
*******************************************************************************/
#include <stdio.h>

int main(void) {
    //Part 1
    int num = 1;
    for(int i = 1; i<=10; i++) {
        printf("%d\n", num);
        num*=3;
    }
    
    //Part 2
    int numc=0; //number of riddles answered correctly
    int attempts=0;
    do{
        if(attempts>0) //If user was wrong before
            printf("Incorrect. Try again\n");
        
        printf("Choose a riddle--enter 1, 2, or 3: ");
        int rid;
        char ans = ' ';
        scanf("%d", &rid);
        scanf("%c", &ans); //clear input buffer
        switch(rid) {
        case 1:
            printf("What has keys but can't open locks? \na. A piano\nb. A map\nc. A computer\n");
            scanf("%c", &ans);
            numc+= (ans=='c' || ans=='C');
            break;
        case 2:
            printf("What goes around the world while it stays in a corner? \na. A stamp\nb. A letter\nc. An envelope\n");
            scanf("%c", &ans);
            numc+= (ans=='a' || ans=='A');
            break;
        case 3:
            printf("What's round and has a thousand squares? \na. A baseball\nb. Toilet paper\nc. Hot air balloon\n");
            scanf("%c", &ans);
            numc+= (ans=='b' || ans=='B');
            break;
        default:
            attempts--; //act like nothing happened, since user did something wrong
            break;
        }
        attempts++;
    }
    while(numc==0 && attempts<3); //while user hasn't yet gotten one correct or used up their attempts
    
    if(numc!=0)
        printf("Correct. The door opens\n");
    else if(attempts==3)
        printf("You have lost\n");
    
    //Part 3
    int evod = 0; //name means even/odd
    printf("Enter a number: ");
    scanf("%d", &evod);
    (evod%2==0) ? (evod+=50) : (evod=evod-25); //if even, add 50, else subtract 25
    printf("The transformed number is: %d", evod);
}
