#include "MultiAppFactory.h"
#include "BrowserApp.h"
#include "RenderApp.h"
#include "OtherApp.h"


CefAppFactory* MultiAppFactory::createFactory()
{
	return new MultiAppFactory();
}

CefApp* MultiAppFactory::createBrowserApp(HWND hWnd)
{
	return new BrowserApp(hWnd);
}

CefApp* MultiAppFactory::createOtherApp(const CefString& type, HWND hWnd)
{
	return new OtherApp();
}

CefApp* MultiAppFactory::createRenderApp(HWND hWnd)
{
	return new RenderApp();
}
