#ifndef MONKC_DEMO_SIMPLESERVER_H
#define MONKC_DEMO_SIMPLESERVER_H

#include "MCObject.h"
#include "MCSocket.h"
#include "MCThread.h"

struct SimpleServer {
    copy_super(MCObject);
    struct MCSocket* socket;
    struct MCThread* worker;
    char* ip;
    char* port;

    fundef(start, void) endfun;
    fundef(stop, void) endfun;
    fundef(restart, void) endfun;
    fundef(release, void) endfun;
end;

constructor(SimpleServer), char* ip, char* port endfun;

#endif //MONKC_DEMO_SIMPLESERVER_H