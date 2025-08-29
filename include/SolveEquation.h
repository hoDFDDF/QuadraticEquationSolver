#ifndef SOLVE_EQUATION_H_
#define SOLVE_EQUATION_H_

enum Roots {
    INFINIT_ROOTS = -1,
    NO_ROOTS = 0,
    ONE_ROOT = 1,
    TWO_ROOTS = 2
};

struct functionParametrs {
    double a;
    double b;
    double c;
    
    double x1;
    double x2;
    Roots nRoots;
};

const double precision = 1e-6; 

bool isZero(double s); 
void solveLinearEquation(functionParametrs* param); //    SquareSolver* solver
void solveQuadraticEquation(functionParametrs* param);
void solveEquation(functionParametrs* param);


#endif // SOLVE_EQUATION_H_

