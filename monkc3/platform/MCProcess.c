#ifndef WIN32

#include "MCProcess.h"

fun(printIDs, void)endfun as(MCProcess)
	printf("pid[%d]ppid[%d]uid[%d]euid[%d]gid[%d]egid[%d]\n", 
		it->pid, it->ppid, it->uid, it->euid, it->gid, it->egid);
end

//returns(0 in child/child-pid in parent/-1 on error)
fun(forkProcess, int)endfun is
	//pid_t fork(void);
	//copy-on-write (COW)
	//typically a "page" in a virtual memory system
	return fork();
end

//may be not supported by OS
fun(registerAtExitCallback, int), void (*func)(void)endfun is
	if(atexit(func)==0)
		return 0;//success
	else
		return -1;//error
end

fun(exitWithStatus, void), int status endfun is
	//this is a system call
	_exit(status);
end

fun(waitAnyChildExit, pid_t), int* statusAddr endfun is
	return wait(statusAddr);
end

fun(waitPIDChildExit, pid_t), pid_t pid, int* statusAddr, int options endfun is
	return waitpid(pid, statusAddr, options);
end

fun(isChildExitNormal, int), int status endfun is
	if(WIFEXITED(status))
		return 1;
	else
		return 0;
end

fun(getChildExitLowOrder8Bit, int), int status endfun is
	return WEXITSTATUS(status);
end

fun(isChildExitBySignal, int), int status endfun is
	if (WIFSIGNALED(status))
		return 1;
	else
		return 0;
end

fun(getChildTerminateSignal, int), int status endfun is
	return WTERMSIG(status);
end

fun(isCoreDumpFileGenerated, int), int status endfun is
	return WCOREDUMP(status);
end

fun(isChildStopped, int), int status endfun is
	if (WIFSTOPPED(status))
		return 1;
	else
		return 0;
end

fun(getChildStopSignal, int), int status endfun is
	return WSTOPSIG(status);
end

fun(waitPIDChildExitGetResourceUseage, pid_t), pid_t pid, int* statusAddr, int options, MCProcessRUseage* useage endfun is
	return wait4(pid, statusAddr, options, useage->rusage_p);
end

constructor(MCProcess)endfun is
    MCObject(any);
    dynamic(MCProcess)
        funbind(printIDs);
        //returns(0 in child/child-pid in parent/-1 on error)
        funbind(forkProcess);
        //may be not supported by OS
        funbind(registerAtExitCallback);
        funbind(exitWithStatus);
        funbind(waitAnyChildExit);
        funbind(waitPIDChildExit);
        funbind(isChildExitNormal);
        funbind(getChildExitLowOrder8Bit);
        funbind(isChildExitBySignal);
        funbind(getChildTerminateSignal);
        funbind(isCoreDumpFileGenerated);
        funbind(isChildStopped);
        funbind(getChildStopSignal);
        funbind(waitPIDChildExitGetResourceUseage);
    end
    return any;
}

#endif
