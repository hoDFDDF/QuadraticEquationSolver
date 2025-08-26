#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "io.h"
#include "SolveEquation.h"
#include "Test.h"
#include "FlagsForCompilation.h"


int clearBuffer() {
    char c = 0;
    do {
        c = getchar();
        if (c == 'q') {
            return 0;
        }
    } while (c != '\n' && c != EOF);
    return 1;
}

int releaseMode(functionPatametrs* param) {
    
    printf("Please, enter 3 ratio numbers(a, b, c). To end program enter (q):\n");
    int c = 0;

    while (true) { // TODO усовершенствовать выводимые фразы, пересмотреть логику

        int right_numbers_of_enter_paramets = scanf("%lf %lf %lf", &(param->a),
                                                                   &(param->b),
                                                                   &(param->c)); // TODO: скорректировать название переменной
        //printf("%lf %lf %lf\n", param->a, param->b, param->c); 
        if(right_numbers_of_enter_paramets != 3){
            if (!clearBuffer()) {
                return 0;
            }
            printf("Incorrect input, try again\n");
            return releaseMode(param);
        }
        
        solveEquation(param);
        printRoots(param); 
        printf("\nContinue enter\n");           
    } 
         return 0; 
}

   



// const char* const test_flag = "--test"; в header file
// поработать над вводом и посмотреть учистку буффера ввода
// сделать кастомный ассерт (по факту это будет твой личный define), использовать макросы __LINE__, PRETTY_FUNC, __FILE__
// define CUSTOM_ASSERT(flag, line, func, file)
// CUSTOM_ASSERT(param != NULL)
// добавить простейший makefile
//make colorPrint
int main(int argc, char* argv[]) {
    functionPatametrs param = {};
   
    if (argc == 2) {
        if (strcmp(argv[1], test_flag) == 0) {
            unitTests();
            return 0;
        }
        if (strcmp(argv[1], help_flag) == 0) {
            printf("Sorry, I can't help you now FUUUCK YOU\n"); // ??????????
            return 0;
        }
        if (strcmp(argv[1], release_flag) == 0) {
            releaseMode(&param);
            return 0;
        }
    }

    printf("fuck you\n");

    return 0;
}

// структуры, enum их имена и т.п каждое слово с большой буквы без пробелов, например, NumberRoots
// название функций, например, prettyFunc (первое с маленькой, дальше с большой)
// переменные, например, pretty_peremennay
// enum внутри, define все капсом, например TWO_ROOTS, CUSTOM_ASSERT
        
    
    

    

    //printf("Enter 3 ratio numbers: ");
    //int c;
    //while ((c = getchar()) != 'q'){
    //int checkScanf = scanf("%lg %lg %lg", &parametrs.a, &parametrs.b, &parametrs.c);

    //printf("%f %f %f\n", a, b, c);
    //printf("isZero(a) = %d\n", isZero(a));
    //if (checkScanf != 3) { // TODO: install anchors extension
    // printf("Incorrect enter ((((. Try again\n"); // TODO: better userinterface
     //   return 0;
    //}
  

   




// TODOTODO: meow("");

// TODO solveEquation




// Code style (possible): 
// if () {...}, while () {...}, function(args);

// TODO:
// 0. Whatever your mentor says.
// 1. Better user interface.
// 2. Multiple files.
