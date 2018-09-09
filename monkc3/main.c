//
//  main.c
//  monkc3
//
//  Created by 孙御礼 on 9/8/30 H.
//  Copyright © 30 Heisei oreisoft. All rights reserved.
//

#include <stdio.h>

#include "Fish.h"

int main(int argc, const char * argv[]) {
    
    var f0 = Fish(alloc(Fish), "tai");
    release(f0);
    
    val f1 = Fish(alloc(Fish), "saba");
    
    let(f1, Fish)
        it->getAge(it);
        it->initWithAge(it, 33);
        printf("age=%d\n", it->getAge(it));
        it->printName(it);
    }

    obj f2 = Fish(alloc(Fish), "sanma");

    char buff[1024];
    f2->info(f2, buff);
    printf("%s\n", buff);
    cast(f2, Fish)->printName(f2);

    def(f3, Fish) = Fish(alloc(Fish), "maguro");
    f3->printName(f3);

    Fish_t f4 = Fish(alloc(Fish), "hokei");
    f4->printName(f4);

    release(f1);
    delete(f2);
    delete(f3);
    delete(f4);

    return 0;
}
