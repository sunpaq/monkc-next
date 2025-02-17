#include "MCGraph.h"

fun(bye, void) end_ as(MCGraph)
    if (self.vertexSet) {
        free(self.vertexSet);
    }
    if (self.edgeSet) {
        free(self.edgeSet);
    }
end

fun(isAdjacent, bool), MCGraphVertex x, MCGraphVertex y end_
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

fun(copyNeighborsOf, struct MCArray*), MCGraphVertex x end_
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
fun(addEdge, struct MCGraph*), MCGraphEdge e end_ as(MCGraph)
    return it;
end

fun(removeEdge, struct MCGraph*), MCGraphEdge e end_ as(MCGraph)
    return it;
end

constructor(MCGraph) end_ as(MCObject)
    MCObject(it, "MCGraph");
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
