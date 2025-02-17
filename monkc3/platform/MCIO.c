#ifndef WIN32

#include "MCIO.h"

#include <limits.h>
#include "MCLog.h"
#include "MCString.h"

#ifndef LINE_MAX
#define LINE_MAX 2048
#endif

#ifndef PATH_MAX
#define PATH_MAX 2048
#endif

#pragma mark - MCFile unbuffered IO

void MCFile_flushAllCacheToDisk(void)
{
    sync();
}

int MCFile_flushAFileCacheToDisk(int fd)
{
    return fsync(fd);
}

int MCFile_isPathExist(char* pathname)
{
    //file exist test
    int res;
    if ((res = access(pathname, F_OK)) != -1)
        return 1;
    return 0;
}

int MCFile_chmod(char* pathname, mode_t mode)
{
    int res;
    if ((res = chmod(pathname, mode))!= -1)
        return 1;
    return 0;
}

int MFFile_truncateFileTo(char* pathname, off_t length)
{
    int res;
    if ((res = truncate(pathname, length))!= -1)
        return 1;
    return 0;
}

mode_t MCFile_setNewFilePermissionMask4Process(mode_t cmask)
{
    return umask(cmask);
}

struct MCFile* MCFile_newReadOnly(char* pathname)
{
    struct MCFile* file = MCFile(alloc(MCFile));
    return file->initWithPathName(file, pathname, O_RDONLY|O_CREAT);
}

struct MCFile* MCFile_newWriteOnly(char* pathname, int isClear)
{
    struct MCFile* file = MCFile(alloc(MCFile));
    if(isClear)
        return file->initWithPathName(file, pathname, O_WRONLY|O_CREAT|O_TRUNC);
    else
        return file->initWithPathName(file, pathname, O_WRONLY|O_CREAT);
}

struct MCFile* MCFile_newReadWrite(char* pathname, int isClear)
{
    struct MCFile* file = MCFile(alloc(MCFile));
    if(isClear)
        return file->initWithPathName(file, pathname, O_RDWR|O_CREAT|O_TRUNC);
    else
        return file->initWithPathName(file, pathname, O_RDWR|O_CREAT);
}

int MCFile_createSymbolLink(char* pathname, char* linkname)
{
    int res;
    if ((res = symlink(pathname, linkname))!= -1)
        return 1;
    return 0;
}

int MCFile_createDirectory(char* pathname)
{
    int res;
    if ((res = mkdir(pathname, S_IRWXU))!= -1)
        return 1;
    return 0;
}

int MCFile_removeDirectory(char* pathname)
{
    int res;
    if ((res = rmdir(pathname))!= -1)
        return 1;
    return 0;
}

fun(initWithPathName, struct MCFile*), char* pathname, int oflag end_ as(MCFile)
    if((it->fd = open(pathname, oflag, 0774))==-1)
        return null;
    it->pathname = pathname;
    if(fstat(it->fd, &it->attribute)<0)
        return null;
    it->buffer = malloc((size_t)it->attribute.st_blksize*10);
    return it;
end

fun(initWithPathNameDefaultFlag, struct MCFile*), char* pathname end_ as(MCFile)
    return initWithPathName(it, pathname, MCFileReadWriteTrunc);
end

fun(readFromBegin, ssize_t), off_t offset, size_t nbytes end_ as(MCFile)
    //use pread/pwrite for atomic operation
    return pread(it->fd, it->buffer, nbytes, offset);
end

fun(readAllFromBegin, ssize_t), off_t offset end_ as(MCFile)
    return readFromBegin(it, offset, (size_t)it->attribute.st_size);
end

fun(readAtLastPosition, size_t), off_t offset, size_t nbytes end_ as(MCFile)
    return (size_t)pread(it->fd, it->buffer, nbytes, offset);
end

fun(readFromEnd, size_t), off_t offset, size_t nbytes end_ as(MCFile)
    return (size_t)pread(it->fd, it->buffer, nbytes, offset);
end

fun(writeToBegin, size_t), off_t offset, void* buf, size_t nbytes end_ as(MCFile)
    return (size_t)pwrite(it->fd, buf, nbytes, offset);
end

fun(writeToLastTime, size_t), off_t offset, void* buf, size_t nbytes end_ as(MCFile)
    return (size_t)pwrite(it->fd, buf, nbytes, offset);
end

fun(writeToEnd, size_t), off_t offset, void* buf, size_t nbytes end_ as(MCFile)
    return (size_t)pwrite(it->fd, buf, nbytes, offset);
end

fun(duplicateFd, int) end_ as(MCFile)
    return dup(it->fd);
end

fun(duplicateFdTo, int), int fd end_ as(MCFile)
    return dup2(it->fd, fd);
end

fun(printAttribute, void) end_ as(MCFile)
    printf("uid:%d gid:%d size:%jd st_mode:%o lmtime:%s",
        it->attribute.st_uid,
        it->attribute.st_gid,
        (intmax_t)it->attribute.st_size,
        it->attribute.st_mode,
        ctime(&it->attribute.st_mtime));
