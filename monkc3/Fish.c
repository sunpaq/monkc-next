//
//  Fish.c
//  monkc3
//
//  Created by 孙御礼 on 9/8/30 H.
//  Copyright © 30 Heisei oreisoft. All rights reserved.
//

#include "Fish.h"

fun(initWithAge, void*), int age) as(Cell)
    obj->age = age;
    return obj;
}

fun(getAge, int)) as(Cell)
    return obj->age;
}

constructor(Fish) {
    Cell(any);
    as(MCObject)
    if (obj->loadClass(obj, "Fish")) {
        funbind(initWithAge);
        funbind(getAge);
    }
    }
    as(Cell)
        obj->age = 10;
    }
    as(Fish)
        funadd(initWithAge);
        funadd(getAge);
    }
    return any;
}
