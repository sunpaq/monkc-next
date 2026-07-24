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

      fundef(height, size_t)endfun;
      fundef(width, size_t)endfun;

      fundef(bye, void)endfun;
      fundef(initWithCopy, struct MCHeap*), struct MCHeap* ref endfun;
      fundef(insertValue, size_t), mc_generic newval endfun;
      fundef(copySortAscend, struct MCArray*)endfun;
      fundef(printAll, void)endfun;
      fundef(release, void)endfun;
end;

constructor(MCHeap), size_t maxcount endfun;

alias(MCHeap);

#endif /* MCHeap_h */
