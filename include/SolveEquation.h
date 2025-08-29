#ifndef SOLVE_EQUATION_H_
#define SOLVE_EQUATION_H_

enum Roots {
    INFINIT_ROOTS = -1,
    NO_ROOTS = 0,
    ONE_ROOT = 1,
    TWO_ROOTS = 2
};

struct FunctionParametrs {
    double a;
    double b;
    double c;
    
    double x1;
    double x2;
    Roots nRoots;
};

const double precision = 1e-6; 

bool isZero(double s); 
void solveLinearEquation(FunctionParametrs* param); 
void solveQuadraticEquation(FunctionParametrs* param);
void solveEquation(FunctionParametrs* param);

#endif // SOLVE_EQUATION_H_