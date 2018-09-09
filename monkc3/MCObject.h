//
//  Object.h
//  monkc3
//
//  Created by 孙御礼 on 9/8/30 H.
//  Copyright © 30 Heisei oreisoft. All rights reserved.
//

#ifndef MCObject_h
#define MCObject_h

#include "MCClass.h"

struct MCObject {
    struct MCClass* claz;
    int ref_count;
    
    //instance
    fundef(info, void), char* buff);

    //class
    fundef(loadClass, bool), const char* name);
    fundef(getClass, struct MCClass*));
    fundef(setFunction, void), const char* key, MCFunction value);
};

constructor(MCObject));

typedef struct MCObject* obj;

#endif /* MCObject_h */
