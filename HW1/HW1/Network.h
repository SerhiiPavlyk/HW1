#pragma once
#ifdef _WIN32
#include "WindowsAPI.h"
#else
#include "LinuxAPI.h"
#endif // _WIN32

void CreateSocket(SOCKET& ListeningSocket, struct sockaddr_in& ServerAddr, const u_short& Port);

void BindSocket(SOCKET& ListeningSocket, struct sockaddr_in& ServerAddr);

void ListenSocket(SOCKET& ListeningSocket);

void AcceptSocket(SOCKET& ListeningSocket, struct sockaddr_in& ClientAddr, SOCKET& NewConnection);

int Recive(SOCKET& NewConnection, std::shared_ptr<char[]> buffer, const int maxSizeofMessage);

void Sent(SOCKET& NewConnection,const char* msg = "Success");

void Close(SOCKET& socket);

void Connect(SOCKET& socket, struct sockaddr_in& ServerAddr);
