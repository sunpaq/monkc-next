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
        obj->ref_count++;
    }
}

bool release(void* any)
{
    if (!any) {
        return false;
    }
    as(MCObject)
        if (obj->ref_count > 0) {
            obj->ref_count--;
        }
        if (obj->ref_count <= 0) {
            //call clean
            printf("free object %p\n", obj);
            mc_free(obj);
            return true;
        }
    }
    return false;
}

fun(info, void), char* buff) as(MCObject)
    if (buff) {
        const char* cname = "";
        if (obj->claz) {
            cname = obj->claz->name;
        }
        sprintf(buff, "claz=%s\nref_count=%d\n", cname, obj->ref_count);
    }
}

fun(loadClass, bool), const char* name) as(MCObject)
    if (obj->claz && strncmp(name, obj->claz->name, strlen(name)) == 0) {
        printf("class %s already loaded\n", name);
        return false;
    } else {
        T(MCClass) c = MCClass_load(name);
        if (c) {
            obj->claz = c;
            obj->claz->appendInstance(obj->claz, obj);
            return true;
        }
    }
    return false;
}

fun(getClass, struct MCClass*)) as(MCObject)
    return obj->claz;
}

fun(setFunction, void), const char* key, MCFunction value) as(MCObject)
    if (obj->claz && key && value) {
        obj->claz->setFunction(obj->claz, key, value);
        printf("%s binding %s\n", obj->claz->name, key);
    }
}

constructor(MCObject) {
    if (any) {
        as(MCObject)
        obj->claz = null;
        obj->ref_count = 1;
        
        funadd(info);
        funadd(loadClass);
        funadd(getClass);
        funadd(setFunction);
        }
    }
    return any;
}
