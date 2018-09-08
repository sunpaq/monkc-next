//
//  MCLock.c
//  monkc3
//
//  Created by 孙御礼 on 9/8/30 H.
//  Copyright © 30 Heisei oreisoft. All rights reserved.
//

#include "MCLock.h"
#include <pthread.h>

static void lock(struct MCLock* obj) {
    while (pthread_mutex_trylock(&obj->mutex)) {
        //wait lock
    }
}

static void unlock(struct MCLock* obj) {
    pthread_mutex_unlock(&obj->mutex);
}

void MCLock(void* any) {
    struct MCLock* obj = (struct MCLock*)any;
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    obj->mutex = mutex;
    obj->lock = lock;
    obj->unlock = unlock;
    obj->initialized = true;
}
