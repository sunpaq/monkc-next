#include "MCObject.h"
#include "MCMem.h"
#include "MCLog.h"

fun(retain, void) end_ as(MCObject)
    if (!it) return;
    self.ref_count++;
end

fun(release, void) end_ as(MCObject)
    if (!it) return;
    if (self.ref_count > 0) {
        self.ref_count--;
    }
    if (self.ref_count <= 0) {
        //call clean
        runtime_log("free object %p\n", it);
        mc_free(it);
    }
end

fun(info, void), char* buff end_ as(MCObject)
    if (buff) {
        const char* cname = "";
        if (self.claz) {
            cname = self.claz->name;
        }
        sprintf(buff, "claz=%s\nref_count=%d\n", cname, self.ref_count);
    }
end

fun(responseTo, void*), const char* name end_ as(MCObject)
    if (name == null) {
        return null;
    }
    if (self.claz != null) {
        MCFunction f;
        if ((f = self.claz->getFunction(self.claz, name)) != null) {
            f(it);
            return f;
        }
        MCFunctionDouble fd;
        if ((fd = self.claz->getFunctionDouble(self.claz, name)) != null) {
            fd(it);
            return fd;
        }
    }
    return null;
end

bool MCObject_class(obj it, const char* name) {
    if (self.claz && strncmp(name, self.claz->name, strlen(name)) == 0) {
        runtime_log("class %s already loaded\n", name);
        return false;
    } else {
        val root = self.claz;
        struct MCClass* c = MCClass_load(name);
        if (c) {
            self.claz = c;
            self.claz->super = root;
            return true;
        }
    }
    return false;
}

constructor(MCObject), const char* name end_ is
    if (any) {
        as(MCObject)
            self.claz = null;
            self.ref_count = 1;
            MCObject_class(it, name);
            funadd(info);
            funadd(responseTo);
            funadd(retain);
            funadd(release);
        end
    }
    return any;
end
