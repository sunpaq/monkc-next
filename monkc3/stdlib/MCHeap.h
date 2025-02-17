#ifndef MCHeap_h
#define MCHeap_h

#include "monkc.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "MCArray.h"

//min heap
structure(MCHeap, MCObject)
      mc_generic* values;
      size_t count;
      size_t maxcount;
      size_t maxheight;

      fundef(height, size_t) end_;
      fundef(width, size_t) end_;

      fundef(bye, void) end_;
      fundef(initWithCopy, struct MCHeap*), struct MCHeap* ref end_;
      fundef(insertValue, size_t), mc_generic newval end_;
      fundef(copySortAscend, struct MCArray*) end_;
      fundef(printAll, void) end_;
      fundef(release, void) end_;
end;

constructor(MCHeap), size_t maxcount end_;

alias(MCHeap);

#endif /* MCHeap_h */
