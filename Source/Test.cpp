#include <stdio.h>
#include <math.h>

#include "Test.h"
#include "ERROR_PARSER.h"
#include "ioFuncs.h"
#include "readTEstsFromFile.h"

bool compareDoubleNumbers(double first_num,  double second_num){
    return (fabs(first_num - second_num) < precision); //если числа  равны выведет true, если нет - false
}

void checkParametrs(functionParametrs* param){

    CUSTOM_ASSERT(param != nullptr);

    functionParametrs get_params = {param->a, param->b, param->c, 0, 0, NO_ROOTS};
  
    solveEquation(&get_params);

    if (get_params.nRoots != param->nRoots) {
        printf("%d - %d\n", param->nRoots, get_params.nRoots);
        printf(COLOR_RED "FAILED. Icorrcet number of roots\n" RESET_ALL);
        return ; // TODO ввести счетчик тестов(сколько прошло, сколько всего)
    }
    if ((get_params.nRoots == ONE_ROOT ) && !(compareDoubleNumbers(get_params.x1, param->x1))) {
        printf(COLOR_RED "FAILED. Your root x = %lg," COLOR_GREEN "should to be: %lg\n" RESET_ALL, param->x1, get_params.x1);
        return ;
    }
    if (get_params.nRoots == TWO_ROOTS &&  !compareDoubleNumbers(get_params.x2, param->x2)) {
        printf(COLOR_RED "FAILED. Your roots x1 =  %lf, x2 = %lf, should be:" COLOR_GREEN " x1 = %lf, x2 = %lf\n" RESET_ALL, get_params.x1, get_params.x2, param->x1, param->x2);
        return ;
    }
        printf(COLOR_GREEN "SUCCESS\n" RESET_ALL); 
}

// nRoots ConvertFromStringToEnum(char symbol) {
//     if (symbol == 'T') {
//         return TWO_ROOTS;
//     }
// }

void unitTests(){   

    FILE* fp = fopen("file.txt", "r");

    //CUSTOM_ASSERT(fp == nullptr);
    const size_t numberOfTests = 5;

    if (fp == NULL) {
        printf("Error: can't open file\n");
        return;
    }

    functionParametrs arrayOfTests[numberOfTests] = {};

    char inputNRootsString[10];

    for (size_t i = 0; i < numberOfTests; i++) {
        fscanf(fp, "%lg %lg %lg %lg %lg %s", &(arrayOfTests[i].a), 
                                             &(arrayOfTests[i].b),
                                             &(arrayOfTests[i].c),
                                             &(arrayOfTests[i].x1),
                                             &(arrayOfTests[i].x2),
                                             inputNRootsString);
                                               
        arrayOfTests[i].nRoots = convertStringFromFileToEnum(*inputNRootsString);  
                             
    }
    
    //functionParametrs array[] = {};
        
       // {1, 5, 6, -2, -3, TWO_ROOTS}, // выравнить, .a = 1, .b = 5
       // {0, 0, 0, NAN, NAN, INFINIT_ROOTS},
       // {0, 3, 5, -5.0/3, NAN, ONE_ROOT},
       // {1, 0, -4, 2, -2, TWO_ROOTS},
       // {0, 0, 1, NAN, NAN, NO_ROOTS},
       // {0.000001, 200000, 300000, -1.5, -2e11, TWO_ROOTS}, 
    //};

   // size_t number_of_unitTests = sizeof(array) / sizeof(array[0]);
    
    for (size_t i = 0; i < numberOfTests; i++) {
        checkParametrs(&arrayOfTests[i]);
    }
}