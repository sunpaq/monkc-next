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

typedef int (*MCFunction)(void* any, ...);
typedef double (*MCFunctionDouble)(void* any, ...);

#endif /* Function_h */
