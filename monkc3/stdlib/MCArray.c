//
// Created by 孙御礼 on 2018-12-04.
//

#include "MCArray.h"

static void expand_array(struct MCArray* obj)
{
    if(obj->maxcount == 0){
        obj->maxcount = 100;
        MCArray(obj, obj->maxcount);
    }else{
        obj->maxcount = (obj->maxcount) * 2;//double
        mc_generic* newbuff = (mc_generic*)malloc(sizeof(mc_generic) * obj->maxcount);
        memcpy(newbuff, obj->buff, obj->maxcount * sizeof(mc_generic));
        free(obj->buff);
        obj->buff = newbuff;
        //printf("[MCArray] expand to (%d)\n", obj->size);
    }
}

static void insert_item(struct MCArray* obj, mc_generic item)
{
    obj->buff[obj->indexLast++] = item;
    obj->count++;
}

static void delete_item(struct MCArray* obj, size_t index)
{
    if(index > obj->indexLast) return;
    obj->buff[index] = (mc_generic){.p=null};
    if(index==obj->indexLast)
        obj->indexLast--;
    obj->count--;
}

fun(addItem, void), mc_generic item) as(MCArray)
    if (self.indexLast >= self.maxcount) {
        expand_array(it);
    }
    insert_item(it, item);
end

fun(addTo, void), mc_generic item, size_t index) as(MCArray)
    if(index >= self.maxcount){
        expand_array(it);
    }
    insert_item(it, item);
end

fun(removeLast, void)) as(MCArray)
    delete_item(it, it->indexLast);
end

fun(removeItem, void), mc_generic* item) as(MCArray)
    size_t i;
    for (i=0; i<self.maxcount; i++) {
        if (&self.buff[i] == item) {
            delete_item(it, i);
        }
    }
end

fun(removeAt, void), size_t index) as(MCArray)
    delete_item(it, index);
end

fun(clear, void)) as(MCArray)
    self.release(it);
    self.buff = (mc_generic*)malloc(sizeof(mc_generic) * 100);
end

fun(itemAt, mc_generic*), size_t index) as(MCArray)
    return &self.buff[index];
end

fun(printAll, void), const char* delimiter) as(MCArray)
    size_t i;
    for (i=0; i<self.count; i++) {
        printf("%.2f%s", self.buff[i].f, delimiter);
    }
    printf("\n");
end

fun(release, void)) as(MCObject)
    self.release(it);
    as(MCArray)
        if (self.buff) {
            free(self.buff);
        }
    end
end

constructor(MCArray), size_t maxcount) as(MCArray)
    MCObject(it);
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
