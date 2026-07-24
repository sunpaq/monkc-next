#ifndef monkc_h
#define monkc_h

#define end          }
#define endfun        )

#define is           {
#define as(cls)      { struct cls* it = (struct cls*)any;
#define let(v, cls)  { struct cls* it = (struct cls*)v;

#define alias(cls)   typedef struct cls cls##_t

#define structure(cls, supercls) struct cls { struct supercls Super;

#define copy_super(cls) struct cls Super;

#define constructor(cls) void* cls(void* any

#define alloc(cls) mc_alloc(sizeof(struct cls))

#define cast_self(cls) struct cls* it = (struct cls*)any;

#define self (*it)

#endif /* monkc_h */