#include "Cell.h"

fun(cellfunc, void) endfun is
    printf("cell function\n");
end

fun(initWithAge, void*), int age endfun as(Cell)
    it->age = age;
    return it;
end

fun(getAge, int) endfun as(Cell)
    return it->age;
end

fun(printName, void) endfun is
    printf("Cell\n");
end

fun(release, void) endfun as(MCObject)
    it->release(it);
end

constructor(Cell), int age endfun is
    MCObject(any);
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