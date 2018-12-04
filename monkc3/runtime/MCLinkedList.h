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

#endif /* MCLinkedList_h */
