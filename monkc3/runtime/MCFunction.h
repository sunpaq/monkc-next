#ifndef Function_h
#define Function_h

#include "MCType.h"

#define function(prefix, name, type)\
type prefix##_##name(struct prefix* it

#define fun(name, type)\
static type name(void* any

#define fundef(name, rtype)\
rtype (*name)(void* any

#define funadd(__fun_name__)\
it->__fun_name__ = __fun_name__

#define funbind(__fun_name__)\
it->__fun_name__ = __fun_name__;\
claz->setFunction(claz, #__fun_name__, (MCFunction)__fun_name__)

#define ff(it, name)\
((obj)it)->claz->getFunction(((obj)it)->claz, #name)(it

#define ff_double(it, name)\
((obj)it)->claz->getFunctionDouble(((obj)it)->claz, #name)(it

typedef int (*MCFunction)(void* any, ...);
typedef double (*MCFunctionDouble)(void* any, ...);

#endif /* Function_h */
