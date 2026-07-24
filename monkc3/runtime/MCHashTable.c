#include "MCHashTable.h"
#include "MCLog.h"

//copy form << The C Programming language >>
//BKDR Hash Function
MCHash MCHashTable_hash(const char* s) {
    register MCHash hashval = 0;
    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    //keep the value positive
    return (hashval & 0x7fffffff);
}

static unsigned probe(MCHash nkey, unsigned slots, unsigned times) {
    return (nkey + times * times) % slots;
}

static unsigned mc_hashtable_sizes[MCHashTableLevelCount] = {
    MIN_HASHTABLE_SIZE,
    3101,
    13001,
    31001,
    130001
};

unsigned get_tablesize(MCHashTableLevel level)
{
    if (level > MCHashTableLevelMax) {
        return mc_hashtable_sizes[MCHashTableLevelMax];
    }
    return mc_hashtable_sizes[level];
}

static void copykey(char* des, const char* key, size_t maxlen) {
    size_t len = strlen(key);
    if (len > maxlen) {
        len = maxlen;
    }
    strncpy(des, key, len);
    des[len] = '\0';
}

fun(release, void) endfun is
    cast_self(MCHashItem);
    if (self.doesAutoReleaseObject && self.value.mcobject) {
        self.value.mcobject->release(self.value.mcobject);
    }
end

constructor(MCHashItem), const char* key, mc_generic value endfun is
    cast_self(MCHashItem);
    MCObject(it);
    self.next = null;
    self.value = value;
    self.tombstone = false;
    self.doesAutoReleaseObject = false;
    self.hash = MCHashTable_hash(key);
    copykey(self.key, key, MAX_KEY_CHARS);
    funadd(release);
    return it;
end

//MCHashTable

fun(getItem, struct MCHashItem*), const char* key endfun is
    cast_self(MCHashTable);
    MCHash hashval = MCHashTable_hash(key);
    unsigned tsize = get_tablesize(0);

    unsigned t = 0;
    while(t < tsize) {
        unsigned i = probe(hashval, tsize, t++);
        //slot empty
        if (!it->items[i]) {
            continue;
        }
        //key not fit
        if (strcmp(key, it->items[i]->key) != 0) {
            continue;
        }
        //pass all the check
        return it->items[i];
    }

    //not find
    return null;
end

fun(putItem, struct MCHashItem*), struct MCHashItem* item endfun is
    cast_self(MCHashTable);
    MCHash hashval = item->hash;
    unsigned tsize = get_tablesize(0);

    unsigned t = 0;
    while(t < tsize) {
        unsigned i = probe(hashval, tsize, t++);
        //slot empty
        if (!it->items[i]) {
            it->items[i] = item;
            return null;
        } else {
            struct MCHashItem* old = it->items[i];
            //slot deleted
            if (old->tombstone) {
                free(old);
                it->items[i] = item;
                runtime_log("add item[%d] = %s\n", i, item->key);
                return null;
            }
            //already have
            if (strcmp(item->key, old->key) == 0) {
                runtime_log("skip add item[%d] = %s\n", i, item->key);
                return old;
            }
        }
    }

    //table is full
    return null;
end

fun(put, mc_generic), const char* key, mc_generic value endfun is
    val item = MCHashItem(alloc(MCHashItem), key, value);
    struct MCHashItem* old = putItem(any, item);
    if (old) {
        return old->value;
    }
    return gen_p(null);
end

fun(get, mc_generic), const char* key endfun is
    struct MCHashItem* item = getItem(any, key);
    if (item) {
        return item->value;
    }
    return gen_p(null);
end

constructor(MCHashTable) endfun is
    cast_self(MCHashTable);
    self.lock = 0;
    self.cache_count = 0;
    self.count = MIN_HASHTABLE_SIZE;
    //set all the slot to nil
    int i;
    for(i=0; i<it->count; i++) {
        self.items[i] = null;
    }
    //add functions
    funadd(putItem);
    funadd(getItem);
    funadd(put);
    funadd(get);
    return any;
end