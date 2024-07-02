#ifndef Fish_h
#define Fish_h

#include "Cell.h"

structure(Fish, Cell)
    int age;
    char name[256];
    fundef(initWithAge, void*), int age);
    fundef(getAge, int));
    fundef(printName, void));
    fundef(release, void));
};

constructor(Fish), const char* name);

alias(Fish);

#endif /* Fish_h */
