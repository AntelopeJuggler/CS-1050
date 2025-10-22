/******************************************************************************
Prelab 8
10/15/2025
*******************************************************************************/
#include <stdio.h>
#define AMT 20

int main(void) {
    int arr[AMT] = {1};
    int total = 0;
    for(int i = 0; i<AMT; i++) {
        arr[i]=1+i;
        total += arr[i];
        printf("array[%d]=%d\n", i-1, arr[i-1]);
    }
    printf("Total = %d\n", total);
    printf("Average = %.2f\n", (double)total/AMT);
    
}