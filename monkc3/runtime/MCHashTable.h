
#ifndef MCHashTable_h
#define MCHashTable_h

#include "MCObject.h"

typedef u_int32_t    MCHash;
#define MCHashMax    UINT32_MAX
#define MAX_KEY_CHARS 256
#define MAX_ITEM_CACHE 10
#define MIN_HASHTABLE_SIZE 1301

struct MCHashItem {
    struct MCHashItem* next;
    MCHash hash;
    bool tombstone;
    mc_generic value;
    char key[MAX_KEY_CHARS + 1];
};

constructor(MCHashItem), const char* key, mc_generic value);

alias(MCHashItem);

struct MCHashTable {
    int lock;
    int cache_count;

    //will return the item if already have one with same key.
    fundef(putItem, struct MCHashItem*), struct MCHashItem* item);
    fundef(getItem, struct MCHashItem*), const char* key);

    fundef(put, mc_generic), const char* key, mc_generic value);
    fundef(get, mc_generic), const char* key);

    //struct MCHashItem* cache[MAX_ITEM_CACHE];
    struct MCHashItem* items[MIN_HASHTABLE_SIZE];
};

constructor(MCHashTable));

util(MCHashTable, hash, MCHash), const char *s);

/*
MCInline MCHashTableIndex firstHashIndex(MCHash nkey, MCHashTableSize slots) {
    return nkey % slots;
    //return (nkey - slots * (nkey / slots));
}

MCInline MCHashTableIndex secondHashIndex(MCHash nkey, MCHashTableSize slots, MCHash first) {
    return (first + (1 + (nkey % (slots - 1)))) % slots;
    //MCHashTableSize slots_1 = slots - 1;
    //MCHash temp = first + 1 + nkey - slots_1 * (nkey / slots_1);
    //return (temp - slots * (temp / slots));
}

mc_hashitem* new_item(const char* key, MCGeneric value, MCHash hashval);
mc_hashtable* new_table(const MCHashTableLevel initlevel);

MCHashTableIndex set_item(mc_hashtable** table_p, mc_hashitem* item, MCBool isAllowOverride, const char* refkey);
mc_hashitem* get_item_byhash(mc_hashtable* table_p, const MCHash hashval, const char* refkey);
mc_hashitem* get_item_bykey(mc_hashtable* const table_p, const char* key);
mc_hashitem* get_item_byindex(mc_hashtable* const table_p, const MCHashTableIndex index);
MCHashTableSize get_tablesize(const MCHashTableLevel level);
*/

#endif
