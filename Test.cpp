#include <stdio.h>
#include <math.h>

#include "Test.h"

void checkParametrs(functionPatametrs* param) {
    functionPatametrs get_params = {param->a, param->b, param->c, 0, 0, NO_ROOTS};
    solveEquation(&get_params);

    if (get_params.nRoots != param->nRoots){
        printf("%d - %d\n", param->nRoots, get_params.nRoots);
        printf("FAILED. Icorrcet number of roots\n");
        return ;
    }
    if ((get_params.nRoots >= 1 ) && param->x1 != get_params.x1) {
        printf("FAILED. Your root x = %lg, should to be: %lg\n", param->x1, get_params.x1);
        return ;
    }
    if (get_params.nRoots >= TWO_ROOTS &&  param->x2 != get_params.x2) {
        printf("FAILED. Your roots x1 =  %lf, x2 = %lf, should be: x1 = %lf, x2 = %lf\n", get_params.x1, get_params.x2, param->x1, param->x2);
        return ;
    }
        printf("SUCCESS\n");
}

void unitTests() {
    functionPatametrs array[] = {
        {1, 5, 6, -2, -3, TWO_ROOTS},
        {0, 0, 0, NAN, NAN, INFINIT_ROOTS},
        {0, 3, 5, -5.0/3, NAN, ONE_ROOT},
        {1, 0, -4, 2, -2, TWO_ROOTS},
        {0, 0, 1, NAN, NAN, NO_ROOTS}
    };

    size_t number_of_unitTests = sizeof(array) / sizeof(array[0]);

    for (size_t i = 0; i < number_of_unitTests; i++){
        checkParametrs(&array[i]);
    }
}