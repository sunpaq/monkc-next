#ifndef MCArrayLinkedList_h
#define MCArrayLinkedList_h

#include <MCType.h>
#include "monkc.h"

//MC array linked list
typedef struct MCALItemStruct {
    struct MCALItemStruct* next;
    struct MCALItemStruct* prev;
    mc_generic value;
    mc_generic userdata;
} MCALItem;

static inline MCALItem MCALItemMake(mc_generic val)
{
    return (MCALItem){null, null, val};
}

static inline void MCALItemLink(MCALItem* A, MCALItem* B)
{
    A->next = B;
    B->prev = A;
}

static inline bool MCALItemIsHead(MCALItem* item)
{
    return (item->prev == null);
}

static inline bool MCALItemIsTail(MCALItem* item)
{
    return (item->next == null);
}

#define MCArrayLinkedListMax 1024
typedef struct {
    bool isCircle;
    size_t count;
    MCALItem* head;
    MCALItem array[MCArrayLinkedListMax];
} MCArrayLinkedList;

static inline void MCALSetHead(MCArrayLinkedList* list, MCALItem* item)
{
    item->prev = null;
    list->head = item;
}

static inline void MCALSetTail(MCArrayLinkedList* list, MCALItem* item)
{
    item->next = null;
}

static inline bool MCALIsEmpty(MCArrayLinkedList* list)
{
    return (list->head == null);
}

MCArrayLinkedList* MCArrayLinkedListInit(MCArrayLinkedList* list, mc_generic values[], size_t count);
MCArrayLinkedList* MCArrayLinkedListInitCircle(MCArrayLinkedList* list, mc_generic values[], size_t count);
MCALItem* MCALDeleteItem(MCArrayLinkedList* list, MCALItem* item);

typedef struct {
    mc_generic data[MCArrayLinkedListMax];
    int nexti[MCArrayLinkedListMax];
    int previ[MCArrayLinkedListMax];
    int count;
} MCArrayList;

MCArrayList* MCArrayListInit(MCArrayList* list);
MCArrayList* MCArrayListAdd(MCArrayList* list, mc_generic data);

#endif /* MCArrayLinkedList_h */
