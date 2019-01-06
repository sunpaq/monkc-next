//
//  Class.c
//  monkc3
//
//  Created by 孙御礼 on 9/8/30 H.
//  Copyright © 30 Heisei oreisoft. All rights reserved.
//

#include "MCClass.h"
#include "MCFunction.h"
#include "MCHashTable.h"
#include "MCMem.h"

static struct MCHashTable* global_classes_table = null;

struct MCClass* MCClass_load(const char* name) {
    if (!global_classes_table) {
        void* any = alloc(MCHashTable);
        if (any) {
            global_classes_table = MCHashTable(any);
        }
    }
    void* any = alloc(MCClass);
    if (any) {
        struct MCClass* cla = MCClass(any, name);
        global_classes_table->put(global_classes_table, name, gen_p(cla));
        printf("class %s loaded\n", name);
        return cla;
    }
    return null;
}

void MCClass_gc(const char* name) {
    struct MCClass* cla = global_classes_table->get(global_classes_table, name).p;
    if (cla) {
        cla->clearInstances(cla);
    }
}

fun(setFunction, void), const char* key, MCFunction value) as(MCClass)
    printf("%s setFunction(%s)\n", it->name, key);
    it->methodtable->put(it->methodtable, key, gen_p(value));
}

fun(getFunction, MCFunction), const char* key) as(MCClass)
    struct MCClass* iter = it;
    while (iter) {
        MCFunction f = iter->methodtable->get(iter->methodtable, key).p;
        if (f) {
            return f;
        }
        iter = iter->super;
    }
    return null;
}

fun(getFunctionDouble, MCFunctionDouble), const char* key) as(MCClass)
    struct MCClass* iter = it;
    while (iter) {
        MCFunctionDouble f = iter->methodtable->get(iter->methodtable, key).p;
        if (f) {
            return f;
        }
        iter = iter->super;
    }
    return null;
}

fun(appendInstance, void), void* instance) as(MCClass)
    struct MCItem item;
    item.data = gen_p(instance);
    item.next = null;
    if (it->instances) {
        it->instances->append(it->instances, item);
    }
}

fun(clearInstances, void)) as(MCClass)
    if (it->instances) {
        it->instances->clear(it->instances);
    }
}

constructor(MCClass), const char* name) {
    as(MCClass)
        strncpy(it->name, name, strlen(name));
        it->name[strlen(name)] = '\0';

        void* mem = mc_alloc(sizeof(MCLinkedList));

        it->super = null;
        it->instances = MCLinkedList(mem);
        it->methodtable = MCHashTable(alloc(MCHashTable));

        funadd(setFunction);
        funadd(getFunction);
        funadd(getFunctionDouble);
        funadd(appendInstance);
        funadd(clearInstances);
    }
    return any;
}
