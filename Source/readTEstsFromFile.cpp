#include "readTEstsFromFile.h"
#include "SolveEquation.h"
#include <string.h>

FILE* fp = fopen("file.txt", "r");

char words[MAX];

int getTestsNumber(){

    int numberOfTests = 0; 

    while (fgets(words, MAX, fp) != NULL) {
        numberOfTests++;
    }
    fseek(fp, 0 ,SEEK_SET);
    fclose(fp);
    return numberOfTests;
}

Roots convertStringFromFileToEnum(char inputNRootsString){
    if (inputNRootsString == 'T') {
        return TWO_ROOTS;
    } else if (inputNRootsString == 'O') {
        return ONE_ROOT;
    } else if (inputNRootsString == 'I') {
        return INFINIT_ROOTS;
    } else if (inputNRootsString == 'N') {
        return NO_ROOTS;
    } else {
        return NO_ROOTS;
    }
}



