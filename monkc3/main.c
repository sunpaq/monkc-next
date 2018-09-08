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
    
    T(Fish) f = new(Fish);
    T(Fish) f2 = new(Fish);
    
    f2->getAge(f2);
    f->initWithAge(f, 33);
    printf("age=%d\n", f->getAge(f));
    
    let(f, MCObject)
        char buff[1024];
        obj->info(obj, buff);
        printf("%s\n", buff);
    }
    
    delete(f);
    delete(f2);

    return 0;
}
