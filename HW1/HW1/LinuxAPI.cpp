#include "pch.h"

#include "LinuxAPI.h"
#ifdef __linux__

void CreateLinuxSocket(SOCKET& ListeningSocket, struct sockaddr_in address, u_short port)
{
	if ((ListeningSocket = socket(AF_INET, SOCK_STREAM, 0)) == 0)
	{
		throw std::runtime_error("socket failed");
	}
	int opt = 1;
	if (setsockopt(ListeningSocket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
	{
		throw std::runtime_error("setsockopt failed");
	}

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(port);
}


void BindLinuxSocket(SOCKET& ListeningSocket, sockaddr_in& ServerAddr)
{
	if (bind(ListeningSocket, (struct sockaddr*)&ServerAddr, sizeof(ServerAddr)) < 0)
	{
		throw std::runtime_error("bind failed");
	}
}

void ListenLinuxSocket(SOCKET& ListeningSocket)
{
	if (listen(ListeningSocket, 1) < 0)
	{
		throw std::runtime_error("listen failed");
	}
}

void AcceptLinuxSocket(SOCKET& ListeningSocket, sockaddr_in& ClientAddr, SOCKET& NewConnection)
{
	if ((NewConnection = accept(ListeningSocket, (struct sockaddr*)&ClientAddr, (socklen_t*)&ClientAddr)) < 0)
	{
		throw std::runtime_error("accept failed");
	}

	std::cout << "\nClient " << NewConnection << " has successfully joined" << std::endl;
}

int RecvLinux(SOCKET& NewConnection, std::shared_ptr<char[]> buffer, const int maxSizeofMessage)
{
	read(NewConnection, buffer.get(), maxSizeofMessage);
	return 1;
}

void SentLinux(SOCKET& NewConnection, const char* msg)
{
	write(NewConnection, msg, strlen(msg));
}

void ConnectLinuxSocket(SOCKET& socket, sockaddr_in& ServerAddr)
{
	// Connect to the server
	if (connect(socket, (struct sockaddr*)&ServerAddr, sizeof(ServerAddr)) < 0)
	{
		std::cout << "connection failed" << std::endl;
		exit(EXIT_FAILURE);
	}
}
#endif