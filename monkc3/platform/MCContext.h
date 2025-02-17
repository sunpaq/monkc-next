#ifndef MCContext_h
#define MCContext_h

#include "MCObject.h"

structure(MCContext, MCObject)
    int argc;
    char** argv;
    char selectionChar;

    fundef(bye, void) end_;
    fundef(dumpParas, void) end_;
    fundef(getPara, char*), int index end_;
    fundef(isIndexedParaEqualTo, int), int index, char* para end_;
    fundef(isHavePara, int), char* para end_;
    fundef(showMenuAndGetSelectionChar, char), int count, ... end_;
    fundef(showConfirmAndGetBOOL, int), const char* confirm end_;
    fundef(getUserInputString, void), char resultString[] end_;
    fundef(getEnvironmentVar, char*), const char* key end_;
    fundef(setEnvironmentVar, int), const char* key, const char* value, int isOverwrite end_;
    fundef(clearEnvironmentVar, int), const char* key end_;
end;

constructor(MCContext), int argc, char** argv end_;

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
