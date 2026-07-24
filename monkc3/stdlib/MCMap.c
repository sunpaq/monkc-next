#include "MCMap.h"

fun(itemsCount, size_t)endfun as(MCMap)
    return it->table->count;
end

fun(setValueForKey, void), mc_generic value, const char* key endfun as(MCMap)
    it->table->put(it->table, key, value);
end

fun(getValueForKey, void), mc_generic* result, const char* key endfun as(MCMap)
    struct MCHashItem* item = it->table->getItem(it->table, key);
    if (item) {
        (*result) = item->value;
        return;
    end
    (*result).p = null;
}

fun(getValueByIndex, void), mc_generic* result, size_t index endfun as(MCMap)
    size_t count = it->table->count;
    if (index < count) {
        struct MCHashItem* item = it->table->items[index];
        if (item) {
            mc_generic v = item->value;
            *result = v;
        }
    end
}

fun(release, void)endfun as(MCMap)
    size_t count = it->table->count;
    size_t i;
    for (i=0; i<count; i++) {
        struct MCHashItem* item = it->table->items[i];
        if (item) {
            mc_generic v = item->value;
            //if there have a MCObject in item, we release it
            if (item->doesAutoReleaseObject && v.mcobject != null) {
                v.mcobject->release(v.mcobject);
            }
        }
    end
}

constructor(MCMap)endfun is
    MCObject(any);
    as(MCMap)
        it->table = MCHashTable(alloc(MCHashTable));
    end
    dynamic(MCMap)
        funbind(itemsCount);
        funbind(setValueForKey);
        funbind(getValueForKey);
        funbind(getValueByIndex);
        funbind(release);
    }
    return any;
}
