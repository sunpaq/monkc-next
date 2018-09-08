//
//  Function.h
//  monkc3
//
//  Created by 孙御礼 on 9/8/30 H.
//  Copyright © 30 Heisei oreisoft. All rights reserved.
//

#ifndef Function_h
#define Function_h

#define fun(name, type)\
static type name(void* any

#define fundef(name, rtype)\
rtype (*name)(void* any

#define funadd(name)\
obj->name = name

#define funbind(name)\
obj->setFunction(obj, #name, (void*(*)(void))name);

typedef void* (*MCFunction)(void);

#endif /* Function_h */
