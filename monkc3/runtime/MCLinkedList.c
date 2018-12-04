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
    if (!it->head.next) {
        it->head = item;
        return;
    }
    struct MCItem* iter = &it->head;
    do {
        iter = iter->next;
    } while (!iter->next);

    struct MCItem* newitem;
    if (it->freecount <= 0) {
        it->free = mc_alloc(sizeof(struct MCItem) * 100);
        it->freecount = 100;
    }

    newitem = &it->free[100 - it->freecount];
    it->freecount--;

    *newitem = item;
    iter->next = newitem;
}

fun(clear, void)) as(MCLinkedList)
    struct MCItem* iter = &it->head;
    while (iter) {
        let(iter->data.p, MCObject)
            release(it);
        }
        struct MCItem* i = iter;
        iter = iter->next;
        mc_free(i);
    }
}

constructor(MCLinkedList)) {
    if (any) {
        as(MCLinkedList)
        it->head.data = gen_p(null);
        it->head.next = null;
        
        it->free = null;
        
        it->freecount = 0;
        
        funadd(append);
        funadd(clear);
        }
    }
    return any;
}
