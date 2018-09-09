//
//  Fish.c
//  monkc3
//
//  Created by 孙御礼 on 9/8/30 H.
//  Copyright © 30 Heisei oreisoft. All rights reserved.
//

#include "Fish.h"

fun(initWithAge, void*), int age) as(Cell)
    it->age = age;
    return it;
}

fun(getAge, int)) as(Cell)
    return it->age;
}

fun(printName, void)) as(Fish)
    printf("%s\n", it->name);
}

constructor(Fish), const char* name) {
    Cell(any, 30);
    as(MCObject)
        if (it->loadClass(it, "Fish")) {
            funbind(initWithAge);
            funbind(getAge);
        }
    }
    as(Cell)
        it->age = 10;
    }
    as(Fish)
        strncpy(it->name, name, strlen(name));
        it->name[strlen(name)] = '\0';

        funadd(initWithAge);
        funadd(getAge);
        funadd(printName);
    }
    return any;
}
