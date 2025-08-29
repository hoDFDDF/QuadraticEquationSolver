#include <stdio.h>

#include "ioFuncs.h"
#include "ERROR_PARSER.h"
#include "SolveEquation.h"

void printRoots(FunctionParametrs* param){

    CUSTOM_ASSERT(param != nullptr);

    switch (param->nRoots) {
        case ONE_ROOT:
            printf(COLOR_BLUE "We found only one root x =" COLOR_GREEN "%lg" RESET_ALL, param->x1 );
            break;
        case TWO_ROOTS:
            printf(COLOR_BLUE "We found two roots " COLOR_GREEN "x1 = %lg , x2 = %lg" RESET_ALL,param->x1, param->x2);
            break;
        case INFINIT_ROOTS:
            printf(COLOR_BLUE "We found INFINITY roots" RESET_ALL);
            break;
        case NO_ROOTS:
            printf(COLOR_CYAN "There are no roots" RESET_ALL);
            break;
        default:
            printf(COLOR_RED "ERROR" RESET_ALL);
            break;
    } 
}

