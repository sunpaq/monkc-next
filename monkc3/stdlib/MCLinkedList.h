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

    fundef(linkNextItem, void), struct MCItem* next end_;
    fundef(linkPrevItem, void), struct MCItem* prev end_;
    fundef(releaseContent, void) end_;
    fundef(release, void) end_;
end;

constructor(MCItem), obj content end_;

alias(MCItem);

struct MCItem* MCItem_itemWithObject(obj content);

//List

structure(MCLinkedList, MCObject)
    MCItem_t* headItem;
    MCItem_t* tailItem;

    bool countChanged;
    unsigned countCache;

    fundef(count, unsigned) end_;
    fundef(cycle, MCItem_t*) end_;
    fundef(addItem, void), MCItem_t* item end_;
    fundef(delItem, void), MCItem_t* item end_;
    fundef(addAndRetainObject, void), obj object end_;
    fundef(pushItem, void), MCItem_t* item end_;
    fundef(popItem, MCItem_t*) end_;
    fundef(itemAtIndex, MCItem_t*), int index end_;
    fundef(addItemAtIndex, void), int index, MCItem_t* item end_;
    fundef(replaceItemAtIndex, void), int index, MCItem_t* withitem end_;
    fundef(insertAfterItem, void), MCItem_t* anchor, MCItem_t* item end_;
    fundef(insertBeforeItem, void), MCItem_t* anchor, MCItem_t* item end_;
    fundef(connectList, struct MCLinkedList*), struct MCLinkedList* otherlist end_;
    fundef(release, void) end_;
end;

constructor(MCLinkedList) end_;

alias(MCLinkedList);

#define MCLinkedListForEach(list, code) \
{struct MCItem* item = list->headItem;  \
while (item != null) {                  \
    code                                \
    item = item->nextItem;              \
}}

#endif /* MCLinkedList_h */
