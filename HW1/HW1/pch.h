#pragma once


#ifdef _WIN32

#pragma comment(lib, "Ws2_32.lib")

#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <Windows.h>

#else
#include <sys/unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define SOCKET int

#endif // _WIN32

#include <iostream>

#include <thread>

#include <string>

#include <queue>

#include <mutex>

#include <algorithm>

#include <stdlib.h>

#include <memory>

#include <exception>
#include <ios>
#include <ostream>	
#include <cstring>