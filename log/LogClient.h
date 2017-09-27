#ifndef __LOGCLIENT_H__
#define __LOGCLIENT_H__
#include <windows.h>

class LogClient
{
public:
	LogClient(const char* ip, int port = 9001);
	~LogClient();
	void log(const char* text, ...);
	void log(const wchar_t* text, ...);
private:
	SOCKET m_socket;
private:
	static bool isInit;
	static int clientCount;
};
#endif
