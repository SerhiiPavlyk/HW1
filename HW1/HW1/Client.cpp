
#include "Client.h"



void Client::Init()
{
#ifdef _WIN32
	InitWinSocket(wsaData);

#endif

	try
	{
		char ipAddress[32];
		std::cout << "Enter the IP address of the server to which you want to connect: ";
		gets_s(ipAddress, 32);
		CreateSocket(s, ServerAddr, Port);
#ifdef _WIN32
		ServerAddr.sin_addr.s_addr = inet_addr(ipAddress);
#endif
		
		// Connect socket s to the server
		std::cout << "Attempting to connect to " << inet_ntoa(ServerAddr.sin_addr) << " : " << htons(ServerAddr.sin_port) << std::endl;

		Connect(s, ServerAddr);

		std::thread InputT(Input, std::ref(s), "Client");
		std::thread OutputT(Output, std::ref(s), "Server");
		std::thread Printer(Print);
		InputT.join();
		OutputT.join();
		if (s)
		Close(s);

#ifdef _WIN32
		WSACleanup();
#endif

	}
	catch (const std::runtime_error& ex)
	{
		std::cout << ex.what() << std::endl;
		if(s)
		Close(s);

#ifdef _WIN32
		WSACleanup();
#endif
	}
}
