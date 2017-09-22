#ifndef __SIMPLECLIENT_H__
#define __SIMPLECLIENT_H__
#include "include/cef_client.h"

#include "SimpleLifeSpanHandler.h"
#include "SimpleRenderHandler.h"
#include "SimpleRenderHandler.h"
#include "SimpleRenderHandler.h"
#include "SimpleDialogHandler.h"
#include "SimpleDisplayHandler.h"
#include "SimpleFocusHandler.h"
#include "SimpleLifeSpanHandler.h"
#include "SimpleJSDialogHandler.h"
#include "SimpleLoadHandler.h"

class SimpleClient : public CefClient
{
public:
	SimpleClient();
	~SimpleClient();

	virtual CefRefPtr<CefDialogHandler> GetDialogHandler() override;


	virtual CefRefPtr<CefDisplayHandler> GetDisplayHandler() override;


	virtual CefRefPtr<CefFocusHandler> GetFocusHandler() override;


	virtual CefRefPtr<CefJSDialogHandler> GetJSDialogHandler() override;


	virtual CefRefPtr<CefLifeSpanHandler> GetLifeSpanHandler() override;


	virtual CefRefPtr<CefRenderHandler> GetRenderHandler() override;


	virtual CefRefPtr<CefLoadHandler> GetLoadHandler() override;

private:
	CefRefPtr<SimpleDialogHandler> m_dialogHandler;
	CefRefPtr<SimpleDisplayHandler> m_displayHandler;
	CefRefPtr<SimpleFocusHandler> m_focusHandler;
	CefRefPtr<SimpleJSDialogHandler> m_jsDialogHandler;
	CefRefPtr<SimpleLifeSpanHandler> m_lifeSpanHandler;
	CefRefPtr<SimpleRenderHandler> m_renderHandler;
	CefRefPtr<SimpleLoadHandler> m_loadHandler;

private:
	IMPLEMENT_REFCOUNTING(SimpleClient);
};
#endif