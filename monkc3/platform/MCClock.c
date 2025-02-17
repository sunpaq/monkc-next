#include "MCClock.h"

#ifndef LINE_MAX
#define LINE_MAX 2048
#endif

fun(bye, void) end_ as(MCClock)
    if (it->currentTimeBuff) {
        free(it->currentTimeBuff);
    }
    if (it->currentGMTBuff) {
        free(it->currentGMTBuff);
    }
end

fun(setTimeToNow, MCClock_t*) end_ as(MCClock)
    time_t timer = time(NULL);
    it->RawTime = *localtime(&timer);
    return it;
end

fun(setTime, void), struct MCTime time end_ as(MCClock)
    if(time.tm_sec!=no_change) it->RawTime.tm_sec = time.tm_sec;
    if(time.tm_min!=no_change) it->RawTime.tm_min = time.tm_min;
    if(time.tm_hour!=no_change) it->RawTime.tm_hour = time.tm_hour;
    if(time.tm_mday!=no_change) it->RawTime.tm_mday = time.tm_mday;
    if(time.tm_mon!=no_change) it->RawTime.tm_mon = time.tm_mon;
    int year = time.tm_year-1900;
    if(time.tm_year!=no_change) it->RawTime.tm_year = year;
    if(time.tm_wday!=no_change) it->RawTime.tm_wday = time.tm_wday;
end

fun(adjustTime, void), struct MCTime time end_ as(MCClock)
    if(time.tm_sec!=no_change) it->RawTime.tm_sec += time.tm_sec;
    if(time.tm_min!=no_change) it->RawTime.tm_min += time.tm_min;
    if(time.tm_hour!=no_change) it->RawTime.tm_hour += time.tm_hour;
    if(time.tm_mday!=no_change) it->RawTime.tm_mday += time.tm_mday;
    if(time.tm_mon!=no_change) it->RawTime.tm_mon += time.tm_mon;
    if(time.tm_year!=no_change) it->RawTime.tm_year += time.tm_year;
    if(time.tm_wday!=no_change) it->RawTime.tm_wday += time.tm_wday;
end

fun(setRawTime, void), struct tm rawTime end_ as(MCClock)
    it->RawTime = rawTime;
end

fun(getTime, void), time_t* const result end_ as(MCClock)
    *result = mktime(&(it->RawTime));
end

fun(getRawTime, void), struct tm* const result end_ as(MCClock)
    *result = it->RawTime;
end

fun(getTimeByString, const char*) end_ as(MCClock)
    strcpy(it->currentTimeBuff, asctime(&(it->RawTime)));
    return it->currentTimeBuff;
end

fun(getCPUClocksPerSecond, void), clock_t* const result end_ is
    *result = CLOCKS_PER_SEC;
end

fun(getCPUClocksSinceStart, void), clock_t* const result end_ is
    *result = clock();
end

fun(getCPUSecondsSinceStart, void), time_t* const result end_ is
    *result = (clock() / CLOCKS_PER_SEC);
end

fun(getCPUSecondsSince, void), time_t since, time_t* const result end_ is
    *result = (clock() / CLOCKS_PER_SEC) - since;
end

fun(getCurrentTimeString, const char*) end_ as(MCClock)
    time_t timer = time(NULL);
    strcpy(it->currentTimeBuff, asctime(localtime(&timer)));
    return it->currentTimeBuff;
end

fun(getCurrentGMTTimeString, const char*) end_ as(MCClock)
    time_t timer = time(NULL);
    strcpy(it->currentGMTBuff, asctime(gmtime(&timer)));
    return it->currentGMTBuff;
end

fun(printTime, void) end_ as(MCClock)
    printf("\n%s", asctime(&it->RawTime));
end

fun(printCurrentTime, void) end_ is
    time_t timer = time(NULL);
    printf("%s", asctime(localtime(&timer)));
end

fun(printCurrentGMTTime, void) end_ is
    time_t timer = time(NULL);
    printf("%s", asctime(gmtime(&timer)));
end

char* MCClock_rawtime2String(time_t* timeval)
{
    return ctime(timeval);
}

char* MCClock_settableTime2String(struct tm *tm)
{
    return asctime(tm);
}

struct tm* MCClock_rawtime2SettableTimeGMT(time_t* timeval)
{
    return gmtime(timeval);
}

struct tm* MCClock_rawtime2SettableTimeLocal(time_t* timeval)
{
    return localtime(timeval);
}

constructor(MCClock) end_ is
    MCObject(any, "MCClock");
    as(MCClock)
        it->currentTimeBuff = (char*)malloc(sizeof(char) * LINE_MAX);
        it->currentGMTBuff = (char*)malloc(sizeof(char) * LINE_MAX);
    end
    dynamic(MCClock)
        funbind(bye);
        funbind(setTimeToNow);
        funbind(setTime);
        funbind(adjustTime);
        funbind(setRawTime);
        funbind(getTime);
        funbind(getRawTime);
        funbind(getTimeByString);
        funbind(getCPUClocksPerSecond);
        funbind(getCPUClocksSinceStart);
        funbind(getCPUSecondsSince);
        funbind(getCPUSecondsSinceStart);
        funbind(getCurrentTimeString);
        funbind(getCurrentGMTTimeString);
        funbind(printTime);
        funbind(printCurrentTime);
        funbind(printCurrentGMTTime);
    end
    return any;
end
