#ifndef Fish_h
#define Fish_h

#include "Cell.h"

struct Fish is
    copy_super(Cell);
    int age;
    char name[256];
    fundef(initWithAge, void*), int age endfun;
    fundef(getAge, int) endfun;
    fundef(printName, void) endfun;
    fundef(release, void) endfun;
end;

constructor(Fish), const char* name endfun;

alias(Fish);

#endif /* Fish_h */