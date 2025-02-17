#ifndef Cell_h
#define Cell_h

#include <stdio.h>
#include "MCObject.h"
#include "MCFunction.h"

structure(Cell, MCObject)
    int age;
    fundef(cellfunc, void) end_;
    fundef(initWithAge, void*), int age end_;
    fundef(getAge, int) end_;
    fundef(printName, void) end_;
    fundef(release, void) end_;
end;

constructor(Cell), int age end_;

alias(Cell);

function(Cell, begin, void) end_;

#endif /* Cell_h */
