#ifndef MCSort_h
#define MCSort_h

#include "MCObject.h"

structure(MCSort, MCObject)
    mc_generic* array;
    size_t length;

    fundef(bye, void)endfun;
    fundef(insertionSort, void)endfun;
    fundef(quickSort, void)endfun;
    fundef(printArray, void)endfun;
end;

constructor(MCSort), mc_generic* array, size_t length endfun;

alias(MCSort);

#endif /* MCSort_h */
