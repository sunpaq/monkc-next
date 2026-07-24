#ifndef Cell_h
#define Cell_h

#include <stdio.h>
#include "MCObject.h"

structure(Cell, MCObject)
    int age;
    fundef(cellfunc, void) endfun;
    fundef(initWithAge, void*), int age endfun;
    fundef(getAge, int) endfun;
    fundef(printName, void) endfun;
    fundef(release, void) endfun;
end;

constructor(Cell), int age endfun;

alias(Cell);

#endif /* Cell_h */