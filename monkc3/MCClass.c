//
//  Class.c
//  monkc3
//
//  Created by 孙御礼 on 9/8/30 H.
//  Copyright © 30 Heisei oreisoft. All rights reserved.
//

#include "MCClass.h"
#include "MCFunction.h"
#include "MCMem.h"

static struct MCClass* global_classes_table[2048];
static int class_index = 0;

struct MCClass* MCClass_load(const char* name) {
    size_t size = sizeof(struct MCClass);
    void* any = mc_alloc(size);
    if (any) {
        struct MCClass* cla = MCClass(any);
        strncpy(cla->name, name, strlen(name));
        cla->name[strlen(name)] = '\0';
        printf("class %s loaded\n", name);
        
        global_classes_table[class_index++] = cla;
        return cla;
    }
    return null;
}

void MCClass_gc(void) {
    for (int i=0; i<class_index; i++) {
        struct MCClass* cla = global_classes_table[i];
        cla->clearInstances(cla);
    }
}

fun(setFunction, void), const char* key, MCFunction value) {

}

fun(appendInstance, void), void* instance) as(MCClass)
    struct MCItem it;
    it.data = instance;
    it.next = null;
    if (obj->instances) {
        obj->instances->append(obj->instances, it);
    }
}

fun(clearInstances, void)) as(MCClass)
    if (obj->instances) {
        obj->instances->clear(obj->instances);
    }
}

constructor(MCClass) {
    as(MCClass)
        void* mem = mc_alloc(sizeof(MCLinkedList));
        obj->instances = MCLinkedList(mem);
    
        funadd(setFunction);
        funadd(appendInstance);
        funadd(clearInstances);
    }
    return any;
}
