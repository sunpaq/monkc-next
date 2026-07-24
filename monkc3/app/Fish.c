#include "Fish.h"

fun(initWithAge, void*), int age endfun as(Cell)
    it->age = age;
    return it;
end

fun(getAge, int) endfun let(any, Cell)
    return it->age;
end

fun(printName, void) endfun as(Fish)
    printf("%s\n", it->name);
end

fun(release, void) endfun as(Cell)
    it->release(it);
end

constructor(Fish), const char* name endfun is
    Cell(any, 30);
    as(Cell)
        it->age = 10;
    end
    as(Fish)
        strncpy(it->name, name, strlen(name));
        it->name[strlen(name)] = '\0';
        funadd(release);
    end
    dynamic(Fish)
        //override
        funbind(initWithAge);
        funbind(getAge);
        funbind(printName);
    end
    return any;
end