
#include "Fish.h"
#include "testcase.h"

void static_call(void) {
    val f = Fish(alloc(Fish), "saba");
    let(f, Fish)
        it->getAge(it);
        it->initWithAge(it, 33);
        printf("age=%d\n", it->getAge(it));
        it->printName(it);
    }
    Release(f);
}

void dynamic_call(void) {
    obj f = Fish(alloc(Fish), "sanma");
    int age = (int)ff(f, getAge));
    ff(f, printName));
    printf("age=%d\n", age);
    Release(f);
}

void type_cast(void) {
    obj f0 = Fish(alloc(Fish), "tai");
    char buff[1024];
    f0->info(f0, buff);
    printf("%s\n", buff);
    cast(f0, Fish)->printName(f0);
    Release(f0);

    def(f3, Fish) = Fish(alloc(Fish), "maguro");
    f3->printName(f3);

    Fish_t* f4 = Fish(alloc(Fish), "hokei");
    f4->printName(f4);

    Release(f3);
    Release(f4);
    f3 = null;
    f4 = null;
}

void method_override(void) {
    Fish_t* f = Fish(alloc(Fish), "shark");
    ff(f, cellfunc));
    ff(f, printName));
    Release(f);
}

int main(int argc, const char * argv[]) {
    printf("----TEST----\n");
    test_all();
    printf("----END----\n");
    
    static_call();
    dynamic_call();
    type_cast();
    method_override();
    return 0;
}
