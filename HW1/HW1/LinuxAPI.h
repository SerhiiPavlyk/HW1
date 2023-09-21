#pragma once
#include "pch.h"

#ifdef __linux__
void CreateLinuxSocket(SOCKET& ListeningSocket, struct sockaddr_in address, u_short port)

void BindLinuxSocket(SOCKET& ListeningSocket, sockaddr_in& ServerAddr);

void ListenLinuxSocket(SOCKET& ListeningSocket);

void AcceptLinuxSocket(SOCKET& ListeningSocket, struct sockaddr_in& ClientAddr, SOCKET& NewConnection);

int RecvLinux(SOCKET& NewConnection, std::shared_ptr<char[]> buffer, const int maxSizeofMessage);

void SentLinux(SOCKET& NewConnection, const char* msg);

void ConnectLinuxSocket(SOCKET& socket, struct sockaddr_in& ServerAddr);
#endif