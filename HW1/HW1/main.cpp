#include "pch.h"
#include "Server.h"
#include "Client.h"


int main(int argc, char* argv[])
{
	//argument validation
	if (argc < 2)
	{
		std::cout << "You must specify the role of the application(Server|Client)" << std::endl;
		system("pause");
		return -1;
	}
	//selection of the application side
	if (strcmp(argv[1], "Server") == 0)
	{
		Server server;
		server.Init();
	}

	else if (strcmp(argv[1], "Client") == 0)
	{
		Client client;
		client.Init();
	}

	else
	{
		std::cout << "Wrong argument\n";
		system("pause");
		return -1;
	}
	system("pause");
	return 0;
}
