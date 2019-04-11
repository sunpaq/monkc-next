#include "MCHashTable.h"
#include "MCArray.h"
#include "MCSocket.h"
#include "MCLinkedList.h"
#include "MCMap.h"
#include "MCTree.h"
#include "MCString.h"
#include "MCClock.h"
#include "Fish.h"
#include "SimpleServer.h"

void test_hashtable() {
    struct MCHashTable* table = MCHashTable(alloc(MCHashTable));
    table->put(table, "this is a key", gen_i(1));
    int i = table->get(table, "this is a key").i;
    if (i != 1) {
        exit(0);
    } else {
        printf("hash feature correct\n");
    }
    free(table);
}

void static_call() {
    val f = Fish(alloc(Fish), "saba");
    let(f, Fish)
        it->getAge(it);
        it->initWithAge(it, 33);
        printf("age=%d\n", it->getAge(it));
        it->printName(it);
    }
    Release(f);
}

void dynamic_call() {
    obj f = Fish(alloc(Fish), "sanma");
    int age = (int)ff(f, getAge));
    ff(f, printName));
    printf("age=%d\n", age);
    Release(f);
}

void type_cast() {
    obj f0 = Fish(alloc(Fish), "tai");
    char buff[1024];
    f0->info(f0, buff);
    printf("%s\n", buff);
    cast(f0, Fish)->printName(f0);
    Release(f0);

    def(f3, Fish) = Fish(alloc(Fish), "maguro");
    f3->printName(f3);

    Fish_t* f4 = Fish(alloc(Fish), "hokei");
    f4->printName(f4);

    Release(f3);
    Release(f4);
    f3 = null;
    f4 = null;
}

void method_override() {
    Fish_t* f = Fish(alloc(Fish), "shark");
    ff(f, cellfunc));
    ff(f, printName));
    Release(f);
}

void test_stdlib() {
    struct MCArray* array = MCArray(alloc(MCArray), 200);
    array->addItem(array, gen_f(0.1));
    array->addItem(array, gen_f(0.2));
    array->addItem(array, gen_f(0.3));
    array->addItem(array, gen_f(0.4));
    array->addItem(array, gen_f(0.5));
    array->printAll(array, "/");
    Release(array);
}

void test_MCMap() {
    struct MCMap* map = MCMap(alloc(MCMap));
    mc_generic result;
    map->setValueForKey(map, gen_i(100), "age");
    map->getValueForKey(map, &result, "age");
    printf("age is = %d\n", result.i);
    Release(map);
}

void test_MCTrie() {
    struct MCTrie* trie = MCTrie(alloc(MCTrie));
    trie->insertValueByKey(trie, gen_i(314), "thepai");
    mc_generic pai = trie->valueOfKey(trie, "thepai");
    printf("the pai is = %d\n", pai.i);
    Release(trie);
}

void test_MCString() {
    struct MCString string;
    MCString_t* strobj = MCString(&string, "1234567");
    char* endptr;
    double res1 = strobj->toDoubleValue(strobj, &endptr);
    double res2 = ff_double(strobj, toDoubleValue), &endptr);
    printf("%lf,%lf", res1, res2);
}

void test_MCClock() {
    struct MCClock clock;
    struct MCClock* c = MCClock(&clock);
    c->setTimeToNow(c);
    c->printCurrentGMTTime(c);
}

void test_SimpleServer() {
    struct SimpleServer* server = SimpleServer(alloc(SimpleServer), "127.0.0.1", "8080");
    server->start(server);
}

int main(int argc, const char * argv[]) {
    test_hashtable();
    static_call();
    dynamic_call();
    type_cast();
    method_override();
    test_stdlib();
    test_MCMap();
    test_MCTrie();
    test_MCString();
    test_MCClock();
    test_SimpleServer();

    return 0;
}
