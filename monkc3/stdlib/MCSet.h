#ifndef MCSet_h
#define MCSet_h

#include <stdio.h>
#include "MCObject.h"

structure(MCSet, MCObject)
    mc_generic* values;
    size_t maxcount;
    size_t count;

    fundef(bye, void)endfun;
    fundef(insertValue, struct MCSet*), mc_generic value endfun;
end;

constructor(MCSet), size_t maxcount endfun;

alias(MCSet);

/*
 - Disjoint Sets
 - Merge-find Sets
 - Union-find Data Structure
   they all the same thing
 */

structure(MCUnionFind, MCSet)
    fundef(findAction, void)endfun;
    fundef(unionAction, void)endfun;
end;

constructor(MCUnionFind)endfun;

alias(MCUnionFind);

#endif /* MCSet_h */
