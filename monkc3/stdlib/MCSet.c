#include "MCSet.h"

fun(bye, void)endfun as(MCSet)
    if (it->values) {
        free(it->values);
    end
}

fun(insertValue, struct MCSet*), mc_generic value endfun as(MCSet)
    if (it->count < it->maxcount) {
        it->values[it->count++] = value;
    end
    return it;
}

constructor(MCSet), size_t maxcount endfun is
    MCObject(any);
    as(MCSet)
        it->values = (mc_generic*)malloc(sizeof(mc_generic)*maxcount);
        it->maxcount = maxcount;
        it->count = 0;
    end
    dynamic(MCSet)
        funbind(bye);
        funbind(insertValue);
    }
    return any;
}



fun(findAction, void)endfun is

end

fun(unionAction, void)endfun is

end

constructor(MCUnionFind)endfun is
    MCSet(any, 0);
    dynamic(MCUnionFind)
        funbind(findAction);
        funbind(unionAction);
    end
    return any;
}
