#ifndef MCMap_h
#define MCMap_h

#include "MCObject.h"
#include "MCHashTable.h"

structure(MCMap, MCObject)
      struct MCHashTable* table;

      fundef(itemsCount, size_t)endfun;
      fundef(setValueForKey, void), mc_generic value, const char* key endfun;
      fundef(getValueForKey, void), mc_generic* result, const char* key endfun;
      fundef(getValueByIndex, void), mc_generic* result, size_t index endfun;
      fundef(release, void)endfun;
end;

constructor(MCMap)endfun;

alias(MCMap);

#endif /* MCMap_h */
