#include "Common.h"

void Print()
{
	while (true)
	{
		// Lock the mutex before accessing the shared data (messageQueue)
		std::unique_lock<std::mutex> lock(g_mtx);

		// Wait until there's a message to print
		g_cv.wait(lock, [&] { return !g_messageQueue.empty(); });

		// Retrieve and print the message
		std::string message = g_messageQueue.front();
		g_messageQueue.pop();
		std::cout << message << std::endl;
	}

}

void Input(SOCKET& socket, const char* Autor)
{
	std::string message;
	while (true)
	{
		std::cout << "\nEnter massage: ";
		std::getline(std::cin, message);
		// Lock the mutex before accessing the shared data (messageQueue)
		std::lock_guard<std::mutex> lock(g_mtx);

		g_messageQueue.push(std::string(Autor)+ ": " + message);

		// Notify the output thread that there's a new message
		g_cv.notify_all();

		Sent(socket, message.c_str());

	}
}

void Output(SOCKET& socket, const char* Autor)
{

	int bytesReceived = 0;
	while (bytesReceived >= 0)
	{
		// Receive data from the client and write it to the output file
		std::shared_ptr<char[]> buffer(new char[maxSizeofMessage]);

		bytesReceived = Recive(socket, buffer, maxSizeofMessage);

		if (bytesReceived <= maxSizeofMessage)
			buffer[bytesReceived] = '\0';
		else
		{
			throw std::runtime_error("The message from the server is too long");
		}
		std::string message(Autor);
		message += ": ";
		for (size_t i = 0; i < bytesReceived; i++)
		{
			message += buffer[i];
		}
		// Lock the mutex before accessing the shared data (messageQueue)
		std::lock_guard<std::mutex> lock(g_mtx);

		g_messageQueue.push(message);

		// Notify the output thread that there's a new message
		g_cv.notify_all();
	}
}
