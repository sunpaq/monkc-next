#ifndef MCObject_h
#define MCObject_h

#include "MCClass.h"
#include "MCFunction.h"

struct MCObject {
    struct MCClass* claz;
    int ref_count;
    
    //instance
    fundef(info, void), char* buff end_;
    fundef(responseTo, void*), const char* name end_;

    //mem manage
    fundef(retain, void) end_;
    fundef(release, void) end_;
};

constructor(MCObject), const char* name end_;

typedef struct MCObject* obj;

bool MCObject_class_loaded(obj it, const char* name);
bool MCObject_class(obj it, const char* name);

#define dynamic(cls) { struct MCClass* claz = ((obj)any)->claz; struct cls* it = (struct cls*)any;

#define Retain(it) ((obj)it)->retain(it)
#define Release(it) ((obj)it)->release(it)

#endif /* MCObject_h */
