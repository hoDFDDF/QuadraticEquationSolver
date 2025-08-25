#include "SolveEquation.h"
#include <math.h>
#include <stdio.h>

bool isZero(double s) {
    return -precision <= s && s <= precision;
}

void solveLinearEquation(functionPatametrs* param) {
    //assert(param != NULL);
    if (isZero(param->b) && isZero(param->c)) {
       param-> nRoots = INFINIT_ROOTS;
    } else if (isZero(param->b) && !isZero(param->c)) {
        param-> nRoots = NO_ROOTS;
    } else {
        param->x1 = -(param->c) / param->b;
        param-> nRoots = ONE_ROOT;
    }
}

void solveQuadraticEquation(functionPatametrs* param){
    //assert(param != NULL);

    double discriminant = (param->b * param->b) - (4 * param->a * param->c);
    if (discriminant > 0) {
        param->x1 = (-(param->b) + sqrt(discriminant)) / (2 * param->a);
        param->x2 = (-(param->b) - sqrt(discriminant)) / (2 * param->a);

        // TODO fprintf(stderr, "...\n");
        param->nRoots = TWO_ROOTS;
        //printf("x1 = %lg\n", param->x1);
        //printf("x2 = %lg\n", param->x2);
        
    } else if (isZero(discriminant)) { // TODO read about double (float) comparison
        param->x1 = (-(param->b) / (2 * param->a));
        param->x2 = param->x1;
        param->nRoots = ONE_ROOT;
    } else if (discriminant < 0) { // if (CompareDoubles(Discriminant, 0) == -1)
        param->nRoots = NO_ROOTS;
    } else {
        return ; // TODO make enum with error codes
    } // TODO also make error parser.
}

void solveEquation(functionPatametrs* param){
   // assert(param != NULL); // Error parser function
    if (!isZero(param->a)) {
        solveQuadraticEquation(param);
    } else {         
        solveLinearEquation(param);
    }
}