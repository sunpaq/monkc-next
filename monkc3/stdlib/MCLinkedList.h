#ifndef MCLinkedList_h
#define MCLinkedList_h

//#include <stdio.h>
#include "MCObject.h"
#include "MCType.h"
//Item

structure(MCItem, MCObject)
    mc_generic value;
    obj object;
    struct MCItem* prevItem;
    struct MCItem* nextItem;

    fundef(linkNextItem, void), struct MCItem* next endfun;
    fundef(linkPrevItem, void), struct MCItem* prev endfun;
    fundef(releaseContent, void)endfun;
    fundef(release, void)endfun;
end;

constructor(MCItem), obj content endfun;

alias(MCItem);

struct MCItem* MCItem_itemWithObject(obj content);

//List

structure(MCLinkedList, MCObject)
    MCItem_t* headItem;
    MCItem_t* tailItem;

    bool countChanged;
    unsigned countCache;

    fundef(count, unsigned)endfun;
    fundef(cycle, MCItem_t*)endfun;
    fundef(addItem, void), MCItem_t* item endfun;
    fundef(delItem, void), MCItem_t* item endfun;
    fundef(addAndRetainObject, void), obj object endfun;
    fundef(pushItem, void), MCItem_t* item endfun;
    fundef(popItem, MCItem_t*)endfun;
    fundef(itemAtIndex, MCItem_t*), int index endfun;
    fundef(addItemAtIndex, void), int index, MCItem_t* item endfun;
    fundef(replaceItemAtIndex, void), int index, MCItem_t* withitem endfun;
    fundef(insertAfterItem, void), MCItem_t* anchor, MCItem_t* item endfun;
    fundef(insertBeforeItem, void), MCItem_t* anchor, MCItem_t* item endfun;
    fundef(connectList, struct MCLinkedList*), struct MCLinkedList* otherlist endfun;
    fundef(release, void)endfun;
end;

constructor(MCLinkedList)endfun;

alias(MCLinkedList);

#define MCLinkedListForEach(list, code) \
{struct MCItem* item = list->headItem;         \
while (item != null) {                  \
    code                                \
    item = item->nextItem;              \
}}

#endif /* MCLinkedList_h */
