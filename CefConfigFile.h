#ifndef __CEFCONFIG_H__
#define __CEFCONFIG_H__
#include "include/cef_command_line.h"

class CefConfigFile
{
public:
	CefConfigFile(CefCommandLine* commandLine);
	void init(const std::string& path);
private:
	CefRefPtr<CefCommandLine> m_commandLine;
};
#endif