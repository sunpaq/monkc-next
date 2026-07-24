#ifndef MCHashTable_h
#define MCHashTable_h

#include "MCObject.h"

typedef uint32_t    MCHash;
#define MCHashMax    UINT32_MAX
#define MAX_KEY_CHARS 256
#define MAX_ITEM_CACHE 10
#define MIN_HASHTABLE_SIZE 1301

struct MCHashItem is
    struct MCHashItem* next;
    MCHash hash;
    bool tombstone;
    bool doesAutoReleaseObject;
    mc_generic value;
    char key[MAX_KEY_CHARS + 1];

    fundef(release, void) endfun;
end;

constructor(MCHashItem), const char* key, mc_generic value endfun;

struct MCHashTable is
    int lock;
    size_t cache_count;
    size_t count;

    //will return the item if already have one with same key.
    fundef(putItem, struct MCHashItem*), struct MCHashItem* item endfun;
    fundef(getItem, struct MCHashItem*), const char* key endfun;

    fundef(put, mc_generic), const char* key, mc_generic value endfun;
    fundef(get, mc_generic), const char* key endfun;

    //struct MCHashItem* cache[MAX_ITEM_CACHE];
    struct MCHashItem* items[MIN_HASHTABLE_SIZE];
end;

constructor(MCHashTable) endfun;

MCHash MCHashTable_hash(const char* key);

typedef enum {
    MCHashTableLevel1 = 0,
    MCHashTableLevel2,
    MCHashTableLevel3,
    MCHashTableLevel4,
    MCHashTableLevelMax,
    MCHashTableLevelCount
} MCHashTableLevel;

unsigned get_tablesize(MCHashTableLevel level);

#endif