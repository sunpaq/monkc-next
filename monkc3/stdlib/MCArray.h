#ifndef MONKC_DEMO_MCARRAY_H
#define MONKC_DEMO_MCARRAY_H

#include "MCObject.h"

structure(MCArray, MCObject)
    size_t count;
    size_t maxcount;
    size_t indexLast;
    mc_generic* buff;

    fundef(addItem, void), mc_generic item end_;
    fundef(addTo, void), mc_generic item, size_t index end_;
    fundef(removeLast, void) end_;
    fundef(removeItem, void), mc_generic* item end_;
    fundef(removeAt, void), size_t index end_;
    fundef(clear, void) end_;
    fundef(itemAt, mc_generic*), size_t index end_;
    fundef(printAll, void), const char* delimiter end_;
    fundef(release, void) end_;
end;

constructor(MCArray), size_t maxcount end_;

function(MCArray, expand, void) end_;
function(MCArray, insert_item, void), mc_generic item end_;
function(MCArray, delete_item, void), size_t index end_;

#endif //MONKC_DEMO_MCARRAY_H
