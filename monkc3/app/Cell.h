//
//  Cell.h
//  monkc3
//
//  Created by 孙御礼 on 9/8/30 H.
//  Copyright © 30 Heisei oreisoft. All rights reserved.
//

#ifndef Cell_h
#define Cell_h

#include <stdio.h>
#include "MCObject.h"

structure(Cell, MCObject)
    int age;
    fundef(cellfunc, void));
    fundef(initWithAge, void*), int age);
    fundef(getAge, int));
    fundef(printName, void));
    fundef(release, void));
};

constructor(Cell), int age);

alias(Cell);

#endif /* Cell_h */
