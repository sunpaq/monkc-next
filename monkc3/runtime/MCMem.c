#include <stdlib.h>
#include "MCMem.h"

//malloc is thread safe since C11
//we can remove the pthread lock here

void* mc_alloc(size_t size) {
    if (size < sizeof(int)) {
        return null;
    }
    void* obj = malloc(size);
    return obj;
}

void mc_free(void* any) {
    if (any) {
        free(any);
    }
}
