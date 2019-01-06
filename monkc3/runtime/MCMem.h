//
//  MCMem.h
//  monkc3
//
//  Created by 孙御礼 on 9/8/30 H.
//  Copyright © 30 Heisei oreisoft. All rights reserved.
//

#ifndef MCMem_h
#define MCMem_h

#include "MCType.h"

void* mc_alloc(size_t size);
void mc_free(void* any);

//void retain(struct MCObject* it);
//bool release(struct MCObject* it);

//#define delete(obj) if (release(obj)) {obj = null;}

#endif /* MCMem_h */
