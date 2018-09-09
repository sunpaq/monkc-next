//
//  MCType.h
//  monkc3
//
//  Created by 孙御礼 on 9/8/30 H.
//  Copyright © 30 Heisei oreisoft. All rights reserved.
//

#ifndef MCType_h
#define MCType_h

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define null NULL
#define K(key) #key
#define F(value) (void*(*)(void))value

#define def(any, type) struct type* any
#define cast(any, type) ((struct type*)any)

typedef void* var;
typedef void* const val;

#endif /* MCType_h */
