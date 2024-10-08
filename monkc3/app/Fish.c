#include "Fish.h"

fun(initWithAge, void*), int age) as(Cell)
    it->age = age;
    return it;
}

fun(getAge, int)) let(any, Cell)
    return it->age;
}

fun(printName, void)) as(Fish)
    printf("%s\n", it->name);
}

fun(release, void)) as(Cell)
    it->release(it);
}

constructor(Fish), const char* name) {
    Cell(any, 30);
    as(Cell)
        it->age = 10;
    }
    as(Fish)
        strncpy(it->name, name, strlen(name));
        it->name[strlen(name)] = '\0';
        funadd(release);
    }
    dynamic(Fish)
        //override
        funbind(initWithAge);
        funbind(getAge);
        funbind(printName);
    }
    return any;
}
