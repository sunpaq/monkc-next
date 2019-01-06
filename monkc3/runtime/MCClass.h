//
//  Class.h
//  monkc3
//
//  Created by 孙御礼 on 9/8/30 H.
//  Copyright © 30 Heisei oreisoft. All rights reserved.
//

#ifndef MCClass_h
#define MCClass_h

#include <stdio.h>
#include <stdlib.h>

#include "monkc.h"
#include "MCFunction.h"
#include "MCType.h"
#include "MCMem.h"
#include "MCLinkedList.h"
#include "MCHashTable.h"

struct MCClass {
    struct MCClass* super;
    struct MCLinkedList* instances;
    struct MCHashTable* methodtable;

    fundef(setFunction, void), const char* key, MCFunction value);
    fundef(getFunction, MCFunction), const char* key);
    fundef(getFunctionDouble, MCFunctionDouble), const char* key);

    fundef(appendInstance, void), void* instance);
    fundef(clearInstances, void));

    char name[256];
};

constructor(MCClass), const char* name);

struct MCClass* MCClass_load(const char* name);
void MCClass_gc(const char* name);

#endif /* MCClass_h */
