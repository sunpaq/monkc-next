//
//  MCGraph.c
//  Sapindus
//
//  Created by YuliSun on 18/11/2016.
//  Copyright © 2016 oreisoft. All rights reserved.
//

#include "MCGraph.h"

fun(bye, void)) as(MCGraph)
    if (it->vertexSet) {
        free(it->vertexSet);
    }
    if (it->edgeSet) {
        free(it->edgeSet);
    }
end

fun(isAdjacent, bool), MCGraphVertex x, MCGraphVertex y)
{
    MCGraphVertex* iter = x.neighbors;
    while (iter) {
        if (iter->index == y.index) {
            return true;
        }
        iter = iter->next;
    }
    return false;
}

fun(copyNeighborsOf, struct MCArray*), MCGraphVertex x)
{
    struct MCArray* array = MCArray(alloc(MCArray), 10);
    MCGraphVertex* iter = x.neighbors;
    while (iter) {
        array->addItem(array, gen_i(iter->index));
        iter = iter->next;
    }
    return array;
}

//To-Do
fun(addEdge, struct MCGraph*), MCGraphEdge e) as(MCGraph)
    return it;
end

fun(removeEdge, struct MCGraph*), MCGraphEdge e) as(MCGraph)
    return it;
end

constructor(MCGraph)) as(MCObject)
    MCObject(any);
    as(MCGraph)
        self.vertexCount = 0;
        self.edgeCount = 0;
        self.vertexSet = null;
        self.edgeSet = null;
    end
    dynamic(MCGraph)
        funbind(bye);
        funbind(isAdjacent);
        funbind(copyNeighborsOf);
        funbind(addEdge);
        funbind(removeEdge);
    end
    return any;
end
