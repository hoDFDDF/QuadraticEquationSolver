#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "ioFuncs.h"
#include "SolveEquation.h"
#include "Test.h"
#include "FlagsForCompilation.h"
#include "ProgramModes.h"

int main(int argc, char* argv[]){

    FunctionParametrs param = {};

    if (argc == 2) {
        if (strcmp(argv[1], test_flag) == 0) {
            unitTests();
            return 0;
        }
        if (strcmp(argv[1], help_flag) == 0) {
            printf(COLOR_MAGENTA "Sorry, I can't help you now FUUUCK YOU\n" RESET_ALL); 
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