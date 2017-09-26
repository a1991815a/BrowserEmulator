#ifndef __MULTIAPPFACTORY_H__
#define __MULTIAPPFACTORY_H__
#include "CefAppFactory.h"

class MultiAppFactory : public CefAppFactory
{
public:
	static CefAppFactory* createFactory();

	virtual CefApp* createBrowserApp(HWND hWnd) override;

	virtual CefApp* createOtherApp(const CefString& type, HWND hWnd) override;

	virtual CefApp* createRenderApp(HWND hWnd) override;
};
#endif
