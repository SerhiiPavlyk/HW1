#pragma once
#include "Common.h"
class Client
{

public:
	void Init();
private:
	WSADATA wsaData;
	SOCKET s;
	struct sockaddr_in ServerAddr, ca;
	int Ret;
	u_short Port = 7300;
	int caSize = sizeof(ca);
};

