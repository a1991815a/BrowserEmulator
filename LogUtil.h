#ifndef __LOGUTIL_H__
#define __LOGUTIL_H__
#include "log/LogClient.h"

#if defined(_DEBUG) && defined(_REMOTE_DEBUG)
#define REMOTE_LOG(format, ...) LogUtil::getLog()->log(format,##__VA_ARGS__)
#define RLOG(format, ...) REMOTE_LOG(format,##__VA_ARGS__)
#else
#define REMOTE_LOG(format, ...) 
#define RLOG(format, ...) 
#endif

class LogUtil
{
public:
	static LogUtil* getInstance();
	static LogClient* getLog();

	LogUtil();
private:
	LogClient m_logClient;
private:
	static LogUtil* m_pInstance;
};
#endif