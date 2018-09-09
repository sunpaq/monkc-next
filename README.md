# Monk-C next version

- experimental implementation of next version Monk-C
- it will take some syntax ideas form modern languages like Swift & Kotlin
- change from C99 to ANSI C standard for porting to more platforms

## Default hidden pointers

    void* any

    struct Class* it

- all functions (include constructor) have [void* any] hidden pointer as first argument.
- you can cast [any] into [struct Class* it] pointer use let()/as()
- you access super class data by cast the [any] pointer to super type

## Default hidden open parenthesis '(' 

    #define fun(name, type)\
    static type name(void* any

- most of the syntax C macros have a hidden open paren '(' or curly '{'
- don't worry about the unbalenced parens. C compiler will notice you to close it.

## Structure as first class

- the C struct and Monk-C class is the same thing.
- you can define constructor and add function into a C struct
- basically you should add 'struct' prefix before Monk-C class
- for easy of use. T(Class) and alias(Class) => Class_t can help

## Types

    var
    val
    obj
    Class_t
    T(Class)

## Type cast

    def(v, Class)

    cast(v, Class)

    let(v, Class)
        it->name(it);
    }

    //cast default 'any' pointer
    as(Class)
        it->data = 0;
    }

## Class define

    structure(cls, super)
        //define your data
    };

    //no params
    constructor(cls));

    or

    //with params
    constructor(cls), int arg1, float arg2);

    //typedef the cls_t for easy to use
    alias(cls);

## Function define

    //no params
    fundef(name, rtype));

    //with params
    fundef(name, rtype), int arg1, float arg2);

## Function implementation

    //will not access data
    fun(name, rtype), int arg) {
        //any pointer is void* type
    }

    //will access data, cast default 'any' to 'it'
    fun(name, rtype), int arg) as(Class)
        //it pointer is strunct Class* type
    }

    //will access data, cast 'any' to 'it'
    fun(name, rtype), int arg) let(any, Class)
        //it pointer is strunct Class* type
    }

## Constructor implementation

    constructor(cls), int arg1, float arg2) {
        Super(any), "yeah");
        as(MCObject)
            if (it->loadClass(it, "Class")) {
                //dynamic binding methods
                funbind(name);
            }
        }
        as(Super)
            it->superdata = 0;
        }
        as(Class)
            it->selfdata1 = arg1;
            it->selfdata2 = arg2;
            //assign static method values
            funadd(name);
        }
        return any;
    }

## Object creation duck types

    var a = Class(alloc(Class), 1, "F15");

    val b = Class(alloc(Class), 2, "F16");

    obj c = Class(alloc(Class), 3, "F18");

## Object creation with types

    Class_t d = Class(alloc(Class), 4, "F22");

    T(Class) e = Class(alloc(Class), 5, "F35");

    def(f, Class) = Class(alloc(Class), 6, "F117");

## Object type cast

    var a = Class(alloc(Class), 1, "F15");

    cast(a, Class)->name(a);

    let(a, Class)
        it->name(it);
    }

## Call static function

    a->functionName(a, p1, p2);

## Call dynamic function (working on)

    ff(a, functionName), p1, p2);

