#ifndef MCContext_h
#define MCContext_h

#include "MCObject.h"

structure(MCContext, MCObject)
    int argc;
    char** argv;
    char selectionChar;

    fundef(bye, void)endfun;
    fundef(dumpParas, void)endfun;
    fundef(getPara, char*), int index endfun;
    fundef(isIndexedParaEqualTo, int), int index, char* para endfun;
    fundef(isHavePara, int), char* para endfun;
    fundef(showMenuAndGetSelectionChar, char), int count, ...endfun;
    fundef(showConfirmAndGetBOOL, int), const char* confirm endfun;
    fundef(getUserInputString, void), char resultString[]endfun;
    fundef(getEnvironmentVar, char*), const char* key endfun;
    fundef(setEnvironmentVar, int), const char* key, const char* value, int isOverwrite endfun;
    fundef(clearEnvironmentVar, int), const char* key endfun;
end;

constructor(MCContext), int argc, char** argv endfun;

alias(MCContext);

extern char **environ;

#endif

/*
#include <stdlib.h>
char *getenv(const char *name);
int putenv(char *str); //need "key=value"
int setenv(const char *name, const char *value, int rewrite);
int unsetenv(const char *name);
*/
