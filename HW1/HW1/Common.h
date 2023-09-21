#pragma once
#include "Network.h"
static std::queue<std::string> g_messageQueue;
static std::mutex g_mtx;
static std::condition_variable g_cv;

const unsigned maxSizeofMessage = 4096;

void Print();
void Input(SOCKET& socket, const char* Autor);
void Output(SOCKET& socket, const char* Autor);