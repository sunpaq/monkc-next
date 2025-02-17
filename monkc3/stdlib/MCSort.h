#ifndef MCSort_h
#define MCSort_h

#include "MCObject.h"

structure(MCSort, MCObject)
    mc_generic* array;
    size_t length;

    fundef(bye, void) end_;
    fundef(insertionSort, void) end_;
    fundef(quickSort, void) end_;
    fundef(printArray, void) end_;
end;

constructor(MCSort), mc_generic* array, size_t length end_;

alias(MCSort);

#endif /* MCSort_h */
