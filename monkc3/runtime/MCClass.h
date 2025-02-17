#ifndef MCClass_h
#define MCClass_h

#include <stdio.h>
#include <stdlib.h>

#include "monkc.h"
#include "MCFunction.h"
#include "MCType.h"
#include "MCMem.h"
#include "MCHashTable.h"

struct MCClass {
    struct MCClass* super;
    struct MCHashTable* methodtable;

    fundef(setFunction, void), const char* key, MCFunction value end_;
    fundef(getFunction, MCFunction), const char* key end_;
    fundef(getFunctionDouble, MCFunctionDouble), const char* key end_;

    char name[256];
};

constructor(MCClass), const char* name end_;

struct MCClass* MCClass_load(const char* name);

#endif /* MCClass_h */
