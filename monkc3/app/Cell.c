#include "Cell.h"

fun(cellfunc, void) end_ is
    printf("cell function\n");
end

fun(initWithAge, void*), int age end_ as(Cell)
    it->age = age;
    return it;
end

fun(getAge, int) end_ as(Cell)
    return it->age;
end

fun(printName, void) end_ is
    printf("Cell\n");
end

fun(release, void) end_ as(MCObject)
    it->release(it);
end

function(Cell, begin, void) end_ is
end

constructor(Cell), int age end_ is
    MCObject(any, "Cell");
    as(Cell)
        it->age = age;
        funadd(release);
    end
    dynamic(Cell)
        funbind(cellfunc);
        funbind(initWithAge);
        funbind(getAge);
        funbind(printName);
    end
    return any;
end
