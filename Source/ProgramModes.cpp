#include <stdio.h>  

#include "ProgramModes.h"
#include "ERROR_PARSER.h"
#include "ioFuncs.h"

bool clearBuffer() {
    int c = 0;
    do {
        c = getchar();
        if (c == 'q') {
            return 0;
        }
    } while (c != '\n' && c != EOF);
    return 1;
}

int releaseMode(functionParametrs* param) {

    CUSTOM_ASSERT(param != nullptr);

    printf(COLOR_YELLOW "Please, enter 3 ratio numbers(a, b, c). To end program enter (q):\n" RESET_ALL);

    while (true) { // TODO усовершенствовать выводимые фразы, пересмотреть логику

        int right_numbers_of_enter_paramets = scanf("%lf %lf %lf", &(param->a),
                                                                   &(param->b),
                                                                   &(param->c)); // TODO: скорректировать название переменной
        if(right_numbers_of_enter_paramets != 3){
            if (!clearBuffer()) {
                return 0;
            }
            printf(COLOR_RED "Incorrect input, try again\n" RESET_ALL);
            return releaseMode(param);
        }
        
        solveEquation(param);
        printRoots(param); 
        printf(COLOR_WHITE "\nContinue enter\n" RESET_ALL);           
    } 
        return 0; 
}