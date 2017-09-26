#include "CefDelegate.h"
#include "WinAppDelegate.h"
#include "MultiAppFactory.h"

int APIENTRY wWinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPTSTR lpCmdLine,
	int nCmdShow) 
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);
#ifdef _DEBUG
	//::AllocConsole();
#endif
	CefRefPtr<CefCommandLine> commandLine = CefCommandLine::CreateCommandLine();
	commandLine->InitFromString(::GetCommandLine());

	std::auto_ptr<CefDelegate> cefDelegate(new CefDelegate(hInstance, lpCmdLine));
	//std::auto_ptr<WinAppDelegate> app(new WinAppDelegate());
	//app->setInstance(hInstance);
	//cefDelegate->setMixedMessageLoop(app.get());
	//cefDelegate->setWnd(app->createWindow());
	cefDelegate->setAppFactory(MultiAppFactory::createFactory());
	cefDelegate->init(commandLine);

	int exitCode = cefDelegate->runMessageLoop();
#ifdef _DEBUG
	//::FreeConsole();
#endif
	return exitCode;
}