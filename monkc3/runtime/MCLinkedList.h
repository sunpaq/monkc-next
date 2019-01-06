//
//  MCLinkedList.h
//  monkc3
//
//  Created by 孙御礼 on 9/8/30 H.
//  Copyright © 30 Heisei oreisoft. All rights reserved.
//

#ifndef MCLinkedList_h
#define MCLinkedList_h

#include <stdio.h>
#include "MCFunction.h"
#include "MCClass.h"
#include "MCType.h"

struct MCItem {
    struct MCItem* next;
    mc_generic data;
    char key[256];
};

struct MCLinkedList {
    struct MCItem head;
    struct MCItem* free;
    int freecount;
    
    fundef(append, void), struct MCItem item);
    fundef(clear, void));
};

constructor(MCLinkedList));

//structure(MCLinkedList, MCObject)
//    MCItem_t* headItem;
//    MCItem_t* tailItem;
//
//    bool countChanged;
//    unsigned countCache;
//
//    fundef(count, unsigned));
//    fundef(cycle, MCItem_t*));
//
//    fundef(addItemAt, void), MCItem_t* item, int index);
//    fundef(addItem, void), MCItem_t* item);
//    fundef(delItem, void), MCItem_t* item);
//    fundef(pushItem, void), MCItem_t* item);
//    fundef(popItem, MCItem_t*));
//    fundef(itemAt, MCItem_t*), int index);
//    fundef(replaceAt, void), int index, MCItem_t* withItem);
//    fundef(insertAfter, void), MCItem_t* anchor, MCItem_t* item);
//    fundef(insertBefore, void), MCItem_t* anchor, MCItem_t* item);
//
//    fundef(connectList, struct MCLinkedList*), struct MCLinkedList* list);
//    fundef(addObject, void), obj object);
//};
//
//constructor(MCLinkedList);

#endif /* MCLinkedList_h */
