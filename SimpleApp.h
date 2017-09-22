#ifndef __SIMPLEAPP_H__
#define __SIMPLEAPP_H__
#include "include/cef_app.h"

class SimpleApp : public CefApp, public CefBrowserProcessHandler
{

public:
	virtual CefRefPtr<CefBrowserProcessHandler> GetBrowserProcessHandler() OVERRIDE
	{
		return this;
	}

	virtual void OnContextInitialized() OVERRIDE;

private:
	IMPLEMENT_REFCOUNTING(SimpleApp);
};
#endif