end

fun(checkPermissionUseRealIDOfProcess, int), int mode end_ as(MCFile)
    int res;
    if ((res = access(it->pathname, mode)) != -1)
        return 1;
    return 0;
end

fun(closeFile, void) end_ as(MCFile)
    //release it->buffer
    free(it->buffer);
    close(it->fd);
end

constructor(MCFile) end_ is
    MCObject(any, "MCFile");
    as(MCFile)
        it->fd = 0;
        it->pathname = "";
        it->buffer = null;
    end
    dynamic(MCFile)
        funbind(initWithPathName);
        funbind(initWithPathNameDefaultFlag);

        funbind(readAllFromBegin);
        funbind(readFromBegin);
        funbind(readAtLastPosition);
        funbind(readFromEnd);
        funbind(writeToBegin);
        funbind(writeToLastTime);
        funbind(writeToEnd);

        funbind(duplicateFd);
        funbind(duplicateFdTo);
        funbind(printAttribute);
        funbind(checkPermissionUseRealIDOfProcess);
        funbind(closeFile);
    end
    return any;
end

#pragma mark - MCStream buffered IO

fun(initWithPath, struct MCStream*), MCStreamType type, const char* path end_ as(MCStream)
    //FILE *fopen(const char *restrict pathname, const char *restrict type);
    //type:
    //r/w/a/ & b & +
    //int setvbuf(FILE *restrict fp, char *restrict buf, int mode, size_t size);
    //[NULL _IOFBF/_IOLBF/_IONBF BUFSIZ]
    
    char decodepath[PATH_MAX] = {0};
    it->fileObject = fopen(MCString_percentDecode(path, decodepath), type.fopenMode);
    if (it->fileObject) {
        //file size
        fseek(it->fileObject, 0, SEEK_END);
        long size = ftell(it->fileObject);
        fseek(it->fileObject, 0, SEEK_SET);
        
        it->buffer = (char*)malloc(size * sizeof(char));
        char* iter = it->buffer;
        
        char c;
        while ((c = (char)fgetc(it->fileObject)) != EOF) {
            *iter++ = c;
        }
        *iter = NUL;
        fseek(it->fileObject, 0, SEEK_SET);
    }
    
    return it;
end

fun(initWithPathDefaultType, struct MCStream*), const char* path end_ as(MCStream)
    return it->initWithPath(it, MakeMCStreamType(MCStreamBuf_FullBuffered, MCStreamOpen_ReadWrite), path);
end

fun(bye, void) end_ as(MCStream)
    if (it->buffer) {
        free(it->buffer);
    }
    //0=OK/NUL=ERROR
    if(fclose(it->fileObject))
        error_log("MCStream close file error\n");
end

fun(getFileDescriptor, int) end_ as(MCStream)
    return fileno(it->fileObject);
end

fun(getChar, int) end_ as(MCStream)
    return fgetc(it->fileObject);
end

fun(putChar, int), int charCode end_ as(MCStream)
    return fputc(charCode, it->fileObject);
end

fun(pushbackChar, int), int charCodeToBePushBack end_ as(MCStream)
    return ungetc(charCodeToBePushBack, it->fileObject);
end

fun(getCString, char*), MCCharBuffer* recvBuffer end_ as(MCStream)
    fgets(recvBuffer->data, (int)recvBuffer->size, it->fileObject);
    return recvBuffer->data;
end

fun(putCString, char*), MCCharBuffer* sendBuffer end_ as(MCStream)
    fputs(sendBuffer->data, it->fileObject);
    return sendBuffer->data;
end

fun(getMCString, struct MCString*) end_ as(MCStream)
    char buff[LINE_MAX];
    fgets(buff, sizeof(buff), it->fileObject);
    return MCString(alloc(MCString), &buff[0]);
end

fun(putMCString, int), struct MCString* str end_ as(MCStream)
    return fputs(str->buff, it->fileObject);
end

fun(getBianryObject, size_t), void* recvBuffer, size_t objectSize, size_t numberOfObjs end_ as(MCStream)
    //size_t fread(void *restrict ptr, size_t size, size_t nobj, FILE *restrict fp);
    return fread(recvBuffer, objectSize, numberOfObjs, it->fileObject);
end

fun(putBianryObject, size_t), void* sendBuffer, size_t objectSize, size_t numberOfObjs end_ as(MCStream)
    //size_t fwrite(const void *restrict ptr, size_t size, size_t nobj, FILE *restrict fp);
    return fwrite(sendBuffer, objectSize, numberOfObjs, it->fileObject);
end

fun(tellOffset, off_t) end_ as(MCStream)
    //off_t ftello(FILE *fp);
    return ftello(it->fileObject);
end

