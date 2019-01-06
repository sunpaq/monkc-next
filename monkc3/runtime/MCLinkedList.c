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

    struct MCItem* newitem = null;
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
        let(iter->data.mcobject, MCObject)
            iter->data.mcobject->release(iter->data.mcobject);
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


/*
 Floyd Cycle Detection (Tortoise and Hare)
 Ot(Nl+Nc) -> fast only go max one loop
 Os(1)
 */

/*
static int detectCycle(MCItem* A, MCItem** start) {
    MCItem *slow = A, *fast = A;
    int slowstep = 0, iscycle = 0;
    while(slow && fast && fast->nextItem) {
        slow = slow->nextItem;
        fast = fast->nextItem->nextItem;
        slowstep++;
        if(slow == fast) {
            iscycle = 1;
            break;
        }
    }
    if(iscycle == 0) {
        start = NULL;
        return 0;
    }

    slow = A;
    while(slow!=fast) {
        slow = slow->nextItem;
        fast = fast->nextItem;
    }

    *start = slow;
    return slowstep;
}

//MCItem

fun(linkNext, void), struct MCItem* next) as(MCItem)
    it->next = next;
    next->prev = it;
}

fun(linkPrev, void), struct MCItem* prev) as(MCItem)
    it->prev = prev;
    prev->next = it;
}

constructor(MCItem), mc_generic value) as(MCItem)
    it->value = value;
    it->object = null;
    it->prev = null;
    it->next = null;

    funadd(linkNext);
    funadd(linkPrev);

    return any;
}

//MCLinkedList

fun(MCLinkedList, unsigned), getCount) as(MCLinkedList)
    if (it->countChanged == true) {
        int i = 0;
        MCItem_p iter = it->headItem;
        while (iter != null) {
            iter = iter->nextItem;
            i++;
        }
        it->countChanged = false;
        it->countCache = i;
        return i;
    }else{
        return it->countCache;
    }
}

fun(MCLinkedList, MCItem_p), cycleStart) as(MCLinkedList)
    MCItem_p start = null;
    detectCycle(obj->headItem, &start);
    if (start) {
        return start;
    }
    return null;
}

fun(addItemAt, void), MCItem_t item, int index) as(MCLinkedList)
    MCItem_p iter = obj->headItem;
    //build list until reach index
    int i = 0;
    while (i < index) {
        if (iter) {
            if (iter->nextItem == null) {
                MCItem_p item = MCItem(alloc(MCItem)) new(MCItem);

                MCLinkedList_pushItem(obj, item);
            }
            iter = iter->nextItem;
        }
        i++;
    }
    //replace the item at index
    MCLinkedList_replaceItemAtIndex(obj, index, item);
}

fun(addItem, void), MCItem_t* item) as(MCLinkedList)
    if (item != null) {
        var(countChanged) = true;
        if (var(tailItem) == null) {
            var(tailItem) = item;
            var(headItem) = item;
        }else{
            MCItem_linkNextItem(var(tailItem), item);
            var(tailItem) = item;
        }
    }
}
fundef(delItem, void), MCItem_p item);
fundef(pushItem, void), MCItem_t item);
fundef(popItem, MCItem_t));
fundef(itemAt, MCItem_t), int index);
fundef(replaceAt, void), int index, MCItem_t withItem);
fundef(insertAfter, void), MCItem_p anchor, MCItem_t item);
fundef(insertBefore, void), MCItem_p anchor, MCItem_t item);

fundef(connectList, struct MCLinkedList*), struct MCLinkedList* list);
fundef(addObject, void), obj object);



fun(MCLinkedList, void, addItem, MCItem* item)
{

}

fun(MCLinkedList, void, delItem, MCItem* item)
{
    if (item != null) {
        var(countChanged) = true;
        if (item == var(headItem)) {
            var(headItem) = null;
            var(tailItem) = null;
            release(item);
        }
        else if (item == var(tailItem)){
            MCItem* tail = var(tailItem)->prevItem;
            tail->nextItem = null;
            release(var(tailItem));
            var(tailItem) = tail;
        }
        else {
            MCItem* prev = item->prevItem;
            MCItem* next = item->nextItem;
            MCItem_linkNextItem(prev, next);
            release(item);
        }
    }
}

fun(MCLinkedList, void, addAndRetainObject, MCObject* object)
{
    MCLinkedList_addItem(obj, MCItem_itemWithObject(object));
}

fun(MCLinkedList, void, pushItem, MCItem* item)
{
    MCLinkedList_addItem(obj, item);
}

fun(MCLinkedList, MCItem*, popItem, voida)
{
    if (cpt(count) > 0 && var(headItem)) {
        MCLinkedList_delItem(obj, var(headItem));
        return var(headItem);
    }
    return null;
}

fun(MCLinkedList, void, insertAfterItem, MCItem* anchor, MCItem* item)
{
    if (anchor != null && item != null) {
        var(countChanged) = true;
        MCItem* next = anchor->nextItem;
        MCItem_linkNextItem(anchor, item);
        MCItem_linkNextItem(item, next);
    }
}

fun(MCLinkedList, void, insertBeforeItem, MCItem* anchor, MCItem* item)
{
    if (anchor != null && item != null) {
        var(countChanged) = true;
        MCItem* prev = anchor->prevItem;
        MCItem_linkPrevItem(anchor, item);
        MCItem_linkPrevItem(item, prev);
    }
}

fun(MCLinkedList, MCLinkedList*, connectList, MCLinkedList* otherlist)
{
    retain(otherlist);
    MCItem_linkNextItem(var(tailItem), otherlist->headItem);
    return obj;
}

fun(MCLinkedList, void, forEach, mc_message callback, void* userdata)
{
    MCItem* item = obj->headItem;
    while (item != null) {
        _push_jump(response_to(callback.object, callback.message), item, userdata);
        item = item->nextItem;
    }
}

fun(MCLinkedList, MCItem*, itemAtIndex, int index)
{
    MCItem* item = obj->headItem;
    int i = 0;
    while (item != null) {
        if (index == i) {
            return item;
        }
        item = item->nextItem;
        i++;
    }
    return null;
}

fun(MCLinkedList, void, replaceItemAtIndex, int index, MCItem* withitem)
{
    MCItem* item = MCLinkedList_itemAtIndex(obj, index);
    if (item) {
        withitem->prevItem = item->prevItem;
        withitem->nextItem = item->nextItem;
        release(item);
    }
}



fun(MCLinkedList, void, bye, voida)
{
MCLinkedListForEach(obj,
        release(item);
);
}

constructor(MCLinkedList) {
    MCObject(any);
    as(MCLinkedList)
        it->headItem = null;
        it->tailItem = it->headItem;
        it->countChanged = true;
        it->countCache = 0;

        funadd(count);
        funadd(cycle);
    };
    dynamic(MCLinkedList)

    };
    return any;
}



onload(MCLinkedList)
{
    if (load(MCObject)) {
        bid(MCLinkedList, void, bye, voida);
        bid(MCLinkedList, void, addItem, MCItem* item);
        bid(MCLinkedList, void, delItem, MCItem* item);
        bid(MCLinkedList, void, addAndRetainObject, MCObject* object);
        bid(MCLinkedList, void, pushItem, MCItem* item);
        bid(MCLinkedList, MCItem*, popItem, voida);
        bid(MCLinkedList, void, insertAfterItem, MCItem* anchor, MCItem* item);
        bid(MCLinkedList, void, insertBeforeItem, MCItem* anchor, MCItem* item);
        bid(MCLinkedList, MCLinkedList*, connectList, MCLinkedList* otherlist);
        bid(MCLinkedList, void, forEach, mc_message callback, void* userdata);
        bid(MCLinkedList, MCItem*, itemAtIndex, int index);
        bid(MCLinkedList, void, addItemAtIndex, int index, MCItem* item);
        bid(MCLinkedList, void, replaceItemAtIndex, int index, MCItem* withitem);
        return cla;
    }else{
        return null;
    }
}

*/