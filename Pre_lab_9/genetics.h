#include <stdio.h>
#include <stdlib.h> //for initializeSequences
#include <time.h> //for initializeSequences
#define NUM_SEQUENCES 5 //task 1
#define SEQUENCE_LENGTH 10 //task 1
#define RELATIONSHIP_THRESHOLD 0.7 //task 2

void initializeSequences(char sequences[NUM_SEQUENCES][SEQUENCE_LENGTH]);
void displaySequences(char sequences[NUM_SEQUENCES][SEQUENCE_LENGTH]);
float calculateSimilarity(char sequences[NUM_SEQUENCES][SEQUENCE_LENGTH], int index1, int index2);
int areRelated(float similarity);
void mutateSequence(char sequences[NUM_SEQUENCES][SEQUENCE_LENGTH], int index, int mutations);
