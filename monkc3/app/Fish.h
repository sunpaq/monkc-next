//
//  Fish.h
//  monkc3
//
//  Created by 孙御礼 on 9/8/30 H.
//  Copyright © 30 Heisei oreisoft. All rights reserved.
//

#ifndef Fish_h
#define Fish_h

#include "Cell.h"

structure(Fish, Cell)
    int age;
    char name[256];
    fundef(initWithAge, void*), int age);
    fundef(getAge, int));
    fundef(printName, void));
};

constructor(Fish), const char* name);

alias(Fish);

#endif /* Fish_h */
