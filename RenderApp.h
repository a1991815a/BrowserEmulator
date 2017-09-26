#ifndef __RENDERAPP_H__
#define __RENDERAPP_H__
#include "include/cef_app.h"

class RenderApp: public CefApp, public CefRenderProcessHandler
{
public:
	virtual void OnBrowserCreated(CefRefPtr<CefBrowser> browser) override;

	virtual void OnWebKitInitialized() override;

	virtual CefRefPtr<CefRenderProcessHandler> GetRenderProcessHandler() override;

private:
	IMPLEMENT_REFCOUNTING(RenderApp);
};
#endif
