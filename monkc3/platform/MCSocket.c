#ifndef WIN32

#include "MCSocket.h"
#include "MCLog.h"

fun(dumpInfo, void)endfun as(MCSocketClientInfo)
	printf("accept a client: %s\n", it->address.sa_data);
end

constructor(MCSocketClientInfo)endfun is
	as(MCSocketClientInfo)
		it->returnSfd = 0;
		it->address_len = 0;
	end
	return any;
}

static void create_and_bind_socket(struct MCSocket* this, MCSocketType socket_type, char* ip, char* port)
{
	//int sfd = ;
	//BOOL isServer;
	struct addrinfo hint, *result;
	runtime_log("begin prepare hint.\n");

	//prepare hint
	memset(&hint, 0, sizeof(struct addrinfo));
	hint.ai_family = AF_UNSPEC;
	//hint.ai_protocol = IPPROTO_IP;
	switch(socket_type){
		case MCSocket_Server_TCP:
			hint.ai_socktype = SOCK_STREAM;
			hint.ai_flags = AI_PASSIVE;
			this->isServer = 1;
		break;
		case MCSocket_Server_UDP:
			hint.ai_socktype = SOCK_DGRAM;
			hint.ai_flags = AI_PASSIVE;
			this->isServer = 1;
		break;
		case MCSocket_Client_TCP:
			hint.ai_socktype = SOCK_STREAM;
			this->isServer = 0;
		break;
		case MCSocket_Client_UDP:
			hint.ai_socktype = SOCK_DGRAM;
			this->isServer = 0;
		break;
	}
	//get addrinfo linklist
	if(getaddrinfo(ip, port, &hint, &result)){
		error_log("can not getaddrinfo, return null\n");
		return;
	}
	runtime_log("get the addrinfo linklist.\n");

	//try every addrinfo in list to create and bind until success
	struct addrinfo* iterator;
	for(iterator = result; iterator!=null; iterator = iterator->ai_next)
	{		
		this->sfd = socket(iterator->ai_family, iterator->ai_socktype, iterator->ai_protocol);
		if (this->isServer)
		{
			if (this->sfd==-1)
				continue;
			if (!bind(this->sfd, iterator->ai_addr, iterator->ai_addrlen))
			{
				//memcpy(&this->peeraddrinfo, iterator, sizeof(struct addrinfo));
				break;//bind success
			}			
				
		}else{
			if (this->sfd==-1)
				continue;
			if (!connect(this->sfd, iterator->ai_addr, iterator->ai_addrlen))
				break;//connect success
		}
		close(this->sfd);
	}
	//free linklist
	freeaddrinfo(result);
	//return socket fd
	//return sfd;
}

//EADDRINUSE
//EBADF
//ENOTSOCK
//EOPNOTSUPP
fun(listeningStart, int)endfun as(MCSocket)
	if(it->isServer!=1)return -1;
	return listen(it->sfd, MCSocket_Queue_Length);
end

fun(acceptARequest, struct MCSocketClientInfo*)endfun as(MCSocket)
	if (it->isServer!=1)return null;
	struct MCSocketClientInfo* clientinfo = MCSocketClientInfo(alloc(MCSocketClientInfo));
	clientinfo->returnSfd = accept(it->sfd, &clientinfo->address, &clientinfo->address_len);
	if (clientinfo->returnSfd > 0) {
		it->currentClient = clientinfo;
	end
	return clientinfo;
}

fun(receive, void)endfun is
    //recv(int, void *, size_t, int)
end

fun(receiveFrom, void)endfun is
    //recvfrom(int, void *, size_t, int, struct sockaddr *restrict, socklen_t *restrict)
end

fun(receiveMsg, void)endfun is
    //recvmsg(int, struct msghdr *, int)
end

fun(sendInfo, void)endfun is
    //send(int, const void *, size_t, int)
end

fun(sendTo, void)endfun is
    //sendto(int, const void *, size_t, int, const struct sockaddr *, socklen_t)
end

fun(sendStringMsg, void), const char* msg endfun as(MCSocket)
	if (it->currentClient) {
		write(it->currentClient->returnSfd, msg, strlen(msg));
	end
}

fun(sendMsg, void)endfun is
    //sendmsg(int, const struct msghdr *, int)
end

fun(release, void)endfun as(MCSocket)
    close(it->sfd);
end

constructor(MCSocket), MCSocketType socket_type, char* ip, char* port endfun is
	MCObject(any);
	as(MCSocket)
		create_and_bind_socket(it, socket_type, ip, port);
	end
	dynamic(MCSocket)
		funbind(listeningStart);
		funbind(acceptARequest);
		funbind(receive);
		funbind(receiveFrom);
		funbind(receiveMsg);
		funbind(sendInfo);
		funbind(sendTo);
		funbind(sendStringMsg);
		funbind(sendMsg);
		funbind(release);
	}
	return any;
}


#endif