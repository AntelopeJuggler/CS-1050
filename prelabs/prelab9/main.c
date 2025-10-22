/******************************************************************************
Prelab 9, 10/21/2025
*******************************************************************************/
#include <stdio.h>
#include "genetics.h"

int main(void) {
    srand(time(NULL));
    char seqs[NUM_SEQUENCES][SEQUENCE_LENGTH] = {0}; //NUM_SEQUENCES and SEQUENCE_LENGTH are defined in genetics.h
    initializeSequences(seqs);
    displaySequences(seqs);
    
    int choice = 0;
    while(1) {
        puts("Choose an operation: ");
        puts("1. Calculate similarity");
        puts("2. Mutate sequence");
        puts("3. Exit");
        scanf("%d", &choice);
        
        if(choice==1) {
            puts("Do you want to calculate similarity for one pair (enter 1) or all the pairs (enter 2)?");
            scanf("%d", &choice); //reusing variable
            if(choice==1) {
                puts("Which two sequences? (0 to 3)");
                int idx1 = 0, idx2 = 0;
                scanf("%d%d", &idx1, &idx2);
                float siml = calculateSimilarity(seqs, idx1, idx2);
                printf("Similarity: %.1f\n", siml);
                printf("The individuals %s related.\n", areRelated(siml) ? "are" : "are not");
            }
            else if(choice==2) {
                for(int i = 0; i<NUM_SEQUENCES; i++) {
                    for(int j = i+1; j<NUM_SEQUENCES; j++) { //looping through unique cases only
                        printf("#%d vs #%d: %.1f\n", i, j, calculateSimilarity(seqs, i, j));
                    }
                }
            }
        }
        else if(choice==2) {
            puts("Enter which sequence (0 to 3) and how many mutations (max 10)");
            int idx = -1, mut = 0;
            scanf("%d%d", &idx, &mut);
            mutateSequence(seqs, idx, mut);
            displaySequences(seqs);
        }
        else if(choice==3)
            break;
        else
            puts("Please enter a number from 1 to 3");
    }

    return 0; //I've been advised to include this, as it is custom. I still don't like it
}