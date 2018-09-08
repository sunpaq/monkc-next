//
//  MCLinkedList.c
//  monkc3
//
//  Created by 孙御礼 on 9/8/30 H.
//  Copyright © 30 Heisei oreisoft. All rights reserved.
//

#include "MCLinkedList.h"
#include "MCMem.h"

fun(append, void), struct MCItem item) as(MCLinkedList)
    if (!obj->head.next) {
        obj->head = item;
        return;
    }
    struct MCItem* iter = &obj->head;
    do {
        iter = iter->next;
    } while (!iter->next);

    struct MCItem* newitem;
    if (obj->freecount <= 0) {
        obj->free = mc_alloc(sizeof(struct MCItem) * 100);
        obj->freecount = 100;
    }

    newitem = &obj->free[100 - obj->freecount];
    obj->freecount--;

    *newitem = item;
    iter->next = newitem;
}

fun(clear, void)) as(MCLinkedList)
    struct MCItem* iter = &obj->head;
    while (iter) {
        let(iter->data, MCObject)
            release(obj);
        }
        struct MCItem* i = iter;
        iter = iter->next;
        mc_free(i);
    }
}

constructor(MCLinkedList) {
    if (any) {
        as(MCLinkedList)
        obj->head.data = null;
        obj->head.next = null;
        
        obj->free = null;
        
        obj->freecount = 0;
        
        funadd(append);
        funadd(clear);
        }
    }
    return any;
}
