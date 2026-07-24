#ifndef MCString_h
#define MCString_h

#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "MCObject.h"

struct MCString is
    copy_super(MCObject);

    size_t length;
    size_t size;
    size_t cursor;
    char* buff;

    fundef(add, void), const char* str endfun;
    fundef(toCString, const char*), char const buff[] endfun;
    fundef(equalTo, int), struct MCString* stringToComp endfun;
    fundef(getCharsUntilEnter, void), char resultString[] endfun;
    fundef(getOneChar, char) endfun;
    fundef(print, void), bool withNewline endfun;
    fundef(startWith, bool), const char* str endfun;
    fundef(toDoubleValue, double), char** endptr endfun;
    fundef(copyCompressedString, struct MCString*) endfun;
    fundef(copyExtractedString, struct MCString*) endfun;
    fundef(randomString, const char*), size_t len endfun;
    fundef(release, void) endfun;
end;

constructor(MCString), const char* cstring endfun;

alias(MCString);

MCString_t* MCString_newWithCString(const char* cstr);
MCString_t* MCString_newWithMCString(MCString_t* mcstr);
MCString_t* MCString_newForHttp(char* cstr, int isHttps);
bool MCString_contains(const char* str, const char* instr);
size_t MCString_replace(const char* str, const char* withstr, const char* instr, char (*buff)[]);
size_t MCString_reverse(const char* str, char *buff);
size_t MCString_extensionFromFilename(const char* name, char* basebuff, char* extbuff);

const char* MCString_percentEncode(const char* str, char *buff);
const char* MCString_percentDecode(const char* str, char *buff);
const char* MCString_baseFromPath(const char* path, char (*buff)[]);
const char* MCString_filenameFromPath(const char* path, char (*buff)[]);
const char* MCString_concate(const char** strings, size_t count, char (*buff)[]);
const char* MCString_concateWith(const char* sp, const char* path1, const char* path2, char (*buff)[]);
const char* MCString_concatePath(const char* path1, const char* path2, char (*buff)[]);
const char* MCString_compressToCharCount(const char* source, char* buff);
const char* MCString_extractFromCharCount(const char* source, char* buff);
void MCString_printPermutationOf(char str[]);

static char* MCStringFill(char* dest, const char* src) {
    char* res = strcpy(dest, src);
    dest[strlen(src)] = '\0';
    return res;
}

static bool MCStringEqualN(const char* A, const char* B, size_t n) {
    if (strncmp(A, B, n) == 0) {
        return true;
    }else{
        return false;
    }
}

static bool MCStringEqual(const char* A, const char* B) {
    if (strcmp(A, B) == 0) {
        return true;
    }else{
        return false;
    }
}

static void MCStringSeedRandom(void) {
    srand((uint32_t)time(NULL));
}

#endif