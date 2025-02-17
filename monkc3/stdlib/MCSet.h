#ifndef MCSet_h
#define MCSet_h

#include <stdio.h>
#include "MCObject.h"

structure(MCSet, MCObject)
    mc_generic* values;
    size_t maxcount;
    size_t count;

    fundef(bye, void) end_;
    fundef(insertValue, struct MCSet*), mc_generic value end_;
end;

constructor(MCSet), size_t maxcount end_;

alias(MCSet);

/*
 - Disjoint Sets
 - Merge-find Sets
 - Union-find Data Structure
   they all the same thing
 */

structure(MCUnionFind, MCSet)
    fundef(findAction, void) end_;
    fundef(unionAction, void) end_;
end;

constructor(MCUnionFind) end_;

alias(MCUnionFind);

#endif /* MCSet_h */
