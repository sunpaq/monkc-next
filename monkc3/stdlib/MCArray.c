#include "MCArray.h"

function(MCArray, expand, void) end_
{
    if(self.maxcount == 0){
        self.maxcount = 100;
        MCArray(it, self.maxcount);
    }else{
        self.maxcount = self.maxcount * 2;//double
        mc_generic* newbuff = (mc_generic*)malloc(sizeof(mc_generic) * self.maxcount);
        memcpy(newbuff, self.buff, self.maxcount * sizeof(mc_generic));
        free(self.buff);
        self.buff = newbuff;
        //printf("[MCArray] expand to (%d)\n", obj->size);
    }
}

function(MCArray, insert_item, void), mc_generic item end_
{
    self.buff[self.indexLast++] = item;
    self.count++;
}

function(MCArray, delete_item, void), size_t index end_
{
    if(index > self.indexLast) return;
    self.buff[index] = (mc_generic){.p=null};
    if(index==self.indexLast)
        self.indexLast--;
    self.count--;
}

fun(addItem, void), mc_generic item end_ as(MCArray)
    if (self.indexLast >= self.maxcount) {
        MCArray_expand(it);
    }
    MCArray_insert_item(it, item);
end

fun(addTo, void), mc_generic item, size_t index end_ as(MCArray)
    if(index >= self.maxcount){
        MCArray_expand(it);
    }
    MCArray_insert_item(it, item);
end

fun(removeLast, void) end_ as(MCArray)
    MCArray_delete_item(it, self.indexLast);
end

fun(removeItem, void), mc_generic* item end_ as(MCArray)
    size_t i;
    for (i=0; i<self.maxcount; i++) {
        if (&self.buff[i] == item) {
            MCArray_delete_item(it, i);
        }
    }
end

fun(removeAt, void), size_t index end_ as(MCArray)
    MCArray_delete_item(it, index);
end

fun(clear, void) end_ as(MCArray)
    self.release(it);
    self.buff = (mc_generic*)malloc(sizeof(mc_generic) * 100);
end

fun(itemAt, mc_generic*), size_t index end_ as(MCArray)
    return &self.buff[index];
end

fun(printAll, void), const char delimiter end_ as(MCArray)
    size_t i;
    for (i=0; i<self.count; i++) {
        printf("%.2f", self.buff[i].f);
        printf("%c", delimiter);
    }
    printf("\n");
end

fun(release, void) end_ as(MCObject)
    as(MCArray)
        if (self.buff) {
            free(self.buff);
        }
    end
    self.ref_count = 0;
end

constructor(MCArray), size_t maxcount end_ is
    MCObject(any, "MCArray");
    as(MCArray)
        self.maxcount = maxcount;
        self.count = 0;
        self.indexLast = 0;
        self.buff = (mc_generic*)malloc(sizeof(mc_generic) * 100);
        funadd(release);
    end
    dynamic(MCArray)
        funbind(addItem);
        funbind(addTo);
        funbind(removeLast);
        funbind(removeItem);
        funbind(removeAt);
        funbind(clear);
        funbind(itemAt);
        funbind(printAll);
    end
    return any;
end
