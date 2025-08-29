#ifndef ERROR_PARCER_
#define ERROR_PARCER_

#include <stdlib.h> 

#include "ioFuncs.h"

// enum SquareSolverErrors {
// SQUARE_SOLVER_STATUS_IS_OK
// WRONG_INPUT
// PTR_IS_NULL
// SQUARE_SOLVER_STATUS_IS_INCORRECT
//}

#define CUSTOM_ASSERT(exeption) {                                                                         \
  if (!(exeption)) {                                                                                      \
  printf( COLOR_RED "FAILED. Your CUSTOM caught error in FILE: %s, on line %d, in function %s " RESET_ALL,\
    __FILE__, __LINE__, __func__);                                                                        \
    abort();                                                                                              \
  }                                                                                                       \
}

#endif //ERROR_PARCER_