#include <math.h>
#include <stdio.h>

#include "SolveEquation.h"
#include "ERROR_PARSER.h"

bool isZero(double s){
    return -precision <= s && s <= precision;
}
// SquareSolverErrors
void solveLinearEquation(functionParametrs* param){
    
    CUSTOM_ASSERT(param != nullptr);
    if (isZero(param->b) && isZero(param->c)) {
       param-> nRoots = INFINIT_ROOTS;
    } else if (isZero(param->b) && !isZero(param->c)) {
        param-> nRoots = NO_ROOTS;
    } else {
        param->x1 = -(param->c) / param->b;
        param-> nRoots = ONE_ROOT;
    }
}

void solveQuadraticEquation(functionParametrs* param){
    CUSTOM_ASSERT(param != nullptr)

    double discriminant = (param->b * param->b) - (4 * param->a * param->c);
    if (discriminant > 0) {
        param->x1 = (-(param->b) + sqrt(discriminant)) / (2 * param->a);
        param->x2 = (-(param->b) - sqrt(discriminant)) / (2 * param->a);

        // TODO fprintf(stderr, "...\n");
        param->nRoots = TWO_ROOTS;
        
    } else if (isZero(discriminant)) { // TODO read about double (float) comparison
        param->x1 = (-(param->b) / (2 * param->a));
        param->x2 = param->x1;
        param->nRoots = ONE_ROOT;
    } else if (discriminant < 0) { // if (CompareDoubles(Discriminant, 0) == -1)
        param->nRoots = NO_ROOTS;
    } else {
        return ;// UNKNOWN_DISCRIMINANT; // TODO make enum with error codes
    } // TODO also make error parser.
}

void solveEquation(functionParametrs* param){
   CUSTOM_ASSERT(param != nullptr); // Error parser function
    if (!isZero(param->a)) {
        solveQuadraticEquation(param);
    } else {         
        solveLinearEquation(param);
    }
}

