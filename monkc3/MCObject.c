//
//  Object.c
//  monkc3
//
//  Created by 孙御礼 on 9/8/30 H.
//  Copyright © 30 Heisei oreisoft. All rights reserved.
//

#include "MCObject.h"
#include "MCMem.h"

void retain(void* any)
{
    if (!any) return;
    as(MCObject)
        it->ref_count++;
    }
}

bool release(void* any)
{
    if (!any) {
        return false;
    }
    as(MCObject)
        if (it->ref_count > 0) {
            it->ref_count--;
        }
        if (it->ref_count <= 0) {
            //call clean
            printf("free object %p\n", it);
            mc_free(it);
            return true;
        }
    }
    return false;
}

fun(info, void), char* buff) as(MCObject)
    if (buff) {
        const char* cname = "";
        if (it->claz) {
            cname = it->claz->name;
        }
        sprintf(buff, "claz=%s\nref_count=%d\n", cname, it->ref_count);
    }
}

fun(loadClass, bool), const char* name) as(MCObject)
    if (it->claz && strncmp(name, it->claz->name, strlen(name)) == 0) {
        printf("class %s already loaded\n", name);
        return false;
    } else {
        T(MCClass) c = MCClass_load(name);
        if (c) {
            it->claz = c;
            it->claz->appendInstance(it->claz, it);
            return true;
        }
    }
    return false;
}

fun(getClass, struct MCClass*)) as(MCObject)
    return it->claz;
}

fun(setFunction, void), const char* key, MCFunction value) as(MCObject)
    if (it->claz && key && value) {
        it->claz->setFunction(it->claz, key, value);
        printf("%s binding %s\n", it->claz->name, key);
    }
}

constructor(MCObject)) {
    if (any) {
        as(MCObject)
        it->claz = null;
        it->ref_count = 1;
        
        funadd(info);
        funadd(loadClass);
        funadd(getClass);
        funadd(setFunction);
        }
    }
    return any;
}
