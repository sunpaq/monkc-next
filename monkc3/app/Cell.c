#include "Cell.h"

fun(cellfunc, void)) is
    printf("cell function\n");
end

fun(initWithAge, void*), int age) as(Cell)
    it->age = age;
    return it;
end

fun(getAge, int)) as(Cell)
    return it->age;
end

fun(printName, void)) is
    printf("Cell\n");
end

fun(release, void)) as(MCObject)
    it->release(it);
end

constructor(Cell), int age) is
    MCObject(any);
    as(Cell)
        it->age = age;
        funadd(release);
    }
    dynamic(Cell)
        funbind(cellfunc);
        funbind(initWithAge);
        funbind(getAge);
        funbind(printName);
    }
    return any;
end
