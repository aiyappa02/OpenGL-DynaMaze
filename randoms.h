#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>

int randoms(){
    srand(time(NULL));
    int randNum = (rand() % 3);
    printf("%d\n", randNum);
    return randNum;
}