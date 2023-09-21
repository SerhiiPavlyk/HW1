#include "Network.h"

void CreateSocket(SOCKET& ListeningSocket, struct sockaddr_in& ServerAddr, const u_short& Port)
{
	try
	{
#ifdef _WIN32
		CreateWinSocket(ListeningSocket, ServerAddr, Port);
#else
		CreateLinuxSocket(ListeningSocket, ServerAddr, Port);
#endif // _WIN32
	}

	catch (...)
	{
		throw;
	}
}

void BindSocket(SOCKET& ListeningSocket, sockaddr_in& ServerAddr)
{
	try
	{
#ifdef _WIN32
		BindWinSocket(ListeningSocket, ServerAddr);
#else
		BindLinuxSocket(ListeningSocket, ServerAddr);
#endif // _WIN32
	}
	catch (...)
	{
		throw;
	}
}

void ListenSocket(SOCKET& ListeningSocket)
{
	try
	{
#ifdef _WIN32
		ListenWinSocket(ListeningSocket);
#else
		ListenLinuxSocket(ListeningSocket);
#endif // _WIN32
	}
	catch (...)
	{
		throw;
	}
}

void AcceptSocket(SOCKET& ListeningSocket, sockaddr_in& ClientAddr, SOCKET& NewConnection)
{
	try
	{
#ifdef _WIN32
		AcceptWinSocket(ListeningSocket, ClientAddr, NewConnection);
#else
		AcceptLinuxSocket(ListeningSocket, ClientAddr, NewConnection);
#endif // _WIN32
	}
	catch (...)
	{
		throw;
	}
}

int Recive(SOCKET& NewConnection, std::shared_ptr<char[]> buffer, const int maxSizeofMessage)
{
	try
	{
#ifdef _WIN32
		return RecvWin(NewConnection, buffer, maxSizeofMessage);
#else
		RecvLinux(NewConnection, buffer, maxSizeofMessage);
		return 1;
#endif // _WIN32
	}
	catch (...)
	{
		throw;
	}
}

void Sent(SOCKET& NewConnection, const char* msg)
{
	try
	{
#ifdef _WIN32
		SentWin(NewConnection, msg);
#else
		SentLinux(NewConnection, msg);
#endif // _WIN32
	}
	catch (...)
	{
		throw;
	}
}

void Close(SOCKET& socket)
{
	try
	{
#ifdef _WIN32
		closesocket(socket);
#else
		close(socket);
#endif // _WIN32
	}
	catch (...)
	{
		throw;
	}
}

void Connect(SOCKET& socket, struct sockaddr_in& ServerAddr)
{
	try
	{
#ifdef _WIN32
		ConnectWinSocket(socket, ServerAddr);
#else
		ConnectLinuxSocket(socket, ServerAddr);
#endif // _WIN32
	}
	catch (...)
	{
		throw;
	}

}
