#ifndef MONKC_DEMO_MCARRAY_H
#define MONKC_DEMO_MCARRAY_H

#include "MCObject.h"

structure(MCArray, MCObject)
    size_t count;
    size_t maxcount;
    size_t indexLast;
    mc_generic* buff;

    fundef(addItem, void), mc_generic item endfun;
    fundef(addTo, void), mc_generic item, size_t index endfun;
    fundef(removeLast, void) endfun;
    fundef(removeItem, void), mc_generic* item endfun;
    fundef(removeAt, void), size_t index endfun;
    fundef(clear, void) endfun;
    fundef(itemAt, mc_generic*), size_t index endfun;
    fundef(printAll, void), const char* delimiter endfun;
    fundef(release, void) endfun;
end;

constructor(MCArray), size_t maxcount endfun;

#endif //MONKC_DEMO_MCARRAY_H
