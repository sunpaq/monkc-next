#include "MCThread.h"
#include "MCLog.h"

fun(bye, void) end_ as(MCThread)
    pthread_attr_destroy(&it->attribute);
end

fun(initWithFPointerArgument, struct MCThread*), void* fp, void* farg end_ as(MCThread)
    if (fp==null) {
        error_log("%s\n","fp can not be nil, do nothing");
        return null;
    }
    it->functionPointer = fp;
    it->functionArgument = farg;
    return it;
end

fun(initWithFPointer, struct MCThread*), void* fp end_ as(MCThread)
    return initWithFPointerArgument(it, fp, null);
end

fun(detach, int) end_ as(MCThread)
    return pthread_detach(it->tid);
end

fun(start, int) end_ as(MCThread)
    int res;
    if (it->isRunOnce==1) {
        res = pthread_once(&(it->once_control), it->functionPointer);
    }else{
        res = pthread_create(&it->tid,//tid, pthread_t type
                             &it->attribute,
                             it->functionPointer,
                             it->functionArgument);
    }
    return res;
end

fun(equal, int), struct MCThread* thread end_ as(MCThread)
    return pthread_equal(it->tid, thread->tid);
end

int MCThread_cancelThread(pthread_t tid)
{
#ifdef __APPLE__
	return pthread_cancel(tid);
#elif __ANDROID__
	return 0;
#else
	return pthread_cancel(tid);
#endif
}

int MCThread_joinThread(pthread_t tid)
{
    //did not pass an returen value pointer
    return pthread_join(tid, NULL);
}

void MCThread_exitWithStatus(void* status)
{
    pthread_exit(status);
}

pthread_t MCThread_currentThread(void)
{
    return pthread_self();
}

constructor(MCThread) end_ {
    MCObject(any, "MCThread");
    as(MCThread)
        //init the vars
        pthread_once_t ponce = PTHREAD_ONCE_INIT;
        it->once_control = ponce;
        it->isRunOnce = 0;//default is NO
        //if you need, you can set the attribute use the raw pthread APIs
        //example: pthread_attr_getstacksize(m_thread->attribute);
        pthread_attr_init(&it->attribute);

        it->functionPointer = null;
        it->functionArgument = null;
    end;
    dynamic(MCThread)
        funbind(bye);
        funbind(initWithFPointerArgument);
        funbind(initWithFPointer);
        funbind(detach);
        funbind(start);
        funbind(equal);
    end;
    return any;
}
