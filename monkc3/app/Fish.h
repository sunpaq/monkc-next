#ifndef Fish_h
#define Fish_h

#include "Cell.h"

structure(Fish, Cell)
    int age;
    char name[256];
    fundef(initWithAge, void*), int age end_;
    fundef(getAge, int) end_;
    fundef(printName, void) end_;
    fundef(release, void) end_;
end;

constructor(Fish), const char* name end_;

alias(Fish);

#endif /* Fish_h */
