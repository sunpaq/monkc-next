//
//  Function.h
//  monkc3
//
//  Created by 孙御礼 on 9/8/30 H.
//  Copyright © 30 Heisei oreisoft. All rights reserved.
//

#ifndef Function_h
#define Function_h

#include "MCType.h"

#define util(cla, name, rtype)\
rtype cla##_##name(void* any

#define fun(name, type)\
static type name(void* any

#define fundef(name, rtype)\
rtype (*name)(void* any

#define funadd(name)\
it->name = name

#define funbind(name)\
claz->setFunction(claz, #name, (MCFunction)name);it->name = name

#define ff(it, name)\
it->claz->getFunction(it->claz, #name)(it

typedef mc_generic (*MCFunction)(void*, ...);



#endif /* Function_h */
