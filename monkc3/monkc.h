//
//  monkc.h
//  monkc3
//
//  Created by 孙御礼 on 9/8/30 H.
//  Copyright © 30 Heisei oreisoft. All rights reserved.
//

#ifndef monkc_h
#define monkc_h

#define T(cls) struct cls*

#define structure(cls, supercls)\
struct cls { struct supercls Super;

#define constructor(cls)\
struct cls* cls(void* any)

#define new(cls)\
cls(mc_alloc(sizeof(struct cls)))

#define as(cls)\
{ struct cls* obj = (struct cls*)any;

#define let(any, cls)\
{ struct cls* obj = (struct cls*)any;

#endif /* monkc_h */
