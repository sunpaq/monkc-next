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

#define fun(name, type)\
static type name(void* any

#define fundef(name, rtype)\
rtype (*name)(void* any

#define funadd(name)\
it->name = name

#define funbind(name)\
claz->setFunction(claz, #name, (MCFunction)name);it->name = name

#define ff(it, name)\
((obj)it)->claz->getFunction(((obj)it)->claz, #name)(it

#define ff_double(it, name)\
((obj)it)->claz->getFunctionDouble(((obj)it)->claz, #name)(it

typedef int64_t (*MCFunction)(void*, ...);
typedef double (*MCFunctionDouble)(void*, ...);

#endif /* Function_h */
