#include "io.h"

void printRoots(functionPatametrs* param){
    switch (param->nRoots){
        case ONE_ROOT:
            printf("We found only one root x = %lg", param->x1);
            break;
        case TWO_ROOTS:
            printf("We found two roots x1 = %lg , x2 = %lg", param->x1, param->x2);
            break;
        case INFINIT_ROOTS:
            printf("We found INFINIT roots");
            break;
        case NO_ROOTS:
            printf("There are no roots");
            break;
    } // Default case for error parsing.
}