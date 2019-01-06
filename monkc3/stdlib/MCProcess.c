#include "MCProcess.h"


fun(printIDs, void)) as(MCProcess)
	printf("pid[%d]ppid[%d]uid[%d]euid[%d]gid[%d]egid[%d]\n", 
		it->pid, it->ppid, it->uid, it->euid, it->gid, it->egid);
}

//returns(0 in child/child-pid in parent/-1 on error)
fun(forkProcess, int)) as(MCProcess)
	//pid_t fork(void);
	//copy-on-write (COW)
	//typically a "page" in a virtual memory system
	return fork();
}

//may be not supported by OS
fun(registerAtExitCallback, int), void (*func)(void)) as(MCProcess)
	if(atexit(func)==0)
		return 0;//success
	else
		return -1;//error
}

fun(exitWithStatus, void), int status) as(MCProcess)
	//this is a system call
	_exit(status);
}

fun(waitAnyChildExit, pid_t), int* statusAddr) as(MCProcess)
	return wait(statusAddr);
}

fun(waitPIDChildExit, pid_t), pid_t pid, int* statusAddr, int options) as(MCProcess)
	return waitpid(pid, statusAddr, options);
}

fun(isChildExitNormal, int), int status) as(MCProcess)
	if(WIFEXITED(status))
		return 1;
	else
		return 0;
}

fun(getChildExitLowOrder8Bit, int), int status) as(MCProcess)
	return WEXITSTATUS(status);
}

fun(isChildExitBySignal, int), int status) as(MCProcess)
	if (WIFSIGNALED(status))
		return 1;
	else
		return 0;
}

fun(getChildTerminateSignal, int), int status) as(MCProcess)
	return WTERMSIG(status);
}

fun(isCoreDumpFileGenerated, int), int status) as(MCProcess)
	return WCOREDUMP(status);
}

fun(isChildStopped, int), int status) as(MCProcess)
	if (WIFSTOPPED(status))
		return 1;
	else
		return 0;
}

fun(getChildStopSignal, int), int status) as(MCProcess)
	return WSTOPSIG(status);
}

fun(waitPIDChildExitGetResourceUseage, pid_t), pid_t pid, int* statusAddr, int options, MCProcessRUseage* useage) as(MCProcess)
	return wait4(pid, statusAddr, options, useage->rusage_p);
}

constructor(MCProcess)) {
    MCObject(any);
    as(MCProcess)
        //
    }
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
    }
    return any;
}
