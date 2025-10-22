#include "genetics.h"
#include <stdio.h>

void initializeSequences(char sequences[NUM_SEQUENCES][SEQUENCE_LENGTH]) {
    for(int i = 0; i<NUM_SEQUENCES; i++) {
        for(int j = 0; j<SEQUENCE_LENGTH; j++) {
            int random = rand()%4; //make random int between 0 and 3. RNG seeded in main?
            if(random==0)
                sequences[i][j] = 'A';
            else if(random==1)
                sequences[i][j] = 'C';
            else if(random==2)
                sequences[i][j] = 'T';
            else
                sequences[i][j] = 'G';
        }
    }
    return;
}

void displaySequences(char sequences[NUM_SEQUENCES][SEQUENCE_LENGTH]) {
    printf("Genetic sequences: \n");
    //prints each letter, row by row
    for(int i = 0; i<NUM_SEQUENCES; i++) {
        for(int j = 0; j<SEQUENCE_LENGTH; j++)
            printf("%c ", sequences[i][j]);
        
        printf("\n");
    }
    printf("\n");
    return;
}

float calculateSimilarity(char sequences[NUM_SEQUENCES][SEQUENCE_LENGTH], int index1, int index2) {
    float simlty = 0;
    for(int i = 0; i<SEQUENCE_LENGTH; i++) {
        int isAT1 = -1; //category for the first index
        if(sequences[index1][i] == 'A' || sequences[index1][i] == 'T')
            isAT1=1;
        else if(sequences[index1][i] == 'C' || sequences[index1][i] == 'G')
            isAT1=0;
        else return -1.0;
        
        int isAT2 = -1; //category for the second index
        if(sequences[index2][i] == 'A' || sequences[index2][i] == 'T')
            isAT2=1;
        else if(sequences[index2][i] == 'C' || sequences[index2][i] == 'G')
            isAT2=0;
        else return -1.0;
        
        if((isAT1 && isAT2) || (!isAT1 && !isAT2))
            simlty++;
    }
    simlty/=(double)SEQUENCE_LENGTH; //total matches are divided by sequence length to obtain a percentage
    return simlty;
}

int areRelated(float similarity) {
    if(similarity>=RELATIONSHIP_THRESHOLD)
        return 1;
    else return 0;
}

void mutateSequence(char sequences[NUM_SEQUENCES][SEQUENCE_LENGTH], int index, int mutations) {
    if(index < 0 || index >= NUM_SEQUENCES) //if index is out of bounds
        return;
    
    int indices[mutations]; //to make sure the same index isn't changed more than once, they'll be recorded here
    
    for(int i = 0; i<mutations; i++) { //looping through mutations
        indices[i] = rand() % SEQUENCE_LENGTH; //random index in sequence TBM (to be mutated)
        
        int random = rand() % 4; //creating mutation
        char toBe = ' ';
        switch(random) {
            case 0: toBe = 'A'; break;
            case 1: toBe = 'C'; break;
            case 2: toBe = 'T'; break;
            case 3: toBe = 'G'; break;
        }
        
        int rep = 0; //to check if same index was changed twice, or if index will change to the same thing
        for(int j = 0; j<i; j++) {
            if(indices[i] == indices[j] || sequences[index][indices[i]] == toBe) {
                rep = 1;
                break;
            }
        }
        if(rep) { //if there is repetition, try again
            i--;
            continue;
        }
        
        //otherwise, finally:
        sequences[index][indices[i]] = toBe;
    }
    
    return;
}
