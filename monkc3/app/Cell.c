//
//  Cell.c
//  monkc3
//
//  Created by 孙御礼 on 9/8/30 H.
//  Copyright © 30 Heisei oreisoft. All rights reserved.
//

#include "Cell.h"

fun(cellfunc, void)) {
    printf("cell function\n");
}

fun(initWithAge, void*), int age) as(Cell)
    it->age = age;
    return it;
}

fun(getAge, int)) as(Cell)
    return it->age;
}

fun(printName, void)) {
    printf("Cell\n");
}

constructor(Cell), int age) {
    MCObject(any);
    as(Cell)
        it->age = age;
    }
    dynamic(Cell)
        funbind(cellfunc);
        funbind(initWithAge);
        funbind(getAge);
        funbind(printName);
    }
    return any;
}
