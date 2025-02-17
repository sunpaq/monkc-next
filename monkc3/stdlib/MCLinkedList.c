#include "MCLinkedList.h"

/*
 Floyd Cycle Detection (Tortoise and Hare)
 Ot(Nl+Nc) -> fast only go max one loop
 Os(1)
 */

static int detectCycle(MCItem_t* A, MCItem_t** start) {
    MCItem_t *slow = A, *fast = A;
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

fun(linkNextItem, void), MCItem_t* next end_ as(MCItem)
    it->nextItem = next;
    next->prevItem = it;
end

fun(linkPrevItem, void), MCItem_t* prev end_ as(MCItem)
    it->prevItem = prev;
    prev->nextItem = it;
end

fun(releaseContent, void) end_ as(MCItem)
    if (it->object) {
        it->object->release(it->object);
    }
end

fun(release, void) end_ {
    as(MCObject)
        it->release(it);
    end
}

constructor(MCItem), obj content end_ {
    MCObject(any, "MCItem");
    as(MCItem)
        it->object = content;
        it->value = gen_p(null);
        it->prevItem = null;
        it->nextItem = null;
        content->retain(content);
    end
    dynamic(MCItem)
        funbind(linkNextItem);
        funbind(linkPrevItem);
        funbind(releaseContent);
        funbind(release);
    end
    return any;
}

struct MCItem* MCItem_itemWithObject(obj content)
{
    struct MCItem* item = MCItem(alloc(MCItem), content);
    return item;
}

//MCLinkedList

fun(count, unsigned) end_ as(MCLinkedList)
    if (it->countChanged == true) {
        unsigned i = 0;
        MCItem_t* iter = it->headItem;
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
end

fun(cycle, MCItem_t*) end_ as(MCLinkedList)
    MCItem_t* start = null;
    detectCycle(it->headItem, &start);
    if (start) {
        return start;
    }
    return null;
end

fun(addItem, void), MCItem_t* item end_ as(MCLinkedList)
    if (item != null) {
        it->countChanged = true;
        if (it->tailItem == null) {
            it->tailItem = item;
            it->headItem = item;
        } else {
            it->tailItem->linkNextItem(it->tailItem, item);
            it->tailItem = item;
        }
    }
end

fun(delItem, void), MCItem_t* item end_ as(MCLinkedList)
    if (item != null) {
        it->countChanged = true;
        if (item == it->headItem) {
            it->headItem = null;
            it->tailItem = null;
            item->release(item);
        }
        else if (item == it->tailItem) {
            MCItem_t* tail = it->tailItem->prevItem;
            tail->nextItem = null;
            it->tailItem->release(it->tailItem);
            it->tailItem = tail;
        }
        else {
            MCItem_t* prev = item->prevItem;
            MCItem_t* next = item->nextItem;
            item->linkNextItem(prev, next);
            item->release(item);
        }
    }
end

fun(addAndRetainObject, void), obj object end_ as(MCLinkedList)
    addItem(it, MCItem_itemWithObject(object));
end

fun(pushItem, void), MCItem_t* item end_ as(MCLinkedList)
    addItem(it, item);
end

fun(popItem, MCItem_t*) end_ as(MCLinkedList)
    if (it->count(it) > 0 && it->headItem) {
        delItem(it, it->headItem);
        return it->headItem;
    }
    return null;
end

fun(insertAfterItem, void), MCItem_t* anchor, MCItem_t* item end_ as(MCLinkedList)
    if (anchor != null && item != null) {
        it->countChanged = true;
        MCItem_t* next = anchor->nextItem;
        linkNextItem(anchor, item);
        linkNextItem(item, next);
    }
end

fun(insertBeforeItem, void), MCItem_t* anchor, MCItem_t* item end_ as(MCLinkedList)
    if (anchor != null && item != null) {
        it->countChanged = true;
        MCItem_t* prev = anchor->prevItem;
        linkPrevItem(anchor, item);
        linkPrevItem(item, prev);
    }
end

fun(connectList, struct MCLinkedList*), struct MCLinkedList* otherlist end_ as(MCLinkedList)
    ((obj)otherlist)->retain(otherlist);
    linkNextItem(it->tailItem, otherlist->headItem);
    return it;
end

fun(itemAtIndex, MCItem_t*), int index end_ as(MCLinkedList)
    MCItem_t* item = it->headItem;
    int i = 0;
    while (item != null) {
        if (index == i) {
            return item;
        }
        item = item->nextItem;
        i++;
    }
    return null;
end

fun(replaceItemAtIndex, void), int index, MCItem_t* withitem end_ as(MCLinkedList)
    MCItem_t* item = itemAtIndex(it, index);
    if (item) {
        withitem->prevItem = item->prevItem;
        withitem->nextItem = item->nextItem;
        release(item);
    }
end

fun(addItemAtIndex, void), int index, MCItem_t* item end_ as(MCLinkedList)
    MCItem_t* iter = it->headItem;
    //build list until reach index
    int i = 0;
    while (i < index) {
        if (iter) {
            if (iter->nextItem == null) {
                item = MCItem(alloc(MCItem), null);
                pushItem(it, item);
            }
            iter = iter->nextItem;
        }
        i++;
    }
    //replace the item at index
    replaceItemAtIndex(it, index, item);
end

fun(MCLinkedList_release, void) end_ as(MCLinkedList)
    MCLinkedListForEach(it,
                        item->release(item);
                        );
end

constructor(MCLinkedList) end_ {
    MCObject(any, "MCLinkedList");
    as(MCLinkedList)
        it->headItem = null;
        it->tailItem = null;
        it->countChanged = false;
        it->countCache = 0;
        it->release = MCLinkedList_release;
    end
    dynamic(MCLinkedList)
        funbind(count);
        funbind(cycle);
        funbind(addItem);
        funbind(delItem);
        funbind(addAndRetainObject);
        funbind(pushItem);
        funbind(popItem);
        funbind(itemAtIndex);
        funbind(addItemAtIndex);
        funbind(replaceItemAtIndex);
        funbind(insertAfterItem);
        funbind(insertBeforeItem);
        funbind(connectList);
    end
    return any;
}
