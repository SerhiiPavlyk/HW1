#include "pch.h"

#include "Server.h"

void Server::Init()
{

	try
	{
#ifdef _WIN32

		InitWinSocket(wsaData);
#endif

		// Fill in the sockaddr_in ServerAddr struct, which will tell the
		//bind function that we want to listen for connections on all interfaces
		//(INADDR_ANY) interfaces, using port 7300.
		// We convert the byte order from system to network (htons and htonl)

		CreateSocket(ListeningSocket, ServerAddr, Port);

		// The bind function binds the address information specified in ServerAddr to the ListeningSocket socket
		BindSocket(ListeningSocket, ServerAddr);

		// Make the socket passive for listening (receiving) TCP connection request from client.
		// The length of the queue of requests for connection is 1
		ListenSocket(ListeningSocket);

		std::cout << "Waiting for a connection at the port: " << Port << std::endl;

		AcceptSocket(ListeningSocket, ClientAddr, NewConnection);

		std::cout << "Successfully connected with " << inet_ntoa(ClientAddr.sin_addr) << ": " << ntohs(ClientAddr.sin_port) << std::endl;
		
		std::thread InputT(Input, std::ref(NewConnection), "Server");
		std::thread OutputT(Output, std::ref(NewConnection), "Client");
		std::thread Printer(Print);
		if (NewConnection)
			Close(NewConnection);
		if (ListeningSocket)
			Close(ListeningSocket);

#ifdef _WIN32
		WSACleanup();
#endif

	}
	catch (const std::runtime_error& ex)
	{
		std::cout << ex.what() << std::endl;
		if (NewConnection)
		Close(NewConnection);
		if (ListeningSocket)
		Close(ListeningSocket);
#ifdef _WIN32
		WSACleanup();
#endif
	}

}


