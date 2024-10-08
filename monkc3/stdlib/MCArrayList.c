#include <stdio.h>
#include <stdlib.h>

#include "MCArrayList.h"
#include "MCLog.h"

MCArrayLinkedList* MCArrayLinkedListInit(MCArrayLinkedList* list, mc_generic values[], const size_t count)
{
    if (count > MCArrayLinkedListMax) {
        error_log("MCArrayLinkedList item count can not over %d\n", MCArrayLinkedListMax);
        exit(-1);
    }
    list->count = count;
    
    int i;
    for (i=0; i<count; i++) {
        MCALItem* A = &list->array[i+0];
        MCALItem* B = &list->array[i+1];
        
        A->value = values[i+0];
        B->value = values[i+1];

        MCALItemLink(A, B);
    }
    list->head = &(list->array[0]);
    
    if (list->isCircle) {
        MCALItem* last = &list->array[count-1];
        MCALItemLink(last, list->head);
    }

    return list;
}

MCArrayLinkedList* MCArrayLinkedListInitCircle(MCArrayLinkedList* list, mc_generic values[], const size_t count)
{
    list->isCircle = true;
    MCArrayLinkedListInit(list, values, count);
    
    return list;
}

void MCArrayLinkedListRelease(MCArrayLinkedList* list)
{
    free(list);
}

MCALItem* MCALDeleteItem(MCArrayLinkedList* list, MCALItem* item)
{
    if (list->isCircle) {
        item->prev->next = item->next;
        item->next->prev = item->prev;
    }else{
        if (MCALItemIsHead(item) == true) {
            MCALSetHead(list, item->next);
        }
        else if (MCALItemIsTail(item) == true) {
            MCALSetTail(list, item->prev);
        }
        else if (MCALItemIsHead(item) == true
                 && MCALItemIsTail(item) == true) {
            list->head = null;
        }
        else {
            item->prev->next = item->next;
            item->next->prev = item->prev;
        }
    }

    item->value.p = null;
    list->count--;
    return list->head;
}

MCArrayList* MCArrayListInit(MCArrayList* list)
{
    int i;
    for (i=0; i<MCArrayLinkedListMax; i++) {
        list->data[i]  = gen_p(null);
        list->nexti[i] = -1;
        list->previ[i] = -1;
    }
    return list;
}

MCArrayList* MCArrayListAdd(MCArrayList* list, mc_generic data)
{
    int i;
    for (i=0; i<MCArrayLinkedListMax; i++) {
        if (list->data[i].p == null) {
            list->data[i] = data;
            if (i==0){
                list->previ[i] = -1;
            }else if(i==MCArrayLinkedListMax-1) {
                list->nexti[i] = -1;
            }
            //double linked list
            list->nexti[i-1] = i;
            list->previ[i] = i-1;
        }
    }
    return list;
}
