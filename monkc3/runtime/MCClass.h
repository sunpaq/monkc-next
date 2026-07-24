#ifndef MCClass_h
#define MCClass_h

#include <stdio.h>
#include <stdlib.h>

#include "monkc.h"
#include "MCFunction.h"
#include "MCType.h"
#include "MCMem.h"
#include "MCHashTable.h"

struct MCClass is
    struct MCClass* super;
    struct MCHashTable* methodtable;

    fundef(setFunction, void), const char* key, MCFunction value endfun;
    fundef(getFunction, MCFunction), const char* key endfun;
    fundef(getFunctionDouble, MCFunctionDouble), const char* key endfun;

    char name[256];
end;

constructor(MCClass), const char* name endfun;

struct MCClass* MCClass_load(const char* name);

#endif /* MCClass_h */