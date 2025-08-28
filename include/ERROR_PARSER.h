#ifndef ERROR_PARCER_
#define ERROR_PARCER_

#include <stdlib.h> 

#define CUSTOM_ASSERT(exeption) \
  if (!(exeption)){\
  printf("FAILED. Your CUSTOM caught error in FILE: %s, on line %d, in function %s ",\
    __FILE__, __LINE__, __func__);\
    abort();\
  }\
//}


#endif //ERROR_PARCER_

