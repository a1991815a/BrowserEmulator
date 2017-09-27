#include "CefConfigFile.h"
#include "FileIni.h"

CefConfigFile::CefConfigFile(CefCommandLine* commandLine)
	:m_commandLine(commandLine)
{

}

void CefConfigFile::init(const std::string& path)
{
	FileIni config(path);
	if (!config.read())
		return;
	if (!config.enterSection("CefConfig"))
		return;
	for (auto iter = config.begin(); iter != config.end(); ++iter)
		m_commandLine->AppendSwitchWithValue(iter->first, iter->second);
}
