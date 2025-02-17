#include "MCSort.h"

fun(bye, void) end_ as(MCSort)
    if (it->array && it->length > 0) {
        free(it->array);
    }
end

fun(swap, void), size_t a, size_t b end_ as(MCSort)
    if (a < b) {
        mc_generic t = it->array[a];
        it->array[a] = it->array[b];
        it->array[b] = t;
    }
end

fun(insertionSort, void) end_ is
end

fun(quicksort, void), const size_t l, const size_t r end_ as(MCSort)
    if (l >= r || l > it->length || r > it->length) {
        //debug_log("quicksort exit l=%ld r=%ld\n", l, r);
        return;
    }
    mc_generic pivot = it->array[l];
    size_t cur = l, idx;
    for (idx = l + 1; idx <= r; idx++) {
        if (MCGenericCompare(it->array[idx], pivot) < 0)
            swap(it, ++cur, idx);
    }
    
    swap(it, l, cur);
    quicksort(it, l, cur - 1);
    quicksort(it, cur + 1, r);
end

fun(quickSort, void) end_ as(MCSort)
    quicksort(it, 0, it->length - 1);
end

fun(printArray, void) end_ as(MCSort)
    size_t i;
    for (i = 0; i < it->length; i++) {
        printf("element of array[%ld]=%.2f\n", i, it->array[i].f);
    }
end

constructor(MCSort), mc_generic* array, size_t length end_ is
    MCObject(any, "MCSort");
    as(MCSort)
        it->array = (mc_generic*)malloc(sizeof(mc_generic) * length);
        size_t i;
        for (i = 0; i < length; i++) {
            it->array[i] = array[i];
        }
        it->length = length;
    end
    dynamic(MCSort)
        funbind(bye);
        funbind(insertionSort);
        funbind(quickSort);
        funbind(printArray);
    end
    return any;
end
