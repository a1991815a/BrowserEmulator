#ifndef __CEFAPPFACTORY_H__
#define __CEFAPPFACTORY_H__
#include <windows.h>
#include "include/cef_app.h"

class CefAppFactory
{
public:
	virtual CefApp* createRenderApp(HWND hWnd) = 0;
	virtual CefApp* createBrowserApp(HWND hWnd) = 0;
	virtual CefApp* createOtherApp(const CefString& type, HWND hWnd) = 0;
};
#endif
