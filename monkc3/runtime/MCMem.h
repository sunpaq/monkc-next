#ifndef MCMem_h
#define MCMem_h

#include "MCType.h"

void* mc_alloc(size_t size);
void mc_free(void* any);

//#define delete(obj) if (release(obj)) {obj = null;}

#endif /* MCMem_h */
