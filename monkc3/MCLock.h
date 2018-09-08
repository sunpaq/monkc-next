//
//  MCLock.h
//  monkc3
//
//  Created by 孙御礼 on 9/8/30 H.
//  Copyright © 30 Heisei oreisoft. All rights reserved.
//

#ifndef MCLock_h
#define MCLock_h

#include <stdbool.h>
#include <pthread.h>

struct MCLock {
    bool initialized;
    pthread_mutex_t mutex;
    
    void (*lock)(struct MCLock* obj);
    void (*unlock)(struct MCLock* obj);
};

void MCLock(void* any);

#endif /* MCLock_h */
