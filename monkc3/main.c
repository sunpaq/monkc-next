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
    
    val f1 = new(Fish);
    
    let(f1, Fish)
        it->getAge(it);
        it->initWithAge(it, 33);
        printf("age=%d\n", it->getAge(it));
    }

    obj f2 = new(Fish);

    char buff[1024];
    f2->info(f2, buff);
    printf("%s\n", buff);

    def(f3, Fish) = new(Fish);

    release(f1);
    delete(f2);
    delete(f3);

    return 0;
}
