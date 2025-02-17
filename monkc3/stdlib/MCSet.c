#include "MCSet.h"

fun(bye, void) end_ as(MCSet)
    if (it->values) {
        free(it->values);
    }
end

fun(insertValue, struct MCSet*), mc_generic value end_ as(MCSet)
    if (it->count < it->maxcount) {
        it->values[it->count++] = value;
    }
    return it;
end

constructor(MCSet), size_t maxcount end_ is
    MCObject(any, "MCSet");
    as(MCSet)
        it->values = (mc_generic*)malloc(sizeof(mc_generic) * maxcount);
        it->maxcount = maxcount;
        it->count = 0;
    end
    dynamic(MCSet)
        funbind(bye);
        funbind(insertValue);
    end
    return any;
end

fun(findAction, void) end_ is
end

fun(unionAction, void) end_ is
end

constructor(MCUnionFind) end_ is
    MCSet(any, 0);
    dynamic(MCUnionFind)
        funbind(findAction);
        funbind(unionAction);
    end
    return any;
end
