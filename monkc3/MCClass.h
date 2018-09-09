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
#include "monkc.h"
#include "MCFunction.h"
#include "MCType.h"
#include "MCMem.h"
#include "MCLinkedList.h"

struct MCClass {
    char name[256];
    struct MCLinkedList* instances;
    
    fundef(setFunction, void), const char* key, MCFunction value);
    fundef(appendInstance, void), void* instance);
    fundef(clearInstances, void));
};

constructor(MCClass));

struct MCClass* MCClass_load(const char* name);
void MCClass_gc(void);

#endif /* MCClass_h */
