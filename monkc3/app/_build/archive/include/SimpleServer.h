//
// Created by 孙御礼 on 2019-04-11.
//

#ifndef MONKC_DEMO_SIMPLESERVER_H
#define MONKC_DEMO_SIMPLESERVER_H

#include "MCObject.h"
#include "MCSocket.h"
#include "MCThread.h"

structure(SimpleServer, MCObject)
    struct MCSocket* socket;
    struct MCThread* worker;
    char* ip;
    char* port;

    fundef(start, void));
    fundef(stop, void));
    fundef(restart, void));
    fundef(release, void));
};

constructor(SimpleServer), char* ip, char* port);

#endif //MONKC_DEMO_SIMPLESERVER_H
