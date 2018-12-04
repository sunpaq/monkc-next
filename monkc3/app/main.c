#include "MCHashTable.h"
#include "Fish.h"
#include "MCArray.h"

void test_hashtable() {
    struct MCHashTable* table = MCHashTable(alloc(MCHashTable));
    table->put(table, "this is a key", gen_i(1));
    int i = table->get(table, "this is a key").i;
    if (i != 1) {
        exit(0);
    } else {
        printf("hash feature correct\n");
    }
}

void static_call() {
    val f = Fish(alloc(Fish), "saba");
    let(f, Fish)
        it->getAge(it);
        it->initWithAge(it, 33);
        printf("age=%d\n", it->getAge(it));
        it->printName(it);
    }
    release(f);
}

void dynamic_call() {
    obj f = Fish(alloc(Fish), "sanma");
    mc_generic age = ff(f, getAge));
    ff(f, printName));
    printf("age=%d\n", age.i);
    release(f);
}

void type_cast() {
    obj f0 = Fish(alloc(Fish), "tai");
    char buff[1024];
    f0->info(f0, buff);
    printf("%s\n", buff);
    cast(f0, Fish)->printName(f0);
    release(f0);

    def(f3, Fish) = Fish(alloc(Fish), "maguro");
    f3->printName(f3);

    Fish_t f4 = Fish(alloc(Fish), "hokei");
    f4->printName(f4);

    delete(f3);
    delete(f4);
}

void method_override() {
    obj f = Fish(alloc(Fish), "shark");
    ff(f, cellfunc));
    ff(f, printName));
}

void test_stdlib() {
    struct MCArray* array = MCArray(alloc(MCArray), 200);
    array->addItem(array, gen_f(0.1));
    array->addItem(array, gen_f(0.2));
    array->addItem(array, gen_f(0.3));
    array->addItem(array, gen_f(0.4));
    array->addItem(array, gen_f(0.5));
    array->printAll(array, "/");
}

int main(int argc, const char * argv[]) {
    test_hashtable();
    static_call();
    dynamic_call();
    type_cast();
    method_override();
    test_stdlib();
    return 0;
}