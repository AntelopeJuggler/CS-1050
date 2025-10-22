/******************************************************************************
Prelab 6
Simone Marta
9/29/25
*******************************************************************************/
#include <stdio.h>
#include <math.h>

int isPrime (int n); //tests if n is prime
int goldbachPrimePairs(int n); //prints n's Goldbach prime pairs (each 2 primes that add to n)

int main() {
    for(int i = 1; i<=100; i++) //prints all primes to 100
        if(isPrime(i)) 
            printf("%d ", i);
    
    printf("\n\n");
    for(int i = 1; i<=100; i++) { //prints all Goldbach pairs to 100
        printf("%d\n", i);
        goldbachPrimePairs(i);
    }
    return 0;
}

//takes in an int. Returns 1 if prime, 0 if nonprime
int isPrime (int n) {
    for(int i = 2; i<=pow(n, 0.5); i++) { //starts at the first prime and goes to the square root of n
        if ((double)n/i==n/i) //if evenly divisible
            return 0;
    }
    return 1; //if no divisors found, is prime
}

//Takes in an int. Prints the int's Goldbach pairs in parentheses
//Returns 1 if one or more pairs exist, 0 otherwise
int goldbachPrimePairs(int n) {
    int ret = 0; //return value, assume no pairs
    for(int i = 2; i<=n/2; i++) { // n/2 to stop repeat pairs
        if(isPrime(i) && isPrime(n-i)) {
            printf("(%d, %d)\n", i, n-i); //prints the two primes that sum to n
            ret = 1;
        }
    }
    return ret;
}