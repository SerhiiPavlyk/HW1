#pragma once
#include "pch.h"
#ifdef _WIN32
void InitWinSocket(WSADATA &wsaData);

void CreateWinSocket(SOCKET& ListeningSocket, struct sockaddr_in& ServerAddr, const u_short& Port,  char *ipAddress);

void CreateWinSocket(SOCKET& ListeningSocket, struct sockaddr_in& ServerAddr, const u_short& Port);

void BindWinSocket(SOCKET& ListeningSocket, struct sockaddr_in& ServerAddr);

void ListenWinSocket(SOCKET& ListeningSocket);

void AcceptWinSocket(SOCKET& ListeningSocket, struct sockaddr_in& ClientAddr, SOCKET& NewConnection);

int RecvWin(SOCKET& NewConnection, std::shared_ptr<char[]> buffer, const int maxSizeofMessage);

void SentWin(SOCKET& NewConnection, const char* msg);

void ConnectWinSocket(SOCKET& socket, struct sockaddr_in& ServerAddr);
#endif