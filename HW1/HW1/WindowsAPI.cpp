#include "WindowsAPI.h"
#include "pch.h"

#ifdef _WIN32
void InitWinSocket(WSADATA& wsaData)
{
	// Initializing Winsock version 2.2
	int res;
	if ((res = WSAStartup(MAKEWORD(2, 2), &wsaData)) != 0)
	{
		//Winsock did not load. The error code is returned by the WSAStartup function
		throw std::runtime_error("WSAStartup error, error number: " + (res - '0') + '\n');
	}
}
void CreateWinSocket(SOCKET& ListeningSocket, sockaddr_in& ServerAddr, const u_short& Port, char* ipAddress)
{
	// Create a new TCP socket to receive connection requests from clients.
	if ((ListeningSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == INVALID_SOCKET)
	{
		WSACleanup();
		throw std::runtime_error("Socket error, error number : " + WSAGetLastError() - '0' + '\n');
	}
	ServerAddr.sin_family = AF_INET;
	ServerAddr.sin_port = htons(Port);
}
void CreateWinSocket(SOCKET& ListeningSocket, struct sockaddr_in& ServerAddr, const u_short& Port)
{
	// Create a new TCP socket to receive connection requests from clients.
	if ((ListeningSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == INVALID_SOCKET)
	{
		WSACleanup();
		throw std::runtime_error("Socket error, error number : " + WSAGetLastError() - '0' + '\n');
	}
	ServerAddr.sin_family = AF_INET;
	ServerAddr.sin_port = htons(Port);
	ServerAddr.sin_addr.s_addr = htonl(INADDR_ANY);
}

void BindWinSocket(SOCKET& ListeningSocket, sockaddr_in& ServerAddr)
{
	if (bind(ListeningSocket, (struct sockaddr*)&ServerAddr, sizeof(ServerAddr)) == SOCKET_ERROR)
	{
		closesocket(ListeningSocket);
		WSACleanup();
		throw std::runtime_error("Bind error, error number : " + WSAGetLastError() - '0' + '\n');
	}
}

void ListenWinSocket(SOCKET& ListeningSocket)
{
	if (listen(ListeningSocket, 1) == SOCKET_ERROR)
	{
		closesocket(ListeningSocket);
		WSACleanup();
		throw std::runtime_error("Listen error, error number : " + WSAGetLastError() - '0' + '\n');
	}
}

void AcceptWinSocket(SOCKET& ListeningSocket, struct sockaddr_in& ClientAddr, SOCKET& NewConnection)
{
	int ClientAddrLen = sizeof(ClientAddr);
	if ((NewConnection = accept(ListeningSocket, (struct sockaddr*)&ClientAddr, &ClientAddrLen)) == INVALID_SOCKET)
	{
		closesocket(ListeningSocket);
		WSACleanup();
		throw std::runtime_error("Accept error, error number : " + WSAGetLastError() - '0' + '\n');
	}
}

int RecvWin(SOCKET& NewConnection, std::shared_ptr<char[]> buffer, const int maxSizeofMessage)
{
	return recv(NewConnection, buffer.get(), maxSizeofMessage, 0);
}

void SentWin(SOCKET& NewConnection, const char* msg)
{
	if (send(NewConnection, msg, strlen(msg), 0) == SOCKET_ERROR)
	{
		closesocket(NewConnection);
		WSACleanup();
		throw std::runtime_error("Send error, error number : " + WSAGetLastError() - '0' + '\n');
	}
}

void ConnectWinSocket(SOCKET& socket, struct sockaddr_in& ServerAddr)
{
	if (connect(socket, (struct sockaddr*)&ServerAddr, sizeof(ServerAddr)) == SOCKET_ERROR)
	{
		closesocket(socket);
		WSACleanup();
		throw std::runtime_error("Connect error, error number : " + WSAGetLastError() - '0' + '\n');
	}
	std::cout << "The connection is successful.\n";
}

#endif

