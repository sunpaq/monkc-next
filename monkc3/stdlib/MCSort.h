#ifndef MCSort_h
#define MCSort_h

#include "MCObject.h"

structure(MCSort, MCObject)
    mc_generic* array;
    size_t length;

    fundef(bye, void));
    fundef(insertionSort, void));
    fundef(quickSort, void));
    fundef(printArray, void));
};

constructor(MCSort), mc_generic* array, size_t length);

alias(MCSort);

#endif /* MCSort_h */
