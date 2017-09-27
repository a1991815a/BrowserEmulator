#include "CefDelegate.h"
#include "WinAppDelegate.h"
#include "MultiAppFactory.h"
#include "LogUtil.h"
#include "CefConfigFile.h"

int APIENTRY wWinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPTSTR lpCmdLine,
	int nCmdShow) 
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	CefRefPtr<CefCommandLine> commandLine = CefCommandLine::CreateCommandLine();
	commandLine->InitFromString(::GetCommandLine());

	{
		CefConfigFile config(commandLine);
		config.init("CefConfig.ini");
	}

	RLOG("³õÊ¼»¯, type:%s", commandLine->HasSwitch("type")? commandLine->GetSwitchValue("type").ToString().c_str() : "browser");
	std::auto_ptr<CefDelegate> cefDelegate(new CefDelegate(hInstance, lpCmdLine));
	std::auto_ptr<WinAppDelegate> app;
	if (!commandLine->HasSwitch("type") || commandLine->GetSwitchValue("type") == "browser")
	{
		app = std::auto_ptr<WinAppDelegate>((new WinAppDelegate()));
		app->setInstance(hInstance);
		cefDelegate->setMixedMessageLoop(app.get());
		cefDelegate->setWnd(app->createWindow());
	}
	else
		cefDelegate->getSetting().multi_threaded_message_loop = true;
	cefDelegate->setAppFactory(MultiAppFactory::createFactory());
	cefDelegate->init(commandLine);

	return cefDelegate->runMessageLoop();
}