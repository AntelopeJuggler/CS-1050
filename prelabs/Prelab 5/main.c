/******************************************************************************
Prelab 5
Simone Marta
9/22/25
This program provides several options for transforming integers, then performs those transformations.
*******************************************************************************/
#include <stdio.h>
int main(void) {
do {
    int ch = 0;
    printf("\n1. Find the factorial of a positive integer\n");
    printf("2. Print the Fibonacci sequence up to a specified number of terms\n");
    printf("3. Calculate the sum of each natural number up to a specified point\n");
    printf("4. Test number properties using logical operators.\n");
    printf("5. Exit program\n");
    scanf("%d", &ch);
    if(ch==5) break;
    
    int num = 0;
    printf("Enter a number: ");
    scanf("%d", &num);
    switch (ch) {
        case 1: //factorial of positive integer using for or do-while loop
            int fact = 1;
            for(int i = num; i>0; i--)
                fact*=i;
            printf("Factorial to %d: %d\n", num, fact);
            break;
        
        case 2: //fibonacci sequence using for or do-while loop
            int sum1 = 0, sum2 = 1, sumt;
            printf("Series: 0");
            for(int i = 1; i<num; i++) {
                sumt=sum1;
                sum1=sum2;
                sum2+=sumt;
                printf(", %d", sum1);
            }
            printf("\n");
            break;
        
        case 3: //sum of natural numbers to n
            printf("Sum: %d\n", num*(num+1)/2);
            break;
        
        case 4: //number properties
            printf("%d is even and greater than 10: %s\n", num, (num%2==0 && num>10) ? "True":"False");
            printf("%d is divisible by 3 or 5: %s\n", num, (num%3==0 || num%5==0)? "True":"False");
            printf("%d is not negative: %s\n", num, !(num<0) ? "True":"False");
            break;
    }
} while(1); }