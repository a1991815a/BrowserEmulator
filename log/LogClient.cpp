#include "LogClient.h"
#include <stdio.h>
#include <varargs.h>

bool LogClient::isInit = false;

int LogClient::clientCount = 0;

LogClient::LogClient(const char* ip, int port /*= 9001*/)
	:m_socket(INVALID_SOCKET)
{
	if (!LogClient::isInit)
	{
		WSADATA data = {};
		WSAStartup(MAKEWORD(2, 2), &data);
		isInit = true;
	}
	++clientCount;

	m_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (m_socket == INVALID_SOCKET)
		exit(GetLastError());
	SOCKADDR_IN addr = {};
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = inet_addr(ip);

	if (connect(m_socket, (sockaddr*)&addr, sizeof(addr)) == SOCKET_ERROR)
		exit(GetLastError());
}

LogClient::~LogClient()
{
	if (m_socket != INVALID_SOCKET)
		::closesocket(m_socket);
	if (--clientCount == 0 && isInit)
	{
		WSACleanup();
		isInit = false;
	}
}

void LogClient::log(const char* text, ...)
{
	va_list ap;
	va_start(ap, text);
	char buf[1024] = {};
	int len = vsprintf_s(buf, text, ap);
	va_end(ap);
	buf[len++] = '\n';

	::send(m_socket, buf, len, 0);
}

void LogClient::log(const wchar_t* text, ...)
{
	va_list ap;
	va_start(ap, text);
	wchar_t buf[1024] = {};
	int len = wvsprintfW(buf, text, ap);
	va_end(ap);
	buf[len++] = '\n';

	::send(m_socket, (char*)buf, len * sizeof(wchar_t), 0);
}
