#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
struct functionPatametrs{
    double a;
    double b;
    double c;
    double* x1;
    double* x2;
    int nRoots;
    double correctX1;
    double correctX2;
    int correctNRoots;

};

    const int INFINIT_ROOTS = -1;
    const int NO_ROOTS = 0;
    const int ONE_ROOT = 1;
    const int ONE_LINEAR_ROOT = 1;
    const int TWO_ROOTS = 2;
    
    
const double precision = 0.00001;

int isZero(double s); 
int solveLinearEquation(functionPatametrs* param); //    SquareSolver* solver
int  solveQuadraticEquation( );
int solveEquation(functionPatametrs* param);
void printRoots(int solution, double x1, double x2);
int unitTests(); 



int main(){
    functionPatametrs parametrs = {};

    parametrs.a = 0,  parametrs.b = 0, parametrs.c = 0;
    parametrs.x1 = 0; parametrs.x2 = 0;
    printf("Enter 3 ratio numbers: ");
    int checkScanf = scanf("%lg %lg %lg", &parametrs.a, &parametrs.b, &parametrs.c);

    //printf("%f %f %f\n", a, b, c);
    //printf("isZero(a) = %d\n", isZero(a));
       if(checkScanf != 3){
        printf("Incorrect enter ((((\n");
        return 0;
    }
    //int solution = solveEquation(a, b, c, &x1, &x2);
    //printf("%d\n", solution);
    //printRoots(solution, x1, x2);
    unitTests();

    return 0;
  
}
int isZero(double s){
    if( -precision <= s && s <= precision){
        return 1;//true;
    }
    else {
        return 0;//false;
    }
}

int solveLinearEquation(functionPatametrs* solver) {
    solver->a;
}
int solveLinearEquation(functionPatametrs* param){
    assert(param->x1 != NULL);
    //printf("solvelinearEquation\n");
    if(isZero(param -> b) && isZero(param -> c)){
        return INFINIT_ROOTS;
    }

    else if(isZero(param -> b) && !isZero(param -> c)){
        return NO_ROOTS;
    }
    else{
        *(param -> x1) = -(param -> c) / param -> b; // TODO brackets not needed
        return  ONE_LINEAR_ROOT;
    }
}

int  solveQuadraticEquation(functionPatametrs* param){
    assert(param -> x1 != NULL);
    assert(param -> x2 != NULL);
    assert(param -> x1 != param -> x2);
    assert(param -> a != NAN);
    // NAN
    //printf("solveQuadraticEquation\n");
    double discriminant = (param -> b *  param -> b) - (4 * param -> a * param -> c);
    //printf("disc = %lg\n", discriminant);
    if (discriminant > 0){
        *(param -> x1) = (-(param -> b) + sqrt(discriminant)) / (2 * param -> a);
        *(param -> x2) = (-(param -> b) - sqrt(discriminant)) / (2 * param -> a);
        printf("x1 = %lg\n", *(param -> x1));
        printf("x2 = %lg\n", *(param -> x1));
        return TWO_ROOTS;
    }
    else if (isZero(discriminant)){ // TODO read about double (float) comparison
        *(param -> x1) = (-(param -> b) / (2 * param -> a));
        *(param -> x2) = *(param -> x1);
        return ONE_ROOT;
    }
    else if(discriminant < 0){
        return NO_ROOTS;
    }

}
// TODO solveEquation
int solveEquation(functionPatametrs* param){
    assert(param -> x1 != NULL);
    assert(param -> x2 != NULL);
    assert(param -> x2 != param -> x1);
    if(!isZero(param -> a)){

        return solveQuadraticEquation(param);
    }
    else {         
        return solveLinearEquation(param);
    }
}

void printRoots(functionPatametrs* param){
    switch(param->nRoots){
        case ONE_ROOT:
            printf("We found only one root x = %lg", param->x1);
            break;
        case TWO_ROOTS:
            printf("We found two roots x1 = %lg , x2 = %lg", param->x1, param->x2);
            break;
        case INFINIT_ROOTS:
            printf("We found INFINIT roots");
            break;
       // case ONE_LINEAR_ROOT:
         //   printf("We found 1 linear root x = %lg", x1);
            break;
        case NO_ROOTS:
            printf("There are no roots");
            break;
    }

}


void checkParametrs(functionPatametrs* param){

double x1 = 0;
double x2 = 0;
int nRoots = solveEquation(param);

if(nRoots != param->correctNRoots){
    printf("FAILED. Icorrcet number of roots\n");
    return ;
}
if((nRoots >= 1 ) &&  x1 != param->correctX1){
     printf("FAILED. Your root x = %lg, should to be: %lg\n", param->x1, param->correctX1);
    return ;
}
if(nRoots >= TWO_ROOTS &&  x2 != param->correctX2 ){
     printf("FAILED. Your roots x1 =  %lf, x2 = %lf, should be: x1 = %lf, x2 = %lf\n", param -> x1, , x2, correctX2);
    return ;
}
    printf("SUCCESS\n");
}


int unitTests(){
    functionPatametrs array[5] = {
    //{.a = 1, .b = 5, .c = 6, .nRoots = TWO_ROOTS, .x1 = -2, .x2 = -3},
    {1, 5, 6, TWO_ROOTS, -2, -3},

    };

    checkParametrs(1, 5, 6,        TWO_ROOTS,  -2,  -3);
    checkParametrs(0, 5, 5,      ONE_ROOT,  -1,    NAN);
    checkParametrs(0, 0, 0,    INFINIT_ROOTS, NAN, NAN);
    checkParametrs(0, 3, 2, ONE_LINEAR_ROOT, -2.0/3, NAN);
    checkParametrs(0, 0, -2,    NO_ROOTS,   NAN,   NAN);
     
    //checkParametrs(0, 0, 0, INFINIT_ROOTS, 0);
}




