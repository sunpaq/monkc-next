#include "SimpleServer.h"

static const char* template = "\
worker thread running...\n\
server[%s:%s] started\n\
please open another terminal and connet this Server by:\n\
------------------------\n\
telnet %s %s\n\
or [curl %s:%s]\n\
------------------------\n\
";

static const char* welcome = "\
---------------------------------\n\
Welcome to join Monk-C community!\n\
Good Old C language with OOP\n\
---------------------------------\n\
";

static void workerThread(struct SimpleServer* server) {
    printf(template, server->ip, server->port, server->ip, server->port, server->ip, server->port);
    server->socket->listeningStart(server->socket);

    struct MCSocketClientInfo* clientInfo;
    while (1) {
        clientInfo = server->socket->acceptARequest(server->socket);
        if (clientInfo != null) {
            //clientInfo->dumpInfo(clientInfo);
            server->socket->sendStringMsg(server->socket, welcome);
            printf("close socket\n");
            close(clientInfo->returnSfd);
            break;
        }
    }
}

fun(start, void) endfun as(SimpleServer)
    printf("starting worker thread...\n");
    workerThread(it);
end

fun(stop, void) endfun is
end

fun(restart, void) endfun is
end

fun(release, void) endfun as(SimpleServer)
    Release(it->socket);
    Release(it->worker);
end

constructor(SimpleServer), char* ip, char* port endfun is
    MCObject(any);
    as(SimpleServer)
        it->ip = ip;
        it->port = port;
        it->socket = MCSocket(alloc(MCSocket), MCSocket_Server_TCP, ip, port);
    end
    dynamic(SimpleServer)
        funbind(start);
        funbind(stop);
        funbind(restart);
        funbind(release);
    end
    return any;
end