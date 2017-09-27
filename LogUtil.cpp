#include "LogUtil.h"

LogUtil* LogUtil::m_pInstance = NULL;

LogUtil* LogUtil::getInstance()
{
	if (m_pInstance == NULL)
		m_pInstance = new LogUtil();
	return m_pInstance;
}

LogClient* LogUtil::getLog()
{
	return &LogUtil::getInstance()->m_logClient;
}

LogUtil::LogUtil()
	:m_logClient("127.0.0.1")
{

}
