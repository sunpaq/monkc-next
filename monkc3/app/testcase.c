//
//  testcase.c
//  monkc3
//
//  Created by 孙御礼 on 2022/02/23.
//  Copyright © 2022 oreisoft. All rights reserved.
//

#include "testcase.h"
#include "MCHashTable.h"
#include "MCArray.h"
#include "MCLinkedList.h"
#include "MCMap.h"
#include "MCTree.h"
#include "MCString.h"
#include "MCClock.h"

void test_hashtable(void) {
    struct MCHashTable* table = MCHashTable(alloc(MCHashTable));
    table->put(table, "this is a key", gen_i(1024));
    table->put(table, "this is another key", gen_i(2048));
    table->put(table, "this is also a key", gen_i(4096));
    
    int i = table->get(table, "this is a key").i;
    if (i != 1024) {
        exit(0);
    } else {
        printf("hash feature correct\n");
    }
    free(table);
}

void test_stdlib(void) {
    struct MCArray* array = MCArray(alloc(MCArray), 200);
    array->addItem(array, gen_f(0.1));
    array->addItem(array, gen_f(0.2));
    array->addItem(array, gen_f(0.3));
    array->addItem(array, gen_f(0.4));
    array->addItem(array, gen_f(0.5));
    array->printAll(array, "/");
    Release(array);
}

void test_MCMap(void) {
    struct MCMap* map = MCMap(alloc(MCMap));
    mc_generic result;
    map->setValueForKey(map, gen_i(100), "age");
    map->getValueForKey(map, &result, "age");
    printf("age is = %d\n", result.i);
    Release(map);
}

void test_MCTrie(void) {
    struct MCTrie* trie = MCTrie(alloc(MCTrie));
    trie->insertValueByKey(trie, gen_i(314), "thepai");
    mc_generic pai = trie->valueOfKey(trie, "thepai");
    printf("the pai is = %d\n", pai.i);
    Release(trie);
}

void test_MCString(void) {
    struct MCString string;
    MCString_t* strobj = MCString(&string, "1234.5678");
    char* errorMessage;
    double res1 = strobj->toDoubleValue(strobj, &errorMessage);
    double res2 = ff_double(strobj, toDoubleValue), &errorMessage);
    if (MCStringEqual(errorMessage, "")) {
        printf("%lf should equal %lf\n", res1, res2);
    } else {
        printf("can not convert %s\n", errorMessage);
    }

    struct MCString base;
    MCString_t* randstr = MCString(&base, "randomstring");
    printf("random string: %s\n", randstr->randomString(randstr, 20));
}

void test_MCClock(void) {
    struct MCClock clock;
    struct MCClock* c = MCClock(&clock);
    c->setTimeToNow(c);
    c->printCurrentGMTTime(c);
}

void test_all(void) {
    MCStringSeedRandom();

    test_hashtable();
    test_stdlib();
    test_MCMap();
    test_MCTrie();
    test_MCString();
    test_MCClock();
}