fun(seekFromBegin, int), off_t offset end_ as(MCStream)
    //int fseeko(FILE *fp, off_t offset, int whence);//SEEK_SET/SEEK_CUR/SEEK_END
    return fseeko(it->fileObject, offset, SEEK_SET);
end

fun(seekFromCurrent, int), off_t offset end_ as(MCStream)
    return fseeko(it->fileObject, offset, SEEK_CUR);
end

fun(seekFromEnd, int), off_t offset end_ as(MCStream)
    return fseeko(it->fileObject, offset, SEEK_END);
end

fun(tellSize, long) end_ as(MCStream)
    fseek(it->fileObject, 0, SEEK_END);
    long size = ftell(it->fileObject);
    rewind(it->fileObject);
    return size;
end

fun(dump, void) end_ as(MCStream)
    printf("%s", it->buffer);
end

constructor(MCStream) end_ is
    MCObject(any, "MCStream");
    as(MCStream)
        it->buffer = null;
    end
    dynamic(MCStream)
        funbind(initWithPath);
        funbind(initWithPathDefaultType);

        funbind(bye);
        funbind(getFileDescriptor);

        funbind(getChar);
        funbind(putChar);
        funbind(pushbackChar);

        funbind(getCString);
        funbind(putCString);
        funbind(getMCString);
        funbind(putMCString);

        funbind(getBianryObject);
        funbind(putBianryObject);

        funbind(tellOffset);
        funbind(seekFromBegin);
        funbind(seekFromCurrent);
        funbind(seekFromEnd);
        funbind(tellSize);
        funbind(dump);
    end
    return any;
end

#pragma mark - MCSelect

fun(initWithSecondAndMicrosec, void), long second, long microsecond end_ as(MCSelect)
    //timeout.tv_sec
    //timeout.tv_usec
    it->timeout.tv_sec = second;
    it->timeout.tv_usec = (int)microsecond;
end

fun(waitForFdsetChange, int) end_ as(MCSelect)
    it->readfd_result_set = it->readfd_set;
    it->writefd_result_set = it->writefd_set;
    it->exceptionfd_result_set = it->exceptionfd_set;
    
    return select(it->maxfd + 1,
                  &it->readfd_result_set,
                  &it->writefd_result_set,
                  &it->exceptionfd_result_set,
                  (it->timeout.tv_usec==0 && it->timeout.tv_sec==0)? NULL : &it->timeout);
end

fun(addFd, void), MCSelect_fd_type type, int fd end_ as(MCSelect)
    if(fd > it->maxfd) it->maxfd = fd;
    switch(type){
        case MCSelect_Readfd:
            FD_SET(fd, &it->readfd_set);
            break;
        case MCSelect_Writefd:
            FD_SET(fd, &it->writefd_set);
            break;
        case MCSelect_Exceptionfd:
            FD_SET(fd, &it->exceptionfd_set);
            break;
    }
end

fun(removeFd, void), MCSelect_fd_type type, int fd end_ as(MCSelect)
    switch(type){
        case MCSelect_Readfd:
            FD_CLR(fd, &it->readfd_set);
            break;
        case MCSelect_Writefd:
            FD_CLR(fd, &it->writefd_set);
            break;
        case MCSelect_Exceptionfd:
            FD_CLR(fd, &it->exceptionfd_set);
            break;
    }
end

fun(isFdReady, int), MCSelect_fd_type type, int fd end_ as(MCSelect)
    switch(type){
        case MCSelect_Readfd:
            return FD_ISSET(fd, &it->readfd_result_set);
            break;
        case MCSelect_Writefd:
            return FD_ISSET(fd, &it->writefd_result_set);
            break;
        case MCSelect_Exceptionfd:
            return FD_ISSET(fd, &it->exceptionfd_result_set);
            break;
    }
end

constructor(MCSelect) end_ is
    MCObject(any, "MCSelect");
    as(MCSelect)
        FD_ZERO(&it->readfd_set);
        FD_ZERO(&it->writefd_set);
        FD_ZERO(&it->exceptionfd_set);

        FD_ZERO(&it->readfd_result_set);
        FD_ZERO(&it->writefd_result_set);
        FD_ZERO(&it->exceptionfd_result_set);
    end
    dynamic(MCSelect)
        funbind(initWithSecondAndMicrosec);
        funbind(waitForFdsetChange);
        funbind(addFd);
        funbind(removeFd);
        funbind(isFdReady);
    end
    return any;
end

#pragma mark - MCProgress

int MCProcess_changeCurrentWorkingDir(char* pathname)
{
    int res;
    if ((res = chdir(pathname))!= -1)
        return 1;
    return 0;
}

int MCProcess_changeCurrentWorkingDirByFd(int fd)
{
    int res;
    if ((res = fchdir(fd))!= -1)
        return 1;
    return 0;
}

char* MCProcess_getCurrentWorkingDir(MCCharBuffer* buff)
{
    return getcwd(buff->data, buff->size);
}

#endif

