#pragma once
#include "Common.h"
class Server
{
public:
	void Init();
private:
	WSADATA wsaData;

	SOCKET NewConnection;
	struct sockaddr_in ServerAddr;
	struct sockaddr_in ClientAddr;
	int ClientAddrLen;
	SOCKET ListeningSocket;
	u_short Port = 7300;
	
};

