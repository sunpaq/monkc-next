#ifndef WIN32

#include "MCProcess.h"

fun(printIDs, void) end_ as(MCProcess)
	printf("pid[%d]ppid[%d]uid[%d]euid[%d]gid[%d]egid[%d]\n", 
		it->pid, it->ppid, it->uid, it->euid, it->gid, it->egid);
end

//returns(0 in child/child-pid in parent/-1 on error)
fun(forkProcess, int) end_ {
	//pid_t fork(void);
	//copy-on-write (COW)
	//typically a "page" in a virtual memory system
	return fork();
}

//may be not supported by OS
fun(registerAtExitCallback, int), void (*func)(void) end_ {
	if(atexit(func)==0)
		return 0;//success
	else
		return -1;//error
}

fun(exitWithStatus, void), int status end_ {
	//this is a system call
	_exit(status);
}

fun(waitAnyChildExit, pid_t), int* statusAddr end_ {
	return wait(statusAddr);
}

fun(waitPIDChildExit, pid_t), pid_t pid, int* statusAddr, int options end_ {
	return waitpid(pid, statusAddr, options);
}

fun(isChildExitNormal, int), int status end_ {
	if(WIFEXITED(status))
		return 1;
	else
		return 0;
}

fun(getChildExitLowOrder8Bit, int), int status end_ {
	return WEXITSTATUS(status);
}

fun(isChildExitBySignal, int), int status end_ {
	if (WIFSIGNALED(status))
		return 1;
	else
		return 0;
}

fun(getChildTerminateSignal, int), int status end_ {
	return WTERMSIG(status);
}

fun(isCoreDumpFileGenerated, int), int status end_ {
	return WCOREDUMP(status);
}

fun(isChildStopped, int), int status end_ {
	if (WIFSTOPPED(status))
		return 1;
	else
		return 0;
}

fun(getChildStopSignal, int), int status end_ {
	return WSTOPSIG(status);
}

fun(waitPIDChildExitGetResourceUseage, pid_t), pid_t pid, int* statusAddr, int options, MCProcessRUseage* useage end_ {
	return wait4(pid, statusAddr, options, useage->rusage_p);
}

constructor(MCProcess) end_ {
    MCObject(any, "MCProcess");
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